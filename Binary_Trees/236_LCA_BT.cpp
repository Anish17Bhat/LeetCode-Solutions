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
    bool pathFinder(TreeNode* root, vector<TreeNode*>&temp, TreeNode* p){
        if(root == nullptr) return false;
        if(root == p){
            temp.push_back(root);
            return true;
        }
        temp.push_back(root);
        if(pathFinder(root->left,temp,p) || pathFinder(root->right,temp,p)) return true;
        temp.pop_back();
        return false;
    } 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path2p;
        vector<TreeNode*>path2q;
        pathFinder(root,path2p,p);
        pathFinder(root,path2q,q);
        int n = path2p.size();
        int m = path2q.size();
        int i = 0 ; 
        int j = 0;
        TreeNode* ans;
        while(i < n && j < m){
            if(path2p[i] != path2q[j]) break;
            ans = path2p[i];
            i++;
            j++;
        }
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
    vector<optional<int>>arr = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    TreeNode* root = buildTree(arr);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* ans = s.lowestCommonAncestor(root,p,q);
    cout<<ans->val;
    cout<<endl;
    return 0;
}