class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
            return postorder;

        stack<TreeNode *> st;

        TreeNode *curr = root;

        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return postorder;
    }
};