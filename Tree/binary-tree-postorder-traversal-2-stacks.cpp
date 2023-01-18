class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
            return postorder;

        stack<TreeNode *> st1, st2;

        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();

            st2.push(node);
            if (node->left != NULL)
                st1.push(node->left);
            if (node->right != NULL)
                st1.push(node->right);
        }
        while (!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};