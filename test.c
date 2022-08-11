#include <stdio.h>
  
char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;
  
int main()
{
    int a = 5 ;
    printf("%d\n" , a+5) ;
    printf("%d\n" , a++) ;
    printf("%d\n" , ++a) ;

    return 0;
}

