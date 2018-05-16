#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int H(int k,int n)
{
	return k%n;
}
int main()
{
	int n;
	cin >> n;
	int * HashTable;
	HashTable = new int[n];
	for (int i = 0; i < n; i++)
	{
		HashTable[i] = -9999999;
	}
	int temp;
	int index;
	int j=0;
	string Number;
	stringstream sin;
	cin.ignore();
	getline(cin,Number);
	sin.str(Number);
	while (sin >> temp)
	{
		index = H(temp, n);
		if (HashTable[index] == -9999999)
			HashTable[index] = temp;
		else while (HashTable[index] != -9999999)
		{
			index = (++index) % n;
		}
		HashTable[index] = temp;
	}
		for (int i = 0; i < n; i++)
		{
			if (HashTable[i] != -9999999)
			{
				cout << i << ' ' << HashTable[i]<<endl;
			}
		}
		system("pause");
}