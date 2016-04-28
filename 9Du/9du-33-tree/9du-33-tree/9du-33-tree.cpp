#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
int n, m;
int num;

//void count(int m){
//	if (m > n) return;
//	if (m <= n) num++;
//	count(2 * m);
//	count(2 * m + 1);
//	return;
//}

int main(){
	while (scanf("%d%d", &m, &n) != EOF && m != 0){
		num = 0;
		//count(m);	使用递归超时了！
		int left = m;//左子树最小值
		int right = m;//右子树最大值
		int i = 0;
		while (right<n){
			num += (int)pow(2.0, i++);
			left = left * 2;
			right = right * 2 + 1;
		}
		while (left <= n){
			num++;
			left++;
		}
		cout << num << endl;
	}
	system("pause");
	return 0;
}