#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node in the BST
struct node* insert_node(struct node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->data) {
        root->left = insert_node(root->left, value);
    }
    else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    
    printf("Inorder traversal of the BST: ");
    inorder_traversal(root);
    printf("\n");
    printf("Press any key to exit...\n");
    getchar();

    return 0;
}
