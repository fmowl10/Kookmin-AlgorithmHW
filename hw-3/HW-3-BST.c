/**
 * @file HW-3-BST.c
 * @author Jinsoek Kim (jinseok1001@outllok.com)
 * @brief BST
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;

struct _node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *temp = malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

void insert(node **root, int data)
{
    if (*root == NULL)
    {
        *root = newNode(data);
        return;
    }
    if ((*root)->data > data)
        insert(&((*root)->left), data);
    else
        insert(&((*root)->right), data);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);

    return;
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
    return;
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
    return;
}

int size(node *root)
{
    if (root == NULL)
        return 0;
    return size(root->left) + 1 + size(root->right);
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    // 여러번 계산됨
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

int sumOfWeight(node *root)
{
    if (root == NULL)
        return 0;

    return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data;
}

int maxPathWeight(node *root)
{
    if (root == NULL)
        return 0;

    int left = maxPathWeight(root->left);
    int right = maxPathWeight(root->right);
    return (left > right ? left : right) + root->data;
}

void mirror(node **root)
{
    if (*root == NULL)
        return;
    mirror(&((*root)->left));
    mirror(&((*root)->right));

    node *temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;
}

void destruct(node **root)
{
    if ((*root) == NULL)
        return;

    destruct(&((*root)->left));
    destruct(&((*root)->right));
    node *temp = *root;
    *root = NULL;
    free(*root);
}

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--)
    {
        int num, i;
        node *root = NULL;
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data;
            scanf("%d", &data);
            insert(&root, data);
        }
        printf("%d\n", size(root));
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제
        if (root == NULL)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}