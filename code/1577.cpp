#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int map[105][105] = {0};
int cn;
int construction[55][5];


int ConstructionCheck(int n1 ,int m1 , int n2 , int m2){
	for (int i =0 ; i< cn; i++){
		//printf("do --> %d %d %d %d : %d %d %d %d  ---> " , n1,m1,n2,m2 , construction[cn][0]  , construction[cn][1] , construction[cn][2] , construction[cn][3]);
		if ( (n1 == construction[i][0] && m1 == construction[i][1] && n2 == construction[i][2] && m2 == construction[i][3]) || (n1 == construction[i][2] && m1 == construction[i][3] && n2 == construction[i][0] && m2 == construction[i][1])){
			//printf("yes!!!!!!!!!!!!!");
			return 1;
		}
		//printf("\n\n");

	}
	return 0;
}



long long int makemap(int n , int m){
	if (map[n][m] != 0 ){
		return map[n][m];
	}
	if (n-1 >=0 && !ConstructionCheck(n,m,n-1,m)){
		if (map[n-1][m] == 0){
			makemap(n-1,m);
		}
		map[n][m] += map[n-1][m];
	}
	if (m-1 >=0 && !ConstructionCheck(n,m,n,m-1)){
		if (map[n][m-1] == 0){
			makemap(n,m-1);
		}
		map[n][m] += map[n][m-1];
	}
	return map[n][m];
}


int main(){
	int n , m;
	map[0][0] = 1;
	scanf("%d %d" , &n , &m);
	scanf("%d" , &cn);
	for (int i =0 ; i< cn; i++){
		scanf("%d %d %d %d" , &construction[i][0], &construction[i][1], &construction[i][2] ,&construction[i][3]);
	}
	//makemap(n,m);
	//for(int i =m; i>=0; i--){
	//	for (int j = 0; j<= n; j++){
	//		printf("%4d" , map[j][i]);
	//	}
	//	printf("\n\n");
	//}
	printf("%lld" ,makemap(n,m));

}
