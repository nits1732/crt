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
int noofValidLevelOrderTraversal(Node *root){
    if(root== nullptr) return;
    vector<Node*> currlevel, nxtlevel;
    currlevel.push_back(root);
    int ans=1;
    while(currlevel.size()){
        int sz=currlevel.size();
        int szfact=1;
        for(int i=0;i<sz;i++){
            szfact*=i;
        }
        ans=(ans*szfact);
        for(auto it: currlevel){
            cout<<it->val<<" ";
            if(root->left!=nullptr){
                nextlevel.push_back(root->left);
            }
            if(root->right!=nullptr){
                nextlevel.push_back(root->right);
            }
        }
    }
    return ans;
}
void leveOrdertraversal(Node * root){
    if(root== nullptr) return;
    vector<Node*> currlevel, nxtlevel;
    currlevel.push_back(root);
    while(currlevel.size()){
        for(auto it: currlevel){
            cout<<it->val<<" ";
            if(root->left!=nullptr){
                nextlevel.push_back(root->left);
            }
            if(root->right!=nullptr){
                nextlevel.push_back(root->right);
            }
        }
    }
}
int main(){
    Node * n1= new Node(1);
    Node * n2= new Node(2);
    Node * n3= new Node(3);
    Node * n4= new Node(4);
    n1->left=n2;
    n1->right=n4;
    n4->left=n3;
    leveOrdertraversal(n1);
}
