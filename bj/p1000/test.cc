#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int N, S, D, F, B, K, cnt[100001], nb, nf, police[100001], p, c[100001];
queue <int> q;
void BFS(int x)
{
q.push(x);
while (!q.empty())
{
x = q.front();
q.pop();
printf("%d %d\n", x, cnt[x]);
int nb = x - B;
int nf = x + F;
if (0 < nb)
if (police[nb] != 1 && c[nb] == 0)
{
c[nb] = 1;
q.push(nb);
cnt[nb]=cnt[x]+1;
}
if (nf<=N)
if (police[nf] != 1 && c[nf] == 0)
{
c[nf] = 1;
q.push(nf);
cnt[nf] = cnt[x] + 1;
}
}

}
int main() {
cin >> N >> S >> D >> F >> B >> K;
for (int i = 1; i <= K; i++)
{
cin >> p;
police[p] = 1;
}
cnt[D] = -1;
BFS(S);//S에서 D까지 탐색 시작
if (cnt[D] == -1) //D로 갈 수 없을 시
cout << "BUG FOUND" << '\n';
else
cout << cnt[D] << '\n';
}
