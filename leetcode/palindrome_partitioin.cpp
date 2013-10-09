#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split_center(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.size();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  vector<string> result;
	cout<<l+1<<" "<<r-1<<endl;
	cout<<s.substr(l+1, r-l-1)<<" "<<s.substr(0,l+1)<<" "<<s.substr(r, s.size()-r)<<endl;
	result.push_back(s.substr(l+1, r-l-1));
	result.push_back(s.substr(0,l+1));
	result.push_back(s.substr(r, s.size()-r));
	return result;
}

vector<vector<string> > partition_helper(string s){
	vector<vector<string> > result;
	if(s.size()==0){
		vector<string> tmp;
		result.push_back(tmp);
		return result;
	}

       if(s.size()==1){
                vector<string> tmp;
		tmp.push_back(s);
                result.push_back(tmp);
                return result;
        }
	
	for(int i=0;i<s.size();i++){
		vector<string> s1 = split_center(s,i,i);
		vector<string> s2 = split_center(s,i,i+1);

                cout<<s1[0]<<" "<<s1[1]<<" "<<s1[2]<<endl;
                cout<<s2[0]<<" "<<s2[1]<<" "<<s2[2]<<endl;

		if(s1[0].size()>0){
		vector<vector<string> > l1 = partition_helper(s1[1]);
		vector<vector<string> > r1 = partition_helper(s1[2]);

		for(int j=0;j<l1.size();j++){
			l1[j].push_back(s1[0]);
		}	

		for(int t = 0; t<l1.size();t++){
			vector<string> tmp = l1[t];
			for(int j=0;j<r1.size();j++){
				for(int k=0; k<r1[j].size(); k++){
					tmp.push_back(r1[j][k]);
				}
			}
			result.push_back(tmp);
		}
		}
                
		if(s2[0].size()>0){
		vector<vector<string> > l2 = partition_helper(s2[1]);
                vector<vector<string> > r2 = partition_helper(s2[2]);


                for(int j=0;j<l2.size();j++){
                        l2[j].push_back(s2[0]);
                }

                for(int t = 0; t<l2.size();t++){
                        vector<string> tmp = l2[t];
                        for(int j=0;j<r2.size();j++){
                                for(int k=0; k<r2[j].size(); k++){
                                        tmp.push_back(r2[j][k]);
                                }
                        }
                        result.push_back(tmp);
                }
		}

	}
}

int main(){
	vector<vector<string> > result = partition_helper("aab");

	cout<<"Result"<<endl;

	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 1;
}


