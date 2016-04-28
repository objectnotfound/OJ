#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
int m, n;
const int maxn = 101;
char matrix[maxn][maxn]; 
int vis[maxn][maxn];
int num = 0;

void dfs(int i, int j){	  //遍历一个“八连块”
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

//dfs函数一般以【位置】作为参数；注意体会何时调用，以及vis数组的更新时机；dx,dy的使用方法
//bfs也可以做图的搜索，可以尝试编码对比
//理解：dfs是用递归实现的，bfs是用队列实现的

//技巧：在这种要读字符的题目中，果断使用cin读入，避免scanf蛋疼的误读‘ ’和‘\n’