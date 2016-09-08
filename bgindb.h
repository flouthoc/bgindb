#ifndef BGIN_DB
#define BGIN_DB
#include <stdarg.h>
#include <sys/types.h>


#define KEY_LEN_MAX 1024;
#define VALUE_LEN_MAX 1024;



/*SwapXBytes functions are from yolinux.com*/

#define Swap2Bytes(val) \
 ( (((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00) )

// Swap 4 byte, 32 bit values:

#define Swap4Bytes(val) \
 ( (((val) >> 24) & 0x000000FF) | (((val) >>  8) & 0x0000FF00) | \
   (((val) <<  8) & 0x00FF0000) | (((val) << 24) & 0xFF000000) )

// Swap 8 byte, 64 bit values:

#define Swap8Bytes(val) \
 ( (((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | \
   (((val) >> 24) & 0x0000000000FF0000) | (((val) >>  8) & 0x00000000FF000000) | \
   (((val) <<  8) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | \
   (((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000) )






typedef enum{

	LOG_MODE_CONSOLE = 0,
	LOG_MODE_FILE = 1,
} BGIN_LOG_MODES;

typedef enum{

	ENABLED = 1,
	DISABLED = 0,
} BGIN_LOGGING;

struct _bgin_handle{


	int data_descriptor;
	int index_descriptor;
	int log_descriptor;
	uint64_t data_offset;
	uint64_t index_offset;
	char *index_path;
	char *data_path;
	char *log_path;
	BGIN_LOGGING canlog;
	BGIN_LOG_MODES logmode;
	char test[100]; /* Note :this must be removed later*/ 


	/*user-interface*/
	//int (*open)(const char *);
	//int (*close)();
	//char *(*get)(const char *);

};

typedef struct _bgin_handle bgin_handle;



bgin_handle *bgin_init(BGIN_LOGGING, ...);
//int bgin_open(const char *);
//int bgin_close(bgin_handle *);
//char *bgin_get(bgin_handle *, const char*);
//int *bgin_put(bgin_handle *, const char*, const *char);
//int *bgin_remove(bgin_handle *, const char*);

/*Error and logs*/







/*Utils*/


#endif
