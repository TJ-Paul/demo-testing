#include<iostream>
#include<vector>

using namespace std;

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    int size;               
    Node *left, *right, *parent;

    Node(int k = 0): 
        key(k), 
        color(RED), 
        size(1),
        left(nullptr), 
        right(nullptr), 
        parent(nullptr) 
        {}
    };
    
class RedBlackTree {
    private:
    Node* root;
    Node* NIL;
    
    void updateSize(Node* x) {
            if (x != NIL)
            x->size = x->left->size + x->right->size + 1;
        }
        
    Node* minimum(Node* x) {
            while (x->left != NIL)
                x = x->left;
            return x;
        }
        
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NIL)
        y->left->parent = x;
        
        y->parent = x->parent;
        
        if (x->parent == NIL)
        root = y;
        else if (x == x->parent->left)
        x->parent->left = y;
        else
        x->parent->right = y;
        
        y->left = x;
        x->parent = y;
        
        y->size = x->size;
        updateSize(x);
    }
    
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NIL)
        y->right->parent = x;
        
        y->parent = x->parent;
        
        if (x->parent == NIL)
        root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;

        y->size = x->size;
        updateSize(x);
    }

    void insertFix(Node* z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }


    void transplant(Node* u, Node* v) {
        if (u->parent == NIL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    void deleteFix(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    RedBlackTree() {
        NIL = new Node();
        NIL->color = BLACK;
        NIL->size = 0;
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
    }

    bool search(int key) {
        Node* cur = root;
        while (cur != NIL) {
            if (key == cur->key) return true;
            if (key < cur->key) cur = cur->left;
            else cur = cur->right;
        }
        return false;
    }

    bool insert(int key) {
        Node* z = new Node(key);
        z->left = z->right = z->parent = NIL;

        Node* y = NIL;
        Node* x = root;

        while (x != NIL) {
            y = x;
            x->size++;
            if (key == x->key) return false;
            if (key < x->key) x = x->left;
            else x = x->right;
        }

        z->parent = y;
        if (y == NIL) root = z;
        else if (key < y->key) y->left = z;
        else y->right = z;

        insertFix(z);
        return true;
    }

    bool remove(int key) {
        Node* z = root;
        while (z != NIL && z->key != key) {
            z->size--;
            if (key < z->key) z = z->left;
            else z = z->right;
        }
        if (z == NIL) return false;

        Node* y = z;
        Node* x;
        Color yOriginal = y->color;

        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginal = y->color;
            x = y->right;

            if (y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
            updateSize(y);
        }

        if (yOriginal == BLACK)
            deleteFix(x);

        return true;
    }

    int countLess(int key) {
        int res = 0;
        Node* cur = root;
        while (cur != NIL) {
            if (key <= cur->key)
                cur = cur->left;
            else {
                res += cur->left->size + 1;
                cur = cur->right;
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cout << N << endl;

    RedBlackTree rbt;

    while (N--) {
        int e, x;
        cin >> e >> x;

        int r = 0;
        if (e == 1) r = rbt.insert(x);
        else if (e == 0) r = rbt.remove(x);
        else if (e == 2) r = rbt.search(x);
        else if (e == 3) r = rbt.countLess(x);

        cout << e << " " << x << " " << r << endl;
    }
    return 0;
}
