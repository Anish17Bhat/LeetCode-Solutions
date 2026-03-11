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
        vector<int> postorderTraversal(TreeNode* root){
            vector<int>postorder;
            TreeNode* cur = root;
            while(cur != nullptr){
                if(cur->right == nullptr){
                    postorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    TreeNode* rightyLeft = cur->right;
                    while(rightyLeft->left && rightyLeft->left != cur){
                        rightyLeft = rightyLeft->left;
                    }
                    if(rightyLeft->left == nullptr){
                        rightyLeft->left = cur;
                        postorder.push_back(cur->val);
                        cur = cur->right;
                    }
                    else{
                        rightyLeft->left = nullptr;
                        cur = cur->left;
                    }
                }
            }
            reverse(postorder.begin(),postorder.end());
            return postorder;
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
    vector<int>postorder = s.postorderTraversal(root);
    for(int ele : postorder){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}