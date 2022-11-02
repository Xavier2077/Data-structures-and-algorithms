class Node
{
    public:
        int value;
        Node *left;
        Node *right;
        Node *parent;
        Node(int val):value(val) {}
};

Node* getSuccessorNode(Node *node)
{
    if(node == nullptr) return node;
    if(node->right != nullptr) return getSuccessorNode(node->right);
    else
    {
        Node *parent = node->parent;
        while(parent != nullptr && parent->left != node)
        {
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}
