#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#define isYear(x) (x%4==0&&x%100!=0)||x%400==0?1:0

using namespace std;
int days[13][2] = {
	0, 0, 31, 31, 28, 29, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31
};
int buf[5001][12][31];
char* weekName[7] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};
char* monthName[13] = {
	"null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

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
	while (tmp.year != 5000){
		buf[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextday();
		cnt++;
	}
	int d;
	char m[20];
	int y;
	while (scanf("%d%s%d", &d, m, &y)!=EOF){
		int i;
		for (i = 1; i <= 12; i++){
			if (strcmp(monthName[i], m) == 0)
				break;
		}
		int num = buf[y][i][d] - buf[2015][8][11];	 //注意负数的求余数问题，有的语言语言负数（C++和Java），有的不允许
		//int dayOfWeek = ((num + 2) % 7) < 0 ? ((num + 2) % 7 + 7) : (num + 2) % 7;
		int dayOfWeek = ((num + 2) % 7 + 7) % 7;
		printf("%s\n", weekName[dayOfWeek]);
	}
	system("pause");
	return 0;
}