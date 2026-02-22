#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
    int key;
    int height;
    Node *left, *right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVL {
private:
    Node* root = nullptr;

    int h(Node* n) { return n ? n->height : 0; }

    int balance(Node* n) { return n ? h(n->left) - h(n->right) : 0; }

    void update(Node* n) {
        if (!n) return;
        n->height = max(h(n->left), h(n->right)) + 1;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* q = x->right;

        x->right = y;
        y->left = q;

        update(y);
        update(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* q = y->left;

        y->left = x;
        x->right = q;

        update(x);
        update(y);
        return y;
    }

Node* rebalance(Node* node) {
    update(node);
    int bf = balance(node);

    if (bf > 1) {
        if (balance(node->left) < 0) {
            node->left->right = rightRotate(node->left->right);
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        return rightRotate(node);
    }

    if (bf < -1) {
        if (balance(node->right) > 0) {
            node->right->left = leftRotate(node->right->left);
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return leftRotate(node);
    }

    return node;
}


    bool contains(Node* node, int key) {
        while (node) {
            if (key == node->key) return true;
            node = (key < node->key) ? node->left : node->right;
        }
        return false;
    }

    Node* insertRec(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key) node->left = insertRec(node->left, key);
        else if (key > node->key) node->right = insertRec(node->right, key);
        return rebalance(node);
    }

    Node* minNode(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteRec(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRec(node->right, key);
        } else {
            if (!node->left || !node->right) {
                Node* child = node->left ? node->left : node->right;
                delete node;
                return child; 
            } else {
                Node* succ = minNode(node->right);
                node->key = succ->key;
                node->right = deleteRec(node->right, succ->key);
            }
        }
        return rebalance(node);
    }

    void preorder(Node* node, vector<int>& out) {
        if (!node) return;
        out.push_back(node->key);
        preorder(node->left, out);
        preorder(node->right, out);
    }

    void inorder(Node* node, vector<int>& out) {
        if (!node) return;
        inorder(node->left, out);
        out.push_back(node->key);
        inorder(node->right, out);
    }

    void postorder(Node* node, vector<int>& out) {
        if (!node) return;
        postorder(node->left, out);
        postorder(node->right, out);
        out.push_back(node->key);
    }

    void levelorder(Node* node, vector<int>& out) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            out.push_back(cur->key);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }


public:
    bool insertKey(int key) {
        if (contains(root, key)) return false;
        root = insertRec(root, key);
        return true;
    }

    bool deleteKey(int key) {
        if (!contains(root, key)) return false;
        root = deleteRec(root, key);
        return true;
    }

vector<int> traverse(int type) {
    vector<int> out;
    if (type == 1) preorder(root, out);
    else if (type == 2) levelorder(root, out); 
    else if (type == 3) inorder(root, out);
    else if (type == 4) postorder(root, out);
    return out;
}

};

int main() {
    int N;
    cin >> N;

    cout << N << endl;

    AVL avl;

    for (int i = 0; i < N; i++) {
        int e, x;
        cin >> e >> x;

        if (e == 1) {
            int r = avl.insertKey(x) ? 1 : 0;
            cout << e << " " << x << " " << r << endl;
        } else if (e == 0) {
            int r = avl.deleteKey(x) ? 1 : 0;
            cout << e << " " << x << " " << r << endl;
        } else if (e == 2) {
            vector<int> ans = avl.traverse(x);
            for (int j = 0; j < (int)ans.size(); j++) {
                if (j) cout << " ";
                cout << ans[j];
            }
            cout << endl;
        }
    }
    return 0;
}
