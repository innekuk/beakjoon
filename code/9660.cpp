#include<iostream>
#include<algorithm>

using namespace std;



int main(){
	long long int n;
	int list[7] = {1,0,1,0,0,0,0};
	scanf("%lld",&n);
	if (list[n%7] == 1){
		printf("CY");
	}
	else{
		printf("SK");
	}
}
