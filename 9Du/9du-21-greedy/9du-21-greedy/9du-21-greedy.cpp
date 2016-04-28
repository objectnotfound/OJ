#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn=1001;
int m, n;

struct node{
	float jb;
	float cf;
	float w;
}nodes[maxn];

bool cmp(node a, node b){
	return a.w >= b.w;
}

int main(){
	
	while (scanf("%d%d", &m, &n)==2){
		if (m == -1 && n == -1) break;
		for (int i = 0; i < n; i++){
			scanf("%f%f", &nodes[i].jb, &nodes[i].cf);
			nodes[i].w = nodes[i].jb / nodes[i].cf;
		}
		sort(nodes, nodes + n, cmp);
		float rest_cf = m - 0.0;
		float max_jb = 0.0;
		for (int i = 0; i < n; i++){
			if (rest_cf >= nodes[i].cf){ //要考虑到等于的情况
				max_jb += nodes[i].jb;
				rest_cf -= nodes[i].cf;
			}
			else if (rest_cf < nodes[i].cf) {
				max_jb += (rest_cf / nodes[i].cf)*nodes[i].jb;
				rest_cf = 0.0;
				break;
			}
		}
		printf("%.3f\n", max_jb);
	}
	system("pause");
	return 0;
}
//稍微注意下边界条件，逻辑还是很简单的