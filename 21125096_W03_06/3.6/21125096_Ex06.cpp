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
    bool isUnivalTree(TreeNode* root) {
        int cur = root->val;
        bool ans = true;
        solveUnival(root, cur, ans);
        return ans;
    }
    void solveUnival(TreeNode* root, int cur, bool &ans){
        if (root == nullptr){
            return;
        }
        if (cur != root->val){
            ans = false;
            return;
        }
        solveUnival(root->left, root->val, ans);
        solveUnival(root->right, root->val, ans);
    }
};