#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

map<string, int> mm;
set<vector<string>> ss;
bool used[8]={0, 0, 0, 0, 0, 0, 0, 0};
void go(int l, int r, vector<string>* user, vector<string>* banned, int* answer)
{
    if ( r == banned->size())
    {
        vector<string> tmp;
        for (int i=0; i<(*user).size(); i++)
        {
            if( used[i] == true ) tmp.push_back( (*user)[i]);
        }
        ss.insert(tmp);
        return;
    }
    
    if ( l == user->size() )
    {
        return;
    }
    
    for (int i=0; i<user->size();  i++)
    {
        if ( used[i] ) continue;
        if ( (*user)[i].size() != (*banned)[r].size() ) continue;
        
        bool matched  = true;
        
        for (int j=0; j<(*user)[i].size(); j++)
        {
            if ( (*user)[i][j] == (*banned)[r][j]  || (*banned)[r][j]== '*') ;
            else matched = false;
        }
        
        if ( matched )
        {
            used[i] =true;
            go( 0, r+1, user, banned, answer);
            used[i] =false;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer=0;
 
	go (0, 0, &user_id, &banned_id,&answer);
    answer = ss.size();
    
    return answer;
}