class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int left=maxGain(node->left);
        int right=maxGain(node->right);

        int maxval=left+right+node->val;
        maxSum=max(maxSum,maxval);

        return node->val+max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
