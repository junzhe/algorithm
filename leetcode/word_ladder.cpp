#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
#include <map>
using namespace std;

 vector<string> findDict(string str, unordered_set<string> &dict){
        vector<string> res;
        int sz = str.size();
        string s = str;
        for (int i=0;i<sz;i++){
            s = str;
            for (char j = 'a'; j<='z'; j++){
                s[i]=j;
                if (dict.find(s)!=dict.end()){
                    res.push_back(s);
                }
            }
             
        }
        return res;
    }
    int diff_count(string a, string b) {
        int count = 0;

        for(int i = 0; (i<a.size())&&(i<b.size()); i++){
            if(a[i]!=b[i]) count++;
        }

        return count;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!start.compare(end)){
            return 2;
        }
        
        queue<string> q;
        queue<string> rq;
        
        int level = 1;
        int rlevel = 1;
        
        q.push(start);
        rq.push(end);
        
        map<string, bool> visited;
        map<string, bool> rvisited;
	
	visited[start] = true;
	rvisited[end] = true;
        
        while((!q.empty())&&(!rq.empty())){
            
            if(q.size()<rq.size()){
                queue<string> next_q;
                while(!q.empty()){
                    string str = q.front();
                    q.pop();
                    for(unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); it++){
                        if((!visited[*it])&&(diff_count(str, *it)<=1)) {
                            next_q.push(*it);
                            visited[*it] = true;
                            
                            if(rvisited[*it]) return rlevel+level;
                        }
                    }
                }
            
                level++;
            
                q = next_q;
            }
            else{
                queue<string> next_rq;
                while(!rq.empty()) {
                    string str = rq.front();
                    rq.pop();
                    for(unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); it++){
                        if((!rvisited[*it])&&(diff_count(str, *it)<=1)) {
                            next_rq.push(*it);
                            rvisited[*it] = true;
                            
                            if(visited[*it]) return rlevel+level;
                        }
                    }
                }
            
                rq = next_rq;
            
                rlevel++;
            }
        }
        
        return 0;
    }

int main(){
	unordered_set<string> dict;

	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	cout<<ladderLength("hit", "cog", dict)<<endl;
}
