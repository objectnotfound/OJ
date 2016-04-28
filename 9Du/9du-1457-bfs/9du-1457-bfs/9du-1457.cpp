#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int maxn = 101;
int vis[maxn][maxn][maxn];

struct node{
	int x, y, z;
	int step;
	void newNode(int tx, int ty, int tz, int tt){
		x = tx;
		y = ty;
		z = tz;
		step = tt;
	}
};

queue<node> q;

int s, n, m;

void aTob(int &a, int sa, int &b, int sb){	  //a向中倒水
	if (a + b <= sb) {
		b = a + b;
		a = 0;
	}
	else{
		a = a + b - sb;
		b = sb;	
	}
}

int bfs(){
	while (!q.empty()){
		node tmp = q.front();
		int tx = tmp.x;
		int ty = tmp.y;
		int tz = tmp.z;
		int ts = tmp.step;
		q.pop();

		if (tx == 0 && ty == tz || ty==0&&tx==tz||tz==0&&tx==ty){
			return ts;
		}

		aTob(tx, s, ty, n);	 //1
		if (vis[tx][ty][tz] == 0){
			node new1;
			new1.newNode(tx,ty,tz,ts+1);
			q.push(new1);
			vis[tx][ty][tz] = 1;
		}
		tx = tmp.x; ty = tmp.y; tz = tmp.z; ts = tmp.step;

		aTob(tx, s, tz, m);
		if (vis[tx][ty][tz] == 0){
			node new1;
			new1.newNode(tx, ty, tz, ts + 1);
			q.push(new1);
			vis[tx][ty][tz] = 1;
		}
		tx = tmp.x; ty = tmp.y; tz = tmp.z; ts = tmp.step;

		aTob(ty, n, tz, m);
		if (vis[tx][ty][tz] == 0){
			node new1;
			new1.newNode(tx, ty, tz, ts + 1);
			q.push(new1);
			vis[tx][ty][tz] = 1;
		}
		tx = tmp.x; ty = tmp.y; tz = tmp.z; ts = tmp.step;

		aTob(ty, n, tx, s);
		if (vis[tx][ty][tz] == 0){
			node new1;
			new1.newNode(tx, ty, tz, ts + 1);
			q.push(new1);
			vis[tx][ty][tz] = 1;
		}
		tx = tmp.x; ty = tmp.y; tz = tmp.z; ts = tmp.step;

		aTob(tz, m, tx, s);
		if (vis[tx][ty][tz] == 0){
			node new1;
			new1.newNode(tx, ty, tz, ts + 1);
			q.push(new1);
			vis[tx][ty][tz] = 1;
		}
		tx = tmp.x; ty = tmp.y; tz = tmp.z; ts = tmp.step;

		aTob(tz, m, ty, n);
		if (vis[tx][ty][tz] == 0){
			node new1;
			new1.newNode(tx, ty, tz, ts + 1);
			q.push(new1);
			vis[tx][ty][tz] = 1;
		}
		tx = tmp.x; ty = tmp.y; tz = tmp.z; ts = tmp.step;	
	}
	return -1;
}

int main(){
	while (cin >> s >> n >> m){
		if (s == 0 && n == 0 && m == 0){
			break;
		}
		memset(vis, 0, sizeof(vis));
		while (!q.empty()){
			q.pop();
		}
		node start;
		start.x = s;
		start.y = 0;
		start.z = 0;
		start.step = 0;
		q.push(start);
		vis[s][0][0] = 1;

		int num = bfs();
		if (num == -1)  printf("NO\n");
		else{
			printf("%d\n", num);
		}

	}
	return 0; 
}

//bfs最关键的地方在于状态的转移！
//此题可以加一些剪枝策略，如s为基数肯定不能分