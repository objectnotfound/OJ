#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;
const int maxn = 2002;
int in[maxn];
map < string, int > m;


int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		if (n == 0) break;
		string a, b;
		m.clear();
		int idx = 0;//一开始m中有0个元素
		for (int i = 1; i <= 2*n; i++){
			in[i] = 0;
		}
		for (int i = 0; i < n; i++){
			cin >> a >> b;
			if (m.find(b) == m.end()){//m中没有b ，编号从1开始
				m[b] = ++idx;
			}
			if (m.find(a) == m.end()){
				m[a] = ++idx;
			}
			int idxb = m[b];
			in[idxb] = 1;
		}
		int num = 0;
		for (int i = 1; i <= idx; i++){
			if (in[i] == 0) num++;
		}
		if (num == 1) printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}