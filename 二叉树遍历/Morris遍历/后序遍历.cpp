//后序遍历
Node* reverse(Node *root)
{
    if(root == nullptr) return;
    Node *pre = nullptr;
    Node *next = nullptr;
    while(root)
    {
       next = root->right;
       root->right = pre;
       pre = root;
       root = next;
    }
    return pre;
}
void print_edge(Node *root)
{
    if(root == nullptr) return;
    auto head = reverse(root);
    auto cur = head;
    while(cur)
    {
        cout << cur->val << " ";
    }
    reverse(head);
    return;
}
void post_morris(Node *root)
{
    if(!root) return;
    Node *cur = root;
    Node *most_right = nullptr;
    while(cur)
    {
        most_right = cur->left;
        if(most_right)
        {
            while(most_right->right && most_right->right != cur) most_right = most_right->right;
            if(most_right->right)
            {
                most_right->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                most_right->right = nullptr;
                print_edge(cur->left);
            }
        }
        cur = cur->right;
    }
    print_edge(root);
    return;
}
