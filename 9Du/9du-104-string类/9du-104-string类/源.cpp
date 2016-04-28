#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++){
		str[i] = tolower(str[i]);
	}
	/*string a;
	gets(a);*/	//错误，gets()的参数不能是string对象

	getchar(); //读掉最后一个换行
	char a[100];
	while (gets(a)){
		string b = a, c = a;
		for (int i = 0; i < b.size(); i++){
			b[i] = tolower(b[i]);
		}
		int t = b.find(str, 0);
		while (t != string::npos){
			b.erase(t, str.size());
			c.erase(t, str.size());   //c保存原始的字符串
			t = b.find(str, t);
		}
		t = c.find(' ', 0);
		while (t != string::npos){
			c.erase(t, 1);
			t = c.find(' ',0);
		}
		cout << c << endl;
	}
	return 0;
}