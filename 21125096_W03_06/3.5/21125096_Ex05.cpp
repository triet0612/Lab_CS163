#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    void levelOrder(Node * root) {
        int max_level = maxLvL(root);
        for (int i = 1; i <= max_level; i++){
            PrintLvlOrd(root, i);
        }
    }

    int maxLvL(Node* root){
        if (root == NULL){
            return 0;
        }
        int max_left = maxLvL(root->left);
        int max_right = maxLvL(root->right);
        return max(max_left, max_right) + 1;
    }

    void PrintLvlOrd(Node * root, int level){
        if (root == NULL){
            return;
        }
        if (level == 1){
            cout << root->data << " ";
        }
        else if (level > 1){
            PrintLvlOrd(root->left, level - 1);
            PrintLvlOrd(root->right, level - 1);
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
