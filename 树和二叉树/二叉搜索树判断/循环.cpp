class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long long pre = LONG_MIN;
        stack<TreeNode*> s;
        while(!s.empty() || root != nullptr)
        {
            if(root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                if(root->val <= pre) return false;
                else pre = root->val;
                root = root->right;
            }
        }
        return true;
    }
};
