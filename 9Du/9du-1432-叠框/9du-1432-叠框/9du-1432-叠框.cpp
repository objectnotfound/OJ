#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n;
	char a;
	char b;
	char sign[80][80];
	while (cin >> n >> a >> b){
		if (n == 1) cout << a<<"\n";
		else{
			int x = (n + 1) / 2, y = (n + 1) / 2;
			sign[x][y] = a;
			for (int i = 1; i <= (n - 1) / 2; i++){
				for (int j = x - i; j <= x + i; j++){
					sign[x - i][j] = i % 2 ? b : a;
					sign[x + i][j] = i % 2 ? b : a;
					sign[j][y - i] = i % 2 ? b : a;
					sign[j][y + i] = i % 2 ? b : a;
				}
			}
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					if (i == 1 && (j == 1 || j == n) || i == n && (j == 1 || j == n)) cout << " ";
					else cout << sign[i][j];
				}
				cout << "\n";
				//if (i<n) cout << "\n";
			}
		}
		cout << "\n";
	}
	system("puase");
	return 0;
}

//	 Presentation Error搞得老子要哭了。。。没有主要到说的是“叠筐与叠筐之间应有一行间隔。”，即两个case之间要有一个换行！
//先用一个二维数组来保存要输出的字符阵列