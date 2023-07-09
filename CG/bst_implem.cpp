#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left,* right;
};

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<"->";
        inorder(root->right);
    }
}

struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = item;
    temp->right=temp->left = NULL;

    return temp;
}

struct node* insert(struct node *node, int data){
    if(node==NULL)
        return newNode(data);
    if(data<node->data)
        node->left = insert(node->left,data);
    else
        node->right = insert(node->right,data);
    return node;
}

struct node *delete(struct node *root, int data){
    // tree is empty
    if(root == NULL)
        return root;

    //find the node to be deleted
    if(data < node->data)
        node->left = delete(node->left,data);
    else if(data > node->data)
        node->right = delete (node->right, data);

    else{
        //only one child or no child
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    }
}

int main(){
    struct node *root=NULL;

    root = insert(root,8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout<<"Inorder traversal: ";
    inorder(root);
}