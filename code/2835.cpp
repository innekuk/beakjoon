#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct SEG{
	long long int tree[345620] = {0};
	long long int lazy[345620] = {0};
	int size = 86405;


	void init(int pos, int val){
		init(pos,val,1,1,size);
	}

	int init(int pos , int val , int node , int s , int e){
		tree[node] += lazy[node]*(e-s+1);
		if (s != e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
		if (pos < s || pos > e){
			return tree[node];
		}
		if (s == e){
			return tree[node] += val;
		}
		int mid = (s+e)/2;
		return tree[node] = init(pos,val,node*2 , s,mid) + init(pos,val,node*2+1,mid+1,e);
	}

	long long int sum (int l , int r){
		return sum(l ,r , 1 , 1, size);
	}

	long long int sum (int l, int r, int node ,int s , int e ){
		tree[node] += lazy[node]*(e-s+1);
		if( s!= e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
		if (e < l || r < s){
			return 0;
		}
		if (l <= s && e <= r){
			return tree[node];
		}
		int mid = (s+e)/2;
		return sum(l,r,node*2,s,mid) + sum(l,r,node*2+1,mid+1,e);
	}
	void rangeinit(int l , int r,int val){
		rangeinit(l, r, val , 1, 1,size);
	}
	long long int rangeinit(int l, int r,int val,int node , int s ,int e){
		tree[node] += lazy[node]*(e-s+1);
		if (s != e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
		if(e < l || r < s){
			return tree[node];
		}
		if (e == s && l <= s && e <= r){
			return tree[node] += val;
		}
		if (l <= s && e <= r){
			lazy[node*2] += val;
			lazy[node*2+1] += val;
			return tree[node] += val*(e-s+1);
		}
		int mid = (s+e)/2;
		return tree[node] = rangeinit(l,r,val , node*2 , s ,mid) + rangeinit(l,r,val,node*2+1 , mid+1 , e);
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
			tree.rangeinit(s,86400,1);
			tree.rangeinit(1,s1,1);
		}
		else{
			tree.rangeinit(s,s1,1);
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




