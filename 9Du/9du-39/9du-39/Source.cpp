//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//const int maxn = 12;
//int a[maxn];
//int b[maxn];
//
//int main(){
//	int aa, bb;
//	while (scanf("%d%d", &aa, &bb)==2){
//		int i = 0, j = 0;
//		while (aa / 10 != 0){  //�ɸ�Ϊaa��=0������Ͳ���Ҫa[i++] = aa % 10;
//			a[i++] = aa % 10;
//			aa /= 10;
//		}
//		a[i++] = aa % 10;
//		while (bb / 10 != 0){
//			b[j++] = bb % 10;
//			bb /= 10;
//		}
//		b[j++] = bb % 10;
//		int num = 0;
//		for (int k = 0; k < i; k++){
//			for (int m = 0; m < j; m++){
//				num += a[k] * b[m];
//			}
//		}
//		printf("%d\n", num);
//	}
//
//	system("pause");
//	return 0;
//}


//����2��
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
char a[11], b[11];
int res2;

int main(){
	while (cin >> a >> b){
		int res=0;
		for (int i = 0; a[i]!=0; i++){
			for (int j = 0; b[j] != 0; j++){
				res += (a[i] - '0')*(b[j] - '0');
			}
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}

//ʹ���ַ�������֣��ܱ�ݣ�ע��'\0'��Ӧ��ASCII����0������ʹ��a[i]!='\0'����a[i]!=0���У�
//int��ȫ�ֱ���(�ѿռ�)���Զ���ʼ��Ϊ0������int�;ֲ�������ջ�ռ䣩�����ʼ����
