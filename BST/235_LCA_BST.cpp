#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else return root;
    }
};

TreeNode *buildTree(const vector<optional<int>> &arr)
{
    if (arr.empty() || !arr[0].has_value())
        return nullptr;

    TreeNode *root = new TreeNode(arr[0].value());
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value())
        {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i].has_value())
        {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main()
{
    Solution s;
    vector<optional<int>> arr = {6,2,8,0,4,7,9,nullopt,nullopt,3,5};
    TreeNode *root = buildTree(arr);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    cout<<s.lowestCommonAncestor(root,p,q)->val<<endl;
    return 0;
}

