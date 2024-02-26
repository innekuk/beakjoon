#include<iostream>
#include<algorithm>

using namespace std;

struct SEG{
	int tree[345620] = {0};
	int size = 86405;


	void init(int pos, int val){
		init(pos,val,1,1,size);
	}

	int init(int pos , int val , int node , int s , int e){
		if (pos < s || pos > e){
			return tree[node];
		}
		if (s == e){
			return tree[node] += val;
		}
		int mid = (s+e)/2;
		return tree[node] = init(pos,val,node*2 , s,mid) + init(pos,val,node*2+1,mid+1,e);
	}

	int sum (int l , int r){
		return sum(l ,r , 1 , 1, size);
	}

	int sum (int l, int r, int node ,int s , int e ){
		if (e < l || r < s){
			return 0;
		}
		if (l <= s && e <= r){
			return tree[node];
		}
		int mid = (s+e)/2;
		return sum(l,r,node*2,s,mid) + sum(l,r,node*2+1,mid+1,e);
	}
};

SEG tree;


int main(){
	int n;
	scanf("%d" ,&n);
	for (int i =0; i< n; i++){
		int h , m ,s , h1, m1,s1;
		scanf("%d:%d:%d - %d:%d:%d" , &h,&m,&s,&h1,&m1,&s1);
		h *=3600;
		m *= 60;
		s += h+m + 1;
		h1 *= 3600;
		m1 *=60;
		s1 += h1+m1+1;
		if (s > s1){
			for (int j = s; j <=86400; j++){

				tree.init(j,1);
			}
			for (int j = 1; j<=s1; j++){
				tree.init(j,1);
			}
		}
		else{
			for (int j=s ; j<=s1; j++){
				tree.init(j,1);
			}
		}
	}
	scanf("%d",&n);

	for (int i=0; i< n; i++){
		int h,m,s,h1,m1,s1;
		scanf("%d:%d:%d - %d:%d:%d" , &h,&m,&s,&h1,&m1,&s1);
		h*=3600;
		m *= 60;
		s += h+m + 1;
		h1 *= 3600;
		m1 *=60;
		s1 += h1+m1+1;
		if (s>s1){
			printf("%.10f\n" , (tree.sum(s,86400)+tree.sum(1,s1))/(double)(86400-s+1+s1));
		}
		else{
			printf("%.10f\n" , tree.sum(s,s1)/(double)(s1-s+1));
		}
	}
}




