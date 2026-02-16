#include <bits/stdc++.h>
using namespace std;

// ===================== Hash functions (from your offline) =====================

int hash1(const string &key, int tableSize)
{
    // Polynomial rolling hash
    unsigned long long hash = 0;
    const int p = 31;
    unsigned long long p_pow = 1;

    for (char c : key)
    {
        hash = (hash + (unsigned long long)(c - 'a' + 1) * p_pow) % tableSize;
        p_pow = (p_pow * p) % tableSize;
    }
    return (int)hash;
}

int hash2(const string &key, int tableSize)
{
    // FNV-1a style
    unsigned long long hash = 2166136261u;
    const unsigned long long FNV_prime = 16777619u;

    for (char c : key)
    {
        hash ^= (unsigned long long)c;
        hash *= FNV_prime;
    }
    return (int)(hash % tableSize);
}

// Helper to make numeric IDs hash nicely with given string hashes.
// Your hash1 assumes lowercase letters, so we normalize by mapping digits and '-'.
// (This keeps using your hash1 function while avoiding bad behavior on digits.)
static inline string norm_id(long long x) {
    string s = to_string(x);
    // map '0'..'9' to 'a'..'j', '-' to 'k'
    for (char &ch : s) {
        if (ch == '-') ch = 'k';
        else if (ch >= '0' && ch <= '9') ch = char('a' + (ch - '0'));
    }
    return s;
}

// ===================== Inner Table (user_id -> permission) =====================

struct InnerSlot {
    long long user_id = 0;
    string perm;
    bool occupied = false;
    bool deleted = false;
};

struct InnerTable {
    int N;
    vector<InnerSlot> t;

    InnerTable(int n=0): N(n), t(n) {}

    int probeIndex(long long user_id, int i) const {
        int h = hash2(norm_id(user_id), N);
        long long idx = ( (long long)h + 1LL*i*i ) % N; // quadratic probing
        return (int)idx;
    }

    // Insert or update permission
    bool insertOrUpdate(long long user_id, const string &perm) {
        int firstDeleted = -1;

        for (int i = 0; i < N; i++) {
            int idx = probeIndex(user_id, i);

            if (!t[idx].occupied) {
                // empty slot: insert here (or into earlier tombstone)
                int put = (firstDeleted != -1 ? firstDeleted : idx);
                t[put].user_id = user_id;
                t[put].perm = perm;
                t[put].occupied = true;
                t[put].deleted = false;
                return true;
            }

            if (t[idx].occupied && t[idx].deleted && firstDeleted == -1) {
                firstDeleted = idx; // remember first tombstone
            }

            if (t[idx].occupied && !t[idx].deleted && t[idx].user_id == user_id) {
                // update existing
                t[idx].perm = perm;
                return true;
            }
        }
        // table full
        return false;
    }

    bool find(long long user_id, string &permOut) const {
        for (int i = 0; i < N; i++) {
            int idx = probeIndex(user_id, i);

            if (!t[idx].occupied) return false; // stop early
            if (t[idx].occupied && !t[idx].deleted && t[idx].user_id == user_id) {
                permOut = t[idx].perm;
                return true;
            }
        }
        return false;
    }

    bool erase(long long user_id, string &permDeleted) {
        for (int i = 0; i < N; i++) {
            int idx = probeIndex(user_id, i);

            if (!t[idx].occupied) return false;
            if (t[idx].occupied && !t[idx].deleted && t[idx].user_id == user_id) {
                permDeleted = t[idx].perm;
                t[idx].deleted = true;
                return true;
            }
        }
        return false;
    }

    vector<pair<long long,string>> allPairs() const {
        vector<pair<long long,string>> res;
        for (int i = 0; i < N; i++) {
            if (t[i].occupied && !t[i].deleted) {
                res.push_back({t[i].user_id, t[i].perm});
            }
        }
        return res;
    }
};

// ===================== Outer Table (group_id -> InnerTable*) =====================

struct OuterSlot {
    long long group_id = 0;
    InnerTable* inner = nullptr;
    bool occupied = false;
    bool deleted = false;
};

