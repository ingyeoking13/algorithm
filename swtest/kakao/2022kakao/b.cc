#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    reverse(deliveries.begin(), deliveries.end());
    reverse(pickups.begin(), pickups.end());
    for (int i=0; i<n; i++) {
        int d = deliveries[i];
        int p = pickups[i];
        if (d || p) {
            int count = max(d,p)/cap + (max(d,p)%cap?1:0);
            answer += count*(n-i)*2;
            int dcount = d/cap + (d%cap?1:0);
            int pcount = p/cap + (p%cap?1:0);
            deliveries[i] = 0;
            pickups[i] = 0;

            int remained = (count - dcount)*cap + (d%cap?(cap-d%cap):0);
            int j = i;
            while( ++j < n && remained > 0) {
                int canDeliver = min(remained, deliveries[j]);
                if (canDeliver){
                    remained -= canDeliver;
                    deliveries[j] -= canDeliver;
                }
            }
            remained = (count - pcount)*cap + (p%cap?(cap-p%cap):0);
            j = i;
            while( ++j < n && remained > 0) {
                int canPickup = min(remained, pickups[j]);
                if (canPickup){
                    remained -= canPickup;
                    pickups[j] -= canPickup;
                }
            }
        }
        // for (int i=0; i<n; i++) {
        //     cout << deliveries[i]<< " " ;
        // }
        // cout <<"\n";
        // for (int i=0; i<n; i++) {
        //     cout << pickups[i] << " ";
        // }
        // cout <<"\n^^" << answer << "\n";
    }
    return answer;
}

int main(){
    // vector<int> input = {1,0,3,1,2};
    // vector<int> pickups = {0,3,0,4,0};
    vector<int> input = {1,0,2,0,1,0,2};
    vector<int> pickups = {0,2,0,1,0,2,0};

    // cout<< solution(4, 5, input, pickups);
    cout<< solution(2, 7, input, pickups);
}