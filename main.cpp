#include <iostream>
#include <vector>
#include <string>
using namespace std;
TreeNode* createTree();
class TreeNode{
    int val;
public:
    TreeNode* left;
    TreeNode* right;
};

int deepOrder(TreeNode* root){
    if (root == nullptr) {
        return 0;
    }
    return max(deepOrder(root->left), deepOrder(root->right)) + 1;
}


int main(){
    TreeNode* root = createTree();
    cout << deepOrder(root) << endl;
}