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

//�ݹ���ص㣺���ڣ��ݹ��㷨

//ʹ��long?����long long ??	 int?
