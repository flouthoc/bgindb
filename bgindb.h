#ifndef BGIN_DB
#define BGIN_DB
#include <stdarg.h>


#define KEY_LEN_MAX 1024;
#define VALUE_LEN_MAX 1024;


typedef enum{

	LOG_MODE_CONSOLE = 0,
	LOG_MODE_FILE = 1,
} BGIN_LOG_MODES;

typedef enum{

	ENABLED = 1,
	DISABLED = 0,
} BGIN_LOGGING;

typedef struct{


	int data_descriptor;
	int index_descriptor;
	int log_descriptor;
	off_t data_offset;
	off_t index_offset;
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

} bgin_handle;



bgin_handle *bgin_init(BGIN_LOGGING, ...);
//int bgin_open(const char *);
//int bgin_close(bgin_handle *);
//char *bgin_get(bgin_handle *, const char*);
//int *bgin_put(bgin_handle *, const char*, const *char);
//int *bgin_remove(bgin_handle *, const char*);

/*Error and logs*/





/*Utils*/


#endif
