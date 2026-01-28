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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* temp = root;
        TreeNode* prev;
        int flag = 0;
        while(temp){
            prev = temp;
            if(temp->val < val){
                temp = temp->right;
                if(!temp) flag = 1;
            }
            else temp = temp->left;
        }
        if(flag) prev->right = new TreeNode(val);
        else prev->left = new TreeNode(val); 
        return root;
    }
};

void levelOrder(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size; i++){
            TreeNode* e = q.front();
            cout<<e->val<<" ";
            q.pop();
            if(e->left) q.push(e->left);
            if(e->right) q.push(e->right);
        }
    }
}

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
    vector<optional<int>>arr = {4,2,7,1,3};
    TreeNode* root = buildTree(arr);
    TreeNode* result = s.insertIntoBST(root,5);
    levelOrder(result);
    cout<<endl;
    cout<<endl;
    return 0;
}