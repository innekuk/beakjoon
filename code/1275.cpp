#include<iostream>
#include<algorithm>

using namespace std;



struct SEG {
	long long int tree[400000] = {0};
	int size = 0;



	void init(int pos,long long int val){
		init(pos , val , 1, 1, size);
	}

	long long int init(int pos , long long int val , int index , int s , int e){
		if (s==e && pos == e){
			return tree[index] = val;
		}
		if (s > val || val > e){
			return tree[index];
		}
		int mid = (s+e)/2;
		return tree[index] = init(pos,val , index*2,s,mid) + init(pos,val,index*2+1,mid+1,e);
	}

	long long int sum(int l , int r){
		return sum(l,r,1,1,size);
	}

	long long int sum(int l , int r , int index ,int s, int e){
		if (l <= s && e <= r){
			return tree[index];
		}
		if (r < s || l > e){
			return 0;
		}
		int mid = (s+e)/2;
		return sum(l, r, index*2,s,mid) + sum(l,r,index*2+1,mid+1,e);
	}
};


SEG tree;



int main () {
	int n , q;
	scanf("%d %d" , &n ,&q);
	tree.size = n;

	for (int i=1; i<=n; i++){
		int a;
		scanf("%d",&a);
		tree.init(i,a);
	}
//	for (int i=0; i< 10; i++){
	//	int x,y;
	//	scanf("%d %d" , &x , &y);
	//	printf("%lld", tree.sum(x,y));
	//}



	for (int i =0 ; i<q; i++){
		int x,y,a,b;
		scanf("%d %d %d %d" , &x,&y,&a,&b);
		if (x > y ){
			printf("%lld\n" , tree.sum(y,x));
		}
		else{
			printf("%lld\n" , tree.sum(x,y));
		}
		cout << "a and b : " << a << " , " << b << endl;
		tree.init(a,b);
	}
	return 0;



}
