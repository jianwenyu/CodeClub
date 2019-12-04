#include <stdio.h>
#include <stdlib.h>

int frogJump(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int a,b,c,i;
    a = 1;
    b = 2;
    c = 0;
    for(i=3;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
    
}

int frogJump2(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return frogJump2(n-1)+frogJump2(n-2);
}

int (*p[2])(int);
int main(int argc, char **argv){
    (p)[0] =frogJump;
    (p)[1] =frogJump2;
    int n = atoi(argv[1]);
    int i = 0;
    for(i = 0; i < 2; i++){
        printf("There are %d ways to jump on stairs %d\n", (*p[i])(n),n);
    }
    
    return 0;
}