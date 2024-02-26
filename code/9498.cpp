#include<iostream>
#include<algorithm>


using namespace std;


int main() {
	int val;
	scanf("%d" , &val);
	if(val >= 90){
		printf("A");
		return 0;
	}
	if (val >= 80){
		printf("B");
		return 0;
	}
	if (val >= 70){
		printf("C");
		return 0;
	}
	if (val >= 60){
		printf("D");
		return 0;
	}
	printf("F");
	return 0;
}
