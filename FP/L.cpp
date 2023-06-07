#include <bits/stdc++.h>
using namespace std;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
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

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void printRes(BSTNode *root)
{
    if (root)
    {
        queue<BSTNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                BSTNode *temp = q.front();
                q.pop();

                if (i == len - 1)
                    cout << temp->key << endl;

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
}

int main()
{
    BST tri;
    bst_init(&tri);
    int n;
    while (cin >> n)
    {
        bst_insert(&tri, n);
    }
    printRes(tri._root);

    return 0;
}
