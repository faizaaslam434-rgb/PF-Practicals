/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  int* res = malloc(sizeof(int) * 100); // Assuming max nodes <= 100 for simplicity
    *returnSize = 0;
    helper(root, res, returnSize);
    return res;
}

void helper(struct TreeNode* node, int* res, int* returnSize) {
    if (node == NULL) return;
    helper(node->left, res, returnSize);
    res[*returnSize] = node->val;
    (*returnSize)++;
    helper(node->right, res, returnSize);
}   
}