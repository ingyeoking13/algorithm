#include <iostream>
#include <vector>

int main(void)
{
int iN;
std::cin >> iN;

std::vector<int> vectorData(iN);

for (int i=0; i<iN; i++)
std::cin >> vectorData[i];

int iMax = 0;
int iCount = 0;

std::vector<int> vectorR;
vectorR.reserve(iN);

for (int i = 0; i < iN; i++)
{
if (iMax < vectorData[i])
{
  iMax = vectorData[i];
  vectorR.push_back(iMax);
  iCount++;
}
}

const int iLen = vectorR.size();
std::cout << iLen << std::endl;
for (int i=0; i<iLen; i++)
std::cout << vectorR[i] << " ";

return 0;
}
