#include <iostream>
#include<stack>
#include<queue>
#include<list>
#define Infienty 9999999
#define visted -10000
#define unvisted -100000
using namespace std;
//第一题=====================================
/*
struct temppoint
{
	int value;
	int marked;
};

void dijitra(int* graph[],int start,temppoint * get,int size)
{
	for (int i = 0; i < size; i++)
	{
		get[i].value = Infienty;
		get[i].marked = unvisted;
	}
	temppoint MinIndex;
	MinIndex.value = Infienty;
	int count = 0;
	int point = start;
	get[point-1].value = 0;
	get[point-1].marked = visted;

	while (count < size) 
	{
		MinIndex.value = Infienty;

		for (int i = 0; i < size; i++)
		{
			if ((get[point-1].value+(graph[point-1][i]) < get[i].value)&&(get[i].marked==unvisted))
				get[i].value = get[point-1 ].value + graph[point - 1][i];
			if ((get[i].value < MinIndex.value) && (get[i].marked == unvisted))
			{
				MinIndex.marked = i;
				MinIndex.value = get[i].value;
			}
		}
		get[MinIndex.marked].marked = visted;
		point = MinIndex.marked+1;
		count++;
		for(int i=0;i<size;i++)
			cout << get[i].value << " ";
		cout << endl;
	}
	
}
int main()
{
	int N, C, S, T;
	cin >> N >> C >> S >> T;
	int **graph;
	graph = new int *[N];
	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if(i!=j)graph[i][j] = Infienty;
			else graph[i][j] = 0;
	}
	int from, to, weight;
	for (int i = 0; i < C; i++)
	{
		cin >> from >> to >> weight;
		if (weight < graph[from - 1][to - 1])
		{
			graph[from - 1][to - 1] = weight;
			graph[to - 1][from - 1] = weight;
		}
	}

	cout << endl;
	temppoint *get;
	get = new temppoint[N];
	dijitra(graph, S, get, N);
	cout << get[T-1].value << endl;
	system("pause");
}*/


//第二题==========================================================


int main()
{
	int M;
	cin >> M;
	while (M--)
	{
		int N, C;
		cin >> N >> C;

		
		int * indegree;
		indegree = new int[N];
		for (int i = 0; i < N; i++)
			indegree[i] = 0;

		int from, to;
		for (int i = 0; i < C; i++)
		{
			cin >> from >> to;
			indegree[to]++;
		}


		int max = -100000;
		for (int i = 0; i < N; i++)
			if (indegree[i] > max)
				max = indegree[i];
		cout << max << endl;
	}
	system("pause");
}

//第三题==================================================
/*
int main()
{
	int M;
	cin >> M;
	while (M--)
	{
		int N, C;
		cin >> N >> C;
		int **graph;
		graph = new int *[N];
		for (int i = 0; i < N; i++)
			graph[i] = new int[N];


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				graph[i][j] = 0;
		}


		int from, to;
		for (int i = 0; i < C; i++)
		{
			cin >> from >> to;
			graph[from - 1][to - 1] = 1;
		}
		int * indegree;
		indegree = new int[N];
		int sum;

		for (int j = 0; j < N; j++)
		{
			sum = 0;
			for (int i = 0; i < N; i++)
				sum += graph[i][j];
			indegree[j] = sum;
		}

		queue<int> Queue;

		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (indegree[i] == 0)
			{
				Queue.push(i);
			}
		}

		while (!Queue.empty())
		{
			int temp;
			temp = Queue.front();
			Queue.pop();
			count++;
			for (int i = 0; i < N; i++)
			{
				if (graph[temp][i] != 0)
				{
					indegree[i]--;
					if (indegree[i] == 0)
					{
						Queue.push(i);
					}
				}

			}
		}
		if (count == N)
			cout << "NO" << endl;
		else cout << "YES" << endl;
			}
}*//*
struct temppoint
{
	int value;
	int marked;
};
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int N, e, s;
		cin >> N>>e>>s;
		temppoint **graph;
		graph = new temppoint *[N];
		for (int i = 0; i < N; i++)
		{
			graph[i] = new temppoint[N];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j].value = 0;
				graph[i][j].marked = unvisted;
			}
		}

		int from, to;
		for (int i = 0; i < e; i++)
		{
			cin >> from >> to ;
			graph[from][to].value = 1;
			graph[to][from].value = 1;
	
		}

		stack<int> Stack;
		temppoint *get;
		temppoint *result;
		get = new temppoint[N];
		result= new temppoint[N];

		int count=1;

		for (int i = 0; i < N; i++)
		{
			get[i].marked = unvisted;
		}
		Stack.push(s);
		get[s].marked = visted;
		result[0].value = s;

		while (!Stack.empty())
		{
			int temp;
			temp = Stack.top();
			Stack.pop();

			for (int i = 0; i < N; i++)
			{
				if (graph[temp][i].value != 0&&get[i].marked==unvisted)
				{
					result[count].value = i;
					Stack.push(i);
					Stack.push(i);
					get[i].marked = visted;
					count++;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			cout << result[i].value;
			if (i != N - 1)
			cout << ' ';
		}
		cout << endl;
	}
}*/
