#include<iostream>
#include<vector>
#include<string>
#include"sct.h"
#include<fstream>
#include<ostream>
using std::vector;
using std::ofstream;
using std::set;
using std::string;
using std::iostream;
using std::ostream;
using std::ifstream;
using std::ios;
using std::endl;
using std::cin;
using std::cout;
vector<student> studentdata;
vector<administrator> AdminData;
//初始化======================================================================
ifstream infile;
void student::StartStudentData()
{
	vector<student>::iterator it;
	it = studentdata.begin();
    string id;
	string name;
	string passwords;
	string securityproblem;
	string answer;
	infile.open("d:\studentdata.txt", ios::in);
	while (getline(infile, id)) {
		getline(infile, name);
		getline(infile, passwords);
		getline(infile, securityproblem);
		getline(infile, answer);
		student smallwork(id, name, passwords, securityproblem, answer);
		it=studentdata.insert(it, smallwork);
	}
	infile.close();
}
void administrator::StartAdminData()
{
	vector<administrator>::iterator it;
	it = AdminData.begin();
	string id;
	string name;
	string passwords;
	string securityproblem;
	string answer;
	infile.open("d:\AdminData.txt", ios::in);
	while (getline(infile, id)) {
		getline(infile, name);
		getline(infile, passwords);
		getline(infile, securityproblem);
		getline(infile, answer);
		administrator smallwork(id, name, passwords, securityproblem, answer);
		it = AdminData.insert(it, smallwork);
	}
	infile.close();
}
//结束====================================================================
ofstream outfile;
void student::OverStudentData()
{
	vector<student>::iterator it;
	outfile.open("d:\studentdata.txt", ios::out);
	for (it = studentdata.begin(); it != studentdata.end(); it++)
	{
		if (it->ID() == "bignews")
			continue;
		outfile << *it;
	}
	outfile.close();
}
void administrator::OverAdmintData()
{
	vector<administrator>::iterator it;
	outfile.open("d:\studentdata.txt", ios::out);
	for (it = AdminData.begin(); it !=AdminData.end(); it++)
	{
		if (it->ID() == "bignews")
			continue;
		outfile << *it;
	}
	outfile.close();
}
 ostream & operator << (ostream & output,  const user & a)
{
	 output << a.id << endl << a.name << endl << a.passwords << endl << a.securityproblem<< endl << a.answer << endl;
	 return output;
}
//初始化及构造函数=====================================================
 user::user(string i, string n, string p, string s, string a) :id(i), name(n), passwords(p), securityproblem(s), answer(a)
 {}
 administrator::administrator(string i, string n, string p, string s, string a) :user(i,n,p,s,a)
 {
	 ;
 }
