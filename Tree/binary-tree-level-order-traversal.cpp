class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> lvl;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                lvl.push_back(node->val);
            }
            res.push_back(lvl);
        }
        return res;
    }
};