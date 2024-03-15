#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;


vector<pair<int,int>> city;

int dp[1000005] = {0};


int main(){
	int c, n;
	scanf("%d %d",&c,&n);
	for (int i =0 ; i< n; i++){
		 int a,b;
		 scanf("%d %d",&a, &b);
		 city.push_back(make_pair(a,b));
	}
	for (int i = 1; true; i++){
		for (int j = 0 ; j< city.size(); j++){
			if (i - city[j].first >= 0 ){
				if (dp[i-city[j].first] + city[j].second > dp[i]){
					dp[i] = dp[i-city[j].first] + city[j].second;
				}
			}
		}
		if (dp[i] >= c){
			printf("%d", i);
			break;
		}
	}
}



