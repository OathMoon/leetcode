/*
 * @Author: OathMoon 
 * @Date: 2018-05-11 22:48:55 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-11 22:55:19
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

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> result;
    queue<TreeNode*> nodequeue;
    nodequeue.push(root);
    
    while (!nodequeue.empty())
    {
        double sum = 0;
        int n = nodequeue.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode* t = nodequeue.front();
            nodequeue.pop();
            
            sum += t->val;
            
            if (t->left)
                nodequeue.push(t->left);
            if(t->right)
                nodequeue.push(t->right);
        }
        
        result.push_back(sum/n);
    }
    
    return result;
}

int main()
{
    vector<int> treeValue {3,9,20,0,0,15,7};
    TreeNode* root = CreateTree(treeValue);

    auto result = averageOfLevels(root);
    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;

    return 0;
}