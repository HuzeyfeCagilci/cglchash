#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "my.hpp"
#include "main.hpp"

using namespace std;

void help()
{
	cout << endl
		 << endl
		 << "-rf [file_path]\t\t\t\tread from file" << endl
		 << "-f [file_path]\t\t\t\thash file" << endl
		 << "-fl [file_path]\t\t\t\thash file line by line" << endl
		 << "-c [file_path] [mhs_file_path]\t\tcheck file with its '.mhs' file" << endl;
}

void rf(char **arg)
{
	my_hash hs;
	hs.update_from_file(arg[2]);
	cout << hex << hs.code << endl;
}

void f(char **arg)
{
	my_hash hs;
	hs.hash_file(arg[2]);
	cout << "file hashed and writed to mhs file" << endl;
}

void fl(char **arg)
{
	my_hash hs;
	hs.hash_file_sep(arg[2]);
}

void check_file(char **arg)
{
	string file1 = string(arg[2]);
	string file2 = string(arg[3]);
	my_hash hs;
	int count = 0;
	stringstream ss;

	hs.update_from_file(arg[2]);
	cout << file1 << endl;
	ifstream inp(file2);

	if (inp.fail())
	{
		cerr << "file not found: " << file2 << endl;
		exit(-1);
	}
	char chr = 'a';
	string st;

	while (chr != '\n')
	{
		chr = inp.get();
		st = st + chr;
		count++;
	}

	ss << hex << st;
	int x;
	ss >> x;

	msg_from("cglc hash", "");

	if (hs.code == x)
		cout << "hash codes are matching." << endl;
	else
		cout << "hash codes are not matching." << endl;
}

void init()
{
	cmdf[0].str = "-rf";
	cmdf[0].fun = rf;

	cmdf[1].str = "-f";
	cmdf[1].fun = f;

	cmdf[2].str = "-fl";
	cmdf[2].fun = fl;

	cmdf[3].str = "-c";
	cmdf[3].fun = check_file;
}

int main(int arg, char **argv)
{
	init();
	// print_my("It successfully executed\n");
	cout << endl;
	msg_from("cglc hash", "");

	if (arg < 2)
	{
		help();
	}
	else if (arg < 3)
	{
		my_hash hs;
		hs.update(argv[1]);
		cout << hex << hs.code << endl;
	}
	else
	{
		for (auto i = 1; i < arg; i++)
		{
			for (auto j = 0; j < cmdlen; j++)
			{
				if (strcmp(argv[i], cmdf[j].str.c_str()) == 0)
				{
					cmdf[j].fun(argv);
				}
			}
		}
	}

	cout << endl;
	return 0;
}