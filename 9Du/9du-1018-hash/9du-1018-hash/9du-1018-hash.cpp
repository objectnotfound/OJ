#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int main(){
	
	int n, score;
	while (scanf("%d", &n) != EOF){
		if (n == 0) break;
		int hash[101];
		memset(hash, 0, sizeof(hash));
		for (int i = 0; i < n; i++) {
			scanf("%d", &score);
			hash[score]++;
		}
		scanf("%d", &score);
		printf("%d\n", hash[score]);
	}
	system("pause");
	return 0;
}