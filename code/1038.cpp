#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main() {
	int map[10][10] ={0};
	int summap[10][10] = {0};
	int n;
	scanf("%d" ,&n);
	for (int i =0; i<10; i++){
		map[0][i] = 1;
	}
	for (int i = 1; i< 10; i++){
		for (int j = i; j < 10; j++){
			for (int k = i-1; k < j; k++){
				map[i][j] += map[i-1][k];
			}
		}
	}
	for (int i = 0; i<10; i++){
		if (i != 0){
			summap[i][i] += summap[i-1][9];
			summap[i][i] += map[i][i];
		}
		for (int j = i+1; j<10; j++){
			summap[i][j] += summap[i][j-1];
			summap[i][j] += map[i][j];
		}
	}

	vector<int> ans;
	ans.push_back(0);
	if (n > 1022){
		printf("-1");
		return 0;
	}
	for (int i =0; i< n; i++){
		ans[0] += 1;
		for (int j =0; j<ans.size(); j++){
			if( ans.size() -1 != j &&(ans[j] >= 10 || ans[j+1] <= ans[j])){
				ans[j+1] += 1;
				ans[j] = j;
			}
			if (ans.size() -1 == j && ( ans[j] >= 10)){
				ans.push_back(j+1);
				ans[j] = j;
			}
		}
	}
	for (int i = ans.size()-1; i>= 0; i--){
		printf("%d" , ans[i]);
	}






		
	



}


