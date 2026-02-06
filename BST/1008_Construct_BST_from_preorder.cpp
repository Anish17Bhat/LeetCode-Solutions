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


class Solution {
    TreeNode* helper(int bound, int &i, vector<int>&preorder){
        if(i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(root->val,i,preorder);
        root->right = helper(bound,i,preorder);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(INT_MAX,i,preorder);
    }
};

void levelOrder(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* e = q.front();
        cout<<e->val<<" ";
        q.pop();
        if(e->left) q.push(e->left);
        if(e->right) q.push(e->right);
    }
}

int main(){
    vector<int> preorder = {10,9,6,7,8,7,5,12,11,13};
    Solution s;
    TreeNode* root = s.bstFromPreorder(preorder);
    levelOrder(root);
    cout<<endl;
    return 0;
}
