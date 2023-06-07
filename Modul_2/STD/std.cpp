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

int stamina = 0;
void cari(BSTNode *root, int value, int tujuan)
{
    if (root)
    {
        if (value == tujuan)
            return;
        if (root->right || root->left)
        {
            if (root->right->key == tujuan)
            {
                stamina += root->stamina + 1;
                cari(root->right, root->right->key, tujuan);
            }
            else if (root->left->key == tujuan)
            {
                stamina += root->stamina + 1;
                cari(root->left, root->left->key, tujuan);
            }
            else
            {
                if (root->right)
                {
                    stamina += root->stamina + 1;
                    cari(root->right, root->right->key, tujuan);
                }
                else
                {
                    stamina += root->stamina + 1;
                    cari(root->left, root->left->key, tujuan);
                }
            }
        }
        else
        {
            stamina += root->stamina + 1;
            cari(root->parent, root->parent->key, tujuan);
        }
    }
}

int main()
{
    BST tri;
    bst_init(&tri);
    int a, b;
    scanf("%d %d", &a, &b);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        bst_insert(&tri, x, y);
    }
    BSTNode *tempA = bst_find(&tri, a);
    BSTNode *tempB = bst_find(&tri, b);

    cari(tempA, tempA->key, tempB->key);

    cout << stamina << endl;

    // for(int i=0; i<n; i++)
    // {
    //     cout << temp->key << " "<< temp->stamina <<  " " << temp->parent->key << " " << temp->parent->stamina << endl;
    //     temp = temp->left;
    // }
}