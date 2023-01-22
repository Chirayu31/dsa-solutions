class Solution
{
    bool getPath(TreeNode *node, vector<int> &arr, int destination)
    {
        if (!node)
            return false;
        arr.push_back(node->val);

        if (node->val == x)
            return true;

        if(getPath(node->left, arr, destination) || getPath(node->right, arr, destination))
            return true;

        arr.pop_back();
        return false;
    }

public:
    vector<int> rootToNode(TreeNode *root, int destination)
    {
        vector<int> arr;
        if (root == NULL)
            return arr;
        getPath(root, arr, destination);
    }
};