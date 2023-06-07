/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 *
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

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

int idx = 0, num[1001];
void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        if (root->key != 0)
            // num[idx++] = root->key;
        // printf("%d ", root->key);
        __bst__inorder(root->right);
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

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst)
{
    __bst__inorder(bst->_root);
}

void printfLeaf(BSTNode *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        printf("%d", root->key);
        //    bst_remove(temp_root, root->key);
    }

    if (root->left)
        printfLeaf(root->left);
    if (root->right)
        printfLeaf(root->right);
}

int delElem(int arr[], int tot, int elem)
{
    int i, j, found = 0;
    for (i = 0; i < tot; i++)
    {
        if (arr[i] == elem)
        {
            for (j = i; j < (tot - 1); j++)
                arr[j] = arr[j + 1];
            found++;
            i--;
            tot--;
        }
    }
    if (found == 0)
        return 101;
    else if (tot == 0)
        return 102;
    else
        return tot;
}

int main()
{
    BST set;
    bst_init(&set);
    int i, j, tc;
    scanf("%d", &tc);
    for (i = 0; i < tc; i++)
    {
        int a;
        scanf("%d", &a);
        bst_insert(&set, a);
    }
    bst_inorder(&set);
    int Q, guess;
    scanf("%d", &Q);
    while (Q--)
    {
        int flag = 0;
        scanf("%d", &guess);
        for (i = 0; i < tc; i++)
        {
            for (j = i + 1; j < tc; j++)
            {
                if (num[i] + num[j] == guess)
                {
                    printf("Aceng mengambil: %d dan %d\n", num[i], num[j]);
                    delElem(num, tc, num[i]);
                    delElem(num, tc, num[j]);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
        {
            BSTNode *temp = set._root;
            printf("[");
            printfLeaf(temp);
            printf("]\n");
        }
    }
    // for(i=0;i<tc;i++)
    //     printf("%d ", num[i]);
    return 0;
}