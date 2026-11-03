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
int Height(node *Root){
    if(Root == NULL){
        return 0;
    }
    if(Root->left==NULL && Root->right==NULL){
        return 0;
    }
    int LH=Height(Root->left);
    int RH=Height(Root->right);
    return 1 + max(LH,RH);
}

int  main(){
    node *root=NULL;
    root=MakeNode('A');
    root->left=MakeNode('B');
    root->right=MakeNode('C');
    root->left->left=MakeNode('F');
    root->right->left=MakeNode('D');
    int r=Height(root);
    cout<<r;

}