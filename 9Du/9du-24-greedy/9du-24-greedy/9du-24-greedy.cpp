//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn = 601;
//int L, n;
//int len[maxn];
//int num;
//
//int solve(int total, int pos){
//	if (pos < n && len[pos] == total) {
//		num++;
//		return 1;
//	}
//	if (pos == n - 1 && len[pos] != total) return 0;
//
//	if (solve(total - len[pos], pos + 1)) {
//		num++;
//		return 1;
//	}
//	else{
//		if (solve(total, pos + 1)){
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}
//}
//
//bool cmp(int a, int b){
//	return a > b;
//}
//
//int main(){
//	while (scanf("%d%d", &L, &n) != EOF){
//		for (int i = 0; i < n; i++){
//			scanf("%d", &len[i]);
//		}
//		sort(len, len + n, cmp);
//		if (len[0] * n <= L){
//			printf("impossible\n");
//		}
//		else{
//			num = 0;
//			if (solve(L, 0)){
//				printf("%d\n", num);
//			}
//			else{
//				printf("impossible\n");
//			}
//		}
//		
//	}
//	system("pause");
//	return 0;
//} //以上代码实现不可切割的情况，即一块木块要么全要，要么不要，所以要使用递归
//
//
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 601;
int len[maxn];
int L, n;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	while (scanf("%d%d", &L, &n) != EOF){
		for (int i = 0; i < n; i++){
			scanf("%d", &len[i]);
		}
		sort(len, len + n, cmp);
		int total = 0, num = 0;
		int state = 0;
		for (int i = 0; i < n; i++){
			if (total + len[i] < L){
				num++;
				total += len[i];
			}
			else if (total + len[i] >= L){
				num++;
				state = 1;
				break;
			}
		}
		if (!state){
			printf("impossible\n");
		}
		else{
			printf("%d\n", num);
		}
	}
	system("pause");
	return 0;
}
//认真读清楚题意，实际上是比较简单的贪心
