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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> zz;
        if (root == NULL)
            return zz;

        queue<TreeNode *> q;
        q.push(root);
        bool f = false;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> lvl(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);

                int idx = (f) ? n - i - 1 : i;
                lvl[idx] = node->val;
            }

            f = !f;
            zz.push_back(lvl);
        }
        return zz;
    }
};