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
    unordered_map<TreeNode*,pair<TreeNode*,int>>parent_track;

    void setParents(TreeNode* root){
        if(!root) return;
        parent_track[root] = {nullptr,-1};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left){
                    parent_track[ele->left] = {ele,0};
                    q.push(ele->left);
                } 
                if(ele->right){
                    parent_track[ele->right] = {ele,1};
                    q.push(ele->right);
                } 
            }
        }
    }

    TreeNode* findDelNode(TreeNode* root, int key){
        while(root && root->val != key){
            root = root->val < key ? root->right : root->left;
        }
        return root;
    }
    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right) return true;
        return false;
    }

    TreeNode* findGreaterLeft(TreeNode* root){
        if(root == nullptr) return nullptr;
        TreeNode* prev = root;
        while(root){
            prev = root;
            root = root->right;
        }
        return prev;
    }

    TreeNode* findSmallerRight(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* prev = root;
        while(root){
            prev = root;
            root = root->left;
        }
        return prev;
    }

    void delNode(TreeNode* node){
        auto parent = parent_track[node];
        if(parent.second) parent.first->right = nullptr;
        else parent.first->left = nullptr; 
        node->left = nullptr;
        node->right = nullptr;
        delete node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        setParents(root);
        TreeNode* node = findDelNode(root,key);
        if(!node) return root;
        if(isLeaf(node) && root == node) return nullptr;
        if(isLeaf(node)){
            auto parent = parent_track[node];
            if(parent.second) parent.first->right = nullptr;
            else parent.first->left = nullptr; 
            return root;
        }
        TreeNode* lefty = node->left;
        TreeNode* righty = node->right;
        if(lefty && righty || lefty && !righty){
            TreeNode* gre = findGreaterLeft(lefty);
            node->val = gre->val;
            if(lefty == gre){
                node->left = lefty->left;
                delete gre;
            }
            else{
                auto parent = parent_track[gre];
                if(gre->left){
                    if(parent.second) parent.first->right = gre->left;
                    else parent.first->left = gre->left; 
                } 
                if(isLeaf(gre)) delNode(gre);
                else delete gre;
            }
        }
        else if(!lefty && righty){
            TreeNode* sm = findSmallerRight(righty);
            node->val = sm->val;
            if(sm == righty){
                node->right = righty->right;
                delete sm;
            }
            else{
                auto parent = parent_track[sm];
                if(sm->right){
                    if(parent.second) parent.first->right = sm->right;
                    else parent.first->left = sm->right; 
                } 
                if(isLeaf(sm)) delNode(sm);
                else delete sm;
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
    TreeNode* res = s.deleteNode(root,5);
    levelOrder(res);
    cout<<endl;
    return 0;
}
