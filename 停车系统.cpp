#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
class park
{
private:
	string carnumber;
	int arrivetime_h;
	int arrivetime_m;
	int leavetime_h;
	int leavetime_m;
public:
	park();
	~park();
	void setcarnumber();
	string getcarnumber();
	void setarrivetime_h();
	int getarrivetime_h();
	void setarrivetime_m();
	int getarrivetime_m();
	void setleavetime_h();
	int getleavetime_h();
	void setleavetime_m();
	int getleavetime_m();
	void add();
	void show();
	void search();
	void deletepark();
	void exitpark();
	int save();
	int read();
	void showface();
	void choose();
};
vector<park>per;
park::park()
{}
park::~park()
{}

void park::setcarnumber()
{
	cout << "输入车牌号";
	cin >> carnumber;
}
string park::getcarnumber()
{
	string _carnumber = carnumber;
	return _carnumber;
}
void park::setarrivetime_h()
{
	cout << "输入到达时间的小时数";
	cin >> arrivetime_h;
}
int park::getarrivetime_h()
{
	int _arrivetime_h = arrivetime_h;
	return _arrivetime_h;
}
void park::setarrivetime_m()
{
	cout << "输入到达时间的分钟数";
	cin >> arrivetime_m;
}
int park::getarrivetime_m()
{
	int _arrivetime_m = arrivetime_m;
	return arrivetime_m;
}
void park::setleavetime_h()
{
	cout << "输入离开时间的小时数";
	cin >> leavetime_h;
}
int park::getleavetime_h()
{
	int _leavetime_h = leavetime_h;
	return _leavetime_h;
}
void park::setleavetime_m()
{
	cout << "输入离开时间的分钟数";
	cin >> leavetime_m;
}
int park::getleavetime_m()
{
	int _leavetime_m = leavetime_m;
	return _leavetime_m;
}

void park::add()
{
	park tmp;
	vector<park>::iterator it;
loop:
	tmp.setcarnumber();
	for (it = per.begin(); it != per.end(); ++it)
	{
		if (!((it->getcarnumber()).compare(tmp.getcarnumber())))
		{
			cout << "与已有车辆重复，请重新输入。" << endl;
			goto loop;
		}
	}
	tmp.setarrivetime_h();
	tmp.setarrivetime_m();
	tmp.setleavetime_h();
	tmp.setleavetime_m();

	per.push_back(tmp);

	cout << "是否继续添加车辆信息 y/n ：";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		goto loop;
	}

}

void park::show()
{
	vector<park>::iterator it;
	if (per.empty())
	{
		cout << "停车场无车" << endl;
	}
	else
	{
		for (it = per.begin(); it != per.end(); ++it)
		{
			int stoptime = 0;
			stoptime = ((it->getleavetime_h()) - (it->getarrivetime_h())) * 60 + (it->getleavetime_m()) - (it->getarrivetime_m());
			cout << "车牌：" << it->getcarnumber() << endl;
			cout << "停车时间：" << stoptime <<" "<<"minutes"<< endl;
		}
		cout << "请按任意键退出" << endl;
		char ch;
		cin >> ch;
	}
}




void park::search()
{
	vector<park>::iterator it;
	if (per.empty())
	{
		cout << "停车场无车" << endl;
	}
	else
	{
		string number;
		int flag = 0;
		cout << "请输入车牌号进行查找" << endl;
		cout << "请输入查找的车牌：";
		cin >> number;
		for (it = per.begin(); it != per.end(); ++it)
		{
			if (it->getcarnumber() == number)
			{
				flag = 1;
				int stoptime = 0;
				stoptime = ((it->getleavetime_h()) - (it->getarrivetime_h())) * 60 + (it->getleavetime_m()) - (it->getarrivetime_m());
				cout << "车牌：" << it->getcarnumber() << endl;
				cout << "停车时间：" << stoptime <<" "<<"minutes"<< endl;
			}
		}

		if (flag == 0)
		{
			cout << "无找到此车" << endl;
		}
		else
		{
			cout << "查找成功" << endl;
		}
		cout << "请按任意键退出" << endl;
		char ch;
		cin >> ch;
	}

}

