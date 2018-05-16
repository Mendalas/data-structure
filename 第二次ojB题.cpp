/*#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int work;
template<class element>
class BinaryTreeNode
{
public:
	element value;
	BinaryTreeNode* left;
	BinaryTreeNode * right;
	BinaryTreeNode * iterator;
	BinaryTreeNode()
	{
		left = NULL;
		right = NULL;
	}
	BinaryTreeNode(element& temp)
	{
		value = temp;
		left = NULL;
		right = NULL;
	}
	void SetLeft(BinaryTreeNode *Left)
	{
		left = Left;
	}
	void SetRight(BinaryTreeNode *Right)
	{
		right = Right;
	}
	void insert(BinaryTreeNode *node,element E)
	{
		if (node->left == NULL)
		{
			iterator = new BinaryTreeNode<element>(E);
			work = 0;
			node->SetLeft(iterator);
			return;
		}
		else if(node->right==NULL)
		{
			iterator = new BinaryTreeNode<element>(E);
			work = 0;
			node->SetRight(iterator);
			return;
		}
	}
	void load(BinaryTreeNode* node, char Char)
	{
		if (node == NULL || (node->value >= 'A'&&node->value <= 'Z'))return;
		load(node->left, Char);
		load(node->right, Char);
		if (work) insert(node,Char);
	}
	void levelorder(BinaryTreeNode*root, int level) {
		if (!root || level < 0)return;
		else if (level == 0) {
			cout << root->value;
		}
		else {
			levelorder(root->left, level - 1); levelorder(root->right, level - 1);
		}
	}
	void travel(BinaryTreeNode* node)
	{
		if (node == NULL)return;
		travel(node->left);
		travel(node->right);
	}
	int height(BinaryTreeNode* root)
	{
		if (root == NULL)return 0;
		else return max(height(root->left), height(root->right)) + 1;
	}
	bool Isbalance(BinaryTreeNode* root)
	{
		int temp1, temp2;
		if (root->left == NULL)
		{
			temp2 = abs(height(root->left) - height(root->right));
			if (temp2 <= 1)
				return true;
			else return false;
		}
		if (root->right == NULL)
		{
			temp2 = abs(height(root->left) - height(root->right));
			if (temp2 <= 1)
				return true;
			else return false;
		}
		
		temp1 = abs(height(root->left) - height(root->right));
		if ((temp1<=1)&&Isbalance(root->left)&&Isbalance(root->right))
			return true;
		else return false;
	}
};

int main()
{
	int n;
	cin >> n;
	work = 1;
	for (int j = 0; j < n; j++)
	{
		string tree;
		cin >> tree;

		BinaryTreeNode<char>* root = new BinaryTreeNode<char>(tree[0]);
		for (int i = 1; i < tree.size(); i++)
		{
			work = 1;
			root->load(root, tree[i]);
		}

		
		for (int i = 0; i < 999; i++)
		{
			root->levelorder(root,i);
		}
		cout << endl;
	}
}*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef struct Node
{
	int weight;
	char value;
	int left;
	int right;
	int parent;
}HTNode, *HuffTree;
int min(HuffTree HT, int& k)
{
	int i = 0;
	int min;
	int min_weight;
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;
	for (; i<k; i++)
	{
		if (HT[i].weight<min_weight&&HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}
	HT[min].parent = 1;
	return min;
}
HuffTree create_HuffmanTree(int *wet, char * val, int n)
{
	int total = 2 * n - 1;
			
	HuffTree HT = new HTNode[total];
	int i;
	for (i = 0; i<n; i++)
	{
		HT[i].parent = -1;
		HT[i].left = -1;
		HT[i].right = -1;
		HT[i].weight = wet[i];
		HT[i].value = val[i];
	}
	for (i = n; i<total; i++)
	{
		HT[i].parent = -1;
		HT[i].left = -1;
		HT[i].right = -1;
		HT[i].weight = 0;

	}

	for (i = n; i<total; i++)
	{
		int small1, small2;
		small1 = min(HT, i);
		small2 = min(HT, i);
		HT[small1].parent = i;
		HT[small2].parent = i;
		HT[i].left = small1;
		HT[i].right = small2;
		HT[i].weight = HT[small1].weight + HT[small2].weight;
	}
	return HT;
}


int HuffCode(HuffTree HT, string s)
{

	int size = s.size();
	int count = 0;

	int i = 0;
	for (int j = 0; j<size; j++)
	{
		while (HT[i].value != s[j])
		{
			i++;

		}
		while (HT[i].parent != -1)
		{
			count++;
			i = HT[i].parent;
		}
		i = 0;

	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int number;
		int size;
		int * wet = new int[size];
		char *val = new char[size];


		cin >> size;
		for (int i = 0; i<size; i++)
		{
			cin >> val[i];
			cin >> wet[i];
		}

		HuffTree HT = create_HuffmanTree(wet, val, size);
		string test;
		cin >> test;
		int total;
		total = HuffCode(HT, test);
		cout << total << endl;
	}
}

