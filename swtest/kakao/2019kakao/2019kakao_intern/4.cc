#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

struct node 
{
    ll val;
    int id;
    node(ll val, int id) : val(val), id(id) {};
    node(){};
    bool operator<(const node& o) const { return val < o.val; }
};

set<node> s;
int p[(int)2e5];

int ufind(int x)
{
    if ( x == p[x]) return x;
    return p[x] = ufind(p[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    for(int i=0; i<2e5; i++) p[i] =i;
    vector<long long> answer;
    
    int id = 0;
    s.insert({k+1, -1});
    for (ll number : room_number) 
    {
        if ( s.find({number, 0}) != s.end()) 
        {
            int pid = ufind(s.find({number,0})->id);
//            cout << " duplicated, most right id is "<< pid << "\n";
            ll l = room_number[pid]+1, r = s.upper_bound({room_number[pid]+1, -1})->val-1;
            
            while( l <= r)
            {
                ll mid = (l+r)/2;
                bool chk = s.find({mid,-1})!=s.end();
                if ( chk )  l = mid+1;
                else r = mid-1;
            }
            s.insert({l, id});
            room_number[id] = l;
            
            auto it =s.find({l-1, 0});
            if (it != s.end()) p[ it->id ] = id;
            
            it = s.find({l+1, 0});
            if (it != s.end() ) p[id] = it->id;
            
            id++;
        }
        else 
        {
            s.insert({number, id});
            auto it =s.find({number-1, 0});
            if (it != s.end()) p[ it->id ] = id;
            
            it = s.find({number+1, 0});
            if ( it != s.end()) p[ id ] = it->id;
            id++;
        }
    }
    
    answer.resize(room_number.size());
    for (node i : s)
    {
        if ( i.val == k+1) continue;
        answer[i.id] = i.val;
    }
    
    return answer;
}