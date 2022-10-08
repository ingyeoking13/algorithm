#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string buildTree(string str) {
    int height = 1;
    int len = str.size();
    while(true) {
        int elem = pow(2, height)-1;
        if (elem >= len) break;
        height++;
    }
    string suffix;
    int elem = pow(2, height) -1;
    for (int i=0; i<elem-len; i++) {
        suffix += "0";
    }
    string result = suffix + str;
    return result;
}

bool validCheck(string str, int f, int t) {
    int mid = (f+t)/2;
    // cout << f << " , " << t << ", " << "idx: " << mid <<"\n";
    if (f == t) return true;
    if (str[mid]=='1') {
        bool result = validCheck(str, f, mid-1);
        result &= validCheck(str, mid+1, t);
        return result;
    }

    bool result = true;
    for (int i=f; i<=t; i++) {
        result &= str[i]=='0';
    }
    return result;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long number: numbers){
        long long origin = number;
        string str;
        while(number){
            str += ('0' + (number%2));
            number /= 2;
        }
        reverse(str.begin(), str.end());
        cout << str <<"\n";
        string treeStr = buildTree(str);
        int len = treeStr.size();
        // cout << len <<"\n";
        int _answer = validCheck(treeStr, 0, len-1);
        answer.push_back(_answer);
    }

    // for (bool ans: answer) {
    //     cout << ans << " ";
    // }
    // cout <<"\n-------\n";
    return answer;
}

int main(){
    solution({7, 5});
    solution({63, 111, 95});
    solution({2, 4});
    solution({1024});
    solution({0b11111111111111111111111111111111111111111111111111111111111111});
}
