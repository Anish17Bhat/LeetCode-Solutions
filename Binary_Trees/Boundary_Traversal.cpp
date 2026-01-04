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

 class Solution{
    bool isLeaf(TreeNode* node){
        if(node->left == nullptr && node->right == nullptr)  return true;
        return false;
    }

    void addLeftBoundary(TreeNode* root, vector<int>&result){
        TreeNode* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) result.push_back(cur->val);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addLeaf(TreeNode* root, vector<int>&result){
        if(isLeaf(root)){
            result.push_back(root->val) ;
            return;
        } 
        if(root->left) addLeaf(root->left,result);
        if(root->right) addLeaf(root->right,result);
    }

    void addRightBoundary(TreeNode* root, vector<int>&result){
        TreeNode* cur = root->right;
        vector<int>temp;
        while(cur){
            if(!isLeaf(cur)) result.push_back(cur->val);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        int n = temp.size();
        for(int i = 0 ; i < n ; i++){
            result.push_back(temp[n-i-1]);
        }
    }


public:
    vector <int> boundary(TreeNode* root){
    	vector<int>result;
        if(!root) return result;
        if(!isLeaf(root)) result.push_back(root->val); 
        addLeftBoundary(root,result);
        addLeaf(root,result);
        addRightBoundary(root,result);
        return result;
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
    vector<optional<int>> arr = {
        1, 2, nullopt, 4, 9, 6, 5, 3, nullopt, nullopt, nullopt, nullopt, nullopt, 7, 8
    };
    TreeNode* root =  buildTree(arr);
    Solution s;
    vector<int>res = s.boundary(root);
    for(int ele : res){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
