#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int h;
	while (cin >> h){
		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= 2 * (h - i); j++) cout << " ";
			for (int j = 1; j <= h + 2 * i - 2; j++) cout << "*";
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}