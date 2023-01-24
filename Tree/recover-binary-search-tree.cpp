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
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev && (root->val < prev->val))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
        {
            int t = last->val;
            last->val = first->val;
            first->val = t;
        }
        else if (first && middle)
        {
            int t = middle->val;
            middle->val = first->val;
            first->val = t;
        }
    }
};