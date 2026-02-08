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
    void findFloor(TreeNode* root, int key, int &predecessor){
        while(root){
            if(root->val < key){
                predecessor = root->val;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
    void findCiel(TreeNode* root, int key, int &successor){
        while(root){
            if(root->val > key){
                successor = root->val;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
    }
	public:
		vector<int> succPredBST(TreeNode* root,int key){
            int predecessor = -1;
            int successor = -1;
            findFloor(root,key,predecessor);
            findCiel(root,key,successor);
            return {predecessor,successor};
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
    vector<optional<int>> arr = {5,2,10,1,4,7,12};
    TreeNode* root = buildTree(arr);
    Solution s;
    vector<int>res = s.succPredBST(root,12);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
