#include &lt;iostream&gt;
#include &lt;map&gt;
using namespace std;

int main() {

    map&lt;int, int&gt;nums;
    int N;
    while (cin &gt;&gt; N) {
        int max = 0;
        int num, maxnum;
        for (int i = 0; i &lt; N; i++) {
            cin &gt;&gt; num;
            nums[num]++;
            if (nums[num] &gt; max) {
                max = nums[num];
                maxnum = num;
            }   
        }   

        cout &lt;&lt; maxnum &lt;&lt; endl;
        nums.clear();
    }   
    return 0;
}