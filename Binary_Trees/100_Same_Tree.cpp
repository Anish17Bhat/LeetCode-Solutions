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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr && q != nullptr || p != nullptr && q == nullptr) return false;
        bool lefty = isSameTree(p->left,q->left);
        if(!lefty) return false;
        bool righty = isSameTree(p->right,q->right);
        if(!righty) return false;

        if(p->val == q->val) return true;
        else return false;
    }
};

int main(){
    Solution s;
    TreeNode *p = new TreeNode(1);
    p->left = nullptr;
    p->right = new TreeNode(2);
    p->right->left = new TreeNode(3);  

    TreeNode *q = new TreeNode(1);
    q->left = nullptr;
    q->right = new TreeNode(2);
    q->right->left = new TreeNode(3);  

    cout<<s.isSameTree(p,q)<<endl;
    return 0;
}
