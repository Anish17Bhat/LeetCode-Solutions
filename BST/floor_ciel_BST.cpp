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
    int Floor = -1;
    int Ceil = -1;
    int findfloor(TreeNode* root, int key){
        if(root == nullptr) return Floor;
        if(root->val == key) return key;
        else if(root->val < key){
            Floor = max(Floor,root->val);
            return findfloor(root->right,key);
        } 
        return findfloor(root->left,key);
    }	
    int findceil(TreeNode* root, int key){
        if(root == nullptr) return Ceil;
        if(root->val == key) return key;
        else if(root->val > key){
            if(Ceil == -1) Ceil = root->val;
            else Ceil = min(Ceil,root->val);
            return findceil(root->left,key);
        } 
        return findceil(root->right,key);
    }	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
            return {findfloor(root,key),findceil(root,key)};
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
    vector<optional<int>>arr = {8, 4, 12, 2, 6, 10, 14};
    TreeNode* root = buildTree(arr);
    vector<int>res = s.floorCeilOfBST(root,11);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
