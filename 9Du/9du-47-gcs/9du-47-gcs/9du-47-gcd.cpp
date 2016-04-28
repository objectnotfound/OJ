#include<cstdio>
#include<iostream>

using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	else return(gcd(b, a%b));
}

//·ÇµÝ¹éÐÎÊ½
//int gcd(int a, int b){
//	//if (b==0) return a;
//	while (b != 0){
//		int tmp = a;
//		a = b;
//		b = tmp%b;
//	}
//	return a;
//}

int main(){
	int a, b;
	while (cin >> a >> b){
		int res = gcd(a, b);
		cout << res << endl;
	}

	return 0;
}