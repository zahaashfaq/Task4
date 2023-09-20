#include<iostream>
#include<fstream>
#include <string>
using namespace std;
struct toDoMemebers{
	char taskName[30];
	char taskStatus[30];
};
void todoMenu()
{
	cout << "\t\tWELCOME TO TODO LIST\n";
	cout << "\t\t1- Add the record\n";
	cout << "\t\t2- Display the record\n";
	cout << "\t\t3- Delete the record\n";
	cout << "\t\t4- Modify the record\n";
	cout << "\t\t5- End the Program\n";
}
void again();
bool findRecord(const char*f,string a)
{
	ifstream fs;
	fs.open(f);
	toDoMemebers a1;
	while (!(fs.eof()))
	{
		if (fs.eof())
		{
			break;
		}
		fs >> a1.taskName;
		fs >> a1.taskStatus;
		if (a1.taskName == a)
		{
			fs.close();
			return false;
		}
	}
	fs.close();
	return true;
}
void addRecord()
{
	toDoMemebers a;
	cout << "Enter your task name :";
	cin >> a.taskName;
	cout << "Enter your Task Status :";
	cin >> a.taskStatus;
	ofstream fs;
	fs.open("toDoList.txt", ios::app);
	if(findRecord("toDoList.txt",a.taskName))
	{
		fs << '\n' << a.taskName;
		fs << '\n' << a.taskStatus;
	}
	fs.close();
	again();
}
void displayRecord()
{
	ifstream ifs;
	string a;
	ifs.open("ToDoList.txt");
	while (!(ifs.eof()))
	{
		if (ifs.eof())
		{
			break;
		}
		ifs >> a;
		cout<<"Task Name :" << a << endl;
		ifs >> a;
		cout<<"Status    :" << a << endl;
	}
	ifs.close();
	again();
}
void deleteRecord()
{
	string a;
	toDoMemebers b;
	int flag = 0;
	cout << "Enter task name you want to delete :";
	cin >> a;
	ifstream fs;
	fs.open("toDoList.txt");
	ofstream ofs;
	ofs.open("temp.txt");
	while (!(fs.eof()))
	{
		if (fs.eof())
		{
			break;
		}
		fs >> b.taskName;
		fs >> b.taskStatus;
		if (a == b.taskName)
		{
			flag = 1;
		}
		else 
		{
			ofs << '\n' << b.taskName;
			ofs << '\n' << b.taskStatus;
		}
	}
	fs.close();
	ofs.close();
	remove("toDoList.txt");
	rename("temp.txt", "toDoList.txt");
	if (flag == 1)
		cout << "\nRecord successfully deleted \n";
	else
		cout << "\nRecord not found \n";
	again();
}
void modifyRecord()
{
	string a,c;
	toDoMemebers b;
	cout << "Enter task name whose status you want to change :";
	cin >> a;
	cout << "Enter status:";
	cin >> c;
	ifstream fs;
	fs.open("toDoList.txt");
	ofstream ofs;
	ofs.open("temp.txt");
	while (!(fs.eof()))
	{
		if (fs.eof())
		{
			break;
		}
		fs >> b.taskName;
		fs >> b.taskStatus;
		if (b.taskName == a)
		{
			ofs << '\n' << b.taskName;
			ofs << '\n' << c;
		}
		else if (b.taskName != a)
		{
			cout << "record not found\n";
			break;
		}
		else
		{
			ofs << '\n' << b.taskName;
			ofs << '\n' << b.taskStatus;
		}
	}
	fs.close();
	ofs.close();
	remove("toDoList.txt");
	rename("temp.txt", "toDoList.txt");
	again();
}
void mainMenu()
{
	todoMenu();
	int num;
	cout << "Enter the choice:";
	cin >> num;
	switch (num)
	{
	case 1:
		addRecord();
		break;
	case 2:
		displayRecord();
		break;
	case 3:
		deleteRecord();
		break;
	case 4:
		modifyRecord();
		break;
	case 5:
		break;
	}
}
int main()
{
	mainMenu();
}
void again()
{
	char choice;
	cout << "You want to see the todo Menu List :(y/n)";
	cin >> choice;
	if (choice == 'y')
	{
		mainMenu();
	}
	else
	{
		exit(0);
	}
}