#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;



map<int,int> dpsubmap;
map<int,int> dpmaxmap;

int dp[100005] = {0};
int dpstartpos[100005] = {0};
int maxdp[100005] = {0};
int arr[100005] = {0};


vector<int> realarr;



int check(int n){
	int startpos = 0;
	int max = arr[0];
	int submax = arr[0];
	dp[0] = realarr[0];
	for (int i =1; i< n; i++){
		if (dp[i-1] > 0){
			dp[i] = dp[i-1] + realarr[i];
		}
		else{
			dp[i] = realarr[i];
			for (int j = startpos; j <i-1; j++){
				maxdp[j] = submax;
			}
			maxdp[i-1] = realarr[i-1];
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
	int sum = 0;
	for (int i =0; i< n; i++){
		if (arr[i] < 0 ){
			if (sum != 0){
				realarr.push_back(sum);
			}
			realarr.push_back(arr[i]);
			sum =0;
		}
		else{
			sum += arr[i];
		}
	}
	if (arr[n-1] >=0){
		realarr.push_back(sum);
	}


	max = check(realarr.size());
	//printf("max : %d\n",max);
	//for (int i =0; i< realarr.size(); i++){
	//	printf("%10d -> dp : %10d ,maxdp : %10d , dpstartpos : %10d\n" , realarr[i], dp[i] , maxdp[i] , dpstartpos[i]);
	//}
	int realmax = max;
	
	for (int i =0; i<realarr.size(); i++){
		int submax;
		int subnum;
		if (realarr[i] < 0 && i != 0){
			//printf("-pos : %d\n" , i);
			submax = dp[i-1];
			subnum = dp[i-1];
			for (int j = i+1 ; j<realarr.size() && subnum >= 0; j++){
				subnum += realarr[j];
				if (submax < subnum){
					submax = subnum;
				}
			}
			if (realmax < submax){
				realmax = submax;
			}
		}
		
	}
	
	printf("%d",realmax);
}






