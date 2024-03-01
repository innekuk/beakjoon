#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

map<int,int> cmap;
int n;
int list[100000] = {0};

int getlength(int start,int size){
	int cnt = 1;
	int f = list[start];
	for (int i = start+1; i < n; i++){
		if (list[i] == f+size){
			cnt++;
			f += size;
		}
	}
	return cnt;
}


int main(){
	
	int maxlength = 0;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d",&list[i]);
	}


	for (int i =0; i<n; i++){
		for (int j = i +1; j<n; j++){
			int a = list[j] - list[i];
			if(cmap[a] == 0 ){
				cmap[a] = 1;
				int length = getlength(i,a);
				if (length > maxlength){
					maxlength = length;
				}
			}
		}
	}

	printf("%d" ,maxlength);
}


