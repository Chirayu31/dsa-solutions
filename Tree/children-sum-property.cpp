/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void childrenSum(TreeNode *root)
    {
        if (root == NULL)
            return;
        int child = 0;

        if (root->left)
        {
            child += root->left->val;
        }
        if (root->right)
        {
            child += root->right->val;
        }

        if (child >= root->data)
        {
            root->data = child;
        }
        else
        {
            if (root->left)
                root->left->data = root->data;
            if (root->right)
                root->right->data = root->data;
        }

        childrenSum(root->left);
        childrenSum(root->right);

        int tot = 0;

        if (root->left)
            tot += root->left->data;

        if (root->right)
            tot += root->right->data;

        if (root->left || root->right)
            root->data = tot;
    }
};