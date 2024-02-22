


#include<iostream>
#include<algorithm>


using namespace std;


int main(){
	char text[15][1005] = {0};
	int n;
	scanf("%d" , &n);
	
	for (int i = 0; i < n; i++){
		scanf("%s" , text[n]);
	}

	for (int i =0 ; i< n ; i++){
		printf("%c" , text[n][0]);
		int j = 0; 
		while(text[n][j] != 0){
			j++;
		}
		printf("%c" , text[n][j-1]);
	}

	return 0;

}



