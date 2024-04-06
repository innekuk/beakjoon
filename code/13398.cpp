#include<iostream>
#include<algorithm>



using namespace std;


int dp[100005] = {0};
int dpstartpos[100005] = {0};
int maxdp[100005] = {0};
int arr[100005] = {0};



int check(int n){
	int startpos = 0;
	int max = arr[0];
	int submax = arr[0];
	dp[0] = arr[0];
	for (int i =1; i< n; i++){
		if (dp[i-1] > 0){
			dp[i] = dp[i-1] + arr[i];
		}
		else{
			dp[i] = arr[i];
			for (int j = startpos; j <i-1; j++){
				maxdp[j] = submax;
			}
			maxdp[i-1] = arr[i-1];
			dpstartpos[i-1] = i-1;
			startpos = i;
			submax = arr[i];
		}
		dpstartpos[i] = startpos;
		if (dp[i] > max){
			max = dp[i];
		}
		if (dp[i] > submax){
			submax = dp[i];
		}
	}
	for (int i = dpstartpos[n-1]; i< n; i++){
		maxdp[i] =submax;
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
	//for (int i =0; i< n; i++){
	//	printf("%d : %d \n" , arr[i] , maxdp[i]);
	//}
	int realmax = max;
	
	for (int i =0; i<n; i++){
		int submax;
		int subnum;
		if (arr[i] < 0 && dpstartpos[i] != i){
			submax = dp[i-1];
			subnum = dp[i-1];
			for (int j = i+1 ; j<n && subnum >= 0; j++){
				subnum += arr[j];
				if (submax < subnum){
					submax = subnum;
				}
			}
		}
		if (realmax < submax){
			realmax = submax;
		}
	}
	
	printf("%d",realmax);
}






