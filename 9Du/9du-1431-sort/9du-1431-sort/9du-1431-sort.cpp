//���������������Ⱑ����sort��qsort����OK��
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int num[1000000];


int cmp(const void* a, const void* b){//����1��ʱ�򣬱�ʾa����b�����桿
	return *(int*)a > *(int*)b;	//����
}
//����qsort����: ���β���ʽ����Ҫ�����ﶼ��������ָ��	�ڷ���ֵֻ����int 

bool cmp2(const int a, const int b){//����ture��ʱ�򣬱�ʾa����b��ǰ�桿���ܴ������
	return a < b;//a<b��ʱ��a����bǰ�棬������
}
//����sort����ȷ���¼��㣺��Ĭ������������ ��cmp��������bool���ͣ����Բ���ָ��
//����ʹ��sort
//sort ����֤���Ԫ�ص����λ�ñ��ֲ��䣬����ǡ��û�б䣬Ҳ����ǡ�ñ��ˡ�std::sort ��װ�˿��������㷨�������Բ��������Լ���Ҫ����û��̫���������� std::sort �����ÿ��ܺܺã�Ҳ���ܲ�����������Ҫ�����Ļ���ԭ���и��˽⡣Ҫ֪��ʲô���ϸ�ƫ��ҲҪ֪��ʲô�����������ͬʱҲҪ֪�� std::sort �����ȶ��������㷨��������֤����ȡ�Ԫ�ص����λ�ã�ʹ�� std::stable_sort ����֤��һ�㡣
//STL����������֧��������ʵ�����vector,deque,stringû��sort��Ա���ɵ���std::sort����list��������Դ���list::sort��

//��˵��һ��qsort��sort��ֻ�ܶ������ڴ�����ݽ������������������Ľṹ���޷�����ġ�

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		memset(num,0, sizeof(num));
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
		}
		sort(num, num + n,cmp2);
		//qsort(num, n, sizeof(num[0]), cmp);
		printf("%d", num[n - 1]);
		for (int i = n - 2; i>=n - m; i--){
			printf(" %d", num[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


////ʹ��hash��˼�룬��ʵ��û�г�ͻ�ļ�hash
//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int offset = 500000;
//const int maxn = 1000001;
//int myhash[maxn];
//
//int main(){
//	int n, m;
//	while (scanf("%d%d", &n, &m) == 2){
//		memset(myhash, 0, sizeof(myhash));
//		int num;
//		for (int i = 0; i < n; i++){
//			scanf("%d", &num);
//			myhash[num + offset] = 1;
//		}
//		for (int i = maxn - 1; i >= 0;i--){
//			if (myhash[i] == 1)	{
//				m--;
//				printf("%d", i - offset);
//				if (m == 0){
//					printf("\n");
//					break;
//				}else{
//					printf(" "); 
//				}
//			}	
//		}
//	}
//	system("pause");
//	return 0;
//}
