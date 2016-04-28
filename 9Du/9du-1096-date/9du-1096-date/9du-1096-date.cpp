#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define isYear(x) (x%4==0&&x%100!=0)||x%400==0?1:0

using namespace std;
int days[13][2] = {
	0, 0, 31, 31, 28, 29, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31
};
int buf[6001][12][31];

struct date{//结构体内的这个函数很有用
	int day;
	int month;
	int year;
	void nextday(){
		day++;
		if (day > days[month][isYear(year)])		{
			day = 1;
			month++;
			if (month > 12){
				month = 1;
				year++;
			}
		}
	}
};


int main(){
	int cnt = 0;
	date tmp;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	while (tmp.year != 6000){
		buf[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextday();
		cnt++;
	}
	date a, b;
	while (scanf("%4d%2d%2d", &a.year, &a.month, &a.day) != EOF){
		scanf("%4d%2d%2d", &b.year, &b.month, &b.day);
		int res = abs(buf[b.year][b.month][b.day] - buf[a.year][a.month][a.day]);
		printf("%d\n", res+1);
	}

	system("pause");
	return 0;
}