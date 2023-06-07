#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    string name;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

class FamilyTree {
    private:
        TreeNode* root;

        TreeNode* findNode(string name) {
            // implementasi algoritma pencarian pada BST
            TreeNode* current = root;
            while (current != NULL && current->name != name) {
                if (name < current->name) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            return current;
        }

        // implementasi algoritma untuk memasukkan node pada BST
        void insertNode(string name) {
            TreeNode* newNode = new TreeNode;
            newNode->name = name;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = NULL;

            if (root == NULL) {
                root = newNode;
                return;
            }

            TreeNode* current = root;
            while (true) {
                if (name < current->name) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        newNode->parent = current;
                        return;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        newNode->parent = current;
                        return;
                    } else {
                        current = current->right;
                    }
                }
            }
        }

    public:
        FamilyTree() {
            root = NULL;
        }

        void buildTree(int N) {
            for (int i = 0; i < N; i++) {
                string name;
                cin >> name;
                insertNode(name);
            }
        }

        void search(int TC) {
            for (int i = 0; i < TC; i++) {
                string cmd, name;
                cin >> cmd >> name;

                TreeNode* node = findNode(name);

                if (cmd == "Ibu") {
                    if (node == root) {
                        cout << "Aku Adalah Pemimpin Keluarga Ini! HAHAHA" << endl;
                    } else {
                        cout << node->parent->name << endl;
                    }
                } else if (cmd == "Anak") {
                    if (node == NULL) {
                        cout << "- -" << endl;
                    } else if (node->left == NULL && node->right == NULL) {
                        cout << "Aku Sedih!! Tidak Memiliki Anak:)" << endl;
                    } else {
                        string leftChild = (node->left == NULL) ? "-" : node->left->name;
                        string rightChild = (node->right == NULL) ? "-" : node->right->name;
                        cout << rightChild << " " << leftChild << endl;
                    }
                }
            }
        }
};

int main() {
    int N, TC;
    cin >> N >> TC;

    FamilyTree familyTree;
    familyTree.buildTree(N);
    familyTree.search(TC);

    return 0;
}