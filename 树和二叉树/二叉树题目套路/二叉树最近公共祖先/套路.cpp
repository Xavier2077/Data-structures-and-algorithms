class Solution {
public:
    void process(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &father)
    {
        if(root == NULL) return;
        father[root->left] = root;
        father[root->right] = root;
        process(root->left, father);
        process(root->right, father);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> father;
        father[root] = root;
        process(root, father);
        unordered_map<TreeNode*, int> set_p;
        TreeNode *cur = p;
        while(cur != father[cur])//建立p到head的父节点链
        {
            set_p[cur] = 1;
            cur = father[cur];
        }
        set_p[root] = 1;
        cur = q;
        while(cur != father[cur])
        {
            if(set_p.find(cur) != set_p.end()) 
            {
                return cur;
            }
            cur = father[cur];
        }
        return root;
    }
};
