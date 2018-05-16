#include<iostream>
using namespace std;
int function(int a, int b)
{
	return a%b;
}
int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int * HashTable;
		int N, M, K;
		int temp;
		cin >> N >> M >> K;
		if (K > M)
		{
			cout << "0" << endl;
			continue;
		}
		HashTable = new int[M];
		for (int i = 0; i < M; i++)
		{
			HashTable[i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			HashTable[function(temp, M)]++;
		}
		cout << HashTable[K] << endl;
	}
}