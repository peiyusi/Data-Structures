#include<stdio.h>  
#include<string.h>  
struct node  
{  
    int b;  
    int k;  
    int m;  
} s[100010] ;  
int main()  
{  
    int i, j;  
    int n;  
    int maxi = 1, c;  
    scanf("%d", &n);  
    for (i = 0; i < n; i++)  
    {  
        scanf("%d", &s[i].b);  
    }  
  
    for (i = 0; i < n; i++)  
    {  
        s[i].k = 1;  
    }  
    for (i = 0; i < n - 1; i++)  
    {  
        for (j = i + 1; j < n; j++)  
        {  
            if (s[j].b > s[j - 1].b)  
            {  
                s[i].k++;  
  
            }  
            else  
            {  
                break;  
            }  
  
        }  
    }  
    for (i = 0; i < n; i++)  
    {  
        if (s[i].k > maxi)  
        {  
            maxi = s[i].k;  
            c = i;  
        }  
    }  
    for (i = c; i < c + maxi-1; i++)  
    {  
        printf("%d ", s[i].b);  
    }  
    printf("%d\n", s[c+maxi-1].b);  
}
