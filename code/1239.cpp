#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int val[10] = {0};

int check(int n){
	int checkarr[8] = {0};
	for (int i =0; i<n; i++){
		if (check[val[i]]==0){
			check[val[i]] = 1;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int main(){
	int n;
	int maxval = 0;
	int arr[10] = {0};
	vector<int> vec;
	scanf("%d",&n);
	for (int i =0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	for (val[0] = 0; val[0] < 8; val[0]++){
		for (val[1]=0; val[1] < 8; val[1]++){
			if (check(2) == 0){
				continue;
			}
			for (val[2]=0; val[2] < 8; val[2]++){
				if (check(3) ==0){
					continue;
				}
				for (val[3]=0; val[3] < 8; val[3]++){
					if (check(4) ==0){
						continue;
					}
					for (val[4]=0; val[4]<8; val[4]++){
						if (check(5) ==0){
							continue;
						}
						for (val[5]=0; val[5] < 8; val[5]++){
							if (check(6) ==0){
								continue;
							}
							for(val[6]=0; val[6] <8; val[6]++){
								if (check(7) ==0){
									continue;
								}
								for(val[7]=0; val[7] <8; val[7]++){
									if (check(8) ==0){
										continue;
									}
									

