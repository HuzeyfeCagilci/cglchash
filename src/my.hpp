#include <iostream>

using namespace std;

class my_hash
{
public:
	int code;
	my_hash();
	void set();
	void update(int code);
	void update(string str);
	void update_array(int *array, int size);
	void update_array(char *array, int size);
	// convert to int and update
	void convert_and_update(char code);
	void convert_and_update_array(char *array, int size);
	void hash_file_sep(char * filename);
	void hash_file(char * filename);
	int update_from_file(char * filename);
};

class my_hash2 : public my_hash
{
public:
	void update(int code);
};

void msg_from(string source, string text);
void print_my(string text);

#define TABLE_SIZE 8

int table[] = {0xabcdef1, 0x6a2b54ef, 0xf9bc787, 0xcbe7a84,
			   0x38f5c8a, 0x25afe011, 0x5acfe2b, 0x4a3e427c};
