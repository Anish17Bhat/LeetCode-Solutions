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
    public:
        vector<int> inorderTraversal(TreeNode* root){
            vector<int>inorder;
            TreeNode* cur = root;
            while(cur != nullptr){
                if(cur->left == nullptr){
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    TreeNode* leftyRight = cur->left;
                    while(leftyRight->right && leftyRight->right != cur){
                        leftyRight = leftyRight->right;
                    }
                    if(leftyRight->right == nullptr){
                        leftyRight->right = cur;
                        cur = cur->left;
                    }
                    else{
                        leftyRight->right = nullptr;
                        inorder.push_back(cur->val);
                        cur = cur->right;
                    }
                }
            }
            return inorder;
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
    vector<optional<int>> arr = {
        1,2,3,4,5,nullopt,nullopt,nullopt,nullopt,nullopt,6
    };
    TreeNode* root = buildTree(arr);
    vector<int>inorder = s.inorderTraversal(root);
    for(int ele : inorder){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}