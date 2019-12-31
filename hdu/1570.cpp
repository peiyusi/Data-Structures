#include &lt;iostream&gt;

using namespace std;

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i &lt;= n; i++) {
        result *= i;
    }   

    return result;
}

int main() {
    int t, n, m;
    char c;
    cin &gt;&gt; t;
    while (t--) {
        cin &gt;&gt; c;
        switch (c) 
        {   
            case 'A':
                cin &gt;&gt; n &gt;&gt; m;
                cout &lt;&lt; (factorial(n)) / (factorial(n - m)) &lt;&lt; endl;
                break;
            case 'C':
                cin &gt;&gt; n &gt;&gt; m;
                cout &lt;&lt; (factorial(n)) / ((factorial(n - m)) * (factorial(m))) &lt;&lt; endl;
                break;
        }   
    }   

    return 0;
}