#include <stdio.h>  
#include <stdlib.h>  
  
int Find(int x, int s[]);  
void Union(int c1, int c2, int s[]);  
  
int main(int argc, char const *argv[])  
{  
    int *s;  
    int N, c1, c2;  
    char ch;  
    scanf("%d", &N);  
    s = (int*)malloc(sizeof(int)*N);  
    for (int i = 0; i < N; ++i){  
        s[i] = i;  
    }  
    while(1){  
        scanf("%c", &ch);  
        if(ch == 'S')  
            break;  
        scanf("%d %d", &c1, &c2);  
        if(ch == 'C'){  
            if(Find(c1, s) == Find(c2, s))  
                printf("yes\n");  
            else  
                printf("no\n");  
        }  
        if(ch == 'I')     
            Union(c1, c2, s);  
    }  
    int count = 0;  
    for (int i = 0; i < N; ++i){  
        if(s[i] == i)  
            count++;  
    }  
    if(count == 1)  
        printf("The network is connected.\n");  
    else  
        printf("There are %d components.\n", count);  
    return 0;  
}  
  
int Find(int x, int s[])  
{  
    if(s[x] == x)  
        return x;  
    else  
        s[x] = Find(s[x], s);  
}  
  
void Union(int c1, int c2, int s[])  
{  
    int root1, root2;  
    root1 = Find(c1, s);  
    root2 = Find(c2, s);  
    if(root1 != root2)  
        s[root2] = root1;  
} 
