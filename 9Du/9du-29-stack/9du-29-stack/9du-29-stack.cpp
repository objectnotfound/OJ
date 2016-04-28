#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;
const int maxn = 1005;
char str[maxn];
stack<int> op;
stack<double> in;
int mat[5][5] = {
	0, 0, 0, 0, 0,
	1, 1, 1, 0, 0,
	1, 1, 1, 0, 0,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1
};

void getNext(int &isOp, int &data, int &i){
	if (i == 0 && op.size()==0){
		isOp = 1;
		data = 0;
		return;
	}
	if (str[i] == '\0'){
		isOp = 1;
		data = 0;
		return;
	}
	if (str[i] >= '0'&&str[i] <= '9'){

		int tmp = str[i] - '0';
		i++;
		while (str[i] >= '0'&&str[i] <= '9'){
			tmp *= 10;
			tmp += str[i];
			i++;
		}
		isOp = 0;
		data = tmp;
		return;			
	}
	else if (str[i] == '+'){
		isOp = 1;
		data = 1;
		i++;
		return;
	}
	else if (str[i] == '-'){
		isOp = 1;
		data = 2;
		i++;
		return;
	}
	else if (str[i] == '*'){
		isOp = 1;
		data = 3;
		i++;
		return;
	}
	else if (str[i] == '/'){
		isOp = 1;
		data = 4;
		i++;
		return;
	}
	
}

int main(){
	while (cin >> str){
		
		int isOp=0,data=0;
		int i = 0;
		while (!in.empty()){
			in.pop();
		}
		while (!op.empty()){
			op.pop();
		}
		
		while (1){
			getNext(isOp, data, i);
			if (!isOp){
				in.push(data);
			}
			if (isOp){
				if (op.empty()){
					op.push(data);
				}
				else {
					if (mat[op.top()][data] == 0){
						op.push(data);
					}
					else{
						while (mat[op.top()][data] == 1){
							double num;
							double a = in.top();
							in.pop();
							double b = in.top();
							in.pop();
							switch (op.top()){
							case 1:{
								num = a + b;
								break;
							}
							case 2:{
								num = b-a;
								break;
							}
							case 3:{
								num = b*a;
								break;
							}
							case 4:{
								num = b / a;
								break;
							}
							}
							in.push(num);
							op.pop();
						}
						op.push(data);
					}
				}
			}
			if (op.size() == 2 && op.top() == 0) {
				break;
			}
		}
		printf("%.0lf\n", in.top());
		

	}
	system("pause");
	return 0;
}


#include <stdio.h>
int main()
{
	int i, j, k, a[100];
	char x;
	while (scanf("%d", &k) != EOF)
	{
		a[0] = 0;
		i = 0;
		a[++i] = k;
		while (scanf("%c", &x) != EOF && (x == '+' || x == '-' || x == '*' || x == '/'))
		{
			scanf("%d", &k);
			if (x == '+')
				a[++i] = k;
			else if (x == '-')
				a[++i] = -1 * k;
			else if (x == '*')
				a[i] *= k;
			else
				a[i] /= k;
		}
		for (j = 1; j <= i; j++)
			a[0] += a[j];
		printf("%d\n", a[0]);
	}
	return 0;
}

#include <iostream>
#include <stack>
using namespace std;

string str;
int pos;

double getNum(){
	double v = 0;
	for (; pos<str.length(); pos++){
		if (str[pos]>'9' || str[pos]<'0'){
			break;
		}
		v *= 10;
		v += str[pos] - '0';
	}
	return 1.0*v;
}

int main(int argc, char* argv[]){
	double a, b;
	double v;
	while (cin >> str){
		stack<double> s;
		pos = 0;
		s.push(getNum());
		while (pos<str.length()){
			if (str[pos] == '*'){
				pos++;
				a = s.top();
				s.pop();
				b = getNum();
				s.push(a*b);
			}
			if (str[pos] == '/'){
				pos++;
				a = s.top();
				s.pop();
				b = getNum();
				s.push(a / b);
			}
			if (str[pos] == '+'){
				pos++;
				s.push(getNum());
			}
			if (str[pos] == '-'){
				pos++;
				s.push(-1.0*getNum());
			}
		}
		v = 0;
		while (!s.empty()){
			v += s.top();
			s.pop();
		}
		cout << v << endl;
	}
	return 0;
}

