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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int maxi = INT_MIN;
        int level = 1;
        int ans = level;
        q.push(root);     
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0 ; i < size ; i++){
                sum += q.front()->val;
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }
            if(sum > maxi){
                maxi = sum;
                ans = level;
            }
            level++;
        }
        return ans;
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
        989,nullopt,10250,98693,-89388,nullopt,nullopt,nullopt,-32127
    };
    TreeNode* root = buildTree(arr);
    cout<<s.maxLevelSum(root)<<endl;
    return 0;
}
