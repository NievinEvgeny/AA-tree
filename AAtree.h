#pragma once

struct aatree
{
    int key;
    int level;
    struct aatree* left;
    struct aatree* right;
};

struct aatree* aatree_init(int key);

struct aatree* aatree_lookup(struct aatree* tree, int key);

struct aatree* aatree_min(struct aatree* tree);

struct aatree* aatree_max(struct aatree* tree);

void aatree_free(struct aatree* tree);

struct aatree* aatree_skew(struct aatree* tree);

struct aatree* aatree_split(struct aatree* tree);

struct aatree* aatree_insert(struct aatree* tree, int key);

struct aatree* aatree_delete(struct aatree* tree, int key);