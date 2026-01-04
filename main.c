#include "Project.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    NODE* head = NULL;
    AVLNode* root = NULL;
    int choice, key;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Append to Bag (insert at end)\n");
        printf("2. Prepend to Bag (insert at beginning)\n");
        printf("3. Print Bag contents\n");
        printf("4. Check if Bag is empty\n");
        printf("5. Display count of elements\n");
        printf("6. Delete element by key\n");
        printf("7. Build AVL Index from Bag\n");
        printf("8. Display inorder traversal of AVL\n");
        printf("9. Display frequency of element in AVL\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertEleEnd(head);
                break;

            case 2:
                head = insertEleBeginning(head);
                break;

            case 3:
                print(head);
                break;

            case 4:
                printf(ifempty(head) ? "Bag is empty.\n" : "Bag is not empty.\n");
                break;

            case 5:
                printf("Number of elements in bag: %d\n", countnode(head));
                break;

            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteKey(head, key);
                root = buildAVLfromBag(head, NULL);
                break;

            case 7:
                root = buildAVLfromBag(head, NULL);
                printf("AVL Index built from bag successfully.\n");
                break;

            case 8:
                printf("Inorder traversal of AVL Tree: ");
                inorderTraversalAVL(root);
                printf("\n");
                break;

            case 9:
                printf("Enter element to check frequency: ");
                scanf("%d", &key);
                DisplayFrequencyAVL(root, key);
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid input. Try again.\n");
        }
    } while (choice != 10);

    return 0;
}
