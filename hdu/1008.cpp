#include &lt;iostream&gt;
#include &lt;math.h&gt;
#include &lt;algorithm&gt;
using namespace std;

int main()
{
    int N;
    while (cin &gt;&gt; N, N)
    {
        int time = 0;
        int temp = 0;
        int floor = 0;
        for (int i = 0; i &lt; N; i++)
        {
            cin &gt;&gt; floor;
            if (i == 0) {
                time = floor * 6;
            } else {
                if (temp &lt; floor) {
                    time += (floor - temp) * 6;
                } else {
                    time += (temp - floor) * 4;
               }
            }
            temp = floor;
        }

        cout &lt;&lt; time + N * 5 &lt;&lt; endl;
    }

    return 0;
}