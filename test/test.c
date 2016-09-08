#include "bgindb.h"
#include <stdio.h>

int main(){

	bgin_handle *bgin_db;
	bgin_db = bgin_init(ENABLED, LOG_MODE_CONSOLE);
	fputs(bgin_db->test, stdout);

	return 0;
}

