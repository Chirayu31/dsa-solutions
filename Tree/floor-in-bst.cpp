int floor(Node *root, int x)
{
    // Code here
    if (root == NULL)
        return -1;
    int ans = -1;

    while (root)
    {
        if (root->data == x)
        {
            ans = x;
            return x;
        }
        if (root->data < x)
        {
            ans = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}
