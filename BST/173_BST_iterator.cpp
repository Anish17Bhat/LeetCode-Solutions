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

class BSTIterator {
    stack<TreeNode*>st;
    void SimulateRecur(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        SimulateRecur(root);
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();
        SimulateRecur(top->right);
        return top->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
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

int main(){
    vector<optional<int>> arr = {7, 3, 15, nullopt, nullopt, 9, 20};
    TreeNode* root = buildTree(arr);
    BSTIterator b(root);
    cout<<b.next()<<" "<<b.next()<<" "<<b.hasNext()<<" "<<b.next()<<" "<<b.hasNext()<<" "<<b.next()<<" "<<b.hasNext()<<" "<<b.next()<<" "<<b.hasNext()<<endl;
    return 0;
}
