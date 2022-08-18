#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        solveSymetric(root, root, ans);
        return ans;
    }
    void solveSymetric(TreeNode* root_L, TreeNode* root_R, bool &ans){
        if (!root_L && !root_R){
            ans *= true;
            return;
        }
        else if ((!root_R && root_L) || (root_R && !root_L)){
            ans *= false;
            return;
        }
        solveSymetric(root_L->left, root_R->right, ans);
        if (root_L->val != root_R->val){
            ans *= false;
            return;
        }
        solveSymetric(root_L->right, root_R->left, ans);
    }
};