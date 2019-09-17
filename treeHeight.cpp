/*
Developer: Hamed Mirlohi
Date: 09/11/2019
In this program we are measuring the height of the tree
*/

#include <iostream>

struct node
{
    node* left;
    node* right;
    int data;
};

node* build_tree(node* root, int d)
{
    if(root == nullptr)
    {
        root = new node;
        root->data = d;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    
    if(d <= root->data)
        root->left = build_tree(root->left, d);
    else
        root->right = build_tree(root->right, d);
    
    return root;
}


// function to calculate the height of a binary search tree
int calculate_height(node* root)
{
    if(root == nullptr)
        return -1;
    int leftHeight = calculate_height(root->left);
    int rightHeight = calculate_height(root->right);
    
    if(leftHeight > rightHeight)
        return ++leftHeight;
    else
        return ++rightHeight;
}

int main(void)
{
    node* root = nullptr;
    
    root = build_tree(root, 5);
    root = build_tree(root, 10);
    root = build_tree(root, 3);
    root = build_tree(root, 2);
    root = build_tree(root, 8);
    root = build_tree(root, 7);
    
    
    display_tree_leftRight(root);
    
    std::cout << "----------------------------\n";
    
    std::cout << calculate_height(root) << std::endl;
    

}

