#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <io.h>
#include <iomanip>
using namespace std;

char * filePath = "D:\\aaa";

vector<string> files;

char str[30];

struct node
{
	string name;
	string activity[100];
	string date[100];
	int time[100];
	int cnt;
	int totaltime;
} stu[200];

void getFiles(string path, vector<string>& files)
{
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}

	return ;
}

int main()
{
	getFiles(filePath, files);
	int size = files.size();
	for (int i = 0;i < size;i++)
		cout << files[i].c_str() << endl;

	for(int i = 0; i < size; i++)
	{
		stu[i].cnt = 0;
		stu[i].totaltime = 0;
	}

	for(int i = 0; i < size; i++)
	{
		freopen(files[i].c_str(), "r", stdin);
		scanf("%*s");
		scanf("%*s");
		scanf("%*s");
		scanf("%*s");
		while(cin >> stu[i].name)
		{
			cin >> stu[i].activity[stu[i].cnt];
			cin >> stu[i].date[stu[i].cnt];
			cin >> stu[i].time[stu[i].cnt];
			stu[i].totaltime += stu[i].time[stu[i].cnt];
			stu[i].cnt++;
		}
		cin.clear();
	}

	freopen("aaa.txt", "w", stdout);
	cout << "|-----------------------------------|" << endl;
	cout << "|      姓名| 活动数量| 总志愿时长(h)|" << endl;
	cout << "|-----------------------------------|" << endl;
	for(int i = 0; i < size; i++)
		cout << "|" << setw(12) << stu[i].name << "| " << setw(8) << stu[i].cnt << "|" << setw(14) << stu[i].totaltime << "|" << endl;
	cout << "|-----------------------------------|" << endl;
	cout << "|--北京师范大学数学科学学院 李喆琛--|" << endl;
	cout << "|-----------------------------------|" << endl;
	cout.clear();

	freopen("bbb.txt", "w", stdout);
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|      姓名|                    活动名称|   日期(y/m/d)|志愿时长(h)|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < stu[i].cnt; j++)
			cout << "|" << setw(12) << stu[i].name << "|" << setw(30) << stu[i].activity[j] << "|" << setw(14) << stu[i].date[j] << "|" << setw(11) << stu[i].time[j] << "|" << endl;
		cout << "|------------------------------------------------------------------|" << endl;
	}
	cout << "|-----------------北京师范大学数学科学学院 李喆琛------------------|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;

	return 0;
}

