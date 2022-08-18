#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void checkSame(TreeNode* A, TreeNode* B, bool &ans){
    if (A == NULL && B == NULL){
        return;
    }
    else if (A == NULL && B != NULL){
        ans *= false;
        return;
    }
    else if (A != NULL && B == NULL){
        ans *= false;
        return;
    }
    checkSame(A->left, B->left, ans);
    if (A->val != B->val){
        ans *= false;
        return;
    }
    checkSame(A->right, B->right, ans);
    return;
}

int isSameTree(TreeNode* A, TreeNode* B) {
    bool ans = true;
    checkSame(A, B, ans);
    return (ans)? 1: 0;
}
