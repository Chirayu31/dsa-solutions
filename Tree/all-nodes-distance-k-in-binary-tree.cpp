/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    void markParents(TreeNode *root, map<TreeNode *, TreeNode *> &mp)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        // mp[i]: node->parent
        map<TreeNode *, TreeNode *> mp;
        markParents(root, mp);

        map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        int dis = 0;
        q.push(target);
        vis[target] = true;

        while (!q.empty())
        {
            int n = q.size();
            if (dis++ == k)
                break;

            for (int i = 0; i < n; i++)
            {

                TreeNode *node = q.front();
                q.pop();

                if (node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if (node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if (mp[node] && !vis[mp[node]])
                {
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
        }

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};