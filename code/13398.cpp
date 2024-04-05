#include<iostream>
#include<algorithm>



using namespace std;


int dp[100005] = {0};
int dpstartpos[100005] = {0};
int arr[100005] = {0};



int check(int n){
	int startpos = 0;
	int max = arr[0];
	dp[0] = arr[0];
	for (int i =1; i< n; i++){
		if (dp[i-1] >= 0){
			dp[i] = dp[i-1] + arr[i];
		}
		else{
			dp[i] = arr[i];
			startpos = i;
		}
		dpstartpos[i] = startpos;
		if (dp[i] > max){
			max = dp[i];
		}
	}
	return max;

}


int main(){
	int n;
	int max;
	scanf("%d", &n);
	for (int i =0; i<n ; i++){
		scanf("%d" , &arr[i]);
	}
	
	if (n==1){
		printf("%d" , arr[0]);
		return 0;
	}
	

	max = check(n);
	//printf("max : %d\n",max);
	int realmax = max;
	
	for (int i =0; i<n; i++){
		if (dp[i] == max){
			if (dpstartpos[i] > 1){
				int submax =arr[dpstartpos[i]-2];
				int sum = submax;
				for (int j = dpstartpos[i] -3; j >= dpstartpos[dpstartpos[i]-2]; j--){
					sum += arr[j];
					if (sum > submax){
						submax = sum;
					}
				}
				if (dp[i] + submax > realmax){
					realmax = dp[i] + submax;
				}
			}
			if (i <= n-3){
				int submax = arr[i+2];
				int sum = submax;
				for (int j = i+3; sum >= 0 && j < n ; j++){
					sum += arr[j];
					if (sum > submax){
						submax = sum;
					}
				}
				if (dp[i] + submax > realmax){
					realmax = dp[i] + submax;
				}
			}
			if (i != dpstartpos[i]){
				for (int j = dpstartpos[i]; j<=i ; j++){
					if (arr[j] < 0 && realmax < dp[i] -arr[j]){
						realmax = dp[i] -arr[j];
					}
				}
			}
		}
	}
	



	printf("%d",realmax);
}