void park::deletepark()
{
	vector<park>::iterator it;
	if (per.empty())
	{
		cout << "停车场无车" << endl;
	}
	else
	{
		string number;
		int flag = 0;
		cout << "请输入查找车牌号" << endl;
		cin >> number;
		for (it = per.begin(); it != per.end(); ++it)
		{
			if ((it->getcarnumber()) == number)
			{
				flag = 1;
				cout << "你要删除的车信息为：" << endl;
				cout << "车牌：" << it->getcarnumber() << endl;
				cout << "到达时间：" << it->getarrivetime_h() << ":" << it->getarrivetime_m() << endl;
				cout << "离开时间：" << it->getleavetime_h() << ":" << it->getleavetime_m() << endl;
				cout << "是否确定删除此车信息 y/n";
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					it = per.erase(it);
				}
			}
		}


		if (flag == 0)
		{
			cout << "未查到该车信息" << endl;
		}
		else
		{
			cout << "删除成功" << endl;
		}
		cout << "请按任意键退出" << endl;
		char ch;
		cin >> ch;
	}

}
int park::save()
{
	ofstream outfile("d:\\car.text", ios::out);
	if (!outfile)
	{
		cerr << "打开文件失败!\n";
		return -1;
	}
	vector<park>::iterator it;
	for (it = per.begin(); it != per.end(); ++it)
	{
		outfile << it->getcarnumber() << endl;
		outfile << it->getarrivetime_h() << endl << it->getarrivetime_m() << endl;
		outfile << it->getleavetime_h() << endl << it->getleavetime_m() << endl;
		outfile << endl;
	}
	outfile.close();
	cout << "保存成功" << endl;
	cout << "请按任意键退出" << endl;
	char ch;
	cin >> ch;
	return 0;

}


int park::read()
{
	park tmp;
	ifstream infile("d:\\car.text", ios::in);
	if (!infile)
	{
		cerr << "打开文件失败" << endl;
		return -1;
	}
	else
	{
		vector<park>::iterator it;
		int a = 1;
		char ch;
		while (!infile.eof())
		{
			if (a == 1)
			{
				infile.get(ch);
				it->carnumber = ch;
				a++;
			}
			if (a == 2)
			{
				infile.get(ch);
				it->arrivetime_h = (int)ch;
				a++;
			}
			if (a == 3)
			{
				infile.get(ch);
				it->arrivetime_m = (int)ch;
				a++;
			}
			if (a == 4)
			{
				infile.get(ch);
				it->leavetime_h = (int)ch;
				a++;
			}
			if (a == 5)
			{
				infile.get(ch);
				it->leavetime_m = (int)ch;
				a = 1;
			}

		}
		infile.close();
		cout << "读取成功" << endl;
	}
	cout << "请按任意键退出" << endl;
	char ch;
	cin >> ch;

	return 0;
}


void park::exitpark()
{
	cout << "确定退出停车管理系统吗？y/n: ";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		exit(1);
	}
}

void park::showface()
{
	cout << endl;
	cout << endl;
	cout << "|***********************************************|" << endl;
	cout << "|*               停车场收费管理系统              *|" << endl;
	cout << "|*                                             *|" << endl;
	cout << "|*                                             *|" << endl;
	cout << "|*   选择功能进行操作                            *|" << endl;
	cout << "|*                   1:添加车辆信息            *|" << endl;
	cout << "|*                   2:查询车辆信息            *|" << endl;
	cout << "|*                   3:显示车辆信息            *|" << endl;
	cout << "|*                   4:删除车辆信息            *|" << endl;
	cout << "|*                   5:保存车辆信息            *|" << endl;
	cout << "|*                   6:读取车辆信息            *|" << endl;
	cout << "|*                   7:退出管理系统            *|" << endl;
	cout << "|*   请输入以上你想要实现的功能(1-7)         	  *|" << endl;
	cout << "|*                                             *|" << endl;
	cout << "|*                                             *|" << endl;
	cout << "|***********************************************|" << endl;
}



void park::choose()
{
	char number;
	park tmp;
	cout << "请输入你要实现的功能(1-7)";
	cin >> number;

	switch (number)
	{
	case '1':
	{
		tmp.add();
		tmp.showface();
		choose();
		break;
	}
	case '2':
	{
		tmp.search();
		tmp.showface();
		choose();
		break;
	}
	case '3':
	{
		tmp.show();
		tmp.showface();
		choose();
	}
	case '4':
	{
		tmp.deletepark();
		tmp.showface();
		choose();
		break;
	}

	case '5':
	{
		tmp.save();
		choose();
		break;
	}
	case '6':
	{
		tmp.read();
		choose();
		break;
	}
	case '7':
	{
		tmp.exitpark();
		break;
	}
	default:
	{
		cout << "输入指令有误，请重新输入！" << endl;
		choose();
		break;
	}
	}
}



int main()
{
	park y;
	y.showface();
	y.choose();
	return 0;
}