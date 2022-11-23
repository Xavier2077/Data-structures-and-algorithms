//前序遍历
void pre_morris(Node *root)
{
    if(root == nullptr) return;
    Node *cur = root;
    Node *most_right = nullptr;
    while(cur)
    {
        most_right = cur->left;
        if(most_right)
        {
            while(most_right->right && most_right->right != cur) most_right = most_right->right;
            if(most_right == nullptr)
            {
                cout << cur->val << " ";
                most_right->right = cur;
                cur = cur->left;
                continue;
            } 
            else
            {
                most_right->right = nullptr;
            }
        }
        else cout << cur->val << " ";
        cur = cur->right;
    }
    return;
}
