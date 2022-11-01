class Info
{
    public:
        int sum;
        int hegiht;
        Info(int sum, int hegiht): sum(sum), hegiht(hegiht){}
};
class solution
{
    public:
        bool isbft(TreeNode *root)
        {
            auto tmp = process(root);
            return pow(2, tmp->height) == sum;
        }
        Info process(TreeNode *root)
        {
            if(root == nullptr) return Info(0, 0);
            Info l = process(root->left);
            Info r = process(root->right);
            int height = max(l.hegiht, r.hegiht) + 1;
            int sum = l.sum + r.sum + 1;
            return Info(sum, height);
        }
};
