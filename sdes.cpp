#include<iostream>
#include<bitset>
using namespace std;
//const int p_10[10]={3,5,2,7,4,10,1,9,8,6};

const int p_10[10] = { 6,8,9,1,10,4,7,2,5,3 };

//const int p_8[8]={6,3,7,4,8,5,10,9};

const int p_8[8] = { 9,10,5,8,4,7,3,6 };

//const int ip[8]={2,6,3,1,4,8,5,7};

const int ip[8] = { 7,5,8,4,1,3,6,2 };

//const int ip_1[8]={4,1,3,5,7,2,8,6};

const int ip_1[8] = { 6,8,2,7,5,3,1,4 };

//const int EP[8] = { 1,4,3,2,3,2,1,4 };

const int EP[8] = { 4,1,2,3,2,3,4,1 };

//const int P4[4] = { 2,4,3,1 };

const int P4[4] = { 1,3,4,2 };

const int S0[4][4] = { 1,0,3,2,
					   3,2,1,0,
	                   0,2,1,3,
	                   3,1,3,2 };

const int S1[4][4] = { 0,1,2,3,
					   2,0,1,3,
	                   3,0,1,0,
	                   2,1,0,3 };

const int SW[8] = { 5,6,7,8,1,2,3,4 };

const string table[4] = { "00","01","10","11" };

bitset<5> LK1;
bitset<5> RK1;
bitset<10>  key_10;
bitset<8> Subkey_1;
bitset<8> Subkey_2;

void left(bitset<5>& a)
{
	bool temp = a[4];
	a=a << 1;
	a[0] = temp;
}
void right(bitset<5>& a)
{
	bool temp = a[0];
	a=a >> 1;
	a[4] = temp;
}
void getSubkey()
{
	// bitset<5> LK1;
	// bitset<5> RK1;
	cout << "please input the 10bits key" << endl;
	cin >> key_10;

	bitset<10> temp;
	bitset<10> temp10;
	for (int i = 0; i < 10; i++)
		temp10[i] = key_10[9 - i];

	for (int i = 0; i<10; i++)
		temp[i] = temp10[p_10[i] - 1];

	for (int i = 0; i<5; i++)
	{
		RK1[i] = temp[i];
		LK1[i] = temp[5+i];//something wrong
	}
	left(LK1);
	left(RK1);

	for (int i = 0; i<5; i++)
	{
		temp[i] = RK1[i];
		temp[5 + i] = LK1[i];
	}


	for (int i = 0; i<8; i++)//getSubkey
	{
		Subkey_1[i] = temp[9-p_8[i]+ 1];
	}


//	cout << LK1 << endl;
	left(LK1);
//	cout << LK1 << endl;
	left(LK1);
//	cout << LK1 << endl;

	left(RK1);
	left(RK1);

	for (int i = 0; i<5; i++)
	{
		temp[5 + i] = LK1[i];
		temp[i] = RK1[i];
	}


	for (int i = 0; i<8; i++)//getSubkey
	{
		Subkey_2[i] = temp[9-p_8[i] + 1];
	}

	cout << "the subkey_1 is " << Subkey_1<<endl;
	cout << "the subkey_2 is " << Subkey_2 << endl;

}
//==================================================


void Encrp(bitset<8> Message)
{
	bitset<8> temp,temp1;
	bitset<4> high, low;
	bitset<4> rk1, lk1;

	for (int i = 0; i<8; i++)
	{
		temp[i] = Message[7-ip[i] + 1];//p1
	}


	for (int i = 0; i<4; i++)
	{
		rk1[i] = temp[i];
		lk1[i] = temp[4 + i];
	}

	for  (int i = 0; i<8; i++)
	{
		temp[i] = rk1[3-EP[i] + 1];//EP(R)
	}
	temp = temp ^ Subkey_1;

	for (int i = 0; i<4; i++)
	{
		low[i] = temp[i];
		high[i] = temp[4 + i];
	}

	int S_0, S_1;
	int i, j;
	i = high[0]  + high[3] * 2;
	j = high[1]  + high[2] * 2;
	S_0 = S0[i][j];
	i = low[0]  + low[3] * 2;
	j = low[1]  + low[2] * 2;
	S_1 = S1[i][j];

	string p4 = "";
	p4 = table[S_0] + table[S_1];
	bitset<4> left(p4);
	bitset<4> left1(p4);

	for (int i = 0; i < 4; i++)
		left1[i] = left[ 3-P4[i] + 1];
	high = lk1 ^ left1;


	for (int i = 0; i<4; i++)
	{
		temp[4 + i] = high[i];
		temp[i] = rk1[i];
	}


//================================================================
	for (int i = 0; i<8; i++)
	{
		temp1[i] = temp[7-SW[i] + 1];//sw
	}

//===========================================================

	for (int i = 0; i<4; i++)
	{
		rk1[i] = temp1[i];
		lk1[i] = temp1[4 + i];
	}



	for (int i = 0; i<8; i++)
	{
		temp1[i] = rk1[3-EP[i] + 1];//EP(R)
	}
	temp1 = temp1 ^ Subkey_2;
	for (int i = 0; i<4; i++)
	{
		low[i] = temp1[i];
		high[i] = temp1[4 + i];
	}

	i = high[0]  + high[3] * 2;
	j = high[1]  + high[2] * 2;
	S_0 = S0[i][j];

	i = low[0]  + low[3] * 2;
	j = low[1]  + low[2] * 2;
	S_1 = S1[i][j];

	p4 = table[S_0] + table[S_1];
	bitset<4> LEFT(p4);
	bitset<4> LEFT1(p4);
	for (int i = 0; i < 4; i++)
		LEFT1[i] = LEFT[3 - P4[i] + 1];

	high = lk1 ^ LEFT1;


	for (int i = 0; i<4; i++)
	{
		temp1[4 + i] = high[i];
		temp1[i] = rk1[i];
	}


//================================================
	for (int i = 0; i < 8; i++)
	{
		temp[i] = temp1[7-ip_1[i] + 1];
	}

	cout <<"after encryp"<< temp<< endl;

	
}
//==================================================




