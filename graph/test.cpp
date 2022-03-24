#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int find_parent(int node , vector<int> &parent){
        if(parent[node] == -1) return node;
        return parent[node] = this->find_parent(parent[node] , parent);
    }
    void dsu_union(int node1 , int node2 , vector<int> &parent,vector<int> &rank){
        int s1 = this->find_parent(node1,parent);
        int s2 = this->find_parent(node2,parent);
        
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2 ;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1 ;
                rank[s1] += s2 ;
            }
        }
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        vector<vector<int>> subsets(s.size());
        vector<int> parent(s.size(),-1);
        vector<int> rank(s.size(),1);
        
        for(uint32_t i = 0 ; i < s.size() ; i++){
            parent[i] = -1;
            rank[i] = 1 ;
        }
        // connect all components
        for(uint32_t i = 0 ; i < s.size();i++){
            dsu_union(pairs[i][0],pairs[i][1],parent,rank);
        }
        
        //group the connected sets in a list
        for(uint32_t i = 0 ; i < s.size() ; i++){
            if(parent[i] == -1){
                subsets[i].push_back(i);
            }
            else{
                subsets[parent[i]].push_back(i);
            }
        }
        
        for(auto &nodes_idxs : subsets){
            string ss = "" ;
            for(auto ele_idx : nodes_idxs){
                ss += s[ele_idx] ;
            }
            sort(ss.begin(),ss.end());
            uint32_t j = 0;
            for(auto ele_idx : nodes_idxs){
                s[ele_idx] = ss[j++];
            }
        }
        
        return s; 
    }
};

int main(){

	vector<vector<int>> my_board = {{0,3},{1,2}};

	Solution s ;
    string st = "dcab";
	cout << s.smallestStringWithSwaps(st,my_board) << endl;

	// for(auto arr : my_board){
	// 	for(auto ele : arr){
	// 		cout << ele ;
	// 	}
	// 	cout << endl ;
	// }

	return 0;
}