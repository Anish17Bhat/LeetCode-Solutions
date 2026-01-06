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
    bool helper(TreeNode* root, vector<int>&temp, TreeNode* node){
        if(root == nullptr) return false;
        if(root == node){
            temp.push_back(root->val);
            return true;
        }
        temp.push_back(root->val);
        if(helper(root->left,temp,node) || helper(root->right,temp,node)) return true;
        temp.pop_back();
        return false;
    }
	public:
		vector<int> allRootToLeaf(TreeNode* root, TreeNode* node) {
            vector<int>temp;
            bool b = helper(root,temp,node);       
            return temp;   
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
    vector<optional<int>>arr = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,1,2,4};
    TreeNode* root = buildTree(arr);
    TreeNode* node = root->right->right->left;
    vector<int>result = s.allRootToLeaf(root,node);
    for(auto a : result){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
