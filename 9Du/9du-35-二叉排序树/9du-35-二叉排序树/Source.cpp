#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 105;
int n, num[maxn];
int loc;

struct node{
	int data;
	node* left;
	node* right;
}trees[maxn];
//静态地分配内存

node* creat(){
	trees[loc].left = trees[loc].right = NULL;
	return &trees[loc++];
}

node* add(node* root,int x){
	if (root == NULL){
		root = creat();
		root->data = x;
		return root;
	}
	else{
		if (x > root->data){
			root->right = add(root->right, x);
		}
		else if (x < root->data){
			root->left = add(root->left, x);
		}
	}
	return root;
}

void preOrder(node* &root){
	if (root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(node* &root){
	if (root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}
void postOrder(node* &root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int main(){
	while (scanf("%d", &n)!=EOF){
		node* root=NULL;
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
			root =  add(root, num[i]);
		}
		preOrder(root);
		printf("\n");
		inOrder(root);
		printf("\n");
		postOrder(root);
		printf("\n");
	}
	system("pause");
	return 0;
}

//关于二叉树的建立和遍历
//①可以考虑这里使用到静态分配，即使用数组
//②建树过程中返回的是指向节点的指针
//考虑用JAVA写一次试试