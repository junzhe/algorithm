#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum2_helper(vector<int>& sol, vector<vector<int> >& result, vector<int>& num, vector<bool> visited, int target){
	if(target == 0){
		result.push_back(sol);
		return;
	}

	for(int i=0;i<num.size();i++){
		if((visited[i] == false)&&((target-num[i])>=0)){
			sol.push_back(num[i]);
			visited[i] = true;
			combinationSum2_helper(sol, result, num, visited, target-num[i]);
				
			sol.pop_back();
		}
	}

	return;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target){
	vector<vector<int> > result;
	vector<int> sol;
	vector<bool> visited(num.size(), false);

	combinationSum2_helper(sol, result, num, visited, target); 
	return result;
}

int main(){
	vector<int> num;
	num.push_back(10);
        num.push_back(1);
        num.push_back(2);
        num.push_back(7);
        num.push_back(6);
        num.push_back(1);
        num.push_back(5);
	
	sort(num.begin(), num.end());

	vector<vector<int> > result = combinationSum2(num, 8);

	for(int i=0;i<result.size();i++){
		for(int j=0; j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}	
		cout<<endl;
	}

	return 0;
}
