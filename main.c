/* Nama File : main.c 	*/
/* Deskripsi : File main untuk ADT Binary Tree */
/* Dibuat oleh : Ersya Hasby Satria, Hisyam Khaeru Umam, Varian Abidarma Syuhada */
/* Tanggal     : 12-05-2025 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

#define MAX 100

typedef struct
{
    char info;
    char left;
    char right;
} InputNode;

int main()
{
    int n;
    InputNode nodes[MAX];
    TreeNode *root = NULL;
    TreeNode *pointer[MAX] = {NULL};

    printf("Masukkan jumlah node: ");
    scanf("%d", &n);

    // Input node info
    for (int i = 0; i < n; i++)
    {
        printf("Node ke-%d\n", i + 1);
        printf("  Info : ");
        scanf(" %c", &nodes[i].info);
        printf("  Left (jika tidak ada, masukkan -): ");
        scanf(" %c", &nodes[i].left);
        printf("  Right (jika tidak ada, masukkan -): ");
        scanf(" %c", &nodes[i].right);
        pointer[i] = createNode(nodes[i].info);
    }

    // Bangun tree berdasarkan input
    root = pointer[0]; // Asumsikan node pertama adalah root

    for (int i = 0; i < n; i++)
    {
        TreeNode *parent = findNode(root, nodes[i].info);
        if (parent)
        {
            if (nodes[i].left != '-')
            {
                for (int j = 0; j < n; j++)
                {
                    if (nodes[j].info == nodes[i].left)
                        parent->left = pointer[j];
                }
            }
            if (nodes[i].right != '-')
            {
                for (int j = 0; j < n; j++)
                {
                    if (nodes[j].info == nodes[i].right)
                        parent->right = pointer[j];
                }
            }
        }
    }

    // Menu
    int pilihan;
    do
    {
        printf("\nMenu:\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Print Tree (Tabel Info, Left Son, Right Son)\n");
        printf("5. Jumlah Daun/Leaf\n");
        printf("6. Mencari Level Node\n");
        printf("7. Kedalaman Tree\n");
        printf("8. Traversal Level-Order\n");
        printf("9. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        char target;
        switch (pilihan)
        {
        case 1:
            printf("PreOrder: ");
            preOrder(root);
            printf("\n");
            break;
        case 2:
            printf("InOrder: ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("PostOrder: ");
            postOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Struktur Tree:\n");
            printTableFormat(root);
            break;
        case 5:
            printf("Jumlah daun: %d\n", countLeaves(root));
            break;
        case 6:
            printf("Masukkan info node: ");
            scanf(" %c", &target);
            int level = findLevel(root, target, 0);
            if (level != -1)
                printf("Node %c berada di level %d\n", target, level);
            else
                printf("Node %c tidak ditemukan.\n", target);
            break;
        case 7:
            printf("Kedalaman Tree: %d\n", treeDepth(root));
            break;
        case 8:
            printf("Level-Order: ");
            levelOrder(root);
            printf("\n");
            break;
        case 9:
            printf("Keluar program.\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 9);

    return 0;
}
