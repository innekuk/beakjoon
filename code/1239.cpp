#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxval = 0;

void getmax(vector<int> ans);


void actionbroth(vector<int> val ,int n , vector<int> ans){
	if (n > 1){
		for (int i =0; i<n; i++){
			vector<int> nextans = ans;
			nextans.push_back(val[i]);
			vector<int> newval;
			for (int j = 0; j<n; j++){
				if (j!=i){
					newval.push_back(val[j]);
				}
			}
			actionbroth(newval,n-1,nextans);
		}
	}
	else {
		ans.push_back(val[0]);
		getmax(ans);
	}
}


void getmax(vector<int> ans){
	vector<int> sum;
	int cnt = 0;
	sum.push_back(ans[0]);
	for (int i =1; i<ans.size(); i++){
		sum.push_back(sum[i-1] + ans[i]);
	}
	for (int i =0; i< sum.size(); i++){
		for (int j =0; j < i; j++){
			if ((sum[i] - sum[j]) == 50){
				cnt++;
			}
		}
	}
	if (maxval < cnt){
		maxval = cnt;
	}
}





int main(){
	int n;
	vector<int> vec;
	scanf("%d",&n);
	for (int i =0; i<n; i++){
		int a;
		scanf("%d",&a);
		vec.push_back(a);
	}
	vector<int> ans;
	actionbroth(vec,n,ans);
	printf("%d",maxval);
}

