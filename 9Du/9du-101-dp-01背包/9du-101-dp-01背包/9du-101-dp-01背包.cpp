#include <iostream>
using namespace std;
int main(){
	int a, e, f;
	for (a = 0; a <= 13; a++){
		for (e = 0; e <= 5; e++){
			for (f = 0; f <= 100; f++){
				int b = 13 - a;
				int g = 9 - e - f;
				int d = (b - 4) / g;
				int c = (a - 4)*f;
				int h = 5 - e;
				if ((b - 4) % g != 0 || d < 0 || d>100 || c < 0 || c>100 || g < 0 || g>100 || h < 0 || h>100){
					break;
				}
				if (c - e*d != 4){
					break;
				}
				printf("%d-%d-%d-%d-%d-%d-%d-%d\n", a, b, c, d, e, f, g, h);
			}
		}
	}
	system("pause");
	return 0;

}
