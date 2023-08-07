#include <iostream>
#include <string>
using namespace std;
#define MAX 1000 //宏定义记录通讯录最大个数

struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct AddressBooks
{
	Person personarray[MAX];
	int size;
};

//菜单
void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1丶添加联系人*****" << endl;
	cout << "*****2丶显示联系人*****" << endl;
	cout << "*****3丶删除联系人*****" << endl;
	cout << "*****4丶查找联系人*****" << endl;
	cout << "*****5丶修改联系人*****" << endl;
	cout << "*****6丶清空联系人*****" << endl;
	cout << "*****0丶退出管理系统***" << endl;
	cout << "***********************" << endl;
}

//确认当前的人是否存在于通信录中
int isExist(AddressBooks* abs, string name)
{
	for(int i = 0; i < abs->size; i++)
	{
		if(abs->personarray[i].name == name)
		{
			return i;
		}
	}

	return - 1;
}

//1、添加联系人
void addPerson(AddressBooks* abs)
{
	if(abs->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入联系人的姓名" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;

		int sex = 0;
		cout << "请输入联系人的性别：1表示男生，2表示女生" << endl;
		while (true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		int age;
		cout << "请输入联系人的年龄" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;

		string phone;
		cout << "请输入联系人的电话" << endl;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		string address;
		cout << "请输入联系人的地址" << endl;
		cin >> address;
		abs->personarray[abs->size].address = address;

		abs->size++;
	}
	system("pause");
	system("cls");
}

//2、显示所有联系人
void showPerson(AddressBooks* abs)
{
	if(abs->size == 0)
	{
		cout << "通讯录中没有任何信息" << endl;
	}
	else
	{
		for(int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personarray[i].name << "\t";
			cout << "性别：" << (abs->personarray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personarray[i].age << "\t";
			cout << "电话：" << abs->personarray[i].phone << "\t";
			cout << "住址：" << abs->personarray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//3、删除联系人
void deletePerson(AddressBooks* abs)
{
	string name;
	cout << "请输入要删除的联系人姓名" << endl;
	cin >> name;
	int flag = isExist(abs, name);
	if(flag != -1)
	{
		for(int i = flag; i < abs->size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "通讯录查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//4、查找联系人
void findPerson(AddressBooks* abs)
{
	string name;
	cout << "请输入要查找的联系人姓名" << endl;
	cin >> name;
	int flag = isExist(abs, name);

	if(flag != -1)
	{
		cout << "姓名：" << abs->personarray[flag].name << "\t";
		cout << "性别：" << (abs->personarray[flag].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personarray[flag].age << "\t";
		cout << "电话：" << abs->personarray[flag].phone << "\t";
		cout << "住址：" << abs->personarray[flag].address << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//5、修改联系人
void modifyPerson(AddressBooks* abs)
{
	string name;
	cout << "请输入要修改的联系人姓名" << endl;
	cin >> name;
	int flag = isExist(abs, name);

	if(flag != -1)
	{
		string name;
		cout << "请重修输入名字" << endl;
		cin >> name;
		abs->personarray[flag].name = name;

		int sex;
		cout << "请重修输入性别" << endl;
		cin >> sex;
		abs->personarray[flag].sex = sex;

		int age;
		cout << "请重修输入年龄" << endl;
		cin >> age;
		abs->personarray[flag].age = age;

		string phone;
		cout << "请重修输入电话" << endl;
		cin >> phone;
		abs->personarray[flag].phone = phone;

		string address;
		cout << "请重修输入地址" << endl;
		cin >> address;
		abs->personarray[flag].address = address;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//6、清空联系人
void cleanPerson(AddressBooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}


//主函数
int main()
{
	int select = 0;
	AddressBooks abs;
	abs.size = 0;



	while (true)
	{
		showMenu();
		cout << "请输入你要实现的功能：" << endl;
		cin >> select;
		
		switch(select)
		{
		case 1: //添加联系人
			addPerson(&abs);
			break;
		case 2: //显示联系人
			showPerson(&abs);
			break;
		case 3: //删除联系人
			deletePerson(&abs);
			break;
		case 4: //查找联系人
			findPerson(&abs);
			break;
		case 5: //修改联系人
			modifyPerson(&abs);
			break;
		case 6: //清空联系人
			cleanPerson(&abs);
			break;
		case 0: //退出程序
			cout << "按任意键退出系统" << endl;
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}