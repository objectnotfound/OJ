//strcmp（）在哪个头文件？？
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
#include<algorithm>
using namespace std;

struct S{
	char name[105];
	int age;
	int score;
}student[1005];

bool cmp(S a, S b){
	if (a.score != b.score) return a.score < b.score;
	else {
		int tmp = strcmp(a.name, b.name);
		if (tmp != 0) return tmp < 0;
		else return a.age < b.age;
	}
}

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++)
			scanf("%s%d%d", student[i].name, &student[i].age, &student[i].score);
		sort(student, student + n, cmp);
		for (int i = 0; i < n; i++){
			printf("%s %d %d\n", student[i].name, student[i].age, student[i].score);
		}
	}
	system("pause");
	return 0;
}