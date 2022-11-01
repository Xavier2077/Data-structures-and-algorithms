class Solution {
    long long last = LONG_LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        bool l = isValidBST(root->left);
        if(root->val <= last) return false;
        else last = root->val;
        bool r = isValidBST(root->right);
        return l && r;
    }
};
