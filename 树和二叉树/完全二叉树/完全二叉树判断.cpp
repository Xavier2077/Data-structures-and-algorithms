class Soultion
{
    public:
        bool is_cbt(TreeNode * root)
        {
            if(root = nullptr) return true;
            bool leaf = false;
            TreeNode *l = nullptr;
            TreeNode *r = nullptr;
            queue<TreeNode*> q;
            q.push(root);
            TreeNode *cur = nullptr;
            while(!q.empty())
            {
                cur = q.front();
                q.pop();
                l = q->left;
                r = q->right;
                if(
                    (left && (l != nullptr || r != nullptr)) 
                    || 
                    (l == nullptr && r != nullptr)
                )
                {
                    return false;
                }
                if(l != nullptr) q.push(l);
                if(r != nullptr) q.push(r);
                if(l == nullptr && r == nullptr) leaf = true;
            }

        }
 
};
