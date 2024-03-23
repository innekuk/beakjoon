#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int map[3200][3200] = {0};

void f(int posx, int posy , int n){
	if (n !=0){
		int get = pow(5,n);
		for (int i =0 ; i< 5; i++){
			f(posx + get*i/5,posy + get*2/5 , n-1);
		}
		for (int i = 1; i< 4; i++){
			f(posx + get*i/5 , posy + get/5 , n-1);
		}
		f(posx + get/5 , posy , n-1);
		f(posx + get*3/5 , posy , n-1);
		f(posx + get*2/5 , posy + get*3/5, n-1);
		f(posx + get*2/5 , posy + get*4/5 , n-1);
		return;
	}
	map[posx][posy] = 1;
	return;
}

int main(){
	int n;
	scanf("%d" , &n);
	f(0,0,n);
	int size = pow(5,n);
	for (int i =size ; i >= 0; i--){
		for (int j =0; j< size; j++){
			if (map[j][i] == 1){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}

}
