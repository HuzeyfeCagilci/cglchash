#include <iostream>

void help();
void init();

#define cmdlen 3

struct funs
{
	string str;
	void (* fun)(char * arg);
};

struct funs cmdf[cmdlen];

