#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 105;
const int inf = 0x7fffffff;
int n;
int a, b, c;
int dist[maxn][maxn];
int fa[maxn];

int findRoot(int x){  //注意是找根，而不是找父节点！！！
	if (fa[x] == x) return x;
	else{
		int tmp = findRoot(fa[x]);
		fa[x] = tmp;
		return tmp;
	}
}

bool inSame(int a, int b){
	if (findRoot(a) == findRoot(b)){
		return true;
	}
	else return false;
}

void merge(int a, int b){
	int rootA = findRoot(a);
	int rootB = findRoot(b);
	fa[rootB] = rootA;
}

int main(){
	while (scanf("%d", &n) != EOF&&n != 0)  {
		for (int i = 0; i < n*(n - 1) / 2; i++){
			scanf("%d%d%d", &a, &b, &c);
			dist[a-1][b-1] = dist[b-1][a-1] = c;
		}
		for (int i = 0; i < n; i++){
			fa[i] = i;
		}
		
		int tmpi = 0,tmpj = 0;
		int sum = 0;
		for (int t = 0; t < n - 1; t++){
			int min = inf; //注意定义min的地方，是每次找下一条边的时候都要初始化为最大的值
			for (int i = 0; i < n; i++){
				for (int j = i + 1; j < n; j++){
					if (!inSame(i, j) && dist[i][j] < min){
						min = dist[i][j];
						tmpi = i;
						tmpj = j;
					}
				}
			}
			merge(tmpi, tmpj);
			sum += dist[tmpi][tmpj];
		}
		int flag = 1;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (!inSame(i, j)) {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			printf("%d\n", sum);
		}
	
	}
	return 0;
}