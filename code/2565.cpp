#include<iostream>
#include<algorithm>

using namespace std;


vector<pair<int,int>> map;
int dp[505] = {0};

int main(){
	int n;
	scanf("%d" , &n);

	for (int i =0 ; i< n ;i++){
		int a,b;
		scanf("%d %d" ,&a, &b);
		map.push_back(make_pair(a,b));
	}
	sort(map.begin(),map.end());
	
	int max = 0;
	for (int i =0 ; i< n; i++){
		for (int j =0; j< map[i].second; j++){
			if (dp[map[i].second] < dp[j] +1){
				dp[map[i].second] = dp[j] + 1;
			}
		}
		if (max < dp[map[i].second]){
			max = dp[map[i].second];
		}
	}
	printf("%d",n-max);
}
