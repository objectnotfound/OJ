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

int num = 0;//现在树中的节点数

node* creat(char ch){
	node n;
	n.lchild = n.rchild = NULL;
	n.ch = ch;
	num++; //第一个节点的编号为1
	nodes[num] = n;
	return &nodes[num];
}

node* build(int prel,int prer,int inl,int inr){
	if (prel <= prer&&inl <= inr){
		if (prel == prer || inl == inr){
			//插入
			return creat(in[inl]);
		}
		for (int i = inl; i <= inr; i++){
			if (in[i] == pre[prel]){
				//把in[i]加到树中
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