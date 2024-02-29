#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

// zero one two three four five six seven eight nine
// 순서대로
// eight , five ,four , nine , one , seven ,six , three , two , zero
//
//
map<char,int> nummap;

bool compare(string first , string second){
	for (int i =0; i < first.length() && second.length() ; i++){
		if( nummap[first[i]] != nummap[second[i]]){
			return nummap[first[i]] < nummap[second[i]];
		}
	}
	return first.length() < second.length();
}


int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n,m;
	char num[10] = {'8','5','4','9','1','7','6','3','2','0'};
	for (int i=0; i< 10; i++){
		nummap[num[i]] = i;
	}
	vector<string> list;
	scanf("%d %d",&n,&m);
	for (int i =n ; i<=m ; i++){
		list.push_back(to_string(i));
	}
	sort(list.begin(),list.end(),compare);
	for (int i =0; i<list.size(); i++){
		cout << list[i] << " ";
		if ((i+1)%10 == 0){
			cout << endl;
		}
	}
}



	
