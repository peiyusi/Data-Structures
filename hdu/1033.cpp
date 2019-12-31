#include&lt;iostream&gt;
using namespace std;
int main(){
  string a;
  while(cin &gt;&gt; a){
      cout &lt;&lt; &quot;300 420 moveto&quot; &lt;&lt; endl;;
      string b = &quot;you&quot;;
      int x = 310, y = 420;
      for(int i = 0;i &lt; a.length(); i++){
        cout &lt;&lt; x &lt;&lt; &quot; &quot; &lt;&lt; y &lt;&lt; &quot; lineto&quot; &lt;&lt; endl;
        if(a[i] == 'A'){
          if(b == &quot;you&quot;){
            y -= 10;
          b = &quot;xia&quot;;
          continue;    
        }  
        if(b == &quot;xia&quot;){
          x -= 10;
          b = &quot;zuo&quot;;
          continue;
        }    
        if(b == &quot;zuo&quot;){
          y += 10;
          b = &quot;shang&quot;;
          continue;
        }
        if(b == &quot;shang&quot;){
          x += 10;
          b = &quot;you&quot;;
          continue;
        }
      }
      if(a[i] == 'V'){
        if(b == &quot;you&quot;){
            y += 10;
          b = &quot;shang&quot;;
          continue;    
        }  
        if(b == &quot;shang&quot;){
          x -= 10;
          b = &quot;zuo&quot;;
          continue;
        }    
        if(b == &quot;zuo&quot;){
          y -= 10;
          b = &quot;xia&quot;;
          continue;
        }
        if(b == &quot;xia&quot;){
          x += 10;
          b = &quot;you&quot;;
          continue;
        }
      }      
    }
    cout &lt;&lt; x &lt;&lt; &quot; &quot; &lt;&lt; y &lt;&lt; &quot; lineto&quot; &lt;&lt; endl &lt;&lt; &quot;stroke&quot; &lt;&lt; endl &lt;&lt; &quot;showpage&quot; &lt;&lt; endl;
  }
  return 0;
}