#include <stdio.h>

int main(){
    int x, y;
    int c = 10, *p, *p1, *p2;
    
    p = &c;
    *p1 = c++;
    *p2 = c;
    printf("%d\n%d\n%d", *p, *p1, *p2);
    return 0;
}