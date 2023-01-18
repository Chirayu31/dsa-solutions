class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> pre;

        if (root == NULL)
            return pre;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            pre.push_back(node->val);

            if (node->right != NULL)
                st.push(node->right);
            if (node->left != NULL)
                st.push(node->left);
        }
        return pre;
    }
};