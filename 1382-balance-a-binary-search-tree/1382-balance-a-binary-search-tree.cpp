class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return build(nums, 0, nums.size() - 1);
    }

private:
    void inorder(TreeNode* node, vector<int>& nums) {
        if (node == nullptr)
            return;

        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;

        int m = l + (r - l) / 2;

        return new TreeNode(
            nums[m],
            build(nums, l, m - 1),
            build(nums, m + 1, r)
        );
    }
};
