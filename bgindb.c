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


/*Declarations*/
static void _bgin_err_throw(const char *, ...);
static void _bgin_err_die(const char *, ...);
static void _bgin_err_core(const char *, va_list);




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
		_bgin_err_die


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
