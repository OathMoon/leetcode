/*
 * @Author: OathMoon 
 * @Date: 2018-05-15 23:31:51 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-15 23:36:40
 */

#include <iostream>
#include <unordered_set>
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

void inorder(TreeNode *root, unordered_set<int>& valset)
{
    if (root)
    {
        inorder(root->left, valset);
        valset.insert(root->val);
        inorder(root->right, valset);
    }
}

using namespace std;

bool findTarget(TreeNode* root, int k)
{
    unordered_set<int> valset;
    
    inorder(root, valset);
    for (auto elem : valset)
    {
        if (k - elem != elem && valset.count(k - elem))
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    vector<int> treeValue {5,3,6,2,4,0,7};

    TreeNode* root = CreateTree(treeValue);
    cout << boolalpha << findTarget(root, 9) << endl;
    cout << boolalpha << findTarget(root, 28) << endl;

    return 0;
}