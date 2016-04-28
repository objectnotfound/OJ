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
		for (int i = 0; i <= slen; i++){  //ע�ⷶΧ�����ȺŸ��ã�
			dp[i][0] = 0;
		}
		for (int i = 0; i <= tlen; i++){
			dp[0][i] = 0;
		}
		for (int i = 1; i <= slen; i++){	//i,j��ʾǰ���ٸ���ע����Ӧ���ַ�Ϊ  s[i-1] �� t[j-1]
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

//����������У�ע�ⲻ���Ӵ����Ӵ�����Ҫ���������ģ�	  ԭ���ǱȽϺ�����
//�ر�ע�����dp[i][j]����i��j��ָ��ǰ���ٸ��ַ������� 1=<i,j<=str�����dp[str1][str2]��Ϊ����