#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int countmap[10005] = {0};


int main(){
	int n, k;
	vector<int> val;
	scanf("%d %d",&n,&k);
	for (int i =0 ; i< n; i++){
		int a;
		scanf("%d",&a);
		val.push_back(a);
	}


	for (int i =0 ; i< val.size(); i++){
		countmap[val[i]]++;
		for (int j = val[i]+1; j<=k; j++){
			countmap[j] += countmap[j-val[i]];
		}
	}
	printf("%d",countmap[k]);
}

