/*
 * @Author: OathMoon 
 * @Date: 2018-05-07 23:16:27 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-07 23:31:34
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

TreeNode* trimBST(TreeNode* root, int L, int R)
{
    while (root->val < L || root->val > R)
    {
        if (root->val < L)
            root = root->right;
        else if (root->val > R)
            root = root->left;
    }
    
    TreeNode *adjustRoot = root;
    while(adjustRoot->left)
    {
        if (adjustRoot->left->val < L)
            adjustRoot->left = adjustRoot->left->right;
        else
            adjustRoot = adjustRoot->left;
    }
    
    adjustRoot = root;
    while(adjustRoot->right)
    {
        if (adjustRoot->right->val > R)
            adjustRoot->right = adjustRoot->right->left;
        else
            adjustRoot = adjustRoot->right;
    }
    
    return root;
}

int main()
{
    vector<int> treeValue {2, 1, 3};

    TreeNode* root = CreateTree(treeValue);
    VisitTree(root);
    root = trimBST(root, 2, 3);
    VisitTree(root);

    return 0;
}