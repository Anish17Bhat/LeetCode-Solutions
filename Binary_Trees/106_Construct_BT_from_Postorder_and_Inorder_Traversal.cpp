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
    unordered_map<int,int>mp;
    int index;
    TreeNode* helper(vector<int>&postorder, int start, int end){
        if(start > end) return nullptr;
        int value = postorder[index--];
        TreeNode* root = new TreeNode(value);
        int mid = mp[value];

        root->right = helper(postorder,mid+1,end);
        root->left = helper(postorder,start,mid-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        index = n - 1;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
        return helper(postorder,0,n-1);
    }
};

int main(){
    Solution s;
    vector<int>postorder = {9,3,15,20,7};
    vector<int>inorder = {9,15,7,20,3};
    TreeNode* root = s.buildTree(postorder,inorder);
    bfs(root);
    cout<<endl;
    return 0;
}
