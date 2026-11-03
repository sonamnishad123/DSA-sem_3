#include<iostream>
using namespace std;
struct node{
    char data;
    struct node *left;
    struct node *right;
};
node *MakeNode(char x){
    node *p;
    p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void PreOrder(node *Root){
    if(Root!=NULL){
        cout<<Root->data<<" ";
        PreOrder(Root->left);
        PreOrder(Root->right);
    }
}
void InOrder(node *Root){
    if(Root!=NULL){
        InOrder(Root->left);
        cout<<Root->data<<" ";
        InOrder(Root->right);
    }
}
void PostOrder(node *Root){
    if(Root!=NULL){
        PostOrder(Root->left);
        PostOrder(Root->right);
        cout<<Root->data<<" ";
    }
}

int CountN2(node *Root){
    if(Root==NULL){
        return 0;
    }
    if(Root->left==NULL && Root->right==NULL){
        return 0;
    }
    if(Root->left!=NULL && Root->right!=NULL){
        return 1 + CountN2(Root->left) + CountN2(Root->right);
    }
    return CountN2(Root->left) + CountN2(Root->right);
}

int  main(){
    node *root=NULL;
    root=MakeNode('A');
    root->left=MakeNode('B');
    root->right=MakeNode('C');
    root->left->left=MakeNode('F');
    root->right->left=MakeNode('D');
    int r =CountN2(root);
    cout<<r;
}