class returnType
{
    public:
        int max;
        int min;
        bool isbst;
        returnType(int max_num, int min_num, bool is): max(max_num), min(min_num), isbst(is) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return process(root)->isbst;
    }
    returnType* process(TreeNode *root)
    {
        if(root == nullptr) return nullptr;
        returnType *l = process(root->left);
        returnType *r = process(root->right);
        int max_num = root->val;
        int min_num = root->val;
        if(l)
        {
            max_num = max(max_num, l->max);
            min_num = min(min_num, l->min);
        }
        if(r)
        {
            max_num = max(max_num, r->max);
            min_num = min(min_num, r->min);
        }
        bool isbst = true;
        if(l != nullptr && (!l->isbst || (l->max >= root->val))) isbst = false;
        if(r != nullptr && (!r->isbst || (r->min <= root->val))) isbst = false;
        return new returnType(max_num, min_num, isbst);
    }
};
