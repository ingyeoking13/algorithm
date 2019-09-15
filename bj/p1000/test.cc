#include <iostream>

using namespace std;

pair<int ,int> myFunc()
{
	return {1, 3};
};

int main()
{
	auto i = myFunc();
	cout << i.first << " " << i.second <<"\n";
}