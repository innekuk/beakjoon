#include<iostream>
#include<algorithm>

using namespace std;


vector<pair<int,int>> map;


int main(){
	int n;
	scanf("%d" , &n);

	for (int i =0 ; i< n ;i++){
		int a,b;
		scanf("%d %d" ,&a, &b);
		map.push_back(make_pair(a,b));
	}
	sort(map.begin(),map.end());
	int cnt = 0;
	while(true){
		//cout << "turn : " << cnt << endl << endl;
		int max = 0;
		int maxpos = -1;
		for (int i =0; i< map.size(); i++){
			int secpos = map[i].second;
			int count = 0;
			for (int j =0 ; j<i; j++){
				if (map[j].second > secpos){
					count++;
				}
			}
			for (int j = i+1; j < map.size(); j++){
				if (map[j].second < secpos){
					count++;
				}
			}
			if (count > max){
				max = count;
				maxpos = i;
			}
			//cout << "    " << map[i].first  << " : " << map[i].second << " --> " << count << endl;
		}
		if (maxpos >= 0 ){
			cnt++;
			map.erase(map.begin() + maxpos);
		}
		else{
			break;
		}
	}
	printf("%d",cnt);
}
