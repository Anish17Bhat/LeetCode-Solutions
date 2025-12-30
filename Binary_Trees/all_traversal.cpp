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
        vector<vector<int>>findTraversal(TreeNode* root){
            stack<TreeNode*>st;
            TreeNode* node = root;
            vector<vector<int>>result;
            vector<int>preorder;
            vector<int>inorder;
            vector<int>postorder;
            while(!st.empty() || node != nullptr){
                if(node != nullptr){
                    st.push(node);
                    preorder.push_back(node->val);
                    node = node->left;
                }
                else{
                    inorder.push_back(st.top()->val);
                    TreeNode* temp = st.top()->right;
                    if(temp == nullptr){
                        while(!st.empty() && st.top()->right == temp){
                            temp = st.top();
                            st.pop();
                            postorder.push_back(temp->val);
                        }
                    }
                    else{
                        node = temp;
                    }
                }
            }
            result = {preorder,inorder,postorder};
            return result;
        }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<vector<int>>ans = s.findTraversal(root);
    for(int i = 0 ; i < ans.size() ; i++){
        if(i == 0) cout<<"Pre-order: "; else if(i == 1) cout<<"In-order: "; else cout<<"Post-order: ";
        for(int ele : ans[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    } 
    return 0;
}
