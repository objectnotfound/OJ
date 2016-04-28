#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 26;
int height[maxn];
int F[maxn];

int n;
int main(){
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> height[i];
		}
		F[0] = 1;
		int totalmax = 1;//全局最小值为1，除非n=0
		for (int i = 1; i < n; i++){
			int tmpmax = 0;
			for (int j = 0; j < i; j++){
				if (height[j] >= height[i]){
					if (F[j]>tmpmax) tmpmax = F[j];
				}
			}
			F[i] = max(1, tmpmax + 1);
			totalmax = max(totalmax, F[i]);
		}
		/*for (int i = 0; i < n; i++){
			printf("%d ", F[i]);
		}
		printf("\n");*/
		printf("%d\n", totalmax);
	}
	return 0;
}

//动态规划问题，写出公式；特别注意边界问题
//最长递增子序列问题，可以处理其他关系

