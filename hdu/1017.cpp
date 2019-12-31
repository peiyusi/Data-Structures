#include &lt;iostream&gt;

using namespace std;

int main(){
    int c;
    int s;
    int n,m;
    int count;
    cin&gt;&gt;s;
    while(s--){
        c=0;
        while(cin&gt;&gt;n&gt;&gt;m){
            c++;
            count=0;
            if(n==0&amp;&amp;m==n)
                break;
            for(int a=1;a&lt;n;a++)
                for(int b=a+1;b&lt;n;b++)
                    if((a*a+b*b +m)%(a*b)==0)
                        count++;
            cout&lt;&lt;&quot;Case &quot;&lt;&lt;c&lt;&lt;&quot;: &quot;&lt;&lt;count&lt;&lt;endl;
        }
        if(s!=0)
            cout&lt;&lt;endl;
    }
    return 0;
}