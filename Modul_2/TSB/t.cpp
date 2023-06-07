#include <bits/stdc++.h>
using namespace std;

typedef struct bstnode_t
{
    int key, stamina;
    struct bstnode_t
        *left,
        *right, *parent;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *root, int value, int stamina)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->stamina = stamina;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, BSTNode *node, int value, int stamina)
{
    if (node == NULL)
        return __bst__createNode(root, value, stamina);
    root = node;
    if (value < node->key)
        node->left = __bst__insert(root, node->left, value, stamina);

    else if (value > node->key)
        node->right = __bst__insert(root, node->right, value, stamina);

    return node;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

BSTNode *bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void bst_insert(BST *bst, int value, int stamina)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, bst->_root, value, stamina);
        bst->_size++;
    }
}

void cariJarak(BSTNode *root, int tujuan, int *stamina)
{
    if (root->key == tujuan)
        return;
    if (root->key < tujuan)
    {
        *stamina += root->right->stamina + 1;
        if (root->right->key != tujuan)
            cariJarak(root->right, tujuan, stamina);
    }
    else if (root->key > tujuan)
    {
        *stamina += root->left->stamina + 1;
        if (root->left->key != tujuan)
            cariJarak(root->left, tujuan, stamina);
    }
}

vector<int> leaf;

void findLeaf(BSTNode *root)
{
    if (root)
    {
        if (root->right == NULL && root->left == NULL)
        {
            leaf.push_back(root->key);
        }
        findLeaf(root->left);
        findLeaf(root->right);
    }
}

BSTNode *AncBawah(BSTNode *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    BSTNode *left = AncBawah(root->left, a, b);
    BSTNode *right = AncBawah(root->right, a, b);
    if (root->key == a || root->key == b)
        return root;
    if (left != NULL && right != NULL)
        return root;
    if (right)
        return right;
    else
        return left;
}

int main()
{
    BST tri;
    bst_init(&tri);
    int money;
    cin >> money;
    int n, r;
    cin >> n >> r;
    bst_insert(&tri, r, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        bst_insert(&tri, a, b);
    }
    findLeaf(tri._root);
    int tc;
    cin >> tc;
    int res = 1e9;
    for (int i = 0; i < tc; i++)
    {
        int bi;
        cin >> bi;
        for (int j = 0; j < leaf.size(); j++)
        {
            BSTNode *Anc = AncBawah(tri._root, bi, leaf[j]);
            int stamina = 0;
            cariJarak(tri._root, leaf[j], &stamina);
            cariJarak(tri._root, bi, &stamina);
            min(res, stamina);
            cout << "->" << stamina;
        }
    }

    cout << res << endl;
}