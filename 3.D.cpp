/*
#include <iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int Partition(int E[], int left, int right, int& pivot)
{
	while (left<right)
	{
		while (cmp(E[++left], pivot));
		while ((left < right) && cmp(pivot, E[--right]));
		swap(E[left], E[right]);
	}
	return left;
}
int main()
{
	int test;
	cin >> test;
	char c;
	int  number[1100];
	for (int i = 0; i < test+1; i++)
	{
		int k = 0;
		while (( c= getchar()) != '\n')
		{
			if (c <= '9'&&c >= '0')
			{
				ungetc(c, stdin);
					cin >> number[k++];
			}
		}
	int result=Partition(number, -1, k-1, number[k-1]);
	if (result == -1)
		;
	else cout << result<<endl;
	 }
}*//*
#include<iostream>
using namespace std;
int main()
{
	char c[10000] = {0};
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) 
	{
	    cin.get(c,10000).get();
		cout << c << endl;
		cout << "called" << endl;
	}
	system("pause");
}*/
#include <iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int Partition(int E[], int left, int right, int& pivot)
{
	while (left<right)
	{
		while (cmp(E[++left], pivot));
		while ((left < right) && cmp(pivot, E[--right]));
		swap(E[left], E[right]);
	}
	return left;
}
int main()
{
	int test;
	cin >> test;
	int temp[1100];
	int Temp;
	int j;
	stringstream sin;
	char number[20000];
	cin.ignore();
	for (int i = 0; i < test; i++)
	{
		for (int i = 0; i < 20000; i++)
		{
			number[i] = 0;
		}
		cin.getline(number, 20000);
		for (int i = 0; i < 20000; i++)
		{
			if (number[i] <= '9'&&number[i] >= '0')
				continue;
			else number[i] = ' ';

		}
		sin.clear();
		sin.str(number);
		j = 0;
		while (sin >> Temp)
		{
			temp[j] = Temp;
			j++;
		}
		int result = Partition(temp, -1, j - 1, temp[j - 1]);
		if (result == -1)
			i--;
		else cout << result << endl;
	}
}
