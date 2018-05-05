/*
 * @Author: OathMoon 
 * @Date: 2018-05-04 23:18:20 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-05 00:28:58
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

TreeNode* CreateTree(vector<int>& treeValue, int index)
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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if (t1 && t2)
    {
        TreeNode *root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    } 
    else
    {
        return t1 ? t1 : t2;
    }
}

int main()
{
    vector<int> treeValue1 {1, 3, 2, 5};
    vector<int> treeValue2 {2, 1, 3, 0, 4, 7};

    TreeNode* root1 = CreateTree(treeValue1, 0);
    TreeNode* root2 = CreateTree(treeValue2, 0);
    VisitTree(root1);
    VisitTree(root2);

    TreeNode* root = mergeTrees(root1, root2);
    VisitTree(root);
}