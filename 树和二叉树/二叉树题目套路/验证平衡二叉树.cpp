class returnType
{
    public:
        bool isBbt;
        int height;
        returnType(bool is, int hgt):isBbt(is), height(hgt){}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return process(root).isBbt;
    }
    returnType process(TreeNode *root)
    {
        if(root == nullptr) return returnType(true, 0);
        returnType l = process(root->left);
        returnType r = process(root->right);

        int height = max(l.height, r.height) + 1;
        bool isBbt = (l.isBbt && r.isBbt) && (abs(l.height - r.height) <= 1);
        return returnType(isBbt, height);
    }
};
