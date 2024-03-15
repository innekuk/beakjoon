#include<iostream>
#include<algorithm>


using namespace std;



char map[55][55] = {0};
int ans[30] = {0};


int main(){
	int n,m;
	scanf("%d %d" ,&n,&m);
	for (int i =0 ; i< n; i++){
		scanf("%s",map[i]);
	}
	for (int i =0; i< n*2; i++){
		for (int j =0; j< m*2; j++){
			ans[map[i%n][j%m]-'A'] += (j-0+1)*(m*2-j)*(i-0+1)*(n*2-i);
		}
	}

	for (int i =0; i<26; i++){
		printf("%d\n" , ans[i]);
	}
}

