#include <algorithm>
#include <iostream>
#include<sstream>
using namespace std;
void inssort(int A[], int n,int& count)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; (j > 0) && (A[j] < A[j - 1]); j--)
		{
			swap(A[j], A[j - 1]);
			count++;
		}
	}
}
int main()
{
	stringstream sin;
	int test;
	cin >> test;
	cin.ignore();
	int temp[1100];
	for (int i = 0; i < test; i++)
	{
		string number;
		cin>>number;
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == ',')
				number[i] = ' ';
		}
		sin.clear();
		sin.str(number);
		int Temp;
		int count=0;
		int j=0;
		while (sin >> Temp)
		{
			temp[j] = Temp;
			j++;
		}
		inssort(temp, j, count);
		cout << count << endl;
	}
	system("pause");
}
