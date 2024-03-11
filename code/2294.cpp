#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[10005] = {0};

int main(){
	int n ,k;
	vector<int> vec;
	scanf("%d %d",&n , &k);
	for (int i =0; i<n; i++){
		int a;
		scanf("%d", &a);
		vec.push_back(a);
	}
	for (int i =1; i<=k; i++){
		for (int j =0; j < vec.size(); j++){
			if (vec[j] == i){
				dp[i] = 1;
				break;
			}
			if (i-vec[j] >= 1 && dp[i-vec[j]] != 0 && (dp[i] == 0 || dp[i-vec[j]] + 1 < dp[i])){

				dp[i] = dp[i-vec[j]] + 1;
			}
		}
	}
	//printf("dp \n");
	//for (int i =1; i<=k; i++){
	//	printf("%d : %d\n",i,dp[i]);
	//}

	if (dp[k] == 0){
		printf("-1");
	}
	else{
		printf("%d",dp[k]);
	}
}
