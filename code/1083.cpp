#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void change(int* s , int* e){
	int temp = *e;
	for (int i =0; e-1-i != s-1; i++){
		*(e-i) = *(e-1-i);


	}
	*s = temp;
}
int getmax(int* s, int* e , int spos){
	int max =0 ;
	int pos = -1;
	for ( int i =0 ; s+i != e; i++){
		if(max < *(s+i)){
			max = *(s+i);
			pos =spos+i;
		}
	}
	return pos;
}



int main(){
	int n;
	int s;
	int a[55];
	scanf("%d" , &n);
	for (int i=0; i< n; i++){
		int b;
		scanf("%d" , &b);
		a[i] = b;
	}
	scanf("%d" , &s);
	int i = 0;
	while(s >0 && i < n){
		int limit = (i+s > n) ? n : i+s;
		int pos = getmax(a+i,a+limit+1 , i);
		change(a+i , a+pos);
		//cout << "changing number is "  << *(a+i) << "," << *(a+pos) << endl;
		//cout << "change : ";
		//for (int j=0; j< n; j++){
		//	cout << a[j] << " ";
		//}
		s -= pos -i;
		i++;
		//cout << endl << "s and i : " << s <<" , " << i;
		//cout << endl << endl;
	}
	for (int i=0; i< n; i++){
		printf("%d " , a[i]);
	}






}
