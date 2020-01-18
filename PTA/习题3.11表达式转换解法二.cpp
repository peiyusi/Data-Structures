#include <iostream>
#include <string>
#include <stdio.h>
#define STEP 3
#define MAX 9999999
using namespace std;
 
string str="";
struct Tree{
    string s;
    Tree *l,*r;
    Tree(){
        l=r=NULL;s="";
    }
    ~Tree(){
        delete l;
        delete r;
    }
};
 
int GetPri(char c){
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/')return 2;
    return -1;
}
 
void In2T(string s,Tree* &T){
    int i,id=-1;int len=s.length();
    int d=0;int p=-1;int mi=MAX;
    for(i=0;i<len;i++){///记录最后计算的那个运算符位置
        if(s[i]=='('){
            d+=STEP;
        }else if(s[i]==')'){
            d-=STEP;
        }else if(GetPri(s[i]==1)&&(i==0||s[i-1]=='(')){///正负号不是运算符
            continue;
        }else if((p=GetPri(s[i]))>0){
            if(p+d<=mi){
                mi=p+d;id=i;
            }
        }
    }
    T=new Tree;///创建子树
    if(id==-1){///去除左右括号
        int id1,id2;
        for(id1=0;id1<len&&s[id1]=='(';id1++);
        for(id2=len-1;id2>=0&&s[id2]==')';id2--);
        T->s=s.substr(id1,id2-id1+1);return;
    }
    T->s=s[id];///
    In2T(s.substr(0,id),T->l);///左子树
    In2T(s.substr(id+1,len-id-1),T->r);///右子树
}
 
void Post(Tree* T){
    if(!T)return;
    Post(T->l);
    Post(T->r);
    if(T->s[0]=='+'&&T->s.length()>1){///去除正号
        ///判断条件还可以为T->s[0]=='+'&&T->left==NULL&&T->right==NULL
       str=str+T->s.substr(1,T->s.length()-1)+" ";return;
    }
    str=str+T->s+" ";
}
 
int main()
{
	freopen("E:in.txt", "r", stdin);
    string ss;
    Tree* T=NULL;
    getline(cin,ss);
    In2T(ss,T);
    Post(T);
    int len=str.length();
    str.erase(len-1,1);///去除末尾空格
    cout<<str;
    fclose(stdin);
    
    return 0;
}


















