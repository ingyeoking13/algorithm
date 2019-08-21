/*
백준 9946 
단어 퍼즐
*/
#include <stdio.h>
#include <string.h>

int main()
{
  // 배열의 길이는 1000 + 1 이어야합니다. null(=0) 문자 가 반드시 끝에 들어가야합니다. 
  char s[(int)1e3+1], s2[(int)1e3+1];
  int test_case =1;
  while(true)
  {
    scanf("%s%s", s, s2);
    if (strcmp(s, "END")==0) return 0;

    int len = strlen(s);
    int len2 = strlen(s2);

    // 0 으로 초기화
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    // s에 있는 문자열을 a~z 0~25 더해줍니다. 
    for (int i=0; i<len; i++) cnt[s[i]-'a']++;
    // s2에 있는 문자열을 a~z 0~25 차감해줍니다.
    for (int i=0; i<len; i++) cnt[s2[i]-'a']--;

    // 하나라도 0이 아니라면 문자의 구성이 다른 것입니다.
    bool chk=true;
    for (int i=0; i<26; i++) 
    {
      if ( cnt[i] != 0) chk=false;
    }

    if (chk) printf("Case %d: same\n", test_case++);
    else printf("Case %d: different\n", test_case++);
  }
}