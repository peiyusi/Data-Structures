#include &lt;iostream&gt;

using namespace std;

int main() {
    int n;
    while (cin &gt;&gt; n) {
        if (n &lt;= 168) {
            cout &lt;&lt; &quot;CRASH &quot; &lt;&lt; n &lt;&lt; endl;
            break;
        }   
    }   



    return 0;
}