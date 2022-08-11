#include<bits/stdc++.h>

using namespace std ;


int main(){

    char *p[] = {"aaa" , "bbb" , "cccc" , "dddd"} ;
    char **ptr[]  = {p+3 , p+2 , p+1 , p} ;
    char ***pptr = ptr ;
    
    printf("%p ------ [%p %p %p %p]\n" , &p , *p , *(p+1) , *(p+2), *(p+3)) ;
    printf("%p ----- [%p]" , &ptr , **(ptr));
    return 0 ;
}