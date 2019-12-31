#include &lt;iostream&gt;
#include &lt;cmath&gt;
using namespace std;
int main()
{ 
    int m,n;
    int lm,ln,onesteps,step;

    while(cin&gt;&gt;m&gt;&gt;n)
    {
        lm = ceil(sqrt(double(m)));
        ln = ceil(sqrt(double(n)));
        if(lm == ln) step = abs(m-n);
        else 
        {
            int mcl,mcr,ncl,ncr;
            mcr = (lm*lm-m)/2 + 1;
            ncr = (ln*ln-n)/2 + 1;
            mcl = abs(m-(lm*lm-2*lm+2))/2+1;
            ncl = abs(n-(ln*ln-2*ln+2))/2+1;
            step = abs(mcr-ncr)+abs(mcl-ncl)+abs(lm-ln);
        }
        cout&lt;&lt;step&lt;&lt;endl;
    }

    return 0;
}