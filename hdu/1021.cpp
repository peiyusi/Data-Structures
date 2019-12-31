#include &lt;iostream&gt;

using namespace std;

int main() {
    int n;
    while (cin &gt;&gt; n) {
       if (n % 4 == 2) {
           cout &lt;&lt; &quot;yes&quot; &lt;&lt; endl;
       } else {
           cout &lt;&lt; &quot;no&quot; &lt;&lt; endl;
       }   
       // int f0 = 7;
       // int f1 = 11;
       // if (n == 0) {
       //     cout &lt;&lt; &quot;no&quot; &lt;&lt; endl;
       // } else if (n == 1) {
       //     cout &lt;&lt; &quot;no&quot; &lt;&lt; endl;
       // } else {
       //     for (int i = 0; i &lt; n - 1; i++) {
       //         int temp = f1;
       //         f1 = f0 + f1;
       //         f0 = temp;
       //         cout &lt;&lt; f1 % 3 &lt;&lt; endl;
       //     }
       //     
        //    if (f1 % 3 == 0) {
        //        cout &lt;&lt; &quot;yes&quot; &lt;&lt; endl;
        //    } else {
        //        cout &lt;&lt; &quot;no&quot; &lt;&lt; endl;
        //    }
    
    }   
    return 0;
}