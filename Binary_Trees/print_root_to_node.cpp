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

class Solution{
    void helper(TreeNode* root, vector<int>&temp, vector<vector<int>>&ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }
        temp.push_back(root->val);
        helper(root->left,temp,ans);
        helper(root->right,temp,ans);
        temp.pop_back();
    }
	public:
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<int>temp;
            vector<vector<int>>ans;
            helper(root,temp,ans);      
            return ans;   
		}
};

TreeNode* buildTree(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main(){
    Solution s;
    vector<optional<int>>arr = {1, 2, 3, nullopt, 5, nullopt, 4};
    TreeNode* root = buildTree(arr);
    vector<vector<int>>result = s.allRootToLeaf(root);
    for(auto a : result){
        for(int b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
