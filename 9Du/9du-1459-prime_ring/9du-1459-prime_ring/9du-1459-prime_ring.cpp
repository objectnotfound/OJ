#include<cstdio>
#include<iostream>
using namespace std;

int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
int ring[17];
int vis[17];
int n;

int isPrime(int x){
	for (int i = 0; i < 15; i++){
		if (prime[i] == x) {
			return 1;
		}
	}
	return 0;
}

void dfs(int num){		//����dfs+���� ������
	if (num == n+1) {	//	 ����
		if (isPrime(ring[num - 1] + ring[1])){
			for (int i = 1; i < n; i++){
				printf("%d ", ring[i]);
			}
			printf("%d\n", ring[n]);
		}
	}

	for (int i = 2; i <= n; i++){
		if (!vis[i] && isPrime(i+ring[num-1])){
			vis[i] = 1;
			ring[num] = i;
			dfs(num+1);
			vis[i] = 0;	//�ص㣡���ݻ�����ʱ��Ҫ��ԭ
		}
	}
}

int main(){
	int nCase=0;
	while (cin>>n){
		for (int i = 1; i <= n; i++){
			vis[i] = 0;
		}
		ring[1] = 1;
		vis[1] = 1;
		printf("Case %d:\n", ++nCase); 
		dfs(2);
		printf("\n");
	}
	return 0;
}

//�ݹ�ͻ��ݡ�dfs�ǽ�����ص�
//���ݹ�����һ��Ҫע�⣬���ֳ��ı�����