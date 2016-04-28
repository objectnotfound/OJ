#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 101;
char s[maxn];
char t[maxn];
int dp[maxn][maxn];

int main(){
	while (scanf("%s%s", s, t) == 2){
		int slen = strlen(s);
		int tlen = strlen(t);
		for (int i = 0; i <= slen; i++){  //注意范围，带等号更好，
			dp[i][0] = 0;
		}
		for (int i = 0; i <= tlen; i++){
			dp[0][i] = 0;
		}
		for (int i = 1; i <= slen; i++){	//i,j表示前多少个，注意相应的字符为  s[i-1] 和 t[j-1]
			for (int j = 1; j <= tlen; j++){
				if (s[i-1] == t[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		printf("%d\n", dp[slen][tlen]);
	}
	return 0;
}

//最长公共子序列（注意不是子串，子串可能要求是连续的）	  原理还是比较好理解的
//特别注意的是dp[i][j]其中i，j是指的前多少个字符，所以 1=<i,j<=str，最后dp[str1][str2]即为所求