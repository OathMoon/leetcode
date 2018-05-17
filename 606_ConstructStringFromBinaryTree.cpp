/*
 * @Author: OathMoon 
 * @Date: 2018-05-17 22:28:04 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-17 22:31:35
 */

#include <iostream>
#include <string>
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

string tree2str(TreeNode* t)
{
    if (!t)
    {
        return "";
    }
    
    string s = to_string(t->val);          
    if (t->right)
    {
        s += "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
    else if (t->left)
    {
        s += "(" + tree2str(t->left) + ")";
    }
    
    return s;
}

int main()
{
    vector<int> treeValue {1,2,3,0,4};

    TreeNode* root = CreateTree(treeValue);
    cout << tree2str(root) << endl;

    return 0;
}