#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};
class Solution {
public:
    unordered_map<int,int>m;
    int k=0;
    TreeNode* TreeCons(vector<int>& pre, vector<int>& in,int l, int r){
        if(l > r)
            return NULL;
        TreeNode* root = new TreeNode(pre[k]);
        int idx = m[pre[k]];
        k++;

        root->left = TreeCons(pre, in, l, idx-1);
        root->right = TreeCons(pre, in, idx+1, r);

        return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }

        k = 0;

        return TreeCons(preorder,inorder,0,inorder.size()-1);
        
    }
};
int main(){
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    Solution sol;
    TreeNode *root =sol.buildTree(preorder,inorder);
    cout<<"Root: "<<root->val<<endl;
    cout<<"Left child: "<<root->left->val<<endl;
    cout<<"Right Child: "<<root->right->val<<endl;
}