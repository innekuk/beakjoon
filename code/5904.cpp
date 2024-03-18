#include<iostream>
#include<algorithm>


using namespace std;


int cnt =1;
int getpos;
void Moo(int n){
	if (cnt > getpos){
		return;
	}
	if (n == 0){
		cnt += 3;
		if (cnt >getpos){
		       if (cnt-getpos == 3){
			       printf("m");
		       }
		       else{
			       printf("o");
		       }
		}
		return;
	}
	Moo(n-1);
	if (cnt > getpos){
		return;
	}

	cnt += n+3;
	if (cnt > getpos && cnt-getpos == n+3){
		printf("m");
		return;
	}
	else if (cnt > getpos){
		printf("o");
		return;
	}
	Moo(n-1);
}



int main(){
	
	scanf("%d",&getpos);
	Moo(100);
}
