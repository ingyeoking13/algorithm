#include <bits/stdc++.h>

using namespace std;

struct Input 
{
    int x, y, h;
    Input(int x, int y, int h) : x(x), y(y), h(h) {};
    Input(){};
    bool operator<(const Input& o ) const
    {
        return x < o.x;
    }
};

Input input[(int)1e5];
int field[(int)2e5];

priority_queue<Input> pq, pq2;

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> input[i].x >> input[i].h >> input[i].y;
        input[i].x = -input[i].x;
        input[i].y = -input[i].y;
        pq.push(input[i]);
    }

    int cur = 0, latest=0;
    multiset<int> mm;
    while(!pq.empty() || !pq2.empty())
    {

        while ( !pq.empty() && (pq2.empty() || -pq2.top().x > -pq.top().x))
        {
            Input now_meet_Building = pq.top();
            pq.pop();
            if ( cur < now_meet_Building.h )
            {
                cur = now_meet_Building.h;
                cout << -now_meet_Building.x << " " << cur << " ";
            }
            mm.insert(-now_meet_Building.h);
            pq2.push({now_meet_Building.y,0, now_meet_Building.h} );
        }

        Input ended_building = pq2.top();
        pq2.pop();

        mm.erase(-ended_building.h);


        int tmp; 
        if ( mm.size() ==0) tmp = 0;
        else tmp = *mm.begin();
        tmp = -tmp;

        if ( ended_building.h == cur && tmp < cur )
        {
            if ( !pq.empty() && pq.top().x == ended_building.x && pq.top().h >= ended_building.h)
            {

            }
            else 
            {
                if ( latest != -ended_building.x)
                     cout << -ended_building.x << " " << tmp << " ";

                cur = tmp;
                latest = -ended_building.x;
            }
        }
    }
}