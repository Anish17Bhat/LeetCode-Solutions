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
 
 void bfs(TreeNode* root){
    if(root == nullptr) return ;
    cout<<root->val<<" ";
    bfs(root->left);
    bfs(root->right);
 }

class Codec {
    void bfs(TreeNode* root, string &s){
        if(root == nullptr){
            s += "#,";
            return;
        } 
        s += to_string(root->val)+",";
        bfs(root->left,s);
        bfs(root->right,s);
    }

    TreeNode* helper(string &data, int &i){
        if(data[i] == '#'){
            i += 2;
            return nullptr;
        }
        int num = 0;
        int neg = false;
        if(data[i] == '-'){
            neg = true;
            i++;
        }
        while(data[i] != ','){
            num = num * 10 + (data[i]-'0');
            i++;
        }
        i++;
        if(neg) num = -num;
        TreeNode* root = new TreeNode(num);
        root->left = helper(data,i);
        root->right = helper(data,i);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        bfs(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return helper(data,i);
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
    Codec s;
    vector<optional<int>> arr = {1,2,2};
    TreeNode* root = buildTree(arr);
    Codec c;
    string str = c.serialize(root);
    TreeNode* rt = s.deserialize(str);
    bfs(rt);
    cout<<endl;
    return 0;
}
