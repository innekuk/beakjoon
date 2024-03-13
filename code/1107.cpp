#include<iostream>
#include<algorithm>

using namespace std;



int check(int val, int * brokenbutton);

int main(){
	int n;
	int brokenbutton[10] = {0};
	int min,max;
	int cnt;
	scanf("%d" , &n);
	int a;
	scanf("%d" , &a);
	for (int i =0; i<a; i++){
		int b;
		scanf("%d", &b);
		brokenbutton[b] = 1;
	}
	cnt = abs(n-100);
	if (a==10){
		printf("%d",cnt);
		return 0;
	}
	//for (int i =0; i<10; i++){
	//	printf("%d , " ,brokenbutton[i]);
	//}
	//printf("\n");
	int maxcnt;
	if (!(a == 9 && brokenbutton[0] == 0)){
		for (max =n; check(max,brokenbutton) ==0; max++);
		maxcnt = check(max,brokenbutton);
		maxcnt += max-n;
		if (maxcnt < cnt){
			cnt = maxcnt;
		}
	}
	

	int mincnt;
	for (min=n; check(min,brokenbutton) ==0 && min >= 0; min--);
	if (min >= 0 ){
		mincnt = check(min,brokenbutton);
		mincnt += n-min;
		if (mincnt < cnt){
			cnt = mincnt;
		}
	}


	printf("%d",cnt);
	return 0;
	
}



int check(int val , int * brokenbutton){
	if (val == 0 && brokenbutton[0] ==0){
		return 1;
	}
	if (val ==0 && brokenbutton[0] == 1){
		return 0;
	}
	int cnt = 0;
	while(val != 0 ){
		if (brokenbutton[val%10] == 1){
			return 0;
		}
		val /= 10;
		cnt++;
	}
	return cnt;
}

