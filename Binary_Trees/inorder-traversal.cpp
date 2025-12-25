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
    // void helper(TreeNode* root, vector<int>&traversal){
        // if(root == nullptr) return;
        // helper(root->left,traversal);
        // traversal.push_back(root->val);
        // helper(root->right,traversal);
    // }
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>traversal;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(true){
            while(node != nullptr){
                st.push(node);
                node = node->left;
            }
            if(st.empty()) break;
            TreeNode* Root = st.top();
            st.pop();
            traversal.push_back(Root->val);
            node = Root->right;
        }
        return traversal;    
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>result = s.inorderTraversal(root);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
