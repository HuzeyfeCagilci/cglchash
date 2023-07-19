#include <iostream>

void help();
void init();

#define cmdlen 4

struct funs
{
	string str;
	void (*fun)(char **arg);
};

struct funs cmdf[cmdlen];
