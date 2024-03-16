#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


bool compare(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}



vector<pair<int,int>> vec;

int main(){
	int n;
	int currenttime;
	scanf("%d", &n);
	for (int i =0; i<n; i++){
		int T , S;
		scanf("%d %d", &T,&S);
		vec.push_back(make_pair(T,S));
	}

	sort(vec.begin(),vec.end(),compare);

	currenttime = vec[0].second - vec[0].first;
	for (int i = 1; i < vec.size(); i++){
		if (currenttime < vec[i].second){
			currenttime = currenttime - vec[i].first;
		}
		else{
			currenttime = vec[i].second - vec[i].first;
		}
	}
	printf("%d",currenttime);
}


	
