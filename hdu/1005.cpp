#include &lt;iostream&gt;

using namespace std;

int main()
{
    int A, B, N;
    int num[50];
    num[1] = num[2] = 1;


    while (cin &gt;&gt; A &gt;&gt; B &gt;&gt; N, A || B || N)
    {
        for (int i = 3; i &lt;= 50; i++)
        {
            num[i] = (A * num[i-1] + B * num[i-2]) % 7;
        }

        cout &lt;&lt; num[N % 49] &lt;&lt; endl;

    }

    return 0;
}