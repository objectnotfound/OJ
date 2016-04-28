#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	int a, b, k;
	while (scanf("%d%d%d", &a, &b, &k) != EOF){
		if (a == 0 && b == 0) break;
		int c = (int)pow(10.0, k);
		if (a%c == b%c){
			printf("-1\n");
		}
		else {
			printf("%d\n", a + b);
		}

	}
	system("pause");
	return 0;
}