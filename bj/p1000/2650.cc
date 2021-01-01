#include <iostream>
#include <vector>

using namespace std;

struct Point{
  int axis;
  int vert;
  Point(int axis, int vert) : axis(axis), vert(vert) {};
};

struct Line{ 
  Point u, v;
  Line(Point u, Point v) : u(u), v(v) {};
}; 

int side(Line line, Point p){
  Point u = line.u;
  Point v = line.v;

  switch(u.axis)
  {
	case 1:
	  //u , v 모두 1에 있을 경우
	  if (v.axis == 1)
	  {
		// u가 v 보다 작은 경우
		if (u.vert < v.vert)
		{
		  // p 가 u 와 v의 사이에 있는경우
		  if (p.axis ==1 && u.vert< p.vert && p.vert < v.vert )
		  {
			return 1;
		  }
		  else return -1;
		}
		else 
		{
		  if (p.axis == 1 && v.vert < p.vert && p.vert < u.vert )
		  {
			return -1;
		  }
		  else return 1;
		}
	  }
	  else if ( v.axis == 2)
	  {
		if (p.axis == 1 )
		{
		  if (u.vert < p.vert ) return 1;
		  else return -1;
		}
		else if (p.axis == 2 )
		{
		  if (v.vert < p.vert ) return 1;
		  else return -1;
		}
		else if (p.axis == 3)
		{
		  return -1;
		}
		else return 1;
	  }
	  else if ( v.axis == 3)
	  {
		if (p.axis == 1 )
		{
		  if (u.vert <p.vert ) return 1;
		  return -1;
		}
		else if (p.axis == 2)
		  return 1;
		else if (p.axis == 3)
		{
		  if (p.vert < v.vert) return 1;
		  else return -1;
		}
		else 
		  return 1;
	  }
	  else
	  {
		if (p.axis == 1) 
		{

		}
		else if (p.axis == 2)
		{

		}
		else if (p.axis == 3)
		{

		}
		else 
		{

		}
	  }
	  break;
	case 2:

	  break;
	case 3:
	  break;
	case 4:
	  break;
  }

};

bool twoLineCrossed(Line l1, Line l2)
{
  return side(l1, l2.u) * side(l1, l2.v) == -1;
};

int main()
{
  int n;
  cin >> n;
  vector<Line> lines;  

  for (int i=0; i<n/2; i++)
  {
	int axis, vert;

	cin >> axis >> vert;
	Point p1 = Point(axis, vert);

	cin >> axis >> vert;
	Point p2 = Point(axis, vert);

	lines.add( p1, p2 ) ;
  }

  int ans1= 0;
  int ans2= 0;

  for (int i=0; i<n/2; i++)
  {
	int ans2Cnt = 0;
	for (int j=i+1; j<n/2; j++)
	{
	  bool crossed = twoLineCrossed( lines[i], line[j] );
	  if ( crossed ) 
	  {
		ans1++;
		ans2Cnt++;
	  }
	}
	if ( ans2 < ans2Cnt ) 
	  ans2 = ans2Cnt;
  }

  cout << ans1 << "\n" << ans2;
}
