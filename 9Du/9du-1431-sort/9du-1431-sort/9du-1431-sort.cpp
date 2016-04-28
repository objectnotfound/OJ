//数据量并不是问题啊，用sort和qsort都是OK的
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int num[1000000];


int cmp(const void* a, const void* b){//返回1的时候，表示a排在b【后面】
	return *(int*)a > *(int*)b;	//升序
}
//对于qsort而言: ①形参形式很重要，这里都是两个空指针	②返回值只能是int 

bool cmp2(const int a, const int b){//返回ture的时候，表示a排在b【前面】（很大的区别）
	return a < b;//a<b的时候，a排在b前面，即升序
}
//对于sort，明确以下几点：①默认是升序排列 ②cmp参数返回bool类型，可以不用指针
//尽量使用sort
//sort 不保证相等元素的相对位置保持不变，可能恰好没有变，也可能恰好变了。std::sort 封装了快速排序算法，但它对参数的有自己的要求，在没有太在意的情况下 std::sort 工作得可能很好，也可能不工作，我需要对它的基本原理有个了解。要知道什么是严格偏序，也要知道什么随机迭代器，同时也要知道 std::sort 不是稳定的排序算法，它不保证“相等”元素的相对位置，使用 std::stable_sort 来保证这一点。
//STL容器的排序，支持随机访问的容器vector,deque,string没有sort成员，可调用std::sort排序；list排序调用自带的list::sort。

//先说明一下qsort和sort，只能对连续内存的数据进行排序，像链表这样的结构是无法排序的。

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


////使用hash的思想，其实是没有冲突的简单hash
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
