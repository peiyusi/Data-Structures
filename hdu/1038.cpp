#include &lt;iostream&gt;
#include &lt;cstdio&gt;

#define p 3.1415927
using namespace std;

int main() {
    float diameter, time ,distance, MPH;
    int revolutions, count = 1;
    while (cin &gt;&gt; diameter &gt;&gt; revolutions &gt;&gt; time, revolutions) {
        distance = (p * diameter * revolutions) / (12 * 5280);  
        MPH = distance * 3600 / time;
        printf(&quot;Trip #%d: %.2f %.2f\n&quot;, count++, distance, MPH);

    }   
    return 0;
}