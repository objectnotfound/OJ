#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
int m, n;
const int maxn = 101;
char matrix[maxn][maxn]; 
int vis[maxn][maxn];
int num = 0;

void dfs(int i, int j){	  //����һ���������顱
	vis[i][j] = 1;
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1; dy <= 1; dy++){
			if (dx != 0 || dy != 0){
				if (!vis[i + dx][j + dy] && matrix[i + dx][j + dy] == '@'){
					dfs(i + dx, j + dy);
				}
			}
		}
	}
}

int main(){
	while (cin >> m >> n){
		if (m == 0) break;
		for (int i = 0; i < m; i++){
			getchar();
			for (int j = 0; j < n; j++){
				//scanf("%c ",&matrix[i][j]);
				cin >> matrix[i][j];
				vis[i][j] = 0;
			}
		}
		num = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (!vis[i][j] && matrix[i][j] == '@'){
					num++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", num);
	}
	return 0;
}

//dfs����һ���ԡ�λ�á���Ϊ������ע������ʱ���ã��Լ�vis����ĸ���ʱ����dx,dy��ʹ�÷���
//bfsҲ������ͼ�����������Գ��Ա���Ա�
//��⣺dfs���õݹ�ʵ�ֵģ�bfs���ö���ʵ�ֵ�

//���ɣ�������Ҫ���ַ�����Ŀ�У�����ʹ��cin���룬����scanf���۵������ ���͡�\n��