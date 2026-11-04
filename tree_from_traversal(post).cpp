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
    unordered_map<int,int> m;
    int k;

    TreeNode* build(vector<int>& inorder,vector<int>& post,int l,int r)
    {
        if(l > r)
            return NULL;

        TreeNode* root = new TreeNode(post[k]);

        int idx = m[post[k]];
        k--;

        root->right = build(inorder, post,idx + 1, r);

        root->left = build(inorder, post,l, idx - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
    {
        m[inorder[i]] = i;
    }

    k = postorder.size() - 1;

    return build(inorder,postorder,0,inorder.size()-1);
    }
};
int main(){
    vector<int> postorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    Solution sol;
    TreeNode *root =sol.buildTree(inorder,postorder);
    cout<<"Root: "<<root->val<<endl;
    cout<<"Left child: "<<root->left->val<<endl;
    cout<<"Right Child: "<<root->right->val<<endl;
}