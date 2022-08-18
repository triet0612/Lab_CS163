#include<bits/stdc++.h>

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

        struct Pair_Node{
            Node* node = NULL;
            int height = 500;
        };

        void topView(Node * root) {
            Pair_Node Node_coor[500] = {};
            Pair_Node nNode_coor[500] = {};
            int coor = 0;
            int height = 0;
            Label_coor(root, Node_coor, nNode_coor, coor, height);
            for (int i = 499; i >= 0; i--){
                if (nNode_coor[i].node != NULL){
                    cout << nNode_coor[i].node->data << " ";
                }
            }
            for (int i = 0; i < 500; i++){
                if (Node_coor[i].node != NULL){
                    cout << Node_coor[i].node->data << " ";
                }
            }
        }

        void Label_coor(Node* root, Pair_Node Node_coor[], Pair_Node nNode_coor[], int coor, int height){
            if (root == NULL){
                return;
            }
            Label_coor(root->left, Node_coor, nNode_coor, coor-1, height+1);
            if (coor < 0){
                if (nNode_coor[-coor].height > height){
                    nNode_coor[-coor].node = root;
                    nNode_coor[-coor].height = height;    
                }
            }
            else {
                if (Node_coor[coor].height > height){
                    Node_coor[coor].node = root;
                    Node_coor[coor].height = height;    
                }             
            }
            Label_coor(root->right, Node_coor, nNode_coor, coor+1, height+1);
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
  
	myTree.topView(root);
    return 0;
}
