typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* EmptyBag();
NODE* insertEleBeginning(NODE* head);
NODE* insertEleEnd(NODE* head);
void print(NODE* head);
NODE* deleteKey(NODE* head, int key);
int ifempty(NODE* head);
int countnode(NODE* head);


typedef struct AVLNode {
    int item;
    int freq;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

int height(AVLNode* node);
int getBalance(AVLNode* node);
AVLNode* rightRotate(AVLNode* y);
AVLNode* leftRotate(AVLNode* x);
AVLNode* insertAVL(AVLNode* root, int val);
AVLNode* buildAVLfromBag(NODE* head, AVLNode* root);
void inorderTraversalAVL(AVLNode* root);
void DisplayFrequencyAVL(AVLNode* root, int ele);
