#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 101;
int n;
struct node{
	int sTime;
	int eTime;
}nodes[maxn];

bool cmp(node a, node b){
	return a.eTime < b.eTime;
}

int main(){
	while (scanf("%d", &n) == 1){
		if (n == 0) break;
		for (int i = 0; i < n; i++){
			scanf("%d%d", &nodes[i].sTime, &nodes[i].eTime);
		}
		sort(nodes, nodes + n, cmp);
		int end = 0;
		int num = 0;
		for (int i = 0; i < n; i++){
			if (nodes[i].sTime >= end) {
				num++;
				end = nodes[i].eTime;
			}
		}
		printf("%d\n",num);
	}
	system("pause");
	return 0;
}
//根据结束时间最早进行贪心，这类问题的重点在于找准贪心的点