#include <iostream>
#include <fstream>
#include <cstring>
#include "my.hpp"

void msg_from(string source, string text)
{
	cout << "[" << source << "]\t" << text;
}

void print_my(string text)
{
	msg_from("my.cpp", text);
}

void my_hash::set()
{
	code = 20050706;
}

my_hash::my_hash()
{
	set();
}

void my_hash::update(int code_)
{
	code = table[(code ^ code_) % TABLE_SIZE] + ((code * 31) ^ (code_ * 19));
}

void my_hash2::update(int code_)
{
	code = (code * 59) + (code_ * 19) + table[(code ^ code_) % TABLE_SIZE] * (code - code_);
}

void my_hash::update_array(int *array, int size)
{
	for (auto i = 0; i < size; i++)
	{
		update(array[i]);
	}
}

void my_hash::update_array(char *array, int size)
{
	convert_and_update_array(array, size);
}

void my_hash::convert_and_update(char code)
{
	update((int)code);
}

void my_hash::convert_and_update_array(char *array, int size)
{
	for (auto i = 0; i < size; i++)
	{
		update((int)array[i]);
	}
}

int my_hash::update_from_file(char * filename)
{
	ifstream file(filename);

	string text;
	while (getline(file, text))
	{
		update(text);
	}

	file.close();
	return 0;
}

void my_hash::update(string str)
{
	char *chr = new char[str.length() + 1];
	strcpy(chr, str.c_str());
	update_array(chr, str.length() + 1);
}

void my_hash::hash_file(char * filename)
{
	string fl(filename);
	ifstream inp(filename);
	ofstream out(fl + ".mhs");
	string line;

	while (getline(inp, line))
	{
		update(line);
	}

	out << hex << code << endl;

	inp.close();
	out.close();
}

void my_hash::hash_file_sep(char * filename)
{
	string fl(filename);
	ifstream inp(filename);
	ofstream out(fl + ".mhs");
	string line;

	while (getline(inp, line))
	{
		set();
		update(line);
		out << hex << code << endl;
	}

	set();

	inp.close();
	out.close();
}
