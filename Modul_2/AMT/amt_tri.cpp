#include <bits/stdc++.h>
#include <set>
#include <math.h>

using namespace std;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions,
 * unless you need to modify or you know how these functions work.
 */

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

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
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

int s;
void __bst__inorder(BST *tree, BSTNode *root)
{
    if (root)
    {
        __bst__inorder(tree, root->left);
        s++;
        if (s == tree->_size)
            printf("%d", root->key);
        else
            printf("%d, ", root->key);
        __bst__inorder(tree, root->right);
    }
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

void bst_inorder(BST *bst)
{
    __bst__inorder(bst, bst->_root);
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void cariMinNode(BST *tree, BSTNode *root, int target, int *flag, int *temp)
{
    if (root)
    {
        if ((target - root->key != root->key) && (__bst__search(tree->_root, target - root->key)))
        {
            *flag = 1;
            *temp = min(root->key, *temp);
        }
        cariMinNode(tree, root->left, target, flag, temp);
        cariMinNode(tree, root->right, target, flag, temp);
    }
}

void findLeaf(BSTNode *root, BST *leaf)
{
    if (root)
    {
        if (root->right == NULL && root->left == NULL)
        {
            bst_insert(leaf, root->key);
        }
        findLeaf(root->left, leaf);
        findLeaf(root->right, leaf);
    }
}

int main()
{
    BST tri;
    BST leaf;
    bst_init(&leaf);
    bst_init(&tri);
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int a;
        scanf("%d", &a);
        bst_insert(&tri, a);
    }
    findLeaf(tri._root, &leaf);
    int Q, guess;
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d", &guess);
        int flag = 0;
        int c = 1e9;
        cariMinNode(&tri, tri._root, guess, &flag, &c);

        if (flag)
        {
            printf("Aceng mengambil: %d dan %d\n", c, guess - c);

            bst_remove(&leaf, c);
            bst_remove(&leaf, guess - c);
            bst_remove(&tri, c);
            bst_remove(&tri, guess - c);
        }
        else
        {
            s = 0;
            printf("[");
            bst_inorder(&leaf);
            printf("]\n");
        }
    }
    return 0;
}