class BSTIterator
{
public:
    stack<TreeNode *> st;

    BSTIterator(TreeNode *root)
    {
        TreeNode *node = root;
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        int ans = node->val;

        node = node->right;
        while (node)
        {
            st.push(node);
            node = node->left;
        }

        return ans;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};