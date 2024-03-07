#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
	int n;
	scanf("%d", &n);
	for (long long int i =0; i<n; i++){
		long long int x,y,length,cnt = 0;
		scanf("%lld %lld",&x,&y);
		length = y-x-2;
		if (length == -1){
			printf("1\n");
			continue;
		}
		if (length == 0){
			printf("2\n");
			continue;
		}
		if (length == 1){
			printf("3\n");
			continue;
		}
		long long int maxspeed;
		for (maxspeed = 2; (maxspeed-1+2)*(maxspeed-3+1) + maxspeed <= length; maxspeed++);
		maxspeed--;
		cnt = (maxspeed-2)*2 +1 + ceil((length-((maxspeed-1+2)*(maxspeed-2)+maxspeed))/(double)maxspeed) + 2;
		printf("%d\n",cnt);
	}
}
		

