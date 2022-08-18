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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

    Node * insert(Node * root, int data) {
        Insert_to_tree(root, data);
        return root;
    }
    void Insert_to_tree(Node* &root, int x){
        if (root == NULL){
            root = new Node(x);
            return;
        }
        if (root->data < x){
            if (root->right == NULL){
                root->right = new Node(x);
            }
            else {
                Insert_to_tree(root->right, x);
            }
        }
        else if (root->data > x){
            if (root->left == NULL){
                root->left = new Node(x);
            }
            else {
                Insert_to_tree(root->left, x);
            }
        }
    }
};