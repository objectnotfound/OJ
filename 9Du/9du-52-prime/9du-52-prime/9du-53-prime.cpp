#include<cstdio>
#include<iostream>

using namespace std;
const int maxn=110002;
int prime[10001];
bool isPrime[maxn];
int num;

void init(){
	for (int m = 0; m < maxn; m++) 
		isPrime[m] = true;
	for (int i = 2; i<maxn && num < 10001; i++){ //Ҫ�ر�ע��߽����⣡����
		//if (num >= 10001) break;
		if (isPrime[i] == false) continue;
		if (isPrime[i]) {
			prime[num++] = i;
			for (int j = i; j < maxn; j += i){
				isPrime[j] = false;
			}
		}
	}	
}

int main(){
	init();

	//int a[10];
	//a[10] = 11;
	//cout << a[10] << endl;

	/*cout << num << endl;
	cout << prime[num-1] << endl;*/

	int k;
	while (cin >> k){
		cout << prime[k - 1] << endl;
	}
	return 0;
}

//ע�⣺
//��������û�ж�����Խ����м�飬���ж�����߽�Ҫ����С�ģ�һ��Ҫ��0~len-1�ĸ��
//�����ı��ʻ��Ǻܸߵģ�11w��������������1w�࣬�ӽ�10%�ˣ�
