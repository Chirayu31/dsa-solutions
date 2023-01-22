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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        long long ans = 0;
        //{node,idx}
        queue<pair<TreeNode *, long long>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            long long n = q.size();
            long long curMin = q.front().second;
            long long first, last;

            for (int i = 0; i < n; i++)
            {
                long long cur_id = q.front().second - curMin;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_id;
                if (i == n - 1)
                    last = cur_id;

                if (node->left != NULL)
                    q.push({node->left, cur_id * 2 + 1});
                if (node->right != NULL)
                    q.push({node->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};