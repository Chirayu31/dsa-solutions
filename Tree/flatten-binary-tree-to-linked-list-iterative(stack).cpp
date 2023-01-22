class Solution
{

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node->right != NULL)
                st.push(node->right);
            if (node->left != NULL)
                st.push(node->left);

            if (!st.empty())
            {
                node->right = st.top();
            }
            node->left = NULL;
        }
    }
};