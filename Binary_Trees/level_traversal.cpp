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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*>q;
        if(root != nullptr) q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i = 0 ; i < size ; i++){
                TreeNode* ele = q.front();
                if(ele->left != nullptr) q.push(ele->left);
                if(ele->right != nullptr) q.push(ele->right);
                temp.push_back(ele->val);
                q.pop();
            }
            result.push_back(temp);
        }
        return result; 
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<vector<int>>result = s.levelOrder(root);
    for(vector<int> ele1 : result){
        for(int ele2 : ele1){
            cout<<ele2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
