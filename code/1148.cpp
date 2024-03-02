#include<iostream>
#include<algorithm>

using namespace std;

int list[200005][30] = {0};
int checklist[30] = {0};
int can[200005] = {0};
int anscode[26];
int length = 0;
void checklistclear(){
	for (int i =0; i<26; i++){
		checklist[i] = 0;
	}
}

void canclear(){
	for (int i =0; i < length; i++){
		can[i] = 0;
	}
}


int main() {
	while(true){
		char getlist[11];
		scanf("%s", getlist);
		if (getlist[0] == '-'){
			break;
		}
		for (int j =0; getlist[j] != 0; j++){
			list[length][getlist[j]-'A'] += 1;
		}
		length++;
	}
	length += 1;
	while(true){
		int min = length,max = 0;
		char getlist[11];
		scanf("%s",getlist);
		if (getlist[0] == '#'){
			break;
		}
		checklistclear();
		for (int i =0; i<9; i++){
			checklist[getlist[i]-'A'] += 1;
		}
		//checkcan
		
		//printf("checklist\n");
		//for (int i =0; i<26; i++){
		//	printf("%c : %d ,",i+'A',checklist[i]);
		//}
		//printf("\n");


		canclear();
		for (int i =0; i<length; i++){
			for (int j =0 ; j < 26; j++){
			       if (checklist[j] < list[i][j]){
			       		can[i] = 1;
					break;
			       }
			}
		}
		
		for (int i=0; i<26; i++){
			anscode[i] = -1;
		}

		for (int i =0 ; i<9; i++){
			int subval =0;
			for (int j = 0; j<length; j++){
				if(can[j] == 0 && list[j][getlist[i]-'A'] > 0){
					//printf("subval!");
					subval++;
				}
			}
			anscode[getlist[i]-'A'] = subval;
			if (min > subval){
				min =  subval;
			}
			if (max < subval){
				max = subval;
			}
		}
		//output
		//
		//
		for (int i =0; i <26; i++){
			if (min == anscode[i]){
				printf("%c",i+'A');
			}
		}
		printf(" %d " , min);
		for (int i =0; i<26; i++){
			if (max == anscode[i]){
				printf("%c",i+'A');
			}
		}
		printf(" %d\n",max);
	}
}