student::student(string i, string n, string p, string s,string a):user(i,n,p,s,a)
{	;
}
string user:: ID()
{
	return id;
}
string user:: Name()
{
	return name;
}
string user::Passwords()  
{
	return passwords;
}
string user::SecurityProblem()
{
	return securityproblem;
}
string user::Answer()
{
	return answer;
}
void user::SetId(string s)
{
	id = s;
}void user::SetSecurity(string a)
{
	securityproblem = a;
}
void user::SetAnswer(string a)
{
	answer = a;
};
void user::SetPasswords(string a)
{
	passwords = a;
}
//注册================================================
void Regist()
{
	int b = 0;
	int bb = 0;
	string i;
	cout << "Nice to meet you ! my friends" << endl;
	while (cout << "please input an id you want." << endl) {
		getline(cin, i);
		vector<student>::iterator it;
		for (it = studentdata.begin(); it != studentdata.end(); it++)
		{
			if (i == it->ID())
			{
				cout << "there have such user  ";
				continue;

			}
		}
		break;
	}
	cout << "ok ,you have an id in our library, please input eight characters as your passwords which are used to login." << endl;
	string  n, p, pp;
	while (1) {
		cin.clear();
		getline(cin, p);
		bb = p.size();
		if (bb != 8)
		{
			cout << "please input 8 characters as you passwords." << endl;
			continue;
		}
		cout << "please input it again qwq" << endl;
		getline(cin, pp);
		if (p != pp)
		{
			cout << "opps！the twice passwords are not same" << endl;
			cout << "do you want to input them again?" << endl;
			while (1) {
				cout << "1:again" << endl << "2: exit" << endl;
				cin >> b;
				if (b == 2)
					return;
				if (b == 1)
				{
					cin.ignore();
					break;//跳出内循环
				}
				else
				{
					cout << "please input the right number!" << endl;
					continue;
				}
			}
		}

		if (b == 1)
		{
			b = 0;
			continue;//回到外循环
		}
			cout << "Nice!you have became one of us! But still you should name yourself " << endl;
			getline(cin, n);
			cout << "perfect!but if you want to change your passwords as your wish,you have set a security question." << endl;
			cout << "your question:";
			string seq, ans;
			getline(cin, seq);
			cout << "And your answer is:";
			getline(cin, ans);
			cout << "you are my sunshine!my only sunshine!welcome to our library!"<<endl;
			student smallwork(i, n, p, seq, ans);
			studentdata.insert(studentdata.end(), smallwork);
			break;
	}
}
//修改密码===================================================================
bool student::CheckPasswords()
{
	int i = 3;//超过三次不允许修改密码
	cout << "nice to see you again" << endl;
	cout << "do you want to change your passwords?" << endl;
	while (1) {
		cout << "1:yes" << endl << "2:false" << endl;
		int b;
		cin >> b;
		if (b == 2)
		{
			cin.ignore();
			cout << " see you again!" << endl;
			return false;
		}
		if (b == 1)
		{
			cin.ignore();
			while (1) {
				if (i == -1)
				{
					cout << "your answer is wrong too many times,you have been forbidden to login,please chat with our administrator" << endl;
					this->SetSecurity("tanxiaofengsheng");//安全问题为标记值时，不允许登陆；
					return false;
				}
				cout << "you have to answer your security question " << endl;
				cout << this->SecurityProblem() << endl;
				string ans, p, pp;
				cout << "and your answer is:";
				getline(cin, ans);
				if (ans == this->Answer())
				{
					while (1) {
						cout << "what's your new 8 characters passwords:";
						int b;
						getline(cin, p);
						b = p.size();
						if (b != 8)
						{
							cout << "pleasa make sure your keywords are 8 characters" << endl;
							continue;
						}
						cout << "please input it again:";
						getline(cin, pp);
						if (p == pp)
						{
							cout << "change passwords successfully!" << endl;
							SetPasswords(p);
							return true;
						}
						else {
							cout << "the second is not same as first!" << endl;
							continue;
						}
					}
				}
				else {
					cout << "you are wrong,you still have " << i << " times to try" << endl;
					i--;
					continue;
				}
			}

		}
		else {
			cout << "please input right number" << endl;
			continue;
		}
	}
}
//登陆================================================================
int user::LogIn()//0代表登陆不成功，1代表学生登陆成功，2代表管理员登陆成功
{
	vector<student>::iterator it;
	vector<administrator>::iterator itt;
	cout << "please input you ID:";
	string i;
	getline(cin, i);
	for (it = studentdata.begin(); it != studentdata.end(); it++)
	{
		if (i == it->ID())
			break;
	}
	for (itt = AdminData.begin(); itt != AdminData.end(); it++)
	{
		if (i == it->ID())
			break;
	}
	if (it == (studentdata.end()) && (itt == AdminData.end()))
	{
		cout << "no such user" << endl;
		return 0;
	}
	string p;
	if (it != studentdata.end()) {
		cout << "please input your passwords:";
		getline(cin, p);
		if (p == it->Passwords())
		{
			if (it->SecurityProblem() == "tanxiaofengsheng")
			{
				cout << "sorry,you have answer your question wrong many times ,you can not login" << endl;
				return 0;
			}
			cout << "log in successfully" << endl;
			return 1;
		}
		else {
			cout << "your passwords are wrong" << endl;
			return 0;
		}
	}
	if ((it == studentdata.end()) && itt != AdminData.end())
	{
		cout << "nice to meet you sir,please input your passwords:" << endl;
		getline(cin, p);
		if (p == it->Passwords())
		{
			cout << "log in successfully sir." << endl;
			return 2;
		}
		else {
			cout << "your passwords are wrong" << endl;
			return 0;
		}
	}
	return 0;
}
//返回学生信息下标==============================
int user::Search(string i)
{
	int ii = 0;
	vector<student>::iterator it;
	for (it = studentdata.begin(); it != studentdata.end(); it++)
	{
		ii++;
		if (i == it->ID())
			break;
	}
	if (it== studentdata.end())
	{
		cout << "no such user" << endl;
		return -1;
	}
	return ii;
}
//给予要删除的学生信息一个标记值，当id为标记值时不予存入文件=================================
bool administrator::Deletestudent(string s)
{
	vector<student>::iterator it;
	for (it = studentdata.begin(); it != studentdata.end(); it++)
	{
		if (s == it->ID())
		{
			it->SetId("bignews");
			return true;
		}
	}
 return false;
}
bool administrator::ReSetSecurity()
{
	cout << "please input a user you want to change it" << endl;
	string i, s, a;
	getline(cin, i);
	int b;
	b = Search(i);
	if (b == -1)
		return false;
	else
		cout << "please input the security problem" << endl;
		getline(cin, s);
		cout << "please input its answer" << endl;
		getline(cin, a);
		studentdata[b].SetSecurity(s);
	studentdata[b].SetAnswer(a);
	return true;
}
int main()
{
	student m;
	m.StartStudentData();
	m.LogIn();
	m.OverStudentData();
}