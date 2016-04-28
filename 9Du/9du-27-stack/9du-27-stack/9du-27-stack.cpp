#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int maxn = 205;
stack<double> in;
stack<int> op;
char str[maxn];
int mat[5][5] =
{ 1, 0, 0, 0, 0,
1, 1, 1, 0, 0,
1, 1, 1, 0, 0,
1, 1, 1, 1, 1,
1, 1, 1, 1, 1,
};

int main(){
	int num1;
	while (scanf("%d", &num1)!=EOF){
		double ans;
		op.push(0);
		in.push(num1);

		char ch;
		int num;
		
		/*scanf("%[^\n]", str);
		int lenth = strlen(str);
		str[lenth] = '#';
		str[lenth + 1] = '\0';*/
		int flag = 1;
		int finish = 0;
		while (1){
			if (flag%2){
				ch = getchar();
				/*if (ch == '\n'&&flag == 1&&num1==0){
					break;
				}*/
				if ( ch == ' '){ 
					ch = getchar(); 
				}
				if (ch == '\n'){
					finish = 1;
					ch = '#';
				}
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '#'){
					int operate;
					if (ch == '+') {
						operate = 1;
					}
					else if (ch == '-') {
						operate = 2;
					}
					else if (ch == '*') {
						operate = 3;
					}
					else if (ch == '/') {
						operate = 4;
					}
					else if (ch == '#') {
						operate = 0;
					}

					if (op.empty() || mat[op.top()][operate] == 0){
						op.push(operate);
					}
					else if (mat[op.top()][operate] == 1){
						while (mat[op.top()][operate] == 1){
							if (op.top() == 0) { ans = in.top(); break; }  //�������

							double a = in.top();
							in.pop();
							double b = in.top();
							in.pop();
							double c;
							if (op.top() == 1){
								c = a + b;
							}
							else if (op.top() == 2){
								c = b - a;
							}
							else if (op.top() == 3){
								c = b * a;
							}
							else if (op.top() == 4){
								c = b / a;
							}
							op.pop();
							in.push(c);
						}
						op.push(operate);
					}
				}
			}
			
			else{
				scanf("%d", &num);
				in.push((double)num);
			}
			if (finish == 1){
				break;
			}
			flag++;
		}
		if (num1 == 0 && flag == 1){
			break;
		}
		printf("%.2lf\n", ans);
	}
	system("pause");
	return 0;
}

//��ջ��ʹ�õ������ѵ㣬�����������ݵ����봦��
//�Ժ������⻹�����ַ���һ��¼��ȽϺã����ӵĻ��Ϳ��ǵ���дһ�����뺯�����ο��̵̳Ľⷨ
//���⣬������������float ��Ϊ double˲�����Ϊʲô��


//������һ���Ƚ�ţ�Ĵ���,��scanf�����úÌţ�
#include "stdio.h"
#include "string.h"
#define MAX 1001

double stack[MAX];
int tail;

int main(){
	int a;
	while (scanf("%d ", &a) && a != 0){
		tail = 0;
		stack[++tail] = 1.0*a;//tailʼ��ָ��ĩβ����λ��
		//1.��ջ�������ݣ��������*/�ţ�ֻ����ջβ��
		char ch1, ch2;
		while (scanf("%c %d%c", &ch1, &a, &ch2) != EOF){
			if (ch1 == '+'){
				stack[++tail] = 1.0*a;//push
			}
			else if (ch1 == '-'){
				stack[++tail] = -1.0*a;//push neg
			}
			else if (ch1 == '*'){
				stack[tail] = stack[tail] * a;//update tail
			}
			else if (ch1 == '/'){
				stack[tail] = stack[tail] / (double)a;//updata tail
			}
			if (ch2 != ' ')break;
		}
		//2.��ջ��ͷ�Ķ���ȫ�������������
		double result = 0;
		for (int i = 1; i <= tail; i++)result += stack[i];
		printf("%.2lf\n", result);
	}
	return 1;
}