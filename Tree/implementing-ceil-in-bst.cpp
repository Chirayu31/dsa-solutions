int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int c = -1;
    // Your code here
    while (root)
    {
        if (root->data == input)
        {
            c = root->data;
            return c;
        }
        if (input > root->data)
        {
            root = root->right;
        }
        else
        {
            c = root->data;
            root = root->left;
        }
    }
    return c;
}