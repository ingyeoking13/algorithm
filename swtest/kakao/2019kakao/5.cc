#include <string>
#include <algorithm>
#include <vector>

using namespace std;
struct item
{
    int x, y, t;
    item(int x, int y, int t) :x(x), y(y), t(t) {};
    bool operator<  (item b)
    {
        if ( x == b.x )
        {
            if ( y == b.y )
            {
                return t< b.t;
            }
            return y < b.y;
        }
        return x < b.x;
    }
};

bool map[104][104][2];
vector<vector<int>> solution(int n, vector<vector<int>> orders) {
    
    vector<vector<int>> answer;
    
    for (int i=0 ;i<104; i++)
    {
        for (int j=0 ;j<104; j++) map[i][j][0] = map[i][j][1] = false;
    }
    
    for (auto order: orders )
    {
        int y = order[0], x = order[1];
        y+=2;
        int bo = order[2], install = order[3];
        
        if (bo)
        {
            if( install )
            {
                bool fine = false;
                // 내 바로 아래 기둥위 || 오른쪽과 왼쪽이 보로 연결  || 내 우측 기둥위
                fine =  map[x-1][y][0] || (map[x][y+1][1] && map[x][y-1][1]) || map[x-1][y+1][0];
                map[x][y][1] = fine;
            }
            else //delete
            {
                bool fine = true;
                // 내가 지움으로 인해서, 
                // 내 위의 기둥 이 건전하지 못 할 경우
                // 내 옆의 보가 건전하지 못 할 경우 
                if ( map[x][y][0] )
                {
                    fine  &= (map[x][y-1][ 1 ] || map[x-1][y][0]);
                }
                if ( map[x][y+1][0])
                {
                    fine  &= (map[x][y+1][ 1 ] || map[x-1][y+1][0]);
                }
                if( map[x][y+1][1])
                {
                    fine &= (map[x-1][y+1][0] || map[x-1][y+2][0]);
                }
                if (map[x][y-1][1])
                {
                    fine &= (map[x-1][y-1][0] || map[x-1][y][0]);
                }
                
                if ( fine ) map[x][y][1] = false;
            }
        }
        else  // 기둥 
        {
            if ( install )
            {
                bool fine = false;
                // 땅 위거나, 보위에 존재 하거나, 다른 기둥이 내아래에 있을 때 
                fine = (x==0) || map[x][y-1][1] ||  map[x][y][1] || map[x-1][y][0];
                map[x][y][0]= fine;
            }
            else 
            {
                bool fine = true;
                // 내 위의 기둥이 건전하지 못할경우
                // 내 위의 보가 건전하지 못할경우
                if ( map[x+1][y][0])
                {
                    // 내 위의 기둥은 보가 필수적이됨
                    fine &= (map[x+1][y][1] || map[x+1][y-1][1]);
                }
                
                if ( map[x+1][y][1])
                {
                    // 내 위 보가 건전하지 못할경우 => 
                    //우측에 기둥이 없거나, 양옆이 보로 연결되어있지 않다면 
                    fine &= (map[x][y+1][0] || (map[x+1][y-1][1] && map[x+1][y+1][1] ) );
                }
                if (map[x+1][y-1][1])
                {
                    // 내 위 좌측 보가 건전하지 못할경우 => 
                    //좌측에 기둥이 없거나, 양옆이 보로 연결되어있지 않다면 
                    fine &= (map[x][y-1][0] || (map[x+1][y-2][1] && map[x+1][y][1]));
                }
                if ( fine ) map[x][y][0] = false;
            }
        }
    }
    
    vector<item> v;
    for (int i=0; i<104; i++)
    {
        for (int j=0; j<104; j++)
        {
            for (int k=0; k<2; k++)
            {
                if ( map[i][j][k ]) v.push_back( {j-2, i, k } );
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        answer.push_back({
            it.x, it.y, it.t
        });
    }
    
    return answer;
}