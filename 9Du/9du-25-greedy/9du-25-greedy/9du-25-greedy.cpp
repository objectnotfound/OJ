#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 501;
float Cmax;
float D;
float Davg;
int N;

struct node{
	float price;
	float dist;
};

bool cmp(node a, node b){
	return a.dist < b.dist;
}

int main(){
	node nodes[maxn];
	while (scanf("%f%f%f%d", &Cmax, &D, &Davg, &N)){
		for (int i = 0; i < N; i++){
			scanf("%f%f", &nodes[i].price, &nodes[i].dist);
		}
		sort(nodes, nodes + N, cmp);//���յ����ľ����С��������
		nodes[N].price = 0;	//���յ㵱�����һ����
		nodes[N].dist = D;
		float maxRun = Cmax*Davg;//�������������ܵľ���
		float sumDist = 0.00; //������ܵ����յ㣬�ܹ����ܶ�Զ
		float sumCost = 0.0;  //������
		float restGas = 0.0;		//��ʣ������

		if (D == 0){
			printf("0.00\n");
		}

		if (nodes[0].dist > 0){
			printf("The maximum travel distance = 0.00\n");
		}
		int i;
		for (i = 0; i < N; i++){	
			if (i != 0){
				restGas = restGas - (nodes[i].dist - nodes[i - 1].dist) / Davg;
			}
			int k = i + 1;
			for (; k<N && nodes[k].price >= nodes[i].price; ++k)//�ҵ�һ���ȵ�ǰ���˵ļ���վ
				continue;
			if (nodes[i].dist + maxRun >nodes[k].dist){//�Ӳ������ܹ�ά�ֵ�K
				float tmpGas = (nodes[k].dist - nodes[i].dist) / Davg - restGas;
				if (tmpGas > 0){ //�����м��
					sumCost += tmpGas * nodes[i].price;
					restGas = (nodes[k].dist - nodes[i].dist) / Davg;
				}				
			}
			else if (nodes[k].dist - nodes[i].dist > maxRun){//��Ҫ������
				sumCost += (Cmax - restGas)*nodes[i].price;
				restGas = Cmax;
			}	
			if (nodes[i+1].dist - nodes[i].dist > maxRun){
				sumDist = nodes[i].dist + maxRun;
				printf("The maximum travel distance = %.2f\n", sumDist);
				break;
			}
		}
		if (i == N){
			printf("%.2f\n", sumCost);
		}
	}
	system("pause");
	return 0;
}

//��ʱ��һ�£�̰�ĵ�˼���Ѿ����յ��ˣ��ҵ�д��Ӧ������Խϼ���һ�֣����Ǳ߽���������û�п��Ǻã��´�����ϸ��������


//if (nodes[i].price < tmpNode.price && nodes[i].dist - tmpNode.dist <= maxRun){
//	sumCost += (nodes[i].dist - tmpNode.dist - canRun) / Davg*tmpNode.price;
//	tmpNode = nodes[i];
//	canRun = 0.0;
//}
//else if (nodes[i].price > tmpNode.price && nodes[i + 1].dist - tmpNode.dist > maxRun){
//	sumCost += (Cmax - canRun / Davg)*tmpNode.price;
//	canRun = maxRun - (nodes[i].dist - tmpNode.dist);
//	tmpNode = nodes[i];
//}
//else if (nodes[i + 1].dist - nodes[i].dist > maxRun){
//	sumDist = tmpNode.dist + maxRun;
//	printf("The maximum travel distance = %.2f\n", sumDist);
//	break;
//}