#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
node *MakeNode(int x){
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

 void CreateTree(node *T){
    int choice;
    cout<<"Whether the left of"<<T->data<< "exists?(1/0) ";
    cin>>choice;
    if(choice == 1){
        int x;
        cout<<"enter the data of left node ";
        cin>>x;
        node *p=MakeNode(x);
        T->left=p;
        CreateTree(p);
    }
    cout<<"Whether the right of "<<T->data<< "exists?(1/0) ";
    cin >> choice;
    if(choice == 1){
        int x;
        cout << "Enter the data of right node: ";
        cin >> x;
        node *p = MakeNode(x);
        T->right = p;
        CreateTree(p);
    }
}

int SumNodes(node *T) {
    if(T == NULL) return 0;
    return T->data + SumNodes(T->left) + SumNodes(T->right);
}

int  main(){
    int x;
    cout<<"enter data of root nodes: ";
    cin>>x;
    node *root=NULL;
    root=MakeNode(x);
    CreateTree(root);

    cout<<"preorder: ";
    PreOrder(root);
    cout<<"\n\nInorder Traversal: ";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    PostOrder(root);

    cout << "\n\nSum of all nodes: " << SumNodes(root) << endl;

}