#include&lt;stdio.h&gt;
#include&lt;algorithm&gt;
using namespace std;
int n[1010][400],a,i,j;
int main(){
    n[1][0]=0;n[2][0]=1;
    for(i=3;i&lt;1002;i++){
        int c=0;
        for(j=0;j&lt;400;j++){
            n[i][j]=n[i-1][j]+2*n[i-2][j]+c;
            c=n[i][j]/10;
            n[i][j]%=10;
        }
    }
    while(~scanf(&quot;%d&quot;,&amp;a)){
        if(a==1) printf(&quot;0\n&quot;);
        else{
            for(j=399;j&gt;=0;j--)
            if(n[a][j]) break;
            for(i=j;i&gt;=0;i--)
            printf(&quot;%d&quot;,n[a][i]);
            printf(&quot;\n&quot;);
        }
    }
}