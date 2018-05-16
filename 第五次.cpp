#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	int test;
	int* numbers;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int n, k;
		cin >> n >> k;
		numbers = new int[n];
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> numbers[i];
		}
		sort(numbers,numbers+n,cmp);
		cout << numbers[k - 1] << endl;
	}
}












/*
void SiftDown(int node, int* &heap,int n)
{
	int lc, rc, j;
	if (node >= (n / 2))return;
	while (node <(n / 2))
	{
		lc = node * 2 + 1;
		rc = node * 2 + 2;
		if (rc >= n)return;
		if (heap[lc] < heap[rc])
			j = lc;
		else j = rc;
		if (heap[node]< heap[j])
			return;
		int temp = heap[node];
		heap[node] = heap[j];
		heap[j] = temp;
		node = j;
	}
}
int main()
{
	int temp;
	int *numbers = new int[100000],*number=new int [100000];
	int j = 0;
	priority_queue<int> heap;
	cin >> temp;
	while (cin.get() == ' ')
	{
		numbers[j] = temp;
		heap.push(temp);
		cin >> temp;
		j++;
	}
	numbers[j] = temp;
	heap.push(temp);
	j++;
	for (int i = (j / 2) - 1; i >= 0; i--)
	{
		SiftDown(i, numbers, j);
	}
	for (int i = 0; i < j; i++)
	{
		cout << numbers[i];
		if (i != j - 1)
		   cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < j; i++)
	{
		temp = heap.top();
		number[i] = temp;
		heap.pop();
	}
	for (int i = 0; i < j; i++)
	{
		cout << number[i];
		if (i != j - 1)
			cout << ' ';
	}
	cout << endl;
}*/