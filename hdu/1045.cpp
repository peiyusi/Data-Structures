#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
char map[5][5],ans,n;
int find(int r,int c)
{
    int i,j;
    for(i=r+1; i&lt;n; i++)
    {
        if(map[i][c]=='X') 
            break;
        map[i][c]='D';
    }
    for(i=r-1; i&gt;=0; i--)
    {
        if(map[i][c]=='X')
            break;
        map[i][c]='D';
    }
    for(j=c+1; j&lt;n; j++)
    {
        if(map[r][j]=='X')
            break;
        map[r][j]='D';
    }
    for(j=c-1; j&gt;=0; j--)
    {
        if(map[r][j]=='X')
            break;
        map[r][j]='D';
    }
}
void dfs()
{
    int i,j;
    for(i=0; i&lt;n; i++)
    {
        for(j=0; j&lt;n; j++)
        {      
            if(map[i][j]=='.'&amp;&amp;map[i+1][j]=='.'&amp;&amp;map[i][j+1]=='.')
                continue; 
            if(map[i][j]=='.')
            {
                map[i][j]='D';
                find(i,j);
                ans++;
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf(&quot;%d&quot;,&amp;n) &amp;&amp; n)
    {
        ans=0;
        memset(map,'\0',sizeof(map)); 
        for(i=0; i&lt;n; i++)
            scanf(&quot;%s&quot;,&amp;map[i]);
        dfs();
        printf(&quot;%d\n&quot;,ans);
    }
    return 0;
}