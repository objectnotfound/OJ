#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;
const int maxn = 55;
int road[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int a, b, c, t;

struct node{
	int x, y, z;
	int t;
};

queue<node> q;
int dx[] = { -1, 0, 0, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0, 0, 0 };
int dz[] = { 0, 0, 0, 1, -1, 0 };


int bfs(){
	while (!q.empty()){
		node tn = q.front();
		/*if (tn.t > t){
			printf("-1\n");
			break;
		}
		if (tn.x == a - 1 && tn.y == b - 1 && tn.z == c - 1){
			printf("%d\n", tn.t);
			break;
		}*/
		q.pop();
		for (int i = 0; i < 6; i++){
			int nx = tn.x + dx[i];
			int ny = tn.y + dy[i];
			int nz = tn.z + dz[i];
			if (nx >= 0 && nx < a && ny >= 0 && ny < b && nz >= 0 && nz < c && vis[nx][ny][nz] == 0 && road[nx][ny][nz] == 0){
				vis[nx][ny][nz] = 1;	  //尼玛，== 和 =！！！
				node ttn;
				ttn.x = nx; ttn.y = ny; ttn.z = nz; ttn.t = tn.t + 1;
				q.push(ttn);
				if (ttn.x == a - 1 && ttn.y == b - 1 && ttn.z == c - 1){
					return ttn.t;
				}
			}
		}
	}
	return -1;
}

int main(){
	int k;
	cin >> k;
	while (k--){
		cin >> a >> b >> c >> t;
		for (int i = 0; i < a; i++){
			for (int j = 0; j < b; j++){
				for (int k = 0; k < c; k++){
					cin >> road[i][j][k];
					vis[i][j][k] = 0;
				}
			}
		}
		while (!q.empty()){
			q.pop();
		}
		node tmp;
		tmp.x = tmp.y = tmp.z = tmp.t = 0;
		q.push(tmp);
		vis[0][0][0] = 1;
		int num = bfs();
		if (num ==-1 && num>t) printf("-1\n");
		else printf("%d\n", num);
		
		return 0;
	}
}

//血的教训！ == 和 = 一定要注意！