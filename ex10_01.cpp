// ex10_01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using std::vector;
using std::endl;
using std::cout;
using std::string;


typedef struct _BALL
{
	int RedBalls[6];
	int BlueBalls[1];
}BALL,*PBALL;


template<typename T>
void listInfo(vector<T> &v)
{
	cout << "Container capacity: " << v.capacity()
		<< " size: " << v.size() << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<double> data;
	listInfo(data);

	cout << endl << "After calling reserver(100):" << endl;
	data.reserve(100);
	listInfo(data);

	cout << endl << "After calling resize(50):" << endl;
	data.resize(50);
	listInfo(data);

	cout << endl << "Input data[5] = 3" << endl;
	data[5] = 3;
	listInfo(data);


	vector<string> numbers(10,"01 02 03 04 05 06");
	cout << "Max Size:" << numbers.max_size();

	//return 0;

	cout << endl << "The initial values are: ";
	for(vector<int>::size_type i=0; i<numbers.size();i++)
		cout << " | " << numbers[i];
	//numbers.reserve(7000000);

	auto oldC = numbers.capacity();
	auto newC = oldC;

	cout << endl << endl;
	listInfo(numbers);
	auto dwS = GetTickCount();
	for(int i=0;i<100;i++)
	{
		numbers.push_back("01 02 03 04 05 06");
		newC = numbers.capacity();
		if(oldC < newC)
		{
			oldC = newC;
			listInfo(numbers);
		}
	}
	dwS = GetTickCount() - dwS;
	cout << endl << "Used Time: " << dwS  << "ms" << endl;
	cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ex10_01^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
	cout <<"**************************双色球全部号码生成时间测试**************************" << endl;
	dwS = GetTickCount();
	PBALL pBall;
	pBall = new BALL[18000000];
	PBALL pBall1 = pBall;
	int b[6]={1,2,3,4,5,5};
	//int m[6]={3,4,5,6,7,8};
	int m[6]={28,29,30,31,32,33};
	char t[30];
	int o;
	for(int i=0;i<18000000;)
	{
		b[5]++;
		for(int j=5;j>0;j--)
		{
			if(b[j] > m[j])
			{
				b[j-1]++;
				for(int k=j;k<6;k++)
					b[k] = b[k-1]+1;
				continue;
			}
			break;
		}
		
		for(int lll=0;lll<16;lll++)
		{
			for(int ll=0;ll<6;ll++)
				pBall[i].RedBalls[ll] = b[ll];
			pBall[i++].BlueBalls[0] = lll+1;
		}

		if((b[0]==m[0])&&(b[1]==m[1])&&(b[2]==m[2])&&(b[3]==m[3])&&(b[4]==m[4])&&(b[5]==m[5]))
		{
			o = i-1;
			break;
		}
	}
	
	
	sprintf_s(t,30,"%02d %02d %02d %02d %02d %02d - %02d",pBall[o].RedBalls[0],pBall[o].RedBalls[1],pBall[o].RedBalls[2],pBall[o].RedBalls[3],pBall[o].RedBalls[4],pBall[o].RedBalls[5],pBall[o].BlueBalls[0]);
	delete[] pBall;
	dwS = GetTickCount() - dwS;

	cout << endl << endl;
	cout <<"总注数: " << o+1 << " 结束号码: " <<  t << endl;
	cout <<"使用内存: " << (o+1)*(sizeof BALL) << " 字节" << endl;
	cout << endl << "生成时间: " << dwS  << "毫秒" << endl;
	return 0;
}

