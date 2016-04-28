#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2002;
const int inf = 0x7fffffff;
int dp[maxn / 2][maxn];
int w[maxn];
int n, k;

int main(){
	while (cin >> n >> k){
		for (int i = 1; i <= n; i++){
			cin >> w[i];
		}
		sort(w + 1, w + n+1);  //注意排序的起始地址！
		for (int i = 0; i <= n; i++){//dp[0][0]是有用的
			dp[0][i] = 0;
		}
		for (int i = 1; i <= n / 2; i++){
			for (int j = 1; j < 2 * i; j++){
				dp[i][j] = inf;
			}
		}
		dp[1][2] = (w[1] - w[2])*(w[1] - w[2]);

		for (int i = 1; i <= k; i++){
			for (int j = i*2; j <= n; j++){
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + (w[j] - w[j - 1])*(w[j] - w[j - 1]));
			}
		}
		printf("%d\n", dp[k][n]);
	}

	return 0;
}