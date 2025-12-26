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
    //     if(root == nullptr) return;
    //     helper(root->left,traversal);
    //     helper(root->right,traversal);
    //     traversal.push_back(root->val);
    // }
    public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>traversal;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(node != nullptr || !st.empty()){
            while(node != nullptr){
                st.push(node);
                node = node->left;
            }
            TreeNode* temp = st.top()->right;
            if(temp == nullptr){
                temp = st.top();
                traversal.push_back(temp->val);
                st.pop();
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    traversal.push_back(temp->val);
                    st.pop();
                }
            }
            else{
                    node = temp;
            }
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
    vector<int>result = s.postorderTraversal(root);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
