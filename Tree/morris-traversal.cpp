#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
vector<int> inorderTraversal(node *root)
{
    vector<int> inorder;
    node *curr = root;

    while (curr != NULL)
    {

        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;

            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}