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
		if (f+size > 100 || f+size < 1){
			break;
		}
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

int abs(int k){
	return (k>0) ? k : -k;
}



int main(){
	
	int maxlength = 0;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d",&list[i]);
	}


	for (int i = -100; i<=100; i++){
		cntlistclear();
		if ( i != 0&&(100/abs(i)+1 < maxlength)){
			continue;
		}
		for (int j =0 ; j< n; j++){
			if (i != 0 && (100/abs(i)+1 < maxlength)){
				break;
			}
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


