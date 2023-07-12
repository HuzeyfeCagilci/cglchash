#include <iostream>
#include "my.hpp"

using namespace std;

// count the conflicts
int conflict(int *data, int len)
{
	int val = 0, ret = 0;

	for (auto i = 0; i < len; i++)
	{
		val = data[i];

		for (auto j = i + 1; j < len; j++)
		{
			if (val == data[j])
			{
				ret++;
				cout << dec;
				cout << "i: " << i << " j: " << j << endl;
			}
		}
		if (i % 1000 == 0)
		{
			cout << "Step: " << dec << i << endl;
		}
	}

	cout << "Step: " << dec << len << endl;

	return ret;
}

int main()
{

#define datalen 100000

	int *data = new int[datalen];

	my_hash2 hs;

	for (auto i = 0; i < datalen; i++)
	{

		hs.update(i);
		data[i] = hs.code;

		// cout << endl;
	}

	/*for(auto i=0; i<100; i++)
	{
		cout << hex << data[i]<<endl;
	}*/

	int con = conflict(data, datalen);

	msg_from("mtest2", "");
	cout << "conflict = " << dec << con << endl;
	;

	/*int * data2 = new int[datalen];

	my_hash2 hs2;

	for(auto i=0; i<datalen; i++)
	{

			hs2.update(i);
			data2[i]=hs2.code;

		//cout << endl;
	}

	cout << "cross = " << dec << cross(data2, datalen) << endl;;
	*/
	return 0;
}
