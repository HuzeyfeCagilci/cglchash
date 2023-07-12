#include <iostream>
#include <cstring>
#include "my.hpp"
#include "main.hpp"

using namespace std;

void help()
{
	cout << endl << endl <<
	"-rf	read from file" << endl <<
	"-f	hash file" << endl <<
	"-fl	hash file line by line" << endl;
}

void rf(char *arg)
{
	my_hash hs;
	hs.update_from_file(arg);
	cout << hex << hs.code << endl;
}

void f(char *arg)
{
	my_hash hs;
	hs.hash_file(arg);
	cout << "file hashed and writed to mhs file" << endl;
}

void fl(char *arg)
{
	my_hash hs;
	hs.hash_file_sep(arg);
}

void init()
{
	cmdf[0].str = "-rf";
	cmdf[0].fun = rf;
	
	cmdf[1].str = "-f";
	cmdf[1].fun = f;

	cmdf[2].str = "-fl";
	cmdf[2].fun = fl;
}

int main(int arg, char **argv)
{
	init();	
	//print_my("It successfully executed\n");
	cout << endl;
	msg_from("cglc hash", "");

	if(arg < 2)
	{
		help();
	}
	else if(arg < 3)
	{
		my_hash hs;
		hs.update(argv[1]);
		cout << hex << hs.code << endl;
	}
	else
	{
		for(auto i = 1; i < arg; i++)
		{
			for(auto j = 0; j < cmdlen; j++)
			{
				if(strcmp(argv[i],cmdf[j].str.c_str())==0)
				{
					cmdf[j].fun(argv[i+1]);
				}
			}
		}
	}

	cout << endl;
	return 0;
}