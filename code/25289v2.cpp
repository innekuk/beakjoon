#include<iostream>
#include<algorithm>


using namespace std;


int list[100001];
int comlist[100001];
int dp[105];

int n;


void dpclear(){
	for (int i =0; i< 101; i++){
		dp[i] = 0;
	}
}
int getdpmax(){
	int a = 0;
	for (int i =0; i<101; i++){
		if (dp[i] > a){
			a = dp[i];
		}
	}
	return a;
}

int main(){
	int maxlength = 0;
	scanf("%d", &n);
	for (int i =0; i< n; i++){

		scanf("%d",&list[i]);
	}

	for (int i = -99; i<=99; i++){
		int max = 0;
		dpclear();
		for (int j =0; j < n; j++){

			if ((list[j]-i < 1 || list[j]-i > 100  )|| dp[list[j]-i] == 0){
				dp[list[j]] = 1;
			}
			else{
				dp[list[j]] = dp[list[j]-i] + 1;
			}
		}
		

		max = getdpmax();
		if (maxlength<max){
			maxlength = max;
		}
	}
	printf("%d",maxlength);

		
}	


