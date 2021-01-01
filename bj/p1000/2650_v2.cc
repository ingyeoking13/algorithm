#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point_old{
  int axis, vert;
  Point_old(int axis, int vert) : axis(axis), vert(vert) {};
};

struct Point{
  int x, y;
  Point() {};
  Point(int x, int y): x(x), y(y) {};
};

struct Line{
  Point u, v;
  Line(Point u, Point v): u(u), v(v){};
};

bool compare(Point l, Point r)
{
  if (l.x == r.x)
	return l.y <= r.y;
  return l.x <= r.x;
}

int ccw(Line l, Point p)
{
  Point u = l.u;
  Point v = l.v;
  int val = (v.x-u.x)*(p.y-u.y) - (v.y-u.y)*(p.x-u.x);
  if (val > 0) return 1;
  else if (val < 0) return -1;
  return 0;
};

bool isCrossed(Line l1, Line l2)
{
  int ccw1 = ccw(l1, l2.u) * ccw(l1, l2.v);
  int ccw2 = ccw(l2, l1.u) * ccw(l2, l1.v);
  int ret = 0;

  if (ccw1 == 0 && ccw2 == 0)
  {
	if( compare(l1.v, l1.u) ) 
	{
	  Point tmp = l1.u;
	  l1.u = l1.v;
	  l1.v = tmp;
	};

	if( compare(l2.v, l2.u) )
	{
	  Point tmp = l2.u;
	  l2.u = l2.v;
	  l2.v = tmp;
	};

	ret = compare( l1.u, l2.u ) && compare( l2.u, l1.v ) && compare( l1.v, l2.v ); 
	ret |= compare( l2.u, l1.u ) && compare( l1.u, l2.v ) && compare( l2.v, l1.v );
  }
  else 
	ret = ccw1<=0 && ccw2<=0;
  return ret;
};

int main()
{
  int n;
  cin >> n;

  vector<Point_old> olds;

  for(int i=0; i<n/2; i++)
  {
	int axis, v;

	cin >> axis >> v;
	Point_old p_1 = Point_old(axis, v);
	olds.push_back(p_1);

	cin >> axis >> v;
	p_1 = Point_old(axis, v);
	olds.push_back(p_1);
  };

  int mxy = 0; 
  int mxx = 0;
  for (int i=0; i<n; i++)
  {
	switch (olds[i].axis)
	{
	  case 1:
	  case 2:
		mxx = max(mxx, olds[i].vert);
		break;
	  case 3:
	  case 4:
		mxy = max(mxy, olds[i].vert);
		break;
	}
  }

  mxx++, mxy++;
  vector<Point> points;
  //restruct all geo info
  for (int i=0; i<n; i++)
  {
	Point p;
	switch( olds[i].axis ) 
	{
	  case 1:
		p = Point(olds[i].vert, 0);
		break;
	  case 2:
		p = Point(olds[i].vert, mxy);
		break;
	  case 3:
		p = Point(0, olds[i].vert);
		break;
	  case 4:
		p = Point(mxx, olds[i].vert);
		break;
	}
	points.push_back(p);
  }

  vector<Line> lines;
  for (int i=0; i<n/2; i++)
	lines.push_back(Line(points[2*i], points[2*i+1]));

  int ans1 = 0;
  int ans2 = 0;
  for (int i=0; i<n/2; i++)
  {
	int tmp = 0;
	//cout << "line1 : " << lines[i].u.x << ", " << lines[i].u.y <<" ";
	//cout << lines[i].v.x << ", " << lines[i].v.y <<"\n";
	for (int j=0; j<n/2; j++)
	{
	  if (i==j) 
		continue;
	  bool c = isCrossed(lines[i], lines[j]);
	 //cout << lines[j].u.x << ", " << lines[j].u.y <<" ";
	  //cout << lines[j].v.x << ", " << lines[j].v.y <<"\n";

	  if (c) 
	  {
		//cout << i << "crossed "<< j << "** \n";
		ans1++;
		tmp++;
	  }
	}
	if (tmp > ans2)
	{
	  ans2 = tmp;
	}
  }

  cout << ans1/2 << "\n" << ans2;
};
