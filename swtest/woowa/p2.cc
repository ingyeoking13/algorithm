#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Photo
{
  Photo(string name, string datetime, int id) : Name(name), myDateTime(datetime) , Id(id){} ;
  string Name;
  string myDateTime;
  int Id;
  bool operator< (Photo& b) { return b.myDateTime < myDateTime; }
};

bool myComparison(const Photo& a, const Photo& b)  { return a.Id < b.Id; }

string solution(string &S) {
      // write your code in C++14 (g++ 6.2.0)
      
      stringstream ss;
      ss.str(S);

      int ID=0;
      int idx=0;
      map<string, int> cityNameMap;
      vector<vector<Photo>> vec;

      while (true )
      {
        string photoName, cityName, day, time;
        ss >> photoName >> cityName >> day >> time;
        if (cin.fail()) break;
        cout << photoName <<  " " << cityName << " " << day  << " " << time ;

        //get extension from photoName O(n) : fileNameLength
        size_t point = photoName.find('.');
        string extension = photoName.substr(point);
        string fileName = cityName+ extension; // concat

        // 어떻게 day, time 을 dateTime 같은 클래스 없이 비교할 지 생각해봄
        string dayTime = day+time;

        if ( cityNameMap.find(cityName) == cityNameMap.end())
        {
          cityNameMap.insert({cityName, idx});
          vec.push_back(vector<Photo>());
          vec[idx].push_back(Photo(fileName, dayTime, ID++) );
          idx++;
        }
        else 
        {
          int i  =  cityNameMap[cityName];
          vec[i].push_back(Photo(fileName, dayTime, ID++));
        };
      }

      // 흠.. 이제 각 vector 는 cityName으로 분류되어있고 dateTime기준으로 정렬함 
      for (int i=0; i<vec.size(); i++) sort(vec[i].begin(), vec[i].end());

      // 그다음 각 vector[cityName] 을 순회하면서 숫자를 붙여줌 

      vector<Photo> ansVector;
      for (int i=0; i< vec.size(); i++)
      {
        int size  =  vec[i].size();
        int d = 0 ; 
        while( size )  size/=10, d++; // 자릿수 

        for (int j=0; j<vec[i].size(); i++)
        {
          auto photo = vec[i][j];

          size_t point = photo.Name.find('.');
          string extension = photo.Name.substr(point);
          photo.Name = photo.Name.substr(0, point);

          string curNumber = to_string(j+1);
          for (int k=0; k<d-curNumber.size(); k++) photo.Name += "0";

          photo.Name += curNumber;  
          photo.Name += extension;

          ansVector.push_back(photo);
        }
      }
      //숫자 다붙였으면 ... 음... ID 기준으로 정렬해줌 
      // 일단 콜렉션에 다 넣자 

      sort(ansVector.begin(), ansVector.end(), myComparison);
      string ans;
      for( auto p : ansVector)
      {
        ans += p.Name;
        ans += "\n";
      }
      return ans;
};

int main()
{
  string input = "photo.jpg, Warsaw, 2013-09-05 14:08:15\njohn.png, London, 2015-06-20 15:13:22\nmyFriends.png, Warsaw, 2013-09-05 14:07:13\nEiffel.jpg, Paris, 2015-07-23 08:03:02\npisatower.jpg, Paris, 2015-07-22 23:59:59\nBOB.jpg, London, 2015-08-05 00:02:03\nnotredame.png, Paris, 2015-09-01 12:00:00\nme.jpg, Warsaw, 2013-09-06 15:40:22\na.png, Warsaw, 2016-02-13 13:33:50\nb.jpg, Warsaw, 2016-01-02 15:12:22\nc.jpg, Warsaw, 2016-01-02 14:34:30\nd.jpg, Warsaw, 2016-01-02 15:15:01\ne.png, Warsaw, 2016-01-02 09:49:09\nf.png, Warsaw, 2016-01-02 10:55:32\ng.jpg, Warsaw, 2016-02-29 22:13:11";
    solution(input);
}

