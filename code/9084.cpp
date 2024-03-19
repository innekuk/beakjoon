#include<iostream>
#include<algorithm>


using namespace std;



int coinarr[20] = {0};

int dparr[10005] ={0};
int main(){
	int t, n,m;
	scanf("%d" , &t);
	for (int i =0; i<t; i++){
		scanf("%d", &n);
		for (int j =0; j < n; j++){
			scanf("%d" , &coinarr[j]);
		}
		scanf("%d",&m);
		for (int j = 0 ; j<= m; j++){
			dparr[j] = 0;
		}
		for (int j = 0 ; j< n ;j++){
			dparr[coinarr[j]] += 1;
			for (int f = coinarr[j] +1; f <= m; f++){
				dparr[f] += dparr[f - coinarr[j]];
			}
		}




		printf("%d\n" , dparr[m]);
	}

}

		


