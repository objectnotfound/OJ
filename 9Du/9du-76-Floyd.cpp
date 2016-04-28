#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 101;
const int inf = -1;	//思考用0x3fffffff好不好
int dist[maxn][maxn];
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
			dist[i][i] = 0; //这句不要会有什么影响？？
		}
			
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			dist[a][b] = dist[b][a] = c;
		}
		for (int k=1; k <=n; k++){
			for (int j = 1; j <= n; j++){		 
				for (int i = 1; i <= n; i++){
					if (dist[i][k] == inf || dist[k][j] == inf){
						continue;
					}
					if (dist[i][j] == inf || dist[i][k] + dist[k][j] < dist[i][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		printf("%d\n", dist[1][n]);
	}
	return 0;
}

//Floyd算法的重点在于中间的三重循环，思考k在外层和在内层有区别吗？？
//目前看来是不同的，k放在最外层通过，明天再测试一下