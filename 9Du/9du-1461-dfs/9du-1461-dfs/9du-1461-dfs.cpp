#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 10;
char road[maxn][maxn];
int vis[maxn][maxn];
int n, m, T;
int desX, desY;
int flag = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, int t){
	if (road[x][y] == 'D'&&t == T){
		flag = 1;
		return;
	}
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//找到可以走的下一节点
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && road[nx][ny] != 'X'){
			vis[nx][ny] = 1;
			dfs(nx, ny, t + 1);
			vis[nx][ny] = 0;	//这里非常重要，因为本次遍历的节点不成功的话，另一条路径还是可以经过这个点
		}
	}
}

int main(){
	while (cin >> n >> m >> T){
		if (n == 0 && m == 0 && T == 0) break;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				vis[i][j] = 0;
				cin >> road[i][j];
			}
		} 
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (road[i][j] == 'D'){
					desX = i;
					desY = j;
				}
			}
		}
		int sx, sy;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (road[i][j] == 'S'){
					sx = i;
					sy = j;
				}
			}
		}
		if (((sx + sy) % 2 + T % 2) % 2 == (desX + desY) % 2){
			vis[sx][sy] = 1;
			dfs(sx, sy, 0);
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//还是回溯时候对现场的“还原”！太重要了
//递归算法的调试相对比较复杂，所以原理尽量不要出问题！

//bfs dfs超时的话，可以适当剪枝试一下，或者scanf?