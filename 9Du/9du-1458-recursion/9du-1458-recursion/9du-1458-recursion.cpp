#include<cstdio>
#include<iostream>
using namespace std;

long long f(int n){
	if (n == 1) return 2;
	else return 3 * f(n - 1) + 2;
}

int main(){
	int n;
	while (cin>>n){
		printf("%lld\n", f(n));
	}
	return 0;
}

//递归的重点：出口，递归算法

//使用long?还是long long ??	 int?
