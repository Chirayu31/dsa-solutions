class Solution
{
private:
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = dfsHeight(root->left);
        int rh = dfsHeight(root->right);

        if (lh == -1 || rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }
};