#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[100];
    int nCase = 1;
    scanf("%s", input);
    while(input[0] != '#'){
        if(strcmp(input, "HELLO") == 0){
            printf("Case %d: ENGLISH\n", nCase++);
        }else if(strcmp(input, "HOLA") == 0){
            printf("Case %d: SPANISH\n", nCase++);
        }else if(strcmp(input, "HALLO") == 0){
            printf("Case %d: GERMAN\n", nCase++);
        }else if(strcmp(input, "BONJOUR") == 0){
            printf("Case %d: FRENCH\n", nCase++);
        }else if(strcmp(input, "CIAO") == 0){
            printf("Case %d: ITALIAN\n", nCase++);
        }else if(strcmp(input, "ZDRAVSTVUJTE") == 0){
            printf("Case %d: RUSSIAN\n", nCase++);
        }else{
            printf("Case %d: UNKNOWN\n", nCase++);
        }
        scanf("%s", input);
    }
    return 0;
}