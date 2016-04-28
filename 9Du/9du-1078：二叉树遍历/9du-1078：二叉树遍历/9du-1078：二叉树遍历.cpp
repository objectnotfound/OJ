#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 30;
char pre[maxn];
char in[maxn];

struct node{
	node* lchild;
	node* rchild;
	char ch;
}nodes[maxn];

int num = 0;//�������еĽڵ���

node* creat(char ch){
	node n;
	n.lchild = n.rchild = NULL;
	n.ch = ch;
	num++; //��һ���ڵ�ı��Ϊ1
	nodes[num] = n;
	return &nodes[num];
}

node* build(int prel,int prer,int inl,int inr){
	if (prel <= prer&&inl <= inr){
		if (prel == prer || inl == inr){
			//����
			return creat(in[inl]);
		}
		for (int i = inl; i <= inr; i++){
			if (in[i] == pre[prel]){
				//��in[i]�ӵ�����
				node* n = creat(in[i]);
				n->lchild = build(prel + 1, i - inl + prel, inl, i - 1);
				n->rchild = build(prer - inr + i + 1, prer, i + 1, inr);
				return n;
			}
		}
	}
	return NULL;
	
}

void post(node* root){
	if (root != NULL){
		post(root->lchild);
		post(root->rchild);
		printf("%c", root->ch);
	}
}


int main(){
	cin >> pre >> in;
	node* root = build(0, strlen(pre) - 1, 0, strlen(in) - 1);
	printf("%d\n", num);
	post(root);
	return 0;
}