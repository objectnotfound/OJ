#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 101;
const int inf = -1;	//˼����0x3fffffff�ò���,-1��ʾ�������У����Ǳ�ʾ���ֵ�ڱȽϵ�ʱ����ܻ������
const int big = 0x3fffffff;
int dist[maxn][maxn];
int vis[maxn];//��¼�ڵ��Ƿ���뵽����
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
			vis[i] = 0;//���нڵ��ʼ��Ϊδ���뵽U��
			dist[i][i] = 0; //��䲻Ҫ����ʲôӰ�죿��  ans:��ȻҪ��
		}
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			dist[a][b] = dist[b][a] = c;
		}
		
		vis[1] = 1;//�ڵ�1��Դ�ڵ�
		int k;
		for (int t = 1; t < n; t++){ //һ��Ҫ��n-1��
			int min = big;
			for (int i = 2; i <= n; i++){
				if (vis[i]==0){
					if (dist[1][i] < min){
						min = dist[1][i];
						k = i;
					}
				}
			}
			//���¾���
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

//dijkstraֻ���㵥Դ��̾�������⣬�㷨˼���prim��С�������㷨���񣬲�ͬ����ÿ��������С��Դ�㵽��U��ϵĽڵ����Сֵ
//���Գ���vector д�ڽ����������ԣ