#include<iostream>
#include<algorithm>

using namespace std;

int list[50005] = {0};

int main(){
	int t ,n;
	
	scanf("%d",&t);
	for (int i =0 ; i<t ; i++){
		scanf("%d",&n);
		for (int j =0 ; j< n; j++){
			scanf("%d" , &list[j]);
		}
		if (list[0] > n-list[0]+1){
			list[0] = n-list[0]+1;
		}

		for (int j =1; j< n ; j++){
			if ((list[j-1] <= n-list[j] +1) && ((list[j] > n-list[j]+1) || (list[j] < list[j-1]))){
				list[j] = n-list[j]+1;
			}
		
		}
		
		int cnt = 0;
		int f = 0;
		for (int j =0; j<n; j++){
			if (list[j] < cnt){
				printf("NO\n");
				f = 1;
				break;
			}	
			cnt = list[j];
		}
		if (f == 0){
			printf("YES\n");
		}
	}
}
	
