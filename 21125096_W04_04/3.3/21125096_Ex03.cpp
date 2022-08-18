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
    TreeNode* invertTree(TreeNode* root) {
        SolveInvertTree(root);
        return root;
    }
    void SolveInvertTree(TreeNode* root){
        if (root == nullptr){
            return;
        }
        SolveInvertTree(root->left);
        SolveInvertTree(root->right);
        TreeNode* cur = root->left;
        root->left = root->right;
        root->right = cur;
    }
};