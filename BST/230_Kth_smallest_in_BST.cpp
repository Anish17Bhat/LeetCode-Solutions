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
    int count = 0;
    int ans = -101;
    bool helper(TreeNode* root, int k){
        if(root == nullptr) return false;
        if(helper(root->left,k)) return true;
        count++;
        if(count == k){
            ans = root->val;
            return true;
        }
        if(helper(root->right,k)) return true;
        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
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
    vector<optional<int>>arr = {9,7,10,5,8,nullopt,11,4,6};
    TreeNode* root = buildTree(arr);
    cout<<s.kthSmallest(root,8)<<endl;
    return 0;
}
