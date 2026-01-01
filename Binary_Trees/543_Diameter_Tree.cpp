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

class Solution {
    int diameter = 0;
    int MaxDepth(TreeNode* root){
        if(!root) return 0;
        int lefty = MaxDepth(root->left);
        int righty = MaxDepth(root->right);
        diameter = max(diameter,lefty+righty);
        return 1 + max(lefty,righty);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        MaxDepth(root);
        return diameter;
    }
};

int main(){
    vector<optional<int>> arr = {
        4, -7, -3, nullopt, nullopt, -9, -3, 9, -7, -4,
        nullopt, 6, nullopt, -6, -6, nullopt, nullopt,
        0, 6, 5, nullopt, 9, nullopt, nullopt, -1,
        -4, nullopt, nullopt, nullopt, -2
    };
    TreeNode* root = buildTree(arr);
    Solution s;
    cout<<s.diameterOfBinaryTree(root)<<endl;
    return 0;
}
