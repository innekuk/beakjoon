#include<iostream>
#include<algorithm>

using namespace std;

char dna[3005];
char copydna[3005];
int T;
int length;

void back(){
	for (int i =0; i < length; i++){
		copydna[i] = dna[i];
	}
}


int main() {
	int min;
	scanf("%d",&T);
	scanf("%s",dna);
	for (length =0; dna[length] != 0; length++);
	min = length;

	for (int i = T; i>= 1; i--){
		int cnt = 0;
		if (length <= i){
			printf("0");
			return 0;
		}
		for (int j = 0; j < length-i; j++){
			back();
			for (int k = j+i; k <length; k++){
				if (copydna[k] != copydna[k-i]){
					cnt++;
					copydna[k] = copydna[k-i];
				}
			}
			for (int k = j -i; k>=0; k--){
				if (copydna[k] != copydna[k+i]){
					cnt++;
					copydna[k] = copydna[k+i];
				}
			}
			if (min > cnt){
				min = cnt;
			}
		}
	}
	printf("%d",min);



}
