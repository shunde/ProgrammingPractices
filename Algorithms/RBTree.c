#include <stdio.h>
#include <stdlib.h>


#define RED 0
#define BLACK 1



typedef struct Node {
    int val;
    int N;
    int color;
    struct Node* left;
    struct Node* right;
}Node, RBTree;


void err_exit(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(0);
}

int size(RBTree *root) {
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

Node* createNode(int x) {
    Node* pNode = (Node *)malloc(sizeof(Node));
    if (!pNode) err_exit("out of memory");
    pNode->val = x;
    pNode->left = pNode->right = NULL; 
    pNode->N = 1;
    pNode->color = RED;
    return pNode;
}

int isRed(Node* h) {
    if (h == NULL) return 0;
    return h->color == RED;
}


static RBTree* insertAux(RBTree *root, int x) {
    if (root == NULL) {
        Node* pNode = createNode(x);
        return pNode;        
    }

    if (x < root->val)
        root->left = insertAux(root->left, x);
    else if (x > root->val)
        root->right = insertAux(root->right, x);
    else {
        // nothing to do
    }

    if (isRed(root->right) && !isRed(root->left)) 
        root = rotateLeft(root);
    if (isRed(root->left) && isRed(root->left->left))
        root = rotateRight(root);
    if (isRed(root->left) && isRed(root->right))
        flipColor(root);

    root->N = 1 + size(root->left) + size(root->right);

    return root;
}

RBTree* insert(RBTree *root, int x) {
    root = insertAux(root, x);
    root->color = BLACK;
    return root;
}

void printRBTree(RBTree *root) {
    if (root) {
        printf("%d(%s, %d), ", root->val, isRed(root)?"R":"B", root->N);
        printRBTree(root->left);
        printRBTree(root->right);
    }
}


int main(int argc, char *argv[]) {
    RBTree* rb_tree = NULL;
    for (int i = 0; i < 20; i++) 
        rb_tree = insert(rb_tree, i);

    printRBTree(rb_tree);
    return 0;
}