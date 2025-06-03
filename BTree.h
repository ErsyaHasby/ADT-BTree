/* Nama File : BTree.h 	*/
/* Deskripsi : File header untuk ADT Binary Tree */
/* Dibuat oleh : Ersya Hasby Satria, Hisyam Khaeru Umam, Varian Abidarma Syuhada */
/* Tanggal     : 12-05-2025 */

#ifndef BTREE_H
#define BTREE_H

typedef struct TreeNode
{
    char info;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(char info);                                   // dibuat oleh Hisyam Khaeru Umam
TreeNode *findNode(TreeNode *root, char info);                     // dibuat oleh Hisyam Khaeru Umam
void insertChild(TreeNode *parent, char leftInfo, char rightInfo); // dibuat oleh Hisyam Khaeru Umam
void preOrder(TreeNode *root);                                     // dibuat oleh Ersya Hasby Satria
void inOrder(TreeNode *root);                                      // dibuat oleh Ersya Hasby Satria
void postOrder(TreeNode *root);                                    // dibuat oleh Ersya Hasby Satria
void levelOrder(TreeNode *root);                                   // dibuat oleh Ersya Hasby Satria
int countLeaves(TreeNode *root);                                   // dibuat oleh Ersya Hasby Satria
void printTree(TreeNode *root);                                    // dibuat oleh Varian Abidarma Syuhada
int treeDepth(TreeNode *root);                                     // dibuat oleh Varian Abidarma Syuhada
int findLevel(TreeNode *root, char target, int level);             // dibuat oleh Varian Abidarma Syuhada
void printTableFormat(TreeNode *root);                             // dibuat oleh Varian Abidarma Syuhada

#endif
