#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
const int maxn = 1005;
bool mark[maxn];
int prime[maxn];
int num;



void init(){
	for (int i = 0; i < maxn; i++) mark[i] = true;
	
	for (int i = 2; i < maxn; i++){
		if (mark[i] == false) continue;
		else{
			if (mark[i] == true){
				prime[num++] = i; //第一个素数是prime[0]=2
				for (int j = i*i; j < maxn; j += i){
					mark[j] = false;
				}
			}
		}
	}
}

int main(){
	init();

	int aPrime[maxn];
	int aN[maxn];
	int aNum;

	int nPrime[maxn];
	int nN[maxn];
	int nNum;

	int n, a;
	
	while (cin>>n&&cin>>a){
	//while (scanf("%d%d",&n,&a)==2){
		nNum = aNum = 0;
		for (int i = 0; i < maxn; i++){
			aN[i] = nN[i] = 0;
		}

		//对a进行素因式分解
		int bound = (int)sqrt(a) + 1;
		for (int i = 0; prime[i] < bound; i++){
			if (a == 1){ break; }
			if (a%prime[i] == 0){
				while (a%prime[i] == 0){
					aPrime[aNum] = prime[i];
					aN[aNum]++;
					a = a / prime[i];
				}
				aNum++;
			}
		}
		if (a != 1){  //对剩余部分进行处理
			aPrime[aNum] = a;
			aN[aNum] = 1;
			aNum++;
		}

		//对n!进行素因数分解
		for (int i = 0; prime[i] <= n; i++){
			if (prime[i] != 0 && n / prime[i] != 0) {//prime[i]肯定是素因数
				nPrime[nNum] = prime[i];
				/*for (int k = 1; n / (int(pow(prime[i], k))) != 0; k++){
					nN[nNum] += n / (int(pow(prime[i], k)));
				}*/
				int t = n;
				while (t){
					nN[nNum] += t / prime[i];
					t /= prime[i];
				}
				nNum++;
			}
		}
		//开始寻找最小的k

		int minK = 100000;
		for (int i = 0; i < aNum; i++){
			for (int j = 0; j < nNum; j++){
				if (nPrime[j] == aPrime[i]){
					if (nN[j] / aN[i] < minK) {
						minK = nN[j] / aN[i];
					}
					break;
				}
			}
		}
		minK = minK == 100000 ? 0 : minK;
		//cout << minK << endl;
		printf("%d\n", minK);
	}
	return 0;
}

//用cout超时了！换成printf好了 太尼玛！！

//很经典的题：1素数筛 2转化为求素因子的问题！