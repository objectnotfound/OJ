#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct cmp{
	bool operator()(int &a, int &b){
		return a>b;	//小顶堆
	}
};

//priority_queue<int, vector<int>, greater<int> > q;	//为什么不行！！！
priority_queue<int, vector<int>, cmp > q;
//这里声明一个优先队列的时候，默认是大顶堆，如果要实现小顶堆，最好自己写cmp结构体
//一般来说，int 类型可以直接用greater<int>来实现，不知道可以为什么不行

int main(){

	int n, tmp;
	while (cin >> n){
		if (n == 0) break;
		while (!q.empty()){
			q.pop();
		}
		for (int i = 0; i < n; i++){
			cin >> tmp;
			q.push(tmp);
		}
		/*while (!q.empty()){
		cout << q.top();
		q.pop();
		}*/
		//注意：关于优先队列，由于其实现是用堆的原理，所以从观察窗口看到的q的值并不是按照顺序排列，但是如果pop出来就是顺序的了
		int sum = 0;
		while (q.size() >= 2){
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			int c = a + b;
			q.push(c);
			sum += c;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;

}
