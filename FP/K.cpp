// Nakama
#include <iostream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
};

struct BST {
    BSTNode* root;
    unsigned int size;
};

BSTNode* createNode(BSTNode* root, int value) {
    BSTNode* newNode = new BSTNode;
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode* root, BSTNode* node, int value) {
    if (node == NULL)
        return createNode(root, value);

    root = node;
    if (value < node->key)
        node->left = insert(root, node->left, value);
    else if (value > node->key)
        node->right = insert(root, node->right, value);

    return node;
}

BSTNode* search(BSTNode* root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void init(BST* tri) {
    tri->root = NULL;
    tri->size = 0u;
}

bool isEmpty(BST* tri) {
    return tri->root == NULL;
}

BSTNode* find(BST* tri, int value) {
    BSTNode* temp = search(tri->root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void insert(BST* tri, int value) {
    if (!find(tri, value)) {
        tri->root = insert(tri->root, tri->root, value);
        tri->size++;
    }
}

void findTreasure(BSTNode* root, int quarry, int* flag) {
    if (root) {
        int sum;
        if (root->parent) {
            if (root->left) {
                sum = root->key + root->parent->key + root->left->key;
                if (sum == quarry && !(*flag)) {
                    cout << quarry << " Selamat! Kalian menemukan harta karunnya" << endl;
                    *flag = 1;
                }
            }
            if (root->right) {
                sum = root->key + root->parent->key + root->right->key;
                if (sum == quarry && !(*flag)) {
                    cout << quarry << " Selamat! Kalian menemukan harta karunnya" << endl;
                    *flag = 1;
                }
            }
        }
        if (root->left && root->right) {
            sum = root->key + root->left->key + root->right->key;
            if (sum == quarry && !(*flag)) {
                cout << quarry << " Selamat! Kalian menemukan harta karunnya" << endl;
                *flag = 1;
            }
        }
        findTreasure(root->left, quarry, flag);
        findTreasure(root->right, quarry, flag);
    }
}

void checkPath(BST* tri, int quarry) {
    int flag = 0;
    findTreasure(tri->root, quarry, &flag);
    if (!flag)
        cout << quarry << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;
}

int main() {
    BST tri;
    init(&tri);
    int n, t, i;

    cin >> n;
    for (i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(&tri, x);
    }
    cin >> t;
    checkPath(&tri, t);

    return 0;
}
