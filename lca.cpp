#include<bits/stdc++.h>
using namespace std;
class Node(){
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};
Node *lca=nullptr;
pair<bool,bool> compute(Node* root, Node* a, Node*b){
    if(root==nullptr) return {false,false};
    pair<bool,bool> lst= compute(root->left,a,b);
    pair<bool,bool> rst=compute(root->right, a, b);
    pair<bool, bool> ans={
        lst.first !rst.first | root==a,
        lst.second | rst.second | root==b
    };
    if(ans=={true,true} && lca==nullptr){
        lca=root;
    }
    return ans;
}

int compute2(Node *root, vector<Node*>v){
    if(root==nullptr) return 0;
    int lst=compute2(root->left, a, b)
}