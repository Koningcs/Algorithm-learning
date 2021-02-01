#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;



struct BSTree {
    int val;
    BSTree* left;
    BSTree* right;
    BSTree():val(0), left(NULL), right(NULL) {};
    BSTree(int x): val(x), left(NULL), right(NULL) {};
};
void Insert(BSTree* &root, int x) {
    
    if(root == NULL) {
        BSTree* p = new BSTree(x);
        p->left = p->right = NULL;
        root = p;
    }
    else {
        if(x < root->val) Insert(root->left, x);
        else Insert(root->right, x);
    }
}

void Build(BSTree* &root, vector<int> v) {
    int n = v.size();
    for(int i = 0; i < n; i ++) {
        Insert(root, v[i]);
    }

}

void MidOrder(BSTree* root) {
    if(root == NULL) return;
    if(root->left != NULL) MidOrder(root->left);
    cout << root->val << endl;
    if(root->right != NULL) MidOrder(root->right);
}

bool _Delete()

bool Delete(BSTree* &root, int x) {
    int flag = true;
    while(root != NULL) {
        if(root->val == x) {

            if(root->left != NULL && root->right != NULL) {

            } else if(root->left != NULL && root->right == NULL) {
                
            } else if(root->left == NULL && root->right != NULL) {

            } else {
                Delete root;
            }


        } else if(root->val < x) {
            Delete(root->right, x);
        } else if(root->val > x) {
            Delete(root->left, x);
        }
    }
}

int main() {

    vector<int> v;
    int n = 0;
    cin >> n;
    BSTree* tree = NULL; 
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Build(tree, v);
    MidOrder(tree);
    return 0;
}


