void in_morris(Node *root)
{
    if(root == nullptr) return;
    Node *cur = root;
    Node *most_right;
    while(cur)
    {
        most_right = cur->left;
        if(most_right)
        {
            while(most_right->right && most_right->right != cur) most_right = most_right->right;
            if(most_right == nullptr) 
            {
                most_right->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                most_right->right = nullptr;
            }
        }
        cout << cur->val << " ";
        cur = cur->right;
    }
    return;
}
