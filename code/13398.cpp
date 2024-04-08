#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int arr[100005] = {0};
int dp[100005][2] = {0};


vector<int> realarr;

int check(int n){
	int MAX = arr[0];
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	for (int i =1; i< n; i++){
		dp[i][0] = max(dp[i-1][0] +arr[i] , arr[i]);
		dp[i][1] = max(dp[i-1][0] , dp[i-1][1] + arr[i]);
		MAX = max( MAX, max(dp[i][0] , dp[i][1]));
	}	
	return MAX;

}


int main(){
	int n;
	int MAX;
	scanf("%d", &n);
	for (int i =0; i<n ; i++){
		scanf("%d" , &arr[i]);
	}
	
	if (n==1){
		printf("%d" , arr[0]);
		return 0;
	}
	

	MAX = check(n);
	//printf("max : %d\n",max);
	//for (int i =0; i< n; i++){
	//	printf("%5d -> dp[0] : %5d , dp[1] : %5d\n" , arr[i], dp[i][0] , dp[i][1]);
	//}
	
	printf("%d",MAX);
}






