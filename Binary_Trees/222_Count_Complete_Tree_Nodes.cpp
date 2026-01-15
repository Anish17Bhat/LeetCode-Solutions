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
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* lefty = root;
        TreeNode* righty = root;
        int l = 0, r = 0;
        while(lefty) {l++; lefty = lefty->left;}
        while(righty) {r++; righty = righty->right;}

        if(l == r) return (1 << l) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
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
    vector<optional<int>>arr = {1,2,3,4,5,6};
    TreeNode* root = buildTree(arr);
    cout<<s.countNodes(root);
    cout<<endl;
    return 0;
}