struct TwoLayerHash {
    int N;
    vector<OuterSlot> outer;

    TwoLayerHash(int n): N(n), outer(n) {}

    int probeIndex(long long group_id, int i) const {
        int h = hash1(norm_id(group_id), N);
        return (h + i) % N; // linear probing
    }

    // Find group slot index; returns -1 if not found
    int findGroupIndex(long long group_id) const {
        for (int i = 0; i < N; i++) {
            int idx = probeIndex(group_id, i);
            if (!outer[idx].occupied) return -1;
            if (outer[idx].occupied && !outer[idx].deleted && outer[idx].group_id == group_id) return idx;
        }
        return -1;
    }

    // Get or create group's inner table
    InnerTable* getOrCreateGroup(long long group_id) {
        int firstDeleted = -1;

        for (int i = 0; i < N; i++) {
            int idx = probeIndex(group_id, i);

            if (!outer[idx].occupied) {
                int put = (firstDeleted != -1 ? firstDeleted : idx);
                outer[put].group_id = group_id;
                outer[put].occupied = true;
                outer[put].deleted = false;
                if (outer[put].inner == nullptr) outer[put].inner = new InnerTable(N);
                return outer[put].inner;
            }

            if (outer[idx].occupied && outer[idx].deleted && firstDeleted == -1) {
                firstDeleted = idx;
            }

            if (outer[idx].occupied && !outer[idx].deleted && outer[idx].group_id == group_id) {
                if (outer[idx].inner == nullptr) outer[idx].inner = new InnerTable(N);
                return outer[idx].inner;
            }
        }
        return nullptr; // outer full
    }

    ~TwoLayerHash() {
        for (auto &s : outer) {
            delete s.inner;
            s.inner = nullptr;
        }
    }
};

// ===================== Output helpers =====================

static void printAllPairs(long long group_id, const vector<pair<long long,string>> &pairs) {
    // Format like: (1, read), (2, write)
    for (size_t i = 0; i < pairs.size(); i++) {
        cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
        if (i + 1 < pairs.size()) cout << ", ";
    }
    cout << "\n";
}

// ===================== Main =====================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    TwoLayerHash db(N);

    while (Q--) {
        string op;
        cin >> op;

        if (op == "INSERT") {
            long long g, u;
            string perm;
            cin >> g >> u >> perm;

            InnerTable* inner = db.getOrCreateGroup(g);
            if (inner) inner->insertOrUpdate(u, perm);
            // no output

        } else if (op == "SEARCH") {
            long long g;
            cin >> g;

            // Peek if there's a second token on this line (user_id) by checking next char
            // But easier: use cin.peek with skipping spaces/newlines carefully.
            // We'll read rest of line and parse.
            string rest;
            getline(cin, rest); // remainder after group_id
            stringstream ss(rest);

            long long u;
            if (ss >> u) {
                // SEARCH group user
                int gi = db.findGroupIndex(g);
                if (gi == -1) {
                    cout << "Group not found\n";
                } else {
                    string perm;
                    if (db.outer[gi].inner && db.outer[gi].inner->find(u, perm)) {
                        cout << perm << "\n";
                    } else {
                        cout << "User not found in group " << g << "\n";
                    }
                }
            } else {
                // SEARCH group
                int gi = db.findGroupIndex(g);
                if (gi == -1) {
                    cout << "Group not found\n";
                } else {
                    auto pairs = db.outer[gi].inner ? db.outer[gi].inner->allPairs()
                                                   : vector<pair<long long,string>>{};
                    printAllPairs(g, pairs);
                }
            }

        } else if (op == "DELETE") {
            long long g, u;
            cin >> g >> u;

            int gi = db.findGroupIndex(g);
            if (gi == -1) {
                cout << "Group not found\n";
            } else {
                string permDel;
                if (db.outer[gi].inner && db.outer[gi].inner->erase(u, permDel)) {
                    cout << "(" << u << ", " << permDel << ") deleted\n";
                } else {
                    cout << "User not found in group " << g << "\n";
                }
            }
        }
    }
    return 0;
}