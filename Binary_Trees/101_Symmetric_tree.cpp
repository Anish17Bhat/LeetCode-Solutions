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
    bool helper(TreeNode* lefty, TreeNode* righty){
        if(lefty && !righty || righty && !lefty) return false;
        else if(lefty && righty){
            if(lefty->val != righty->val) return false;
        }
        else if(lefty == righty) return true;
        bool l = helper(lefty->left,righty->right);
        if(!l) return false;
        bool r = helper(lefty->right,righty->left);
        if(!r) return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
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
    vector<optional<int>> arr = {
        1,2,2,nullopt,3,nullopt,3
    };
    TreeNode* root = buildTree(arr);
    cout<<s.isSymmetric(root)<<endl;
    cout<<endl;
    return 0;
}
