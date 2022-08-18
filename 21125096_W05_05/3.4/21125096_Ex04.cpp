#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthsmallest(TreeNode* A, int B) {
    vector<int> ans;
    int k = B-1;
    Transversal(A, B, ans);
    return ans[k];
}

void Transversal(TreeNode* A, int &k, vector<int> &ans){
    if (A == NULL || k == 0){
        return;
    }
    Transversal(A->left, k, ans);
    ans.push_back(A->val);
    k--;
    Transversal(A->right, k, ans);
}
