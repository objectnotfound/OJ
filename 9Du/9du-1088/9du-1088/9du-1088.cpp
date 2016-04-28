#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 101;
int s[maxn];
int e[maxn];
int point[10005];

int main(){
	int l, m;
	while (scanf("%d%d", &l, &m) == 2){
		for (int i = 0; i <= l; i++){
			point[i] = 1;
		}
		for (int i = 0; i < m; i++)	{
			scanf("%d%d", &s[i], &e[i]);
			for (int j = s[i]; j <= e[i]; j++){
				point[j] = 0;
			}
		}
		int num = 0;
		for (int i = 0; i <= l; i++){
			if (point[i] == 1) num++;
		}
		printf("%d\n", num);
	}
	system("pause");
	return 0;
}
