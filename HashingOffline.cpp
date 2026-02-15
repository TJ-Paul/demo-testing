#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <unordered_set>
#include <iomanip>
#include <algorithm>

using namespace std;

// Configuration parameters (single-source variables)
const int INITIAL_TABLE_SIZE = 13;
const double LOAD_FACTOR_THRESHOLD = 0.5;
const double COMPACTION_THRESHOLD = 0.25;

// Constants for custom probing
const int C1 = 1;
const int C2 = 3;

// Hash table entry
template <typename K, typename V>
struct Entry
{
    K key;
    V value;
    bool isDeleted;

    Entry() : isDeleted(false) {}
    Entry(K k, V v) : key(k), value(v), isDeleted(false) {}
};

// Node for chaining
template <typename K, typename V>
struct ChainNode
{
    K key;
    V value;
    ChainNode *next;

    ChainNode(K k, V v) : key(k), value(v), next(nullptr) {}
};

// Utility functions
bool isPrime(int n)
{
    if (n <= 1) // numbers <= 1 are not prime
        return false;
    if (n <= 3) // 2 and 3 are prime
        return true; 
    if (n % 2 == 0 || n % 3 == 0) // eliminate multiples of 2 and 3
        return false;

    for (int i = 5; i * i <= n; i += 6)     // all primes > 3 are of the form (6k +- 1)
    {                                       // discrete math
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int nextPrime(int n)
{
    if (n <= 2)
        return 2;
    int prime = n;
    while (!isPrime(prime))
    {
        prime++;
    }
    return prime;
}

int prevPrime(int n)
{
    if (n <= 2)
        return 2;
    int prime = n;
    while (prime > 2 && !isPrime(prime))
    {
        prime--;
    }
    return prime;
}

// Hash functions
int hash1(const string &key, int tableSize)
{
    // Polynomial rolling hash (Horner's method)
    unsigned long long hash = 0;
    const int p = 31; // prime number
    unsigned long long p_pow = 1;

    for (char c : key)
    {
        hash = (hash + (c - 'a' + 1) * p_pow) % tableSize;
        p_pow = (p_pow * p) % tableSize;
    }

    return hash;
}

int hash2(const string &key, int tableSize)
{
    // FNV-1a hash adapted for string
    unsigned long long hash = 2166136261u;
    const unsigned long long FNV_prime = 16777619u;

    for (char c : key)
    {
        hash ^= c;
        hash *= FNV_prime;
    }

    return hash % tableSize;
}

int auxHash(const string &key, int tableSize)
{
    // Simple auxiliary hash for double hashing
    // Returns a value between 1 and tableSize-1
    int h = 0;
    for (char c : key)
    {
        h = (h * 37 + c) % (tableSize - 1);
    }
    return h + 1; // Ensure non-zero
}   // auxHash (h2) cannot be 0 or table_size 





// Base Hash Table class
template <typename K, typename V>
class HashTableBase
{
protected:
    int tableSize;
    int numElements;
    int collisionCount;
    int insertionsSinceExpansion;
    int deletionsSinceCompaction;

public:
    HashTableBase(int size = INITIAL_TABLE_SIZE)
        : tableSize(size), numElements(0), collisionCount(0),
          insertionsSinceExpansion(0), deletionsSinceCompaction(0) {}

    virtual ~HashTableBase() {}

    virtual bool insert(const K &key, const V &value) = 0;
    virtual bool search(const K &key, V &value, int &hits) = 0;
    virtual bool remove(const K &key) = 0;

    int getCollisionCount() const { return collisionCount; }
    int getNumElements() const { return numElements; }
    double getLoadFactor() const { return (double)numElements / tableSize; }
    void resetCollisionCount() { collisionCount = 0; }
};





// Chaining Hash Table
template <typename K, typename V>
class ChainingHashTable : public HashTableBase<K, V>
{
private:
    vector<ChainNode<K, V> *> table;
    int (*hashFunc)(const string &, int);

    void resize(int newSize)
    {
        vector<ChainNode<K, V> *> oldTable = table;
        int oldSize = this->tableSize;

        table.clear();
        table.resize(newSize, nullptr);
        this->tableSize = newSize;
        this->numElements = 0;

        // Rehash all elements
        for (int i = 0; i < oldSize; i++)
        {
            ChainNode<K, V> *current = oldTable[i];
            while (current != nullptr)
            {
                if (!current->key.empty())
                {
                    insert(current->key, current->value);
                }
                ChainNode<K, V> *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

public:
    ChainingHashTable(int (*hf)(const string &, int), int size = INITIAL_TABLE_SIZE)
        : HashTableBase<K, V>(size), hashFunc(hf)
    {
        table.resize(size, nullptr);
    }

    ~ChainingHashTable()
    {
        for (int i = 0; i < this->tableSize; i++)
        {
            ChainNode<K, V> *current = table[i];
            while (current != nullptr)
            {
                ChainNode<K, V> *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    bool insert(const K &key, const V &value) override
    {
        int index = hashFunc(key, this->tableSize);

        // Check if key already exists
        ChainNode<K, V> *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return false; // Key already exists
            }
            current = current->next;
        }

        // Count collision if chain already exists
        if (table[index] != nullptr)
        {
            this->collisionCount++;
        }

        // Insert at head
        ChainNode<K, V> *newNode = new ChainNode<K, V>(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        this->numElements++;
        this->insertionsSinceExpansion++;

        // Check for expansion
        if (this->getLoadFactor() > LOAD_FACTOR_THRESHOLD &&
            this->insertionsSinceExpansion >= this->numElements / 2)
        {
            int newSize = nextPrime(2 * this->tableSize);
            resize(newSize);
            this->insertionsSinceExpansion = 0;
        }

        return true;
    }

    bool search(const K &key, V &value, int &hits) override
    {
        hits = 0;
        int index = hashFunc(key, this->tableSize);

        ChainNode<K, V> *current = table[index];
        while (current != nullptr)
        {
            hits++;
            if (current->key == key)
            {
                value = current->value;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    bool remove(const K &key) override
    {
        int index = hashFunc(key, this->tableSize);

        ChainNode<K, V> *current = table[index];
        ChainNode<K, V> *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                this->numElements--;
                this->deletionsSinceCompaction++;

                // Check for compaction
                if (this->tableSize > INITIAL_TABLE_SIZE &&
                    this->getLoadFactor() < COMPACTION_THRESHOLD &&
                    this->deletionsSinceCompaction >= this->numElements / 2)
                {
                    int newSize = prevPrime(this->tableSize / 2);
                    if (newSize >= INITIAL_TABLE_SIZE)
                    {
                        resize(newSize);
                        this->deletionsSinceCompaction = 0;
                    }
                }

                return true;
            }
            prev = current;
            current = current->next;
        }

        return false;
    }
};

// Open Addressing Base Class
template <typename K, typename V>
class OpenAddressingHashTable : public HashTableBase<K, V>
{
protected:
    vector<Entry<K, V>> table;
    vector<bool> occupied;
    int (*hashFunc)(const string &, int);

    virtual int probe(const K &key, int i) = 0;

    void resize(int newSize)
    {
        vector<Entry<K, V>> oldTable = table;
        vector<bool> oldOccupied = occupied;
        int oldSize = this->tableSize;

        table.clear();
        occupied.clear();
        table.resize(newSize);
        occupied.resize(newSize, false);
        this->tableSize = newSize;
        this->numElements = 0;

        // Rehash all elements
        for (int i = 0; i < oldSize; i++)
        {
            if (oldOccupied[i] && !oldTable[i].isDeleted)
            {
                insert(oldTable[i].key, oldTable[i].value);
            }
        }
    }

public:
    OpenAddressingHashTable(int (*hf)(const string &, int), int size = INITIAL_TABLE_SIZE)
        : HashTableBase<K, V>(size), hashFunc(hf)
    {
        table.resize(size);
        occupied.resize(size, false);
    }

    bool insert(const K &key, const V &value) override
    {
        if (this->getLoadFactor() > LOAD_FACTOR_THRESHOLD &&
            this->insertionsSinceExpansion >= this->numElements / 2)
        {
            int newSize = nextPrime(2 * this->tableSize);
            resize(newSize);
            this->insertionsSinceExpansion = 0;
        }

        int i = 0;
        bool collisionOccurred = false;

        while (i < this->tableSize)
        {
            int index = probe(key, i);

            if (!occupied[index] || table[index].isDeleted)
            {
                table[index] = Entry<K, V>(key, value);
                occupied[index] = true;
                this->numElements++;
                this->insertionsSinceExpansion++;
                if (collisionOccurred)
                {
                    this->collisionCount++;
                }
                return true;
            }

            if (table[index].key == key)
            {
                return false; // Key already exists
            }

            collisionOccurred = true;
            i++;
        }

        return false; // Table full
    }

    bool search(const K &key, V &value, int &hits) override
    {
        hits = 0;
        int i = 0;

        while (i < this->tableSize)
        {
            int index = probe(key, i);
            hits++;

            if (!occupied[index])
            {
                return false; // Empty slot, key not found
            }

            if (!table[index].isDeleted && table[index].key == key)
            {
                value = table[index].value;
                return true;
            }

            i++;
        }

        return false;
    }

    bool remove(const K &key) override
    {
        int i = 0;

        while (i < this->tableSize)
        {
            int index = probe(key, i);

            if (!occupied[index])
            {
                return false;
            }

            if (!table[index].isDeleted && table[index].key == key)
            {
                table[index].isDeleted = true;
                this->numElements--;
                this->deletionsSinceCompaction++;

                if (this->tableSize > INITIAL_TABLE_SIZE &&
                    this->getLoadFactor() < COMPACTION_THRESHOLD &&
                    this->deletionsSinceCompaction >= this->numElements / 2)
                {
                    int newSize = prevPrime(this->tableSize / 2);
                    if (newSize >= INITIAL_TABLE_SIZE)
                    {
                        resize(newSize);
                        this->deletionsSinceCompaction = 0;
                    }
                }

                return true;
            }

            i++;
        }

        return false;
    }
};

// Double Hashing
template <typename K, typename V>
class DoubleHashingTable : public OpenAddressingHashTable<K, V>
{
protected:
    int probe(const K &key, int i) override
    {
        int h1 = this->hashFunc(key, this->tableSize);
        int h2 = auxHash(key, this->tableSize);
        return (h1 + i * h2) % this->tableSize;
    }

public:
    DoubleHashingTable(int (*hf)(const string &, int), int size = INITIAL_TABLE_SIZE)
        : OpenAddressingHashTable<K, V>(hf, size) {}
};

// Custom Probing
template <typename K, typename V>
class CustomProbingTable : public OpenAddressingHashTable<K, V>
{
protected:
    int probe(const K &key, int i) override
    {
        int h1 = this->hashFunc(key, this->tableSize);
        int h2 = auxHash(key, this->tableSize);
        return (h1 + C1 * i * h2 + C2 * i * i) % this->tableSize;
    }

public:
    CustomProbingTable(int (*hf)(const string &, int), int size = INITIAL_TABLE_SIZE)
        : OpenAddressingHashTable<K, V>(hf, size) {}
};

// Random word generator
class WordGenerator
{
private:
    mt19937 rng;
    uniform_int_distribution<int> dist;

public:
    WordGenerator() : rng(random_device{}()), dist(0, 25) {}

    string generateWord(int length)
    {
        string word;
        for (int i = 0; i < length; i++)
        {
            word += ('a' + dist(rng));
        }
        return word;
    }

    vector<string> generateUniqueWords(int count, int length)
    {
        vector<string> words;
        unordered_set<string> seen;

        while (words.size() < static_cast<size_t>(count))
        {
            string word = generateWord(length);
            if (seen.find(word) == seen.end())
            {
                seen.insert(word);
                words.push_back(word);
            }
        }

        return words;
    }
};

// Performance evaluation
void evaluatePerformance()
{
    const int NUM_WORDS = 10000;
    const int WORD_LENGTH = 10;
    const int NUM_SEARCHES = 1000;

    WordGenerator generator;
    vector<string> words = generator.generateUniqueWords(NUM_WORDS, WORD_LENGTH);

    cout << "Generated " << NUM_WORDS << " unique words of length " << WORD_LENGTH << endl;
    cout << "\nPerformance Evaluation:\n";
    cout << "====================================================================================\n";
    cout << setw(25) << "" << setw(30) << "Hash1" << setw(30) << "Hash2" << endl;
    cout << setw(25) << "Method"
         << setw(15) << "Collisions" << setw(15) << "Avg Hits"
         << setw(15) << "Collisions" << setw(15) << "Avg Hits" << endl;
    cout << "------------------------------------------------------------------------------------\n";

    // Test each combination
    vector<pair<string, vector<HashTableBase<string, int> *>>> tests = {
        {"Chaining Method", {new ChainingHashTable<string, int>(hash1), new ChainingHashTable<string, int>(hash2)}},
        {"Double Hashing", {new DoubleHashingTable<string, int>(hash1), new DoubleHashingTable<string, int>(hash2)}},
        {"Custom Probing", {new CustomProbingTable<string, int>(hash1), new CustomProbingTable<string, int>(hash2)}}};

    for (auto &test : tests)
    {
        cout << setw(25) << test.first;

        for (int hashVersion = 0; hashVersion < 2; hashVersion++)
        {
            HashTableBase<string, int> *ht = test.second[hashVersion];

            // Insert all words
            for (size_t i = 0; i < words.size(); i++)
            {
                ht->insert(words[i], i + 1);
            }

            int collisions = ht->getCollisionCount();

            // Search for random sample
            mt19937 rng(42); // Fixed seed for reproducibility
            uniform_int_distribution<int> dist(0, NUM_WORDS - 1);

            int totalHits = 0;
            for (int i = 0; i < NUM_SEARCHES; i++)
            {
                int idx = dist(rng);
                int value, hits;
                ht->search(words[idx], value, hits);
                totalHits += hits;
            }

            double avgHits = (double)totalHits / NUM_SEARCHES;

            cout << setw(15) << collisions << setw(15) << fixed << setprecision(2) << avgHits;

            delete ht;
        }

        cout << endl;
    }

    cout << "====================================================================================\n";
}

int main()
{
    cout << "Hash Table Implementation - CSE208 Assignment\n";
    cout << "============================================\n\n";

    cout << "Configuration:\n";
    cout << "  Initial table size: " << INITIAL_TABLE_SIZE << endl;
    cout << "  Load factor threshold: " << LOAD_FACTOR_THRESHOLD << endl;
    cout << "  Compaction threshold: " << COMPACTION_THRESHOLD << endl;
    cout << "  Custom probing C1: " << C1 << ", C2: " << C2 << endl;
    cout << endl;

    evaluatePerformance();

    return 0;
}
