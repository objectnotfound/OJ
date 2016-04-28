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
		sort(nodes, nodes + N, cmp);//按照到起点的距离从小到大排序
		nodes[N].price = 0;	//把终点当做最后一个点
		nodes[N].dist = D;
		float maxRun = Cmax*Davg;//加满油最多可以跑的距离
		float sumDist = 0.00; //如果不能到达终点，总共能跑多远
		float sumCost = 0.0;  //总消费
		float restGas = 0.0;		//还剩多少油

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
			for (; k<N && nodes[k].price >= nodes[i].price; ++k)//找第一个比当前便宜的加油站
				continue;
			if (nodes[i].dist + maxRun >nodes[k].dist){//加部分油能够维持到K
				float tmpGas = (nodes[k].dist - nodes[i].dist) / Davg - restGas;
				if (tmpGas > 0){ //不是中间点
					sumCost += tmpGas * nodes[i].price;
					restGas = (nodes[k].dist - nodes[i].dist) / Davg;
				}				
			}
			else if (nodes[k].dist - nodes[i].dist > maxRun){//需要加满油
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

//暂时放一下，贪心的思想已经掌握到了，我的写法应该是相对较简洁的一种，但是边界条件可能没有考虑好，下次再仔细看看问题


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