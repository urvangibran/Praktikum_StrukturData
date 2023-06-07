#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define LL long long
#define ULL unsigned long long
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
LL una = 9223372036854775800; /** * Node structure and * uniqueBST structure */

typedef struct bstnode_t
{
    LL key, Edge, dalan;
    struct bstnode_t \ 
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    LL _size;
} BST;

/** * !!! WARNING UTILITY FUNCTION !!! * Recognized by prefix "bst" * --------------------------------------------- * Note that you better never access these functions, * unless you need to modify or you know how these functions work. */

BSTNode *_bst_createNode(LL value, LL edge)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->Edge = edge;
    newNode->dalan = una;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *_bstinsert(BSTNode *root, LL value, LL edge)
{
    if (root == NULL)
        return __bst_createNode(value, edge);

    if (value < root->key)
        root->left = _bst_insert(root->left, value, edge);
    else if (value > root->key)
        root->right = _bst_insert(root->right, value, edge);

    return root;
}

BSTNode *_bst_search(BSTNode *root, LL value, LL edge)
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

BSTNode *_bst_findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *_bst_remove(BSTNode *root, LL value, LL edge)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = _bst_remove(root->right, value, edge);
    else if (value < root->key)
        root->left = _bst_remove(root->left, value, edge);
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

        BSTNode *temp = _bst_findMinNode(root->right);
        root->key = temp->key;
        root->Edge = temp->Edge;
        root->right = _bst_remove(root->right, temp->key, temp->Edge);
    }
    return root;
}

void _bstinorder(BSTNode *root)
{
    if (root)
    {
        __bstinorder(root->left);
        printf("%lld %lld %lld\n", root->key, root->Edge, root->dalan);
        __bst_inorder(root->right);
    }
}

void _bstpostorder(BSTNode *root)
{
    if (root)
    {
        __bstpostorder(root->left);
        __bst_postorder(root->right);
        printf("%lld %lld\n", root->key, root->Edge);
    }
}

void _bstpreorder(BSTNode *root)
{
    if (root)
    {
        printf("%lld %lld\n", root->key, root->Edge);
        __bstpreorder(root->left);
        __bst_preorder(root->right);
    }
}

/** * PRIMARY FUNCTION * --------------------------- * Accessible and safe to use. */

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) { return bst->_root == NULL; }

bool bst_find(BST *bst, LL value, LL edge)
{
    BSTNode *temp = _bst_search(bst->_root, value, edge);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, LL value, LL edge)
{
    if (!bst_find(bst, value, edge))
    {
        bst->_root = __bst_insert(bst->_root, value, edge);
        bst->_size++;
    }
}

void bst_remove(BST *bst, LL value, LL edge)
{
    if (bst_find(bst, value, edge))
    {
        bst->_root = __bst_remove(bst->_root, value, edge);
        bst->_size--;
    }
}

/** * Binary search tree traversal * - Inorder * - Postorder * - Preorder */

void bst_inorder(BST *bst)
{   
    _bstinorder(bst->_root);
}

void bst_postorder(BST *bst)
{
    _bstpostorder(bst->_root);
}

void bst_preorder(BST *bst)
{
    _bstpreorder(bst->_root);
}

LL min(LL x, LL y)
{
    if (x < y)
        return x;
    return y;
}

LL yerin(BSTNode *root, LL sum)
{
    if (root == NULL)
        return sum;
    if (root != NULL && root->dalan != una)
        return root->dalan;
    else if (root != NULL && root->dalan == una)
    {
        LL yow;
        if (root->left != NULL && root->right != NULL)
        {
            yow = min(yerin(root->left, sum + root->Edge), yerin(root->right, sum + root->Edge));
            root->dalan = yow - sum - root->Edge;
        }
        else if (root->left != NULL)
        {
            yow = yerin(root->left, sum + root->Edge);
            root->dalan = yow - sum - root->Edge;
        }
        else if (root->right != NULL)
        {
            yow = yerin(root->right, sum + root->Edge);
            root->dalan = yow - sum - root->Edge;
        }
        else
        {
            root->dalan = 0;
            return sum + root->Edge;
        }
        return yow;
    }
    else
        return 0;
}

LL yosha(BST *bst, LL value)
{
    BSTNode *temp = bst->_root;
    LL take = 4611686018427387900, care = 4611686018427387900, take1 = 4611686018427387900, care1 = 4611686018427387900, nuani;
    LL take2 = 4611686018427387900, care2 = 4611686018427387900, take3 = 4611686018427387900, care3 = 4611686018427387900;
    while (temp != NULL)
    {
        if (value < temp->key)
        {
            BSTNode *temp1 = temp->left;
            if (temp1->key == value)
            {
                take = temp->dalan;
                care = temp1->Edge;
            }

            BSTNode *temp2 = temp1->left; // kiri kiri
            if (temp2 != NULL)
                if (temp2->key == value)
                {
                    take1 = temp->dalan;
                    care1 = temp2->Edge + temp1->Edge;
                }

            temp2 = temp1->right; // kiri kanan
            if (temp2 != NULL)
                if (temp2->key == value)
                {
                    take2 = temp->dalan;
                    care2 = temp2->Edge + temp1->Edge;
                }
            temp = temp->left;
        }
        else if (value > temp->key)
        { /////////////////////////////////////
            BSTNode *temp1 = temp->right;
            if (temp1->key == value)
            {
                take = temp->dalan;
                care = temp1->Edge;
            }

            BSTNode *temp2 = temp1->left; // kanan kiri
            if (temp2 != NULL)
                if (temp2->key == value)
                {
                    take1 = temp->dalan;
                    care1 = temp2->Edge + temp1->Edge;
                }

            temp2 = temp1->right; // kanan kanan
            if (temp2 != NULL)
                if (temp2->key == value)
                {
                    take2 = temp->dalan;
                    care2 = temp2->Edge + temp1->Edge;
                }
            temp = temp->right;
        }
        else
        {
            nuani = temp->dalan;
            break;
        }
    }
    LL yerinn = min(nuani, take + care);
    yerinn = min(yerinn, take1 + care1);
    yerinn = min(yerinn, take2 + care2);
    return yerinn;
}

int main()
{
    BST set;
    bst_init(&set);
    LL n, m;
    scanf("%lld%lld", &n, &m);
    n--;
    bst_insert(&set, m, 0);
    while (n--)
    {
        LL a, b;
        scanf("%lld%lld", &a, &b);
        bst_insert(&set, a, b);
    }
    BSTNode *temp = set._root;
    LL eunha = yerin(temp, 0);
    bst_inorder(&set);
    // puts("");
    LL num;
    scanf("%lld", &num);
    LL apa = 0;
    while (num--)
    {
        LL yuju;
        scanf("%lld", &yuju);
        LL yey = yosha(&set, yuju);
        if (!apa)
        {
            apa = 1;
            printf("%lld", yey);
        }
        else
        {
            printf(" %lld", yey);
        }
    }
    printf("\n");
    return 0;
}