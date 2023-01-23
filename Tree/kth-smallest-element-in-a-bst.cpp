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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *node = root;
        int cnt = 0;
        int ans = INT_MIN;

        while (node != NULL)
        {
            if (node->left == NULL)
            {
                cnt++;
                if (cnt == k)
                    ans = node->val;
                node = node->right;
            }
            else
            {
                TreeNode *prev = node->left;
                while (prev->right && prev->right != node)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = node;
                    node = node->left;
                }
                else
                {
                    prev->right = NULL;
                    cnt++;
                    if (cnt == k)
                        ans = node->val;
                    node = node->right;
                }
            }
        }
        return ans;
    }
};