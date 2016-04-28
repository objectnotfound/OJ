#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 101;
const int inf = -1;	//˼����0x3fffffff�ò���
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
			dist[i][i] = 0; //��䲻Ҫ����ʲôӰ�죿��
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

//Floyd�㷨���ص������м������ѭ����˼��k���������ڲ��������𣿣�
//Ŀǰ�����ǲ�ͬ�ģ�k���������ͨ���������ٲ���һ��