void decode(bitset<8> message, bitset<8> key1, bitset<8> key2)
{
	bitset<8> temp, temp1;
	bitset<4> high, low;
	bitset<4> rk1, lk1;

	for (int i = 0; i<8; i++)
	{
		temp[i] = message[7 - ip[i] + 1];//p1
	}


	for (int i = 0; i<4; i++)
	{
		rk1[i] = temp[i];
		lk1[i] = temp[4 + i];
	}

	for (int i = 0; i<8; i++)
	{
		temp[i] = rk1[3 - EP[i] + 1];//EP(R)
	}
	temp = temp ^ key2;

	for (int i = 0; i<4; i++)
	{
		low[i] = temp[i];
		high[i] = temp[4 + i];
	}

	int S_0, S_1;
	int i, j;
	i = high[0] + high[3] * 2;
	j = high[1] + high[2] * 2;
	S_0 = S0[i][j];
	i = low[0] + low[3] * 2;
	j = low[1] + low[2] * 2;
	S_1 = S1[i][j];

	string p4 = "";
	p4 = table[S_0] + table[S_1];
	bitset<4> left(p4);
	bitset<4> left1(p4);

	for (int i = 0; i < 4; i++)
		left1[i] = left[3 - P4[i] + 1];
	high = lk1 ^ left1;


	for (int i = 0; i<4; i++)
	{
		temp[4 + i] = high[i];
		temp[i] = rk1[i];
	}


	//================================================================
	for (int i = 0; i<8; i++)
	{
		temp1[i] = temp[7 - SW[i] + 1];//sw
	}

	//===========================================================

	for (int i = 0; i<4; i++)
	{
		rk1[i] = temp1[i];
		lk1[i] = temp1[4 + i];
	}



	for (int i = 0; i<8; i++)
	{
		temp1[i] = rk1[3 - EP[i] + 1];//EP(R)
	}
	temp1 = temp1 ^ key1;
	for (int i = 0; i<4; i++)
	{
		low[i] = temp1[i];
		high[i] = temp1[4 + i];
	}

	i = high[0] + high[3] * 2;
	j = high[1] + high[2] * 2;
	S_0 = S0[i][j];

	i = low[0] + low[3] * 2;
	j = low[1] + low[2] * 2;
	S_1 = S1[i][j];

	p4 = table[S_0] + table[S_1];
	bitset<4> LEFT(p4);
	bitset<4> LEFT1(p4);
	for (int i = 0; i < 4; i++)
		LEFT1[i] = LEFT[3 - P4[i] + 1];

	high = lk1 ^ LEFT1;


	for (int i = 0; i<4; i++)
	{
		temp1[4 + i] = high[i];
		temp1[i] = rk1[i];
	}


	//================================================
	for (int i = 0; i < 8; i++)
	{
		temp[i] = temp1[7 - ip_1[i] + 1];
	}
	cout << "after encode" << temp << endl;


}


int main()
{
	while (true)
	{
		getSubkey();
		cout << "please input the message" << endl;
		bitset<8> message,message1;
		cin >> message;
		Encrp(message);
		cout << "please input the code" << endl;
		cin >> message;
		decode(message, Subkey_1, Subkey_2);
	}
		system("pause");
}
