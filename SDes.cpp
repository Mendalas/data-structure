#include<iostream>
#include<bitset>
using namespace std;
const int p_10[10]={3,5,2,7,4,10,1,9,8,6};
bitset<5> LK1;
bitset<5> RK1;
bitset<10>  key_10;
void getSubkey()
{
    cout<<"please input the 10bits key"<<endl;
    bool bit;
    for(int i=0;i<10;i++)
        {
            cin>>bit;
            key_10[i]=bit;
        }
    bitset<10> temp;

    for(int i=0;i<10;i++)
        temp[i]=key_10[p_10[i]];
    
    for(int i=0;i<5;i++)
        {
            LK1[i]=temp[i];
            RK1[i]=temp[5+i];
        }

}

bitset<5> left(bitset<5>)
{
}
int main()
{
    system("pause");

}
