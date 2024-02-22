


#include<iostream>
#include<algorithm>


using namespace std;


int main(){
	char text[15][1005] = {0};
	int n;
	scanf("%d" , &n);
	
	for (int i = 0; i < n; i++){
		scanf("%s" , text[i]);
	}

	for (int i =0 ; i< n ; i++){
		printf("%c" , text[i][0]);
		int j = 0; 
		while(text[i][j] != 0){
			j++;
		}
		printf("%c\n" , text[i][j-1]);
	}

	return 0;

}



