#include &lt;iostream&gt;

using namespace std;

int main() {
    int k, a;
    while (cin &gt;&gt; k) {
        for (a = 0; ; a++) {
            if ((18 + k * a) % 65 == 0) {
                cout &lt;&lt; a &lt;&lt; endl;
                break;
            }   
            if (a &gt; 65) {
                cout &lt;&lt; &quot;no&quot; &lt;&lt; endl;
                break;
            }   
        }   
    }   

    return 0;
}