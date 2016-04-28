#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 101;
float p[maxn];
int t, n, v; 
float w;

int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%f", &n, &v, &w);
		for (int i = 0; i < n; i++){
			scanf("%f", &p[i]);
		}
		sort(p, p + n);
		int num = 0;
		float average = 0.0;
		for (int i = 0; i < n; i++){
			if ((average*num + p[i]) / (num + 1) <= w) {
				average = (average*num + p[i]) / (num + 1);
				num++;
			}
			else{ 
				break; 
			}
		}
		if (num == 0) {
			printf("0 0.00\n");
		}
		else{
			printf("%d %.2f\n", num*v, average / 100);
		}
	}
	system("pause");
	return 0;
}
//由于体积是一样的，而且只能全部混合，问题实际上简化了很多，贪心策略也容易想到