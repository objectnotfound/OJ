#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 101;
int height[maxn];
int dp_inc[maxn];
int dp_dec[maxn];

int n;
int main(){
	while (cin >> n){
		for (int i = 0; i < n; i++){
			scanf("%d", &height[i]);
			//cin >> height[i];
		}
		
		dp_inc[0] = 1;
		for (int i = 1; i < n; i++){
			int tmpmax = 0;	  
			for (int j = 0; j < i; j++){
				if (height[j] < height[i]){
					tmpmax = max(tmpmax, dp_inc[j] + 1);
				}
			}
			dp_inc[i] = max(1, tmpmax);
		}

		dp_dec[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--){
			int tmpmax = 0;
			for (int j = n-1; j > i; j--){
				if (height[j] < height[i]){
					tmpmax = max(tmpmax, dp_dec[j] + 1);
				}
			}
			dp_dec[i] = max(1, tmpmax);
		}

		int res = 0;
		for (int i = 0; i < n; i++){
			res = max(res, dp_inc[i] + dp_dec[i]-1);
		}
		printf("%d\n", n - res);
	}
	return 0;
}
//最长递增子串问题的变型，两次用到，一正一反
//超时后，cin换成scanf后OK

