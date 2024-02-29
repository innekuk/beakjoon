#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
using namespace std;

int node[55][55] = {0};
int node2[55][55] = {0};

int main(){
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i =0; i<n; i++){
		int a;
		scanf("%d",&a);
		if (a != -1){
			node[a][i] = 1;
			
		}
	}
	int s;
	scanf("%d",&s);
	for (int i =0 ; i<n; i++){
		node[i][s] = 0;
	}
	stack<int> st;
	for (int i =0; i <n; i++){
		if (node[s][i] == 1){
			st.push(i);
		}
	}
	node[s][51] = -1;
	while(!st.empty()){
		int get = st.top();
		st.pop();
		for (int i =0; i< n; i++){
			if (node[get][i] == 1){
				st.push(i);
			}
		}
		node[get][51] = -1;
	}
	for (int i =0 ; i< n; i++){
		if (node[i][51] != -1){
			int f = 0;
			for (int j =0 ; j < n; j++){
				if (node[i][j] == 1){
					f = 1;
					break;
				}
			}
			if (f == 0){
				cnt++;
			}
		}
	}


	printf("%d",cnt);
	


}
