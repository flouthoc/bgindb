#include "bgindb.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>	
#include <stdlib.h>	
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>


bgin_handle * bgin_init(BGIN_LOGGING canlog, ...){

	bgin_handle *bgindb;
	if((bgindb = malloc(sizeof(bgin_handle))) == NULL)
		exit(1);
		//_bgin_err_die("BginDB: failed to initialize db instalnce\n");

	bgindb->canlog = canlog;

	if(canlog == ENABLED){
		va_list ap;
		va_start(ap, canlog);
		bgindb->logmode = va_arg(ap, BGIN_LOG_MODES);
		va_end(ap);
	}

	return bgindb;
}


/*int * bgin_open(const char *filepath){

	int length;
	//bgin_handle *main_handle = malloc(sizeof(bgin_handle));
	length = strlen(filepath);
	if(length == 0)

	bgin_handle_internal *db_internal = malloc(sizeof(bgin_handle_internal)
	db_internal->index_path = 


}*/
