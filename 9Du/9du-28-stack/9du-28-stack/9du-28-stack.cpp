#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;
int n;
int a;
char ch;
char tmp;
stack<int> s;



int main(){
	while (scanf("%d", &n) != EOF){
		if (n == 0){ break; }
		tmp=getchar();
		while (!s.empty()){
			s.pop();
		}
		for (int i = 0; i < n; i++){
			cin >> ch;
			switch (ch){
			case 'A':{
				if (s.empty()){
					printf("E\n");
				}
				else{
					printf("%d\n", s.top());
				}
				break;
			}
			case 'P':{
				cin >> a;
				s.push(a);
				break;
			}
			case 'O':{
				if (s.empty()){

				}
				else{
					s.pop();
				}
				break;
			}	
			}		
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//这种题以后多用cin cout 因为对于字符的处理用scanf很JB蛋疼!