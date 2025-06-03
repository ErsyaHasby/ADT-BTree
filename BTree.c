/* Nama File : BTree.c 	*/
/* Deskripsi : File body untuk ADT Binary Tree */
/* Dibuat oleh : Ersya Hasby Satria, Hisyam Khaeru Umam, Varian Abidarma Syuhada */
/* Tanggal     : 12-05-2025 */

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

TreeNode *createNode(char info)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *findNode(TreeNode *root, char info)
{
    if (!root)
        return NULL;
    if (root->info == info)
        return root;
    TreeNode *left = findNode(root->left, info);
    if (left)
        return left;
    return findNode(root->right, info);
}

void insertChild(TreeNode *parent, char leftInfo, char rightInfo)
{
    if (parent && leftInfo != '-')
        parent->left = createNode(leftInfo);
    if (parent && rightInfo != '-')
        parent->right = createNode(rightInfo);
}

void preOrder(TreeNode *root)
{
    if (root)
    {
        printf("%c ", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if (root)
    {
        inOrder(root->left);
        printf("%c ", root->info);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->info);
    }
}

void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        TreeNode *current = queue[front++];
        printf("%c ", current->info);
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

void printTree(TreeNode *root)
{
    printf("| Info | Left | Right |\n");
    printf("------------------------\n");
    if (!root)
        return;
    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        TreeNode *current = queue[front++];
        printf("|  %c   |  %c   |   %c   |\n",
               current->info,
               current->left ? current->left->info : '-',
               current->right ? current->right->info : '-');
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

int countLeaves(TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int treeDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int left = treeDepth(root->left);
    int right = treeDepth(root->right);
    return 1 + (left > right ? left : right);
}

int findLevel(TreeNode *root, char target, int level)
{
    if (!root)
        return -1;
    if (root->info == target)
        return level;
    int l = findLevel(root->left, target, level + 1);
    if (l != -1)
        return l;
    return findLevel(root->right, target, level + 1);
}

void printTableFormat(TreeNode *root)
{
    printf("| %-10s | %-10s | %-10s |\n", "Node", "Left", "Right");
    printf("|------------|------------|------------|\n");

    if (root == NULL)
        return;

    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        TreeNode *curr = queue[front++];

        printf("| %-10c | %-10c | %-10c |\n",
               curr->info,
               curr->left ? curr->left->info : '-',
               curr->right ? curr->right->info : '-');

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
}