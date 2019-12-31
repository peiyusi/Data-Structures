#include &lt;iostream&gt;

using namespace std;

int main() {
    int i, j;
    while (cin &gt;&gt; i &gt;&gt; j) {
        int count = 1;
        int max_count = 0;  
        cout &lt;&lt; i &lt;&lt; &quot; &quot; &lt;&lt; j;
        if (i &gt; j) {
            int temp = i;
            i = j;
            j = temp;
        }   

        for (; i &lt;= j; i++) {
            int num = i;
            if (num == 1) {
                if (max_count &lt; 1) {
                    max_count = 1;
                }   
            } else {
                while (num != 1) {
                    if (num % 2 == 1) {
                        num = 3 * num + 1;
                    } else {
                        num /= 2;
                    }   
                    count++;
                }   
                if (max_count &lt; count) {
                    max_count = count;
                }   
            }   
    
            count = 1;
        }   
        cout &lt;&lt; &quot; &quot;  &lt;&lt; max_count &lt;&lt; endl;
    }   
    

    return 0;
}