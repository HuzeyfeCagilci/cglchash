#ifndef MY_HPP
#define MY_HPP

#include <string>

using namespace std;

class my_hash
{
  public:
    long code;
    my_hash();
    void set();
    void update(int code);
    void update(string str);
    void update_array(int *array, int size);
    void update_array(char *array, int size);
    // convert to int and update
    void convert_and_update(char code);
    void convert_and_update_array(char *array, int size);
    void hash_file_sep(char *filename);
    void hash_file(char *filename);
    int update_from_file(char *filename);
};

class my_hash2 : public my_hash
{
  public:
    void update(int code);
};

void msg_from(string source, string text);
void print_my(string text);

#define TABLE_SIZE 16

int table[] = {16421, 55381, 53923, 56659, 11251, 39323, 58451, 88747,
               64601, 84809, 82811, 34351, 21757, 77951, 50129, 90677};

#endif // MY_HPP