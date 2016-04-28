#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
const int maxn = 105;
char str[maxn];
char tmpStr[maxn];
struct node{
	char ch;
	int i;
	node(char ch1,int i1){
		ch = ch1;
		i = i1;
	}
};

stack<node> s;

int main(){
	while (scanf("%s",str)!=EOF){
		memset(tmpStr, 0, sizeof(tmpStr));
		strcpy(tmpStr, str);
		for (int i = 0; str[i] != '\0'; i++){
			tmpStr[i] = ' ';
			if (str[i] == '(' || str[i] == ')'){
				node tmp = node(str[i],i);
				if (!s.empty() && s.top().ch == '('&&tmp.ch == ')'){
					s.pop();
				}
				else{
					s.push(tmp);
				}
			}
		}
		while (!s.empty()){
			tmpStr[s.top().i] = (s.top().ch == '(' ? 36 : '?');
			s.pop();
		}
		printf("%s\n", str);
		printf("%s\n", tmpStr);
		/*int k;
		for (k = strlen(tmpStr) - 1; tmpStr[k] == ' '; k--){}
		for (int i = 0; i <= k; i++){
			printf("%c", tmpStr[i]);
		}
		printf("\n");*/
		

	}
	system("pause");
	return 0;
}
//忘了写！=EOF 直接Output Limit Exceed了七次！！！