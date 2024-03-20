#include<iostream>
#include<algorithm>


using namespace std;

int dp[1005] = {0};
int input[1005] = {0};

int getdistance(int s , int e){
	int min = input[s];
	int max = input[s];
	for (int i = s + 1 ; i <=e;i++){
		if (min > input[i]){
			min = input[i];
		}
		if (max < input[i]){
			max = input[i];
		}
	}
	return max-min;
}


int main (){
	int n;
	scanf("%d" ,&n);
	for (int i =0 ; i< n; i++){
		scanf("%d", &input[i]);
	}

	for (int i =0; i< n; i++){
		for (int j =0; j<=i; j++){
			
			int val =getdistance(j,i);
			if (j != 0){
				val += dp[j-1];
			}

			if (dp[i] < val){
				dp[i] = val;
			}
		}
	}
	printf("%d",dp[n-1]);
}



