class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        rbtree.insert(num);
    }

    // Returns the median of current data stream
    double findMedian() {
        int n = rbtree.size();
        if (n == 0) return 0;
        int mid1, mid2;
        if (n % 2 == 1) {
            mid1 = mid2 = (1+n)/2;
        } else {
            mid1 = (1+n)/2;
            mid2 = mid1 + 1;
        }

        if (mid1 == mid2)
            return rbtree.rankN(mid1);
        else
            return (rbtree.rankN(mid1)+rbtree.rankN(mid2))*1.0/2;
    }
private:
    class RBTree {
    private:
        enum Color { RED = 0, BLACK = 1};
        struct Node {
            int val;
            int N;
            Color color;
            Node *left;
            Node *right;
            Node(int x): val(x), N(1), color(RED), left(NULL), right(NULL) {}
        };
        Node *root;
    private:
        Node* insertAux(Node *root, int x) {
            if (root == NULL) {
                Node* pNode = new Node(x);
                return pNode;
            }

            if (x <= root->val)
                root->left = insertAux(root->left, x);
            else if (x > root->val)
                root->right = insertAux(root->right, x);


            if (isRed(root->right) && !isRed(root->left))
                root = rotateLeft(root);
            if (isRed(root->left) && isRed(root->left->left))
                root = rotateRight(root);
            if (isRed(root->left) && isRed(root->right))
                flipColor(root);

            root->N = 1 + size(root->left) + size(root->right);

            return root;
        }

        Node* insert(Node* root, int x) {
            root = insertAux(root, x);
            root->color = BLACK;
            return root;
        }

        int size(Node *root) {
            if (root == NULL) return 0;
            return root->N;
        }

        Node* rotateLeft(Node *h) {
            Node* x = h->right;
            h->right = x->left;
            x->left = h;
            x->color = h->color;
            h->color = RED;
            x->N = h->N;
            h->N = 1 + size(h->left) + size(h->right);
            return x;
        }

        Node* rotateRight(Node *h) {
            Node* x = h->left;
            h->left = x->right;
            x->right = h;
            x->color = h->color;
            h->color = RED;
            x->N = h->N;
            h->N = 1 + size(h->left) + size(h->right);
            return x;
        }

        void flipColor(Node *h) {
            h->color = RED;
            h->left->color = BLACK;
            h->right->color = BLACK;
        }

        int isRed(Node* h) {
            if (h == NULL) return 0;
            return h->color == RED;
        }

        int rankN(Node *root, int n) {
            if (n == size(root->left) + 1)
                return root->val;
            else if (n < size(root->left) + 1)
                return rankN(root->left, n);
            else
                return rankN(root->right, n - size(root->left) - 1);
        }

    public:
        RBTree(): root(NULL) {}
        void insert(int x) { root = insert(root, x); }
        int rankN(int n) { return rankN(root, n); }
        int size() { return size(root); }
    };

    RBTree rbtree;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();