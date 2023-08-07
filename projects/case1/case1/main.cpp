#include <iostream>
#include <string>
using namespace std;
#define MAX 1000 //�궨���¼ͨѶ¼������

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

//�˵�
void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1ؼ�����ϵ��*****" << endl;
	cout << "*****2ؼ��ʾ��ϵ��*****" << endl;
	cout << "*****3ؼɾ����ϵ��*****" << endl;
	cout << "*****4ؼ������ϵ��*****" << endl;
	cout << "*****5ؼ�޸���ϵ��*****" << endl;
	cout << "*****6ؼ�����ϵ��*****" << endl;
	cout << "*****0ؼ�˳�����ϵͳ***" << endl;
	cout << "***********************" << endl;
}

//ȷ�ϵ�ǰ�����Ƿ������ͨ��¼��
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

//1�������ϵ��
void addPerson(AddressBooks* abs)
{
	if(abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "��������ϵ�˵�����" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;

		int sex = 0;
		cout << "��������ϵ�˵��Ա�1��ʾ������2��ʾŮ��" << endl;
		while (true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		int age;
		cout << "��������ϵ�˵�����" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;

		string phone;
		cout << "��������ϵ�˵ĵ绰" << endl;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		string address;
		cout << "��������ϵ�˵ĵ�ַ" << endl;
		cin >> address;
		abs->personarray[abs->size].address = address;

		abs->size++;
	}
	system("pause");
	system("cls");
}

//2����ʾ������ϵ��
void showPerson(AddressBooks* abs)
{
	if(abs->size == 0)
	{
		cout << "ͨѶ¼��û���κ���Ϣ" << endl;
	}
	else
	{
		for(int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personarray[i].name << "\t";
			cout << "�Ա�" << (abs->personarray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personarray[i].age << "\t";
			cout << "�绰��" << abs->personarray[i].phone << "\t";
			cout << "סַ��" << abs->personarray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//3��ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
	string name;
	cout << "������Ҫɾ������ϵ������" << endl;
	cin >> name;
	int flag = isExist(abs, name);
	if(flag != -1)
	{
		for(int i = flag; i < abs->size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "ͨѶ¼���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//4��������ϵ��
void findPerson(AddressBooks* abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	cin >> name;
	int flag = isExist(abs, name);

	if(flag != -1)
	{
		cout << "������" << abs->personarray[flag].name << "\t";
		cout << "�Ա�" << (abs->personarray[flag].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personarray[flag].age << "\t";
		cout << "�绰��" << abs->personarray[flag].phone << "\t";
		cout << "סַ��" << abs->personarray[flag].address << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//5���޸���ϵ��
void modifyPerson(AddressBooks* abs)
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	cin >> name;
	int flag = isExist(abs, name);

	if(flag != -1)
	{
		string name;
		cout << "��������������" << endl;
		cin >> name;
		abs->personarray[flag].name = name;

		int sex;
		cout << "�����������Ա�" << endl;
		cin >> sex;
		abs->personarray[flag].sex = sex;

		int age;
		cout << "��������������" << endl;
		cin >> age;
		abs->personarray[flag].age = age;

		string phone;
		cout << "����������绰" << endl;
		cin >> phone;
		abs->personarray[flag].phone = phone;

		string address;
		cout << "�����������ַ" << endl;
		cin >> address;
		abs->personarray[flag].address = address;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanPerson(AddressBooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}


//������
int main()
{
	int select = 0;
	AddressBooks abs;
	abs.size = 0;



	while (true)
	{
		showMenu();
		cout << "��������Ҫʵ�ֵĹ��ܣ�" << endl;
		cin >> select;
		
		switch(select)
		{
		case 1: //�����ϵ��
			addPerson(&abs);
			break;
		case 2: //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //�˳�����
			cout << "��������˳�ϵͳ" << endl;
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}