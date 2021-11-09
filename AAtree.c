#include "AAtree.h"
#include <stdio.h>
#include <stdlib.h>

struct aatree* aatree_init(int key)
{
    struct aatree* tree = (struct aatree*)malloc(sizeof(struct aatree));
    tree->key = key;
    tree->level = 1;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct aatree* aatree_lookup(struct aatree* tree, int key)
{
    while (tree != NULL)
    {
        if (key == tree->key)
        {
            return tree;
        }
        else if (key < tree->key)
        {
            tree = tree->left;
        }
        else
        {
            tree = tree->right;
        }
    }
    return tree;
}

struct aatree* aatree_min(struct aatree* tree)
{
    if (tree == NULL)
    {
        return tree;
    }
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree;
}

struct aatree* aatree_max(struct aatree* tree)
{
    if (tree == NULL)
    {
        return tree;
    }
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree;
}

void aatree_free(struct aatree* tree)
{
    if (tree == NULL)
    {
        return;
    }
    aatree_free(tree->left);
    aatree_free(tree->right);
    free(tree);
}

struct aatree* aatree_skew(struct aatree* tree)
{
    if ((tree == NULL) || (tree->left == NULL))
    {
        return tree;
    }
    if (tree->level != tree->left->level)
    {
        return tree;
    }
    struct aatree* left = tree->left;
    tree->left = left->right;
    left->right = tree;
    tree = left;
    return tree;
}

struct aatree* aatree_split(struct aatree* tree)
{
    if ((tree == NULL) || (tree->right->right == NULL))
    {
        return tree;
    }
    if (tree->right->right->level != tree->level)
    {
        return tree;
    }
    struct aatree* right = tree->right;
    tree->right = right->left;
    right->left = tree;
    tree = right;
    tree->level++;
    return tree;
}

struct aatree* aatree_insert(struct aatree* tree, int key)
{
    if (tree == NULL)
    {
        tree = aatree_init(key);
        return tree;
    }
    if (key < tree->key)
    {
        tree->left = aatree_insert(tree->left, key);
    }
    else if (key > tree->key)
    {
        tree->right = aatree_insert(tree->right, key);
    }
    else
    {
        return tree;
    }
    tree = aatree_skew(tree);
    tree = aatree_split(tree);
    return tree;
}

struct aatree* aatree_delete(struct aatree* tree, int key)
{
    if (tree == NULL)
    {
        return tree;
    }
    struct aatree* deleted = NULL;
    struct aatree* last = tree;
    if (key < tree->key)
    {
        tree->left = aatree_delete(tree->left, key);
    }
    else
    {
        deleted = tree;
        tree->right = aatree_delete(tree->right, key);
    }
    if ((tree == last) && (deleted != NULL) && (key == deleted->key))
    {
        deleted->key = tree->key;
        deleted = NULL;
        tree = tree->right;
        free(last);
    }
    else if ((tree->left == NULL) || (tree->right == NULL))
    {
        return tree;
    }
    else if ((tree->left->level < tree->level - 1) || (tree->right->level < tree->level - 1))
    {
        tree->level--;
        if (tree->right->level > tree->level)
        {
            tree->right->level = tree->level;
        }
        tree = aatree_skew(tree);
        tree->right = aatree_skew(tree->right);
        tree->right->right = aatree_skew(tree->right->right);
        tree = aatree_split(tree);
        tree->right = aatree_split(tree->right);
    }
    return tree;
}
