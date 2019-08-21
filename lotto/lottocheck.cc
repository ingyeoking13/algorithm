#include <iostream>

using namespace std;

int main()
{
    int T= 11;
    while(T--)
    {
        int sum = 0;
        for (int i=0; i<6; i++)
        {
            int tmp = 0;
            cin >> tmp;
            sum += tmp;
        }
        cout << sum <<"\n";
    }
}