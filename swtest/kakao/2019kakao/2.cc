#include <string>
#include <iostream>
#include <vector>

using namespace std;

string go ( string p )
{
    if (  p.size() == 0) return "";
    
    string u;
    
    int cnt = 0;
    bool balanced = true;
    int i;
    for ( i=0 ; i<p.size(); i++)
    {
        if ( p[i] == '(')  cnt ++;
        else cnt --;
        
        u += p[i];
        if ( cnt == 0 ) 
        {
            i++;
            break;
        }
        if ( cnt < 0) balanced = false;
    }
    
    string v;
    if ( i < p.size() )  v = p.substr(i);
    if (balanced ) 
    {
        u += go (v);
        return u;
    }
    else 
    {
        string nstr;
        nstr += '(';
        nstr += go (v);
        nstr += ')';
        
        string pp;
        for (int j = 1; j<i; j++)
        {
            if ( p[j] == '(') pp += ')';
            else pp += '(';
        }
        return  nstr + pp;
    }
    
}

int main()
{
    string p ;
    cin >> p;
    cout << go(p);
    return 0;
}