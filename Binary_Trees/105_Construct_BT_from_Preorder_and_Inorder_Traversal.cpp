#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 void bfs(TreeNode* root){
    if(root == nullptr) return ;
    cout<<root->val<<" ";
    bfs(root->left);
    bfs(root->right);
 }

 class Solution {
     int ind = 0;
     unordered_map<int,int>mp;
     TreeNode* helper(vector<int>&preorder, int start, int end){
        if(start > end) return nullptr;

        int mid = mp[preorder[ind]];
        TreeNode* root = new TreeNode(preorder[ind++]);

        root->left = helper(preorder,start,mid-1);
        root->right = helper(preorder,mid+1,end);
        return root;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
        return helper(preorder,0,n-1);
    }
};

int main(){
    Solution s;
    vector<int>preorder = {10,9,3,7,6,1,0,8,5,2,4};
    vector<int>inorder = {7,3,9,1,6,0,10,2,5,8,4};
    TreeNode* root = s.buildTree(preorder,inorder);
    bfs(root);
    cout<<endl;
    return 0;
}
