#include &lt;iostream&gt;

using namespace std;

int main()
{
    int start;
    int sum = 0;
    while (cin &gt;&gt; start)
    {   
        for (int i = 0; i &lt;= start; i++)
        {   
            sum += i;
        }   
        cout &lt;&lt; sum &lt;&lt; &quot;\n\n&quot;;
        sum = 0;
    }   

    return 0;   
}