#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 101;
const int inf = -1;	//思考用0x3fffffff好不好,-1表示存在性行，但是表示最大值在比较的时候可能会出问题
const int big = 0x3fffffff;
int dist[maxn][maxn];
int vis[maxn];//记录节点是否加入到Ｕ中
int n, m;

int main(){
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0){
			break;
		}
		int a, b, c;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dist[i][j] = inf;
			}
			vis[i] = 0;//所有节点初始化为未加入到U中
			dist[i][i] = 0; //这句不要会有什么影响？？  ans:当然要！
		}
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			dist[a][b] = dist[b][a] = c;
		}
		
		vis[1] = 1;//节点1是源节点
		int k;
		for (int t = 1; t < n; t++){ //一共要找n-1次
			int min = big;
			for (int i = 2; i <= n; i++){
				if (vis[i]==0){
					if (dist[1][i] < min){
						min = dist[1][i];
						k = i;
					}
				}
			}
			//更新距离
			vis[k] = 1;
			for (int i = 2; i <= n; i++){
				if (vis[i] == 0 && dist[1][k] + dist[k][i] < dist[1][i]){
					dist[i][1] = dist[1][i] = dist[1][k] + dist[k][i];
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				printf("dist[%d][%d]=%d \n", i, j, dist[i][j]);
			}
		}
	}
	return 0;
}

//dijkstra只计算单源最短距离的问题，算法思想和prim最小生成树算法很像，不同的是每次是找最小的源点到非U结合的节点的最小值
//可以尝试vector 写邻接链表做尝试！