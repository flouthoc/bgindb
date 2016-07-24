#ifndef BGIN_BTREE
#define BGIN_BTREE

#include <stdint.h>
#include <sys/types.h>

#define HASH_LENGTH 20

#define BTREE_MAX_KEYS 2*bgin_btree_degree - 1;
#define BTREE_MIN_KEYS bgin_btree_degree - 1;
#define BTREE_MIN_CHILD bgin_btree_degree;
#define BTREE_MAX_CHILD 2*bgin_btree_degree;

struct btree_node{

	int8_t leaf;
	uint8_t key[BTREE_MAX_KEYS]; //in doubt if this is right data type ? :\
	uint64_t values[BTREE_MAX_KEYS];
	uint64_t children[BTREE_MAX_CHID];
	uint64_t offset;

};

struct bgin_btree{

	struct btree_node *root;
	size_t num_nodes;
};


int *bgin_btree_put(struct *bgin_btree, void *key, void *value);
int *bgin_btree_get(struct *bgin_btree, void *key, void *value);
int *bgin_btree_delete(struct *bgin_btree, void *key, void *value);







#endif