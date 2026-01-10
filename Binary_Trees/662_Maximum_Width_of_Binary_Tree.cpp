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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int res = 1;
        while(!q.empty()){
            int size = q.size();
            int found = 0;
            int start = -1, end = -1;
            for(int i = 0 ; i < size ; i++){
                auto t = q.front();
                q.pop();
                if(!found && t.first->left){
                    start = 2*(t.second) + 1;
                    found = 1;
                }
                if(!found && t.first->right){
                    start = 2*(t.second) + 2;
                    found = 1;
                }
                if(t.first->left){
                    end = 2 * (t.second) + 1;
                    q.push({t.first->left,end});
                }
                if(t.first->right){
                    end = 2 * t.second + 2;
                    q.push({t.first->right,end});
                }
            }
            res = max(res, end - start + 1);
        }     
        return res;
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
    vector<optional<int>>arr = {9,3,2,5,3,nullopt,9};
    TreeNode* root = buildTree(arr);
    cout<<s.widthOfBinaryTree(root);
    cout<<endl;
    return 0;
}
