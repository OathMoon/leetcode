/*
 * @Author: OathMoon 
 * @Date: 2018-05-12 22:22:08 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-12 22:24:44
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

int maxDepth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    vector<int> treeValue {3,9,20,0,0,15,7};

    TreeNode* root = CreateTree(treeValue);
    cout << maxDepth(root) << endl;

    return 0;
}