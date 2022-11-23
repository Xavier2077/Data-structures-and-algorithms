//基础遍历
void morris(Node *root)
{
    if(root == nullptr) return;
    Node *cur = root;
    Node *most_right = nullptr;
    while(cur != nullptr)
    {
        most_right = cur->left;
        //如果有左孩子
        if(most_right)
        {
            while(most_right->right != nullptr && most_right->right != cur)
            {
                most_right = most_right->right;
            }
            if(most_right->right == nullptr)
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
        cur = cur->right;
    }
    return;
}
