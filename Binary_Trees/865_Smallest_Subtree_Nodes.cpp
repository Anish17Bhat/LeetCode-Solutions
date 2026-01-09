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
    vector<TreeNode*> bfs(TreeNode* root){
        vector<TreeNode*>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans.clear();
            for(int i = 0 ; i < size ; i++){
                ans.push_back(q.front());
                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }

    TreeNode* lca(TreeNode* root, vector<TreeNode*>&deepestNodes){
        if(!root || (find(deepestNodes.begin(),deepestNodes.end(),root) != deepestNodes.end())){
            return root;
        }
        TreeNode* l = lca(root->left,deepestNodes);
        TreeNode* r = lca(root->right,deepestNodes);

        if(l && r) return root;

        return l ? l : r; 
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*>deepestNodes = bfs(root);
        return lca(root,deepestNodes);
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
    vector<optional<int>>arr = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    TreeNode* root = buildTree(arr);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;
    TreeNode* ans = s.subtreeWithAllDeepest(root);
    cout<<ans->val;
    cout<<endl;
    return 0;
}
