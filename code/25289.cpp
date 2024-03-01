#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

map<int,int> cmap;
int n;
int list[100000] = {0};
int cntlist[100000] = {0};


int getlength(int start,int size){
	int cnt = 1;
	int f = list[start];
	for (int i = start+1; i < n; i++){
		if (list[i] == f+size){
			cntlist[i] = 1;
			cnt++;
			f += size;
		}
	}
	return cnt;
}
void cntlistclear(){
	for (int i =0; i < n; i++){
		cntlist[i] = 0;
	}
}


int main(){
	
	int maxlength = 0;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d",&list[i]);
	}


	for (int i = -100; i<=100; i++){
		cntlistclear();
		for (int j =0 ; j< n; j++){
			if(cntlist[j] == 0){
				int length = getlength(j , i);
				if (length > maxlength){
					maxlength = length;
				}
			}
		}
	}



	printf("%d" ,maxlength);
}


