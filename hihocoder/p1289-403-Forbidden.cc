#include <cstdio>
#include <cstdint>
#include <climits>
#include <cstring>
using namespace std;


struct Node {
    Node *left;   // 0
    Node *right;  // 1
    bool isLeaf;  // One Entry
    bool isAllowed;
    int rank;
    Node(): left(NULL), right(NULL), isLeaf(false) {}
};


struct IPRule {
    uint32_t ip;
    unsigned int maskBits;
    bool isAllowed;
    int rank;
    IPRule(): isAllowed(false), maskBits(32), rank(-1) { ip = 0x00; }
};

class BinaryTrie {
public:
    BinaryTrie() {
        root = new Node();
    }

    void AddIPRule(const IPRule &rule) {
        root = addIPRule(root, rule, 1);
    }

    bool isAllowed(const uint32_t ip) {
        bool allowed = true;
        int rank = INT_MAX;
        Node *cur = root;
        uint32_t mask = 0x80000000;
        while (cur != NULL) {
            if (cur->isLeaf) {
                if (cur->rank < rank) {
                    rank = cur->rank;
                    allowed = cur->isAllowed;
                }
            }
            if (ip & mask)
                cur = cur->right;
            else
                cur = cur->left;

            mask /= 2;
        }
        return allowed;
    }

    ~BinaryTrie() {
        freeNode(root);
    }

private:
    Node *addIPRule(Node* root, const IPRule &rule, int step) {
        if (root == NULL) {
            root = new Node();
        }
        if (step > rule.maskBits) {
            if (!root->isLeaf) { // Very Important. corner case. 重复的IP规则，以最开始出现的为准。
                root->isLeaf = true;
                root->isAllowed = rule.isAllowed;
                root->rank = rule.rank;
            }
        } else {
            uint32_t mask = 0x80000000 >> (step - 1);
            if (rule.ip & mask) {
                root->right = addIPRule(root->right, rule, step + 1);
            } else {
                root->left = addIPRule(root->left, rule, step + 1);
            }
        }
        return root;
    }

    void freeNode(Node* root) {
        if (root) {
            if (root->left)
                freeNode(root->left);
            if (root->right)
                freeNode(root->right);
            delete root;
        }
    }
private:
    Node *root;
};

int main(int argc, char* argv[]) {
    int N, M;
    char buf[80];
    scanf("%d %d", &N, &M);
    BinaryTrie ruleFilter;
    for (int i = 0; i < N; i++) {
        IPRule rule;
        scanf("%s", buf);
        if (strcmp(buf, "allow") == 0)
            rule.isAllowed = true;
        else
            rule.isAllowed = false;

        unsigned int c1, c2, c3, c4;
        unsigned int c5;
        c5 = 32;
        scanf("%u.%u.%u.%u/%u", &c1, &c2, &c3, &c4, &c5);
        rule.ip = c4 + (c3 << 8) + (c2 << 16) + (c1 << 24);
        rule.maskBits = c5;
        rule.rank = i + 1;
        ruleFilter.AddIPRule(rule);
    }

    for (int i = 0; i < M; i++) {
        uint32_t ip;
        unsigned int c1, c2, c3, c4;
        scanf("%u.%u.%u.%u", &c1, &c2, &c3, &c4);
        ip =  c4 + (c3 << 8) + (c2 << 16) + (c1 << 24);

        if (ruleFilter.isAllowed(ip))
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}