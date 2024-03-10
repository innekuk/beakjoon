#include<iostream>
#include<algorithm>
#include<map>

using namespace std;


map<int , int> dpmap;
int p , q;

int get(int i);

int main(){
	dpmap[0] = 1;
	int n;
	scanf("%d %d %d", &n,&p,&q);
	printf("%d",get(n));

}



int get(int i){

	if (dpmap[i] != 0){
		return dpmap[i];
	}
	return dpmap[i] = get(i/p) + get(i/q);
}
