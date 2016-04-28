#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct cmp{
	bool operator()(int &a, int &b){
		return a>b;	//С����
	}
};

//priority_queue<int, vector<int>, greater<int> > q;	//Ϊʲô���У�����
priority_queue<int, vector<int>, cmp > q;
//��������һ�����ȶ��е�ʱ��Ĭ���Ǵ󶥶ѣ����Ҫʵ��С���ѣ�����Լ�дcmp�ṹ��
//һ����˵��int ���Ϳ���ֱ����greater<int>��ʵ�֣���֪������Ϊʲô����

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
		//ע�⣺�������ȶ��У�������ʵ�����öѵ�ԭ�����Դӹ۲촰�ڿ�����q��ֵ�����ǰ���˳�����У��������pop��������˳�����
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
