#include <bits/stdc++.h>
#define MAX 55

using namespace std;

int maxStage = 0;

int max(int a, int b) { return (a > b) ? a : b; }

typedef struct AVLNode_t
{
    int key;
    int height;
    int strength;
    struct AVLNode_t *left, *right;
} AVLNode;

typedef struct avl_t
{
    int size;
    AVLNode *root;
} Avl;

AVLNode *createNode(int value, int str)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->key = value;
    newNode->height = 1;
    newNode->strength = str;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

AVLNode *rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
    newParrent->height = max(getHeight(newParrent->left), getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
    newParrent->height = max(getHeight(newParrent->left), getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *leftCaseRotate(AVLNode *node)
{
    return rightRotate(node);
}

AVLNode *rightCaseRotate(AVLNode *node)
{
    return leftRotate(node);
}

AVLNode *leftRightCaseRotate(AVLNode *node)
{
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

AVLNode *rightLeftCaseRotate(AVLNode *node)
{
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

int getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode *insert(AVLNode *node, int value, int str)
{
    if (node == NULL)
        return createNode(value, str);
    if (value < node->key)
        node->left = insert(node->left, value, str);
    else if (value > node->key)
        node->right = insert(node->right, value, str);

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->key)
        return leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->key)
        return leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->key)
        return rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->key)
        return rightLeftCaseRotate(node);

    return node;
}

AVLNode *search(AVLNode *root, int value)
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

void avl_init(Avl *avl)
{
    avl->size = 0;
    avl->root = NULL;
}

bool avl_fidx(Avl *avl, int value)
{
    AVLNode *temp = search(avl->root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void avl_insert(Avl *avl, int value, int str)
{
    if (!avl_fidx(avl, value))
    {
        avl->root = insert(avl->root, value, str);
        avl->size++;
    }
}

void avl_maxStage(AVLNode *root)
{
    if (root)
    {
        avl_maxStage(root->right);
        maxStage++;
    }
}

void getKey(AVLNode *root, int idx, int key[MAX][MAX], int strength[MAX][MAX], int sum[MAX], int last[MAX])
{
    if (root)
    {
        getKey(root->left, idx, key, strength, sum, last);
        key[idx][last[idx]] = root->key;
        strength[idx][last[idx]] = root->strength;
        sum[idx] += root->strength;
        last[idx]++;
        getKey(root->right, idx + 1, key, strength, sum, last);
    }
}

bool elim(AVLNode *root, int *stage, char *z, int s)
{
    int key[MAX][MAX], strength[MAX][MAX], sum[MAX], last[MAX];
    memset(last, 0, sizeof(last));
    memset(sum, 0, sizeof(sum));
    getKey(root, 1, key, strength, sum, last);

    for (int i = 1; i <= maxStage; i++)
    {
        if (i == maxStage)
        {
            cout << "Final Stage:\n";
            for (int j = 0; j < last[i]; j++)
                cout << "Boss " << z << "_" << key[i][j] << ": " << strength[i][j] << "\n";
        }
        else
        {
            cout << "Stage " << i << ":\n";
            for (int j = 0; j < last[i]; j++)
            {
                char a = 'A';
                printf("Monster %c%d_%d_%d: %d\n", a + j, key[i][j], i, j + 1, strength[i][j]);
            }
            cout << "=>\n";
        }
        if (i & 1)
            sum[i] *= 0.9;
        else
            sum[i] *= 0.8;
        s -= sum[i];
        if (s > 0)
            (*stage)++;
    }
    if (s > 0)
        return true;
    else
        return false;
}

int main()
{
    Avl avltri;
    avl_init(&avltri);

    int n, s, a, dmg, stage = 1;
    char z[10];
    cin >> n >> s >> z;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> dmg;
        avl_insert(&avltri, a, dmg);
    }
    avl_maxStage(avltri.root);
    cout << "Ultraman lapet(Power: " << s << ")\nPlanet: " << z << "\n-----------------------\n";
    if (elim(avltri.root, &stage, z, s))
        cout << "\nResult:\nUltraman Lapet lolos dari Planet " << z;
    else
    {
        if (stage == maxStage)
            cout << "\nResult:\nUltraman Lapet terperangkap di Planet " << z << " pada Final Stage";
        else
            cout << "\nResult:\nUltraman Lapet terperangkap di Planet " << z << " pada Stage " << stage;
    }
    return 0;
}