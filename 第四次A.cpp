#include<iostream>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
struct node
{
	string value;
	double fre;
	bool operator <(const node& a ) const
	{
		return fre>a.fre;
	}
	node (const node&a)
	{
		value=a.value;
		fre=a.fre;
	}
	node()
	{
		value="";
		fre=0;
	}
	node(string s,int lev ,double freq)
	{
		value=s;
		fre=freq;
	}
	node(char s,double freq)
	{
		value=s;
		fre = freq;
	}
};
int main()
{
	int test;
	cin>>test;
	for(int i=0;i<test;i++)
	{
		priority_queue<node> heap;
		int many;
		cin>>many;
		int frequency;
		char Char;
		int  level[300] = {0};

		for(int j=0;j<many;j++)
		{
			cin>>Char;
			cin>>frequency;
			node temp (Char,frequency);
			heap.push(temp);
		}
		while(heap.size()!=1)
	 {
		node temp_1;
		node temp_2;
		temp_1=heap.top();
		heap.pop();
		temp_2=heap.top();
		heap.pop();
		node temp_3;
		temp_3.value = temp_2.value + temp_1.value;
		temp_3.fre=temp_1.fre+temp_2.fre;
		for (int j = 0; j < temp_3.value.size(); j++)
		{
			level[temp_3.value[j]]++;
		}
		heap.push(temp_3);
	 }
		string TEMP;
		cin >> TEMP;
		int sum = 0;
		for (int j = 0; j < TEMP.size(); j++)
		{
			sum += level[TEMP[j]];
		}
		cout << sum<<endl;
	}
}