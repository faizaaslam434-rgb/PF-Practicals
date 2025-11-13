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
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    inorder(root->left, result, index);   // Visit left subtree
    result[(*index)++] = root->val;       // Visit root node
    inorder(root->right, result, index);  // Visit right subtree
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));  // allocate space for result
    *returnSize = 0;
    inorder(root, result, returnSize);
    return result;
}