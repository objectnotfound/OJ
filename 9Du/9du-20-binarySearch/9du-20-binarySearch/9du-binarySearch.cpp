#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 101;
int a[maxn];
int b[maxn];
int n, m;

int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) scanf("%d", &b[i]);
		sort(a, a + n);
		for (int i = 0; i < m; i++){
			int flag = 0;
			int l = 0, r = n - 1;
			while (l <= r){
				int mid = (l + r) / 2;
				if (b[i] == a[mid]){
					flag = 1;
					break;
				}
				else if (b[i] < a[mid])
					r = mid - 1;
				else if (b[i] > a[mid])
					l = mid + 1;
			}
			if (!flag)
				printf("NO\n");
			else printf("YES\n");
		}
	}
	system("pause");
	return 0;

}

//注意二分查找的条件和边界处理，是否有=，是否+-1等