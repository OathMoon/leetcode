/*
 * @Author: OathMoon 
 * @Date: 2018-06-05 00:01:53 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-06-05 00:18:58
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateTree(vector<int>& treeValue, int index = 0)
{
    if (index >= treeValue.size() || treeValue[index] == 0)
        return nullptr;

    TreeNode* root = new TreeNode(treeValue[index]);
    root->left = CreateTree(treeValue, 2 * index + 1);
    root->right = CreateTree(treeValue, 2 * index + 2);

    return root;
}

void VisitTree(TreeNode* root)
{
    queue<TreeNode*> nodeQueue;

    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        cout << node->val << "  ";

        if (node->left)
        {
            nodeQueue.push(node->left);
        }

        if (node->right)
        {
            nodeQueue.push(node->right);
        }
    }

    cout << endl;
}

void dfs(TreeNode* root, int& preval)
{
    if (root == nullptr)
        return;
    
    dfs(root->right, preval);
    preval += root->val;
    root->val = preval;
    
    dfs(root->left, preval);
}

TreeNode* convertBST(TreeNode* root)
{
    if (root ==  nullptr)
        return nullptr;
    
    int preval = 0;
    dfs(root, preval);
    
    return root;
}

int main()
{
    vector<int> treeValue {5,2,13};
    TreeNode* root = CreateTree(treeValue);
    VisitTree(root);
    root = convertBST(root);
    VisitTree(root);

    return 0;
}