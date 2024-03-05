#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;


map<string,int> smap;

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
		if (length <= i || min == 0){
			printf("0");
			return 0;
		}
		
		for (int j = 0; j< i; j++){
			int count[4] = {0};
			int countmax = 0;
			int countpos = -1;
			for (int k=j; k < length; k += i){
			       if (dna[k] == 'A'){
				       count[0]++;
			       }
			       if (dna[k] == 'C'){
				       count[1]++;
			       }
			       if (dna[k] =='G'){
				       count[2]++;
			       }
			       if (dna[k] =='T'){
				       count[3]++;
			       }
			}
			

			for (int j =0 ; j<4; j++){
				if (countmax < count[j]){
					countmax = count[j];
					countpos = j;
				}
			}
			for (int j =0; j< 4; j++){
				if (countpos != j){
					cnt += count[j];
				}
			}
		}
		if (cnt < min){
			min = cnt;
		}
	}
	printf("%d",min);



}
