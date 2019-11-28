#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> a[30], b;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int w = board.size();
    int h = board[0].size();

    for (int i=0; i<w; i++ )
    {
        for (int j=h-1; j>=0; j--)
        {
            if ( board[j][i] == 0) continue;
            a[i].push_back( board[j][i] );
        }
    }

    for (int i : moves )
    {
        i--;
        if ( a[i].size() == 0 ) continue;
        
        int item = a[i].back();
        a[i].pop_back();
        if ( b.size() > 0 && item == b.back()) b.pop_back(), answer+=2;
        else b.push_back(item);
    }

    return answer;
}