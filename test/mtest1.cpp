#include <iostream>
#include "my.hpp"

using namespace std;

int cross(int * data, int len)
{
	int val=0,ret=0;

	for(auto i=0; i<len; i++)
	{
		val=data[i];

		for(auto j=i+1; j<len; j++)
		{
			if(val==data[j]) 
			{
				ret++;
				cout << dec;
				cout << "i: " << i << " j: " << j << endl;
			}
		}
	}

	return ret;
}

int main(int, char **)
{
	msg_from("test.cpp", "Hello from test program.");
	print_my("It successfully executed\n");

	my_hash hs;

	int array[12] = {
		789163814, 140917789, 24124984, 1846184685, 45891564,
		48864846, 6846184, 4555642, 15, 8965, 488485, 98123784};

	char str[] = "Huzeyfe Çağılcı iyi ki doğmuş.";

	hs.update(0);
	cout<<hex<<hs.code<<endl;
	
	hs.update_array(str, 41);
	cout<<hex<<hs.code<<endl;
	
	hs.update_array(array, 12);
	cout<<hex<<hs.code<<endl;
	
	hs.update(1769);
	cout<<hex<<hs.code<<endl;
	


	hs.update(0);
	cout<<hex<<hs.code<<endl;

	hs.update(0);
	cout<<hex<<hs.code<<endl;

	my_hash2 hs3;
	char txt[]="../sample3.txt";
	hs3.update_from_file(txt);
	cout<<hex<<hs3.code<<endl;

	my_hash hs2;
	char txt2[]="../sample3.txt";
	hs2.hash_file_sep(txt2);
	
	return 0;
}
