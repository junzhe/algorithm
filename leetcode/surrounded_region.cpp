#include <vector>
#include <iostream>

using namespace std;

   bool helper(vector<vector<char> > &board, vector<vector<bool> > &visited, int x, int y){
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        bool is_trap = true;

        visited[x][y] == true;

        for(int i=0; i<4; i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];

            if((xx>=0)&&(xx<board.size())&&(yy>=0)&&(yy<board[0].size())){
                    if((!visited[xx][yy])&&(board[xx][yy]=='O'))
                        is_trap = is_trap && helper(board, visited, xx, yy);
            }else{
                is_trap = false;
                break;
            }
        }

        if(is_trap)
            board[x][y] = 'X';

        return is_trap;
    }


    void solve(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<bool> > visited;
        
        for(int i=0; i<board.size();i++){
            vector<bool> tmp;
            for(int j=0; j<board.size(); j++){
                tmp.push_back(false);
            }
            
            visited.push_back(tmp);
        }
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
		if((!visited[i][j])&&(board[i][j]=='O'))
			helper(board, visited, i, j);
            }
        }
    }
    

int main(){
	vector<vector<char> > board;

	for(int i=0; i<4; i++){
		vector<char> tmp;
		for(int j=0; j<4; j++){
			tmp.push_back('O');
		}
		board.push_back(tmp);
	}

	solve(board);

        for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
               		cout<<board[i][j]<<" ";
		 }

		cout<<endl;
        }
	return 0;
}
