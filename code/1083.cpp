#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
int s;
int a[55];

void change(int* a , int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}



int main(){
	scanf("%d" , &n);
	for (int i=0; i< n; i++){
		int b;
		scanf("%d" , &b);
		a[i] = b;
	}
	scanf("%d" , &s);
	while(s !=0){
		for (int i =0 ; i< n-1; i++){
			if(a[i] < a[i+1]){
				change(&a[i] , &a[i+1]);
				break;
			}
		}
		s--;




	}
	for (int i=0; i< n; i++){
		printf("%d " , a[i]);
	}






}
