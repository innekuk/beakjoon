#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;

stack<int> st;
vector<vector<int>> point;


int main(){
	char map[35] = {0};
	scanf("%s", map);
	int sum = 0;
	int i = 0;
	point.push_back(vector<int>());
	while(map[i] != 0){
		if (map[i] == '('){
			st.push(1);
			point.push_back(vector<int>());
		}
		if (map[i] == '['){
			st.push(2);
			point.push_back(vector<int>());
		}
		if (((map[i] == ')' || map[i] == ']') && st.empty()) || (map[i] == ')' && st.top() == 2) || (map[i] == ']' && st.top() == 1)){
			printf("0");
			return 0;
		}
		if (map[i] == ')' && st.top() == 1){
			st.pop();
			if (map[i-1] == '('){
				point.pop_back();
				point[point.size()-1].push_back(2);
			}
			if (map[i-1] == ')' || map[i-1] == ']'){
				int val = 0;
				for (int j =0; j < point[point.size()-1].size(); j++){
					val += point[point.size()-1][j];
				}
				val *= 2;
				point.pop_back();
				point[point.size()-1].push_back(val);
			}
		}
		if (map[i] == ']' && st.top() == 2){
			st.pop();
			if (map[i-1] == '['){
				point.pop_back();
				point[point.size()-1].push_back(3);
			}
			if (map[i-1] == ')' || map[i-1] == ']'){
				int val = 0;
				for (int j = 0; j < point[point.size()-1].size() ; j++){
					val += point[point.size()-1][j];
				}
				val *= 3;
				point.pop_back();
				point[point.size()-1].push_back(val);
			}
		}

		//printf("check : %d \n" , i);
		//for (int j =0 ; j< point.size(); j++){
		//	printf("%d : ",j);
		//	for (int k = 0; k < point[j].size(); k++){
		//		printf("%d " , point[j][k]);
		//	}
		//	printf("\n");
		//}
		//printf("\n");
		i++;
	}
	if (!st.empty()){
		printf("0");
		return 0;
	}
	for (int i =0; i< point[0].size(); i++){
		sum += point[0][i];
	}
	printf("%d",sum);
}
		
