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
    bool checkChildrenSum(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;

        int lefty = root->left ? root->left->val : 0;
        int righty = root->right ? root->right->val : 0;

        if(lefty + righty != root->val) return false;
        
        bool l = checkChildrenSum(root->left);
        if(!l) return false;

        bool r = checkChildrenSum(root->right);
        if(!r) return false;

        return l && r ;
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
       10,4,6,1,3,2,4
    };
    TreeNode* root = buildTree(arr);
    cout<<s.checkChildrenSum(root)<<endl;
    cout<<endl;
    return 0;
}
