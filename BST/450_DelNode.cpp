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
    TreeNode* Replace(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(key < root->val) root->left = deleteNode(root->left,key);
            else if(key > root->val) root->right = deleteNode(root->right,key);
            else{
                TreeNode* lefty = root->left;
                TreeNode* righty = root->right;
                if(!lefty && !righty){
                    delete root;
                    return nullptr;
                }
                else if(!lefty || !righty){
                    TreeNode* temp;
                    if(lefty){
                        temp = root->left;
                    }
                    else temp = root->right;
                    delete root;
                    return temp;
                }
                else{
                    TreeNode* find = Replace(root->left);
                    root->val = find->val;
                    root->left = deleteNode(root->left,find->val);
                }
            }
        }
        return root;
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
void levelOrder(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* e = q.front();
        cout<<e->val<<" ";
        q.pop();
        if(e->left) q.push(e->left);
        if(e->right) q.push(e->right);
    }
}

int main(){
    Solution s;
    vector<optional<int>>arr = {4,nullopt,7,6,8,5,nullopt,nullopt,9};
    TreeNode* root = buildTree(arr);
    TreeNode* res = s.deleteNode(root,9);
    levelOrder(res);
    cout<<endl;
    return 0;
}
