#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;string.h&gt;
using namespace std;

int main()
{
   char N[1000];
   while (cin &gt;&gt; N)
   {
       int n = 0;
       if (N[0] == '0')
       {
           break;
       } else {
           for (int i = 0; i &lt; strlen(N); i++)
           {
               n += N[i] - '0';
           }
           if (n % 9 == 0)
           {
               cout &lt;&lt; 9 &lt;&lt; endl;
           } else {
               cout &lt;&lt; n % 9 &lt;&lt; endl;
           }
       }
   }

   return 0;
}