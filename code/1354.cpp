#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

map<long long int ,long long int> dpmap;

long long int n,p,q,x,y;

long long int getval(long long int i);

int main(){
	scanf("%lld %lld %lld %lld %lld",&n,&p,&q,&x,&y);

	printf("%lld",getval(n));
}


long long int getval(long long int i){
	if (i<=0){
		return 1;
	}
	if (dpmap[i]){
		return dpmap[i];
	}
	return dpmap[i] = getval(i/p-x) + getval(i/q-y);
}

