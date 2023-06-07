#include <bits/stdc++.h>
using namespace std;

typedef struct bstnode_t
{
    int key, stamina;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(int value, int stamina)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->stamina = stamina;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value, int stamina)
{
    if (root == NULL)
        return __bst__createNode(value, stamina);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, stamina);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, stamina);

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

void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root)
{
    if (root)
    {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}
void __bst__preorder(BSTNode *root)
{
    if (root)
    {
        __bst__preorder(root->left);
        __bst__preorder(root->right);
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

void bst_insert(BST *bst, int value, int stamina)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value, stamina);
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

void bst_postorder(BST *bst)
{
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst)
{
    __bst__preorder(bst->_root);
}

int cnt = 0;
int findRute(BSTNode *root, int pos, int stamina)
{
    if(root)
    {
        cnt++;
        stamina += root->stamina + 1;
        // cout << "root" << root->key << endl;;
        if(pos > root->key)
        {
            return findRute(root->right, pos, stamina);
        }

        else if(pos < root->key)
        {
            return findRute(root->left, pos, stamina);
        }
    }
    return stamina;
}

BSTNode *AncBawah(BSTNode *root, int a, int b)
{
    if(root == NULL)
        return NULL;

    BSTNode *kiri = AncBawah(root->left, a, b);
    BSTNode *kanan = AncBawah(root->right, a, b);
    if (root -> key == a || root->key == b)
        return root;
    if(kiri != NULL && kanan != NULL)
        return root;
    return kanan ? kanan : kiri;
}

int main()  
{
    BST tri;
    bst_init(&tri);
    int a, b;
    scanf("%d %d", &a, &b);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {   
        int x, y;
        scanf("%d %d",&x, &y);
        bst_insert(&tri, x, y);
    }
    int stamina = 0;
    int jarakA = findRute(tri._root, a, stamina);
    int jarakB = findRute(tri._root, b, stamina);
    BSTNode *AncTemp = AncBawah(tri._root, a, b);
    // int Anc = findRute(tri._root, AncTemp->key, stamina);
    cout << AncTemp->key << " " << AncTemp->stamina <<endl;
    // cout << jarakA << endl;
    // cout << jarakB << endl;
    // cout << Anc << endl;
    // cout << AncTemp->stamina << endl;
    // cout << cnt;
    // cout << (jarakA - 1) + (jarakB - 1) - 2 * (Anc - 1) + AncTemp->stamina << endl;
    return 0;
}