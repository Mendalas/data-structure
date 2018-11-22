#include<iostream>
#include<algorithm>
using namespace std;
int DOVE = 0;

bool IsPrimeNmuber(int Number)
{
	for (int i = 2; i <= sqrt(Number); i++)
		if (Number%i == 0 && i != Number)
			return false;
	return true;
}
int FindTheMinCommon(int a, int b)
{
	int MAX, MIN;
	MAX = max(a, b);
	MIN = min(a, b);
	DOVE++;
	if ((MAX%MIN) == 0)
		return MIN;
	return FindTheMinCommon(MAX%MIN, MIN);
}
int R(int a, int b, int j)
{
	if (j == -2)
		return a;
	if (j == -1)
		return b;
	return (R(a, b, j - 2) % R(a, b, j - 1));
}
int Q(int a, int b, int j)
{
	return ((R(a, b, j - 2) / R(a, b, j - 1)));
}
int T(int a, int b, int j)
{
	if (j == -2)
		return 0;
	if (j == -1)
		return 1;
	return((-Q(a, b, j))*T(a, b, j - 1) + T(a, b, j - 2));
}
int S(int a, int b, int j)
{
	if (j == -2)
		return 1;
	if (j == -1)
		return 0;
	return ((-Q(a, b, j))*S(a, b, j - 1) + S(a, b, j - 2));
}
int fai(int m)
{
	if (IsPrimeNmuber(m))
		return m - 1;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (FindTheMinCommon(i, m) == 1)
			count++;
	}
	return count;
}
int i_1(int i, int j)
{
	//int i, j;
	//while (cin >> i >> j)
	DOVE = 0;
	int temp, t, s;
	int MAX, MIN;
	MAX = max(i, j);
	MIN = min(i, j);
	temp = FindTheMinCommon(i, j);
	//cout << temp << endl;
	t = T(MAX, MIN, DOVE - 2);
	s = S(MAX, MIN, DOVE - 2);
	if (MAX == i)
	{
		return s;
		//cout << s << " " << t << " " << endl;
		//cout << s*i + j*t << endl;
	}
	else
	{
		return t;
		//cout << t << " " << s << " " << endl;
		//cout << t*i + s*j << endl;
	}
}
int abm(int number, int chengfang, int m)
{
	int a = 1;
	int b = number;
	while (chengfang != 1)
	{
		int temp;
		temp = chengfang % 2;
		if (temp == 0)
		{
			chengfang /= 2;
			b = (b*b) % m;
			continue;
		}
		else a = (a*b) % m;
		chengfang /= 2;
		b = (b*b) % m;
	}
	a = (a*b) % m;
	return a;
}
int main()
{
	cout << "please input two prime number" << endl;
	int p, q, n;
	while (cin >> p >> q)
	{
		if (IsPrimeNmuber(p) && IsPrimeNmuber(q))
		{
			n = p*q;
			int Fai = fai(p)*fai(q);
			int e=13;
			for (int i = 2; i < Fai; i++)
			{
				if (FindTheMinCommon(i, Fai) == 1)
				{
					e = i;
					break;
				}
			}
			cout << "the common key n is " << n << " and the e is " << e << endl;
			int d;
			d = i_1(e, Fai);
			cout << "please input a number that you want to encrypt" << endl;
			int c,m;
			cin >> m;
			c = abm(m, e, n);
			cout << "the result after encrypted is" << c << endl;
			cout << "the result after decrypted is" << abm(c,d,n) << endl;
			cout << "please input two prime number" << endl;
		}
		else cout << "please cout right number" << endl;
	}
}
