#include <iostream>
#include <vector>
using namespace std;

struct BSTNode
{
    int key;
    BSTNode *left;
    BSTNode *right;
};

struct BST
{
    BSTNode *_root;
    int _size;
};

BSTNode *bst_createNode(int value)
{
    BSTNode *newNode = new BSTNode();
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *bst_insert(BSTNode *root, int value)
{
    if (root == NULL)
        return bst_createNode(value);

    if (value < root->key)
        root->left = bst_insert(root->left, value);
    else if (value > root->key)
        root->right = bst_insert(root->right, value);

    return root;
}

BSTNode *bst_search(BSTNode *root, int value)
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

BSTNode *bst_findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *bst_remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = bst_remove(root->right, value);
    else if (value < root->key)
        root->left = bst_remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            delete root;
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            delete root;
            return leftChild;
        }

        BSTNode *temp = bst_findMinNode(root->right);
        root->key = temp->key;
        root->right = bst_remove(root->right, temp->key);
    }
    return root;
}

vector<int> v;
void bst_inorder(BSTNode *root)
{
    if (root)
    {
        bst_inorder(root->left);
        v.push_back(root->key);
        bst_inorder(root->right);
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
    BSTNode *temp = bst_search(bst->_root, value);
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
        bst->_root = bst_insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = bst_remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst)
{
    v.clear();
    bst_inorder(bst->_root);
}

void findHeight(BSTNode *root, int value, int *height, int *flag)
{
    if (root)
    {
        if (root->key == value)
        {
            *flag = 1;
            return;
        }
        else if (root->key < value)
        {
            *height += 1;
            findHeight(root->right, value, height, flag);
        }
        else if (root->key > value)
        {
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
    while (true)
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
                cout << endl;
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
