#ifndef BTREE_H
#define BTREE_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>



struct TreeNode{

	size_t *children;
	size_t *value;
	char *key;
};
