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
    int mod = 1000000007;
    long long findSum(TreeNode* root, long long sum){
        if(root == nullptr) return sum;
        sum += root->val;
        sum = findSum(root->left,sum);
        sum = findSum(root->right,sum);
        return sum;
    }
    long long helper(TreeNode* root,long long total_sum, long long &maxi) {
        if(root == nullptr) return 0;

        long long l = helper(root->left,total_sum,maxi);
        long long r = helper(root->right,total_sum,maxi);

        long long subtree_sum = root->val + l + r;
        maxi = max(maxi,(total_sum - subtree_sum) * subtree_sum);
        return subtree_sum;
    }
    public:
    long long maxProduct(TreeNode* root) {
        long long total_sum = findSum(root,0);
        long long maxi = 0; 
        helper(root,total_sum,maxi);
        return maxi % mod;
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
        1,nullopt,2,3,4,nullopt,nullopt,5,6
    };
    TreeNode* root = buildTree(arr);
    cout<<s.maxProduct(root)<<endl;
    cout<<endl;
    return 0;
}