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
	for (int i = 2; i<maxn && num < 10001; i++){ //要特别注意边界问题！！！
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

//注意：
//本编译器没有对数组越界进行检查，所有对数组边界要格外小心，一定要有0~len-1的概念！
//素数的比率还是很高的，11w个数中素数就有1w多，接近10%了！
