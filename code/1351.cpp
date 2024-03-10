#include<iostream>
#include<algorithm>
#include<map>

using namespace std;


map<long long int , long long int> dpmap;
long long int p , q;

long long int get(long long int i);

int main(){
	dpmap[0] = 1;
	long long int n;
	scanf("%d %d %d", &n,&p,&q);
	printf("%d",get(n));

}



long long int get(long long int i){

	if (dpmap[i] != 0){
		return dpmap[i];
	}
	return dpmap[i] = get(i/p) + get(i/q);
}

