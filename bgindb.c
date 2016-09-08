#include "bgindb.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdio.h>	
#include <stdlib.h>	
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>


#define HASH_LENGTH 20
#define BGIN_BTREE_DEGREE 1024

#define BTREE_MAX_KEYS 2*BGIN_BTREE_DEGREE - 1;
#define BTREE_MIN_KEYS BGIN_BTREE_DEGREE - 1;
#define BTREE_MIN_CHILD BGIN_BTREE_DEGREE;
#define BTREE_MAX_CHILD 2*BGIN_BTREE_DEGREE;

struct btree_node{

	uint8_t leaf;
	uint16_t key[BTREE_MAX_KEYS]; //in doubt if this is right data type ? :\
	uint64_t value_offset[BTREE_MAX_KEYS];
	uint64_t children[BTREE_MAX_CHILD];
	uint64_t offset;
	size_t keys-filled;

};

struct bgin_btree{

	struct btree_node *root;
	size_t num_nodes;
};




/*Declarations (some people even call them prototypes :D )*/


static void _bgin_err_throw(const char *, ...);
static void _bgin_err_die(const char *, ...);
static void _bgin_err_core(const char *, va_list);

static inline uint16_t  swap_be16(uint16_t);
static inline uint32_t  swap_be32(uint32_t val);
static inline uint64_t  swap_be64(uint64_t val);


static de-cereal(int *, const char *, ...);
static _de_cereal(int *, const char *, va_list); 


static int *bgin_btree_put(struct bgin_btree *, void *, void *);
static int *bgin_btree_get(struct bgin_btree *, void *, void *);
static int *bgin_btree_delete(struct bgin_btree *, void *, void *);
static struct btree_node * bgin_btree_getchild(struct bgin_btree *, size_t index);


static int *bgin_btree_get(struct bgin_btree *btree, void *key, void *value){

		size_t i = 0;
		struct btree_node *node = btree->root;

		if(node == NULL || key == NULL || value == NULL)
			return -1;



}


static uint64_t bgin_btree_search(struct btree *node, void *key){

	size_t i;

	while(i <= node->key_filled && key>node->key[i])
		i++;

	if(i<= node->key_filled && (key == node->key[i]))
		return value_offset[i];

	if(node->leaf){
		return -1;

	}else{
		node = bgin_btree_getchild(node, i);
		return bgin_btree_search(node, key);
	}


}


static struct btree_node * bgin_btree_getchild(struct btree_node *node, size_t index){


		char *format_buffer = malloc(1000);
		struct btree_node *node_n = malloc(sizeof(struct btree_node));
		uint64_t child_offset = node->children[index];

		snprintf(format_buffer, 1000, "ui8, ui16, ui64[%d], ui64[%d], ui64[%d], ui32", BTREE_MAX_KEYS, BTREE_MAX_KEYS, BTREE_MAX_CHILD);
		de_cereal(fd_index , format_buffer, &node_n->leaf, &node_n->key, &node_n->value_offset, &node_n->children, &node_n->offset, &node_n->keys-filled);
		return node_n;



}



bgin_handle * bgin_init(BGIN_LOGGING canlog, ...){

	bgin_handle *bgindb;
	if((bgindb = malloc(sizeof(bgin_handle))) == NULL)
		_bgin_err_die("BginDB: failed to initialize db instalnce\n");

	bgindb->canlog = canlog;

	if(canlog == ENABLED){
		va_list ap;
		va_start(ap, canlog);
		bgindb->logmode = va_arg(ap, BGIN_LOG_MODES);
		va_end(ap);
	}

	return bgindb;
}


int * bgin_open(bgin_handle *bgindb, const char *filepath){

	int length;
	//bgin_handle *main_handle = malloc(sizeof(bgin_handle));

	if(bgindb == NULL){

		//write log

	}

	length = strlen(filepath);
	if(length == 0)

	bgin_handle_internal *db_internal = malloc(sizeof(bgin_handle_internal)
	db_internal->index_path = malloc(length + 6);
	db_internal->data_path = malloc(length + 5);

	sprintf(db_internal->index_path, "%s.index", filepath);
	sprintf(db_internal->data_path, "%s.data", filepath);




}

static void _bgin_err_die(const char *format, ...){

	va_list ap;
	va_start(ap, format);
	_bgin_err_core(format, ap);
	va_end(ap);
	exit(1);
}


static void _bgin_err_throw(const char *format, ...){

}



static void _bgin_err_core(const char *format, va_list ap){

	char buf[4096];
	vsprintf(buf, format, ap);
	strcat(buf, "\n");
	fputs(buf, stderr);

}
