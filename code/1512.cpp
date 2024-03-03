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
		for (int j = 0; j < length-i; j++){
			smap.clear();
			string code = "";
			for (int k = j ; k < j+i;k++){
				code += dna[k];
			}
			if (smap[code] == 0){
				for (int k = j+i; k <length; k++){
					if (dna[k] != code[k%i -j%i]){
						cnt++;
					}
				}
				for (int k = j -i; k>=0; k--){
					if (dna[k] != code[k%i - j%i]){
						cnt++;
					}
				}
				if (min > cnt){
					min = cnt;
				}
				smap[code] = 1;
			}
			
			
		}
	}
	printf("%d",min);



}
