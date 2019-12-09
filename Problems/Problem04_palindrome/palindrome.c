#include <stdio.h>
#include <string.h>

int isPallindrome(char *s){
    char *s1,*s2;
    s1 = s;
    s2 = s+strlen(s)-1;
    while(s1<s2){
        if(*s1==*s2){
            s1++;
            s2--;
            continue;

        }else{
            return 0;
        }
    }
    return 1;

}

int main(int argc, char** argv){
    if(argc<2){
        printf("usage: main string\n");
        return -1;
    }
    if(isPallindrome(argv[1])){
        printf("Yes, the string is a palindrome\n");
        
    }else{
        printf("No, the string is not a palindrome\n");
    }

    return 0;
}