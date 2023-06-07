#include <bits/stdc++.h>
#include <set>

using namespace std;

vector<int> leaf;
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

int idx = 0, num[1001];
void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        num[idx++] = root->key;
        // printf("%d", root->key);
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
        printf("%d,", root->key);
        //    bst_remove(temp_root, root->key);
    }

    if (root->left)
        printfLeaf(root->left);
    if (root->right)
        printfLeaf(root->right);
}


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

int main()
{
    BST tri;
    set<int> arr1;
    int arr[10001] = {0};
    bst_init(&tri);
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int a;
        scanf("%d", &a);
        bst_insert(&tri, a);
        arr[a] = a;
        arr1.insert(a);
    }
    BSTNode *temp = tri._root;
    findLeaf(temp);
    bst_inorder(&tri);
    int Q, guess;
    scanf("%d", &Q);
    while (Q--)
    {
        int c = 0;
        bool flag = 1;
        int j = 0;
        scanf("%d", &guess);
        for (auto i : arr1)
        {
            if (arr[guess - i] > 0)
            {
                flag = 0;
                cout << "Aceng mengambil: " << i << " " << arr[guess - i] << endl;
                for (int x = 0; x < leaf.size() && c < 2; x++)
                {
                    if (leaf[x] == i || leaf[x] == arr[guess - i])
                    {
                        leaf.erase(leaf.begin() + x);
                        c++;
                    }
                }
                arr1.erase(arr[guess - i]);
                arr1.erase(i);
                arr[guess - i] = 0;
                break;
            }
        }
        if (flag)
        {
            printf("[");
            for (int i = 0; i < leaf.size(); i++)
            {
                cout << leaf[i];
                if (i != leaf.size() - 1)
                    cout << ",";
            }
            printf("]\n");
        }
    }

    // while(!leaf.empty())
    // {
    //     cout << leaf.back() << endl;
    //     leaf.pop_back();
    // }
    return 0;
}