
#ifndef _BST_H_
#define _BST_H_

typedef struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    struct bst_node *parent;
    int key;
    int height;
} BST_NODE;

typedef struct bst {
    BST_NODE *root;
    int size;
    int maxSize;    
} BST;

BST_NODE *createBSTNode(int key, BST_NODE* L, BST_NODE* R, BST_NODE* P);

BST* createBST(int max);

int isEmpty(BST* B);

int isFull(BST* B);

void insert(BST* B, BST_NODE* node);

void showTree(BST* B);

int delete(BST* B, int key);

void clear(BST* B);
#endif