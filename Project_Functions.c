#include "Project.h"
#include <stdio.h>
#include <stdlib.h>

// LINKED LIST (BAG)
NODE* EmptyBag() {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter the element to be inserted in the bag: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

NODE* insertEleBeginning(NODE* head) {
    NODE* temp = EmptyBag();
    temp->next = head;
    return temp;
}

NODE* insertEleEnd(NODE* head) {
    NODE* temp = EmptyBag();
    if (head == NULL)
        return temp;

    NODE* curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}

void print(NODE* head) {
    NODE* temp = head;
    if (!temp) {
        printf("Bag is empty.\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

NODE* deleteKey(NODE* head, int key) {
    if (head == NULL) {
        printf("Bag is empty.\n");
        return NULL;
    }

    NODE* temp = head;
    NODE* prev = NULL;

    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Key not found.\n");
        return head;
    }

    if (!prev)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
    return head;
}

int ifempty(NODE* head) {
    return head == NULL;
}

int countnode(NODE* head) {
    int count = 0;
    for (NODE* temp = head; temp; temp = temp->next)
        count++;
    return count;
}

// AVL TREE (INDEX)

int height(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));

    return y;
}

AVLNode* insertAVL(AVLNode* root, int val) {
    if (root == NULL) {
        AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
        newNode->item = val;
        newNode->freq = 1;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (val == root->item) {
        root->freq++;
        return root;
    }
    else if (val < root->item)
        root->left = insertAVL(root->left, val);
    else
        root->right = insertAVL(root->right, val);

    root->height = 1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && val < root->left->item)
        return rightRotate(root);
    if (balance < -1 && val > root->right->item)
        return leftRotate(root);
    if (balance > 1 && val > root->left->item) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && val < root->right->item) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLNode* buildAVLfromBag(NODE* head, AVLNode* root) {
    for (NODE* temp = head; temp != NULL; temp = temp->next)
        root = insertAVL(root, temp->data);
    return root;
}

void inorderTraversalAVL(AVLNode* root) {
    if (!root) return;
    inorderTraversalAVL(root->left);
    printf("%d(%d) ", root->item, root->freq);
    inorderTraversalAVL(root->right);
}

void DisplayFrequencyAVL(AVLNode* root, int ele) {
    if (root == NULL) {
        printf("Element %d not found.\n", ele);
        return;
    }
    if (ele == root->item)
        printf("Element %d found with frequency %d.\n", root->item, root->freq);
    else if (ele < root->item)
        DisplayFrequencyAVL(root->left, ele);
    else
        DisplayFrequencyAVL(root->right, ele);
}
