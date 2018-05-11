/*
 * @Author: OathMoon 
 * @Date: 2018-05-11 23:17:57 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-11 23:23:08
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

TreeNode* invertTree(TreeNode* root)
{
    if (root == nullptr)
    {
        return root;
    }
    
    invertTree(root->right);
    invertTree(root->left);
    
    swap(root->left, root->right);
    
    return root;
}

int main()
{
    vector<int> treeValue {4,2,7,1,3,6,9};

    TreeNode* root = CreateTree(treeValue);
    VisitTree(root);
    
    root = invertTree(root);
    VisitTree(root);

    return 0;
}