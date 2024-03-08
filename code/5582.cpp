#include<iostream>
#include<algorithm>


using namespace std;


int dpmap[2][4005] ={0};


int main(){
	char a[4005],b[4005];
	int max = 0;
	scanf("%s",a);
	scanf("%s",b);
	int alength = 0 , blength = 0;
	
	for (;a[alength] != 0; alength++);
	
	for (; b[blength] != 0; blength++);

	for (int i =0; i < alength; i++){
		for (int j = blength-1; j>=0; j--){
			if (a[i] == b[j] && j != 0){
				dpmap[(i+1)%2][j] = dpmap[i%2][j-1] +1;
			}
			if (a[i] == b[j] && j ==0){
				dpmap[(i+1)%2][j] = 1;
			}
		}
		for (int j =0; j < blength; j++){
			if (max < dpmap[(i+1)%2][j]){
				max = dpmap[(i+1)%2][j];
			}
		}
	}

	printf("%d",max);
}


