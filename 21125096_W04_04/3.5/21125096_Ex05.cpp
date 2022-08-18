#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void InsertBST(Node* &root, int x);

void Transversal(Node* root, Node* &cur, double &MAX);

double minBST(Node* root);

double maxBST(Node* root);

int main(){
    int n, l;
    cin >> n >> l;
    Node* root = NULL;
    int temp;
    cin >> temp;
    root = new Node{temp, NULL, NULL};
    for (int i = 1; i < n; i++){
        cin >> temp;
        InsertBST(root, temp);
    }
    double MAX = 0;
    Node* cur = root;
    Transversal(root, cur, MAX);
    MAX = MAX/2;
    double maxx = maxBST(root);
    double minn = minBST(root);
    MAX = max(l - maxx, MAX);
    MAX = max(minn, MAX);
    cout << fixed << setprecision(9) << MAX;
    return 0;
}

void InsertBST(Node* &root, int x){
    if (root == NULL){
        root = new Node{x, NULL, NULL};
        return;
    }
    if (root->data > x){
        InsertBST(root->left, x);
    }
    else {
        InsertBST(root->right, x);
    }
}

void Transversal(Node* root, Node* &cur, double &MAX){
    if (root == NULL){
        return;
    }
    Transversal(root->left, cur, MAX);
    if (cur != NULL){
        MAX = max(double(root->data - cur->data), MAX);
    }
    cur = root;
    Transversal(root->right, cur, MAX);
}

double minBST(Node* root){
    while (root->left != NULL){
        root = root->left;
    }
    return root->data;
}

double maxBST(Node* root){
    while (root->right != NULL){
        root = root->right;
    }
    return root->data;
}
