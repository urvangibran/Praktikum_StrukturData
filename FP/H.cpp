#include <iostream>
#include <vector>
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
    int _size;
} BST;

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

vector<int> v;
void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        v.push_back(root->key);
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

void findHeight(BSTNode *root, int value, int *height, int *flag)
{
    if (root)
    {
        // cout << root->key << " ";
        if (root->key == value)
        {
            *flag = 1;
            return;
        }
        else if (root->key < value)
        {
            // cout << "bla";
            *height += 1;
            findHeight(root->right, value, height, flag);
        }
        else if (root->key > value)
        {
            // cout << "bla";
            *height += 1;
            findHeight(root->left, value, height, flag);
        }
    }
}

void findPath(BSTNode *root, int value)
{
    if (root->key == value)
    {
        cout << "S";
    }
    if (root->key < value)
    {
        cout << "R";
        findPath(root->right, value);
    }
    else if (root->key > value)
    {
        cout << "L";
        findPath(root->left, value);
    }
}

int main()
{
    BST tri;
    bst_init(&tri);

    int num;
    while (1)
    {
        string opt;
        cin >> opt;
        if (opt == "IN")
        {
            cin >> num;
            bst_insert(&tri, num);
        }
        else if (opt == "FD")
        {
            int height = 1, flag = 0;
            cin >> num;
            findHeight(tri._root, num, &height, &flag);
            if (flag)
                cout << "on level " << height << endl;
            else
                cout << "no " << num << endl;
        }
        else if (opt == "RK")
        {
            bst_inorder(&tri);
            cin >> num;
            int len = tri._size;
            if (num <= len)
                cout << v[num - 1] << endl;
            else
                cout << "-1" << endl;
        }
        else if (opt == "PH")
        {
            cin >> num;
            if (bst_find(&tri, num))
            {
                findPath(tri._root, num);
                cout << "\n";
            }
            else
                cout << "no " << num << endl;
        }
        else if (opt == "STOP")
        {
            cout << "done" << endl;
            return 0;
        }
    }
}