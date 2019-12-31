#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;algorithm&gt;
#include &lt;cstdio&gt;

using namespace std;

const string consecutives=&quot;aeiou&quot;;

bool is_consecutive(char c){
    for( unsigned int i=0; i&lt;consecutives.size(); i++ )
        if( c==consecutives[i] )
            return true;
    return false;
}

bool has_no_consective(string&amp; s){
    for( unsigned i=0; i&lt;s.size(); i++ )
        if(is_consecutive(s[i]))
            return false;
    return true;
}

bool solve_func(string&amp; s){
    if (has_no_consective(s))
        return false;
    if (s.size() == 1){
        if(is_consecutive(s[0]))
            return true;
        else
            return false;
    }
    if( s.size() == 2){
        if( is_consecutive(s[0])&amp;&amp;is_consecutive(s[1])&amp;&amp;s[0]==s[1]&amp;&amp;(s[0]!='e'&amp;&amp;s[0]!='o') )
            return false;
        if (!is_consecutive(s[0])&amp;&amp;!is_consecutive(s[1])&amp;&amp;s[0]==s[1])
            return false;
        else
            return true;
    }
    for( unsigned i=0; i&lt;s.size()-2; i++ ){
        if((is_consecutive(s[i])&amp;&amp;is_consecutive(s[i+1])&amp;&amp;is_consecutive(s[i+2])) || (!is_consecutive(s[i])&amp;&amp;!is_consecutive(s[i+1])&amp;&amp;!is_consecutive(s[i+2])))
            return false;
        if(is_consecutive(s[i])&amp;&amp;is_consecutive(s[i+1])&amp;&amp;s[i]==s[i+1]&amp;&amp;s[i]!='e'&amp;&amp;s[i]!='o')
            return false;
        if(is_consecutive(s[i+1])&amp;&amp;is_consecutive(s[i+2])&amp;&amp;s[i+1]==s[i+2]&amp;&amp;s[i+1]!='e'&amp;&amp;s[i+1]!='o')
            return false;
        if( !is_consecutive(s[i])&amp;&amp;!is_consecutive(s[i+1])&amp;&amp;s[i]==s[i+1] )
            return false;
        if( !is_consecutive(s[i+1])&amp;&amp;!is_consecutive(s[i+2])&amp;&amp;s[i+1]==s[i+2] )
            return false;

    }
    return true;
}

int main(){
    string password;
    while(cin &gt;&gt; password &amp;&amp; password != &quot;end&quot;){
        if(solve_func(password)){
            printf(&quot;&lt;%s&gt; is acceptable.\n&quot;, password.c_str());
        }
        else{
            printf(&quot;&lt;%s&gt; is not acceptable.\n&quot;, password.c_str());
        }
    }
    return 0;
}