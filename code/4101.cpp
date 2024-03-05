#include<iostream>
#include<algorithm>

using namespace std;


int main(){
	while(1){
		int a,b;
		scanf("%d %d",&a,&b);
		if (a==0 && b==0){
			break;
		}
		if (a>b){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
