#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
const int maxn = 1005;
int num[maxn];

int main(){
	int n, d;
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
		}
		scanf("%d", &d);
		int left = (int)pow(2.0, d - 1);
		int right = (int)pow(2.0, d) - 1;
		if (left>n) cout << "EMPTY" << endl;
		else{
			while (left < n && left < right){
				cout << num[left - 1] << ' ';
				left++;
			}
			cout << num[left - 1];
			cout << endl;
		}

	}
	system("pause");
	return 0;
}