#include "bgin_btree.h"

int *bgin_btree_get(struct bgin_btree *btree, void *key, void *value){

		size_t i = 0;
		struct btree_node *node = btree->root;

		if(node == NULL || key == NULL || value == NULL)
			return -1;



}


uint64_t bgin_btree_search(struct btree *node, void *key){

	int i;

	while(i <= node->key_filled && key>node->key[i])
		i++;

	if(i<= node->key_filled && (key == node->key[i]))
		return value_offset[i];


}