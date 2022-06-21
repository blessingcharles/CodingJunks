#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string generate_indents(int count){
    int indent = 0 ;
    string temp = "" ;
    while(indent < count){
        temp.push_back('\t');
        indent++ ;
    }
    return temp ;
}

bool canStopToken(char ch){
    return ch == '{' or ch == '}' or ch == '[' or ch == ']' or ch == ',' ;
}

vector<string> prettyJSON(string A) {
    int current_indent = 0 ;
    vector<string> res ;
    
    int ptr = 0 ;
    int N = A.size() ;
    
    while(ptr < N){
        string temp = "" ;
        cout << ptr << endl ;

        if(A[ptr] == '{' or A[ptr] == '['){
            temp += generate_indents(current_indent);
            temp.push_back(A[ptr]);
            ptr++ ;
            current_indent++ ;    
        }
        else if(A[ptr] == '}' or A[ptr] == ']'){
            current_indent-- ;
            temp += generate_indents(current_indent);
            temp.push_back(A[ptr]);
            ptr++ ;
            if(ptr < N and A[ptr] == ','){
                temp.push_back(',');
                ptr++ ;
            }
        }
        else{
            temp += generate_indents(current_indent);
            // delimiters  , and [ and {
            while(not canStopToken(A[ptr])){
                temp.push_back(A[ptr]);
                ptr++ ;
            } 
            if(A[ptr] == ','){
                temp.push_back(',');
                ptr++ ;
            }
        }
        res.push_back(temp) ;
    }
    return res ;
}


int main()
{
    string jj = "{\"attributes\":[{\"nm\":\"ACCOUNT\",\"lv\":[{\"v\":{\"Id\":null,\"State\":null},\"vt\":\"java.util.Map\",\"cn\":1}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":13585},{\"nm\":\"PROFILE\",\"lv\":[{\"v\":{\"Party\":null,\"Ads\":null},\"vt\":\"java.util.Map\",\"cn\":2}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":41962}]}" ;

    for(string ss : prettyJSON(jj)){
        cout << ss << endl ;
    }
	return 0;
}