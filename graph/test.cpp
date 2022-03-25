#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int Keys_Req = 0 ; 
    vector<vector<bool>> visited ;
    int keys[26] = {0};
    int N , M ;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= this->M or col >= this->N ;
    }
    int backtrack(vector<string> &grid , int row , int col , int cur_keys){

        if(isInvalid(row , col) or grid[row][col] == '#' or visited[row][col] == true)
            return -1 ;
        cout << row << "  " << col << "  " << cur_keys << endl ;
        
        char c = grid[row][col] ;
        bool found_key_here = false ;
        if(c <= 122 and c >= 97){
            cur_keys++ ;
            if(cur_keys == Keys_Req){
                return 0 ;
            }
            keys[c-'a']++ ;
            cout << "key found " << c << " " << keys[c-'a'] << endl ;
            found_key_here = true ;
        }
        else if(c >= 65 and c <= 90){
            // its a lock ! do we have a key ?
            if(keys[(c + 32)-'a'] == 0){
                // we don't have a key in this path
                cout << "locked " << grid[row][col]+32 << endl ;
                return -1 ;
            }
        }
        visited[row][col] = true ;
        
        int temp = 0 , min_vals = INT_MAX;
        bool valid_path = false ;
        
        for(int i = 0 ; i < 4 ; i++){
            temp = backtrack(grid , row+dx[i] , col+dy[i] ,cur_keys) ;
            if(temp != -1){
                min_vals = min(min_vals ,1+temp);
                valid_path = true ;
            }    
        }
        visited[row][col] = true ;
        if(found_key_here) keys[c-'a']-- ;
        return (valid_path)?min_vals:-1 ;
    }
public:
    int shortestPathAllKeys(vector<string>& grid) {

        memset(keys , 0 , 26);
        this->M = grid.size();         
        this->N = grid[0].size();
        visited.resize(this->M , vector<bool>(this->N , false));
        
        for(int i = 0 ; i < this->M ; i++){
            for(int j = 0 ; j <this->N ; j++){
                if(grid[i][j] <= 122 and grid[i][j] >= 97)
                    Keys_Req++ ;
                else if(grid[i][j] == '#'){
                    visited[i][j] = true ; 
                }           
            }
        }

        for(int i = 0 ; i < this->M ; i++){
            for(int j = 0 ; j <this->N ; j++){
                cout << visited[i][j] << " " ;        
            }
            cout << endl ;
        }

        //   for(int i = 0 ; i < 26 ; i++){
            
        //     cout << keys[i] << endl ;
        // }
        
        return backtrack(grid , 0 , 0 , 0);
    }
};
int main(){

	vector<vector<int>> my_board = {{0,3},{1,2}};

	Solution s ;
    vector<string> grid= {"@..aA","..B#.","....b"};

	cout << s.shortestPathAllKeys(grid) << endl;

	// fsor(auto arr : my_board){
	// 	for(auto ele : arr){
	// 		cout << ele ;
	// 	}
	// 	cout << endl ;
	// }

	return 0;
}