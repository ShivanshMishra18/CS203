#include <bits/stdc++.h>
using namespace std;

struct point
{
	long long int x, y;
};
point ppf;

// Rotation orientation from p3 to p1 via p2
int orientation(point p1, point p2, point p3)
{
	int sign = (p2.x - p1.x)*(p3.y - p2.y) - (p2.y - p1.y)*(p3.x - p2.x);

	if (sign == 0)	return 0;	// Collinear
	if (sign > 0)	return 1;	// Clockwise
	return 2;					// Anticlockwise
}

point StackSecondElement(stack <point> &ss) 
{
    point temp = ss.top();
    ss.pop();

    point ret = ss.top();
    ss.push(temp);

    return ret; 
}

long long int DistanceSquare(point p1, point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

bool compare(point &p1, point &p2)
{
    int orientStatus = orientation(p1, ppf, p2);

    if (!orientStatus) {
        return (DistanceSquare(p1, ppf) > DistanceSquare(p2, ppf)) ? false : true; 
    }

    if (orientStatus == 1)
        return false;
    return true;
}

int main()
{
	int n;
	long long int xx, yy;
	vector <point> v;
	cin>>n;

	for (int i=0; i<n; i++)
    {
        point p_in;
		cin>>p_in.x>>p_in.y;

        v.push_back(p_in);
    }

    xx = v[0].x;    yy = v[0].y;

    for (int i=1; i<n; i++)
    {   
        if ((xx>v[i].x) || (xx==v[i].x && yy>v[i].y))
        {
            xx = v[i].x;
            yy = v[i].y;			
        }
    }

	ppf.x = xx;
	ppf.y = yy;

	sort(v.begin(), v.end(), compare);
    // cout << xx << " " << yy ;
    // cout << "\nSorted: ";
    // for (int t=0; t<n; t++) {cout<<"("<<v[t].x<<", "<<v[t].y<<") ";} cout<<"\n";

    int m=1;

    for (int i=1; i<n; i++)
    {
        while ( (i<(n-1)) && (orientation(v[i], ppf, v[i+1])==0) )
            i++;

        v[m++] = v[i];
    }
    v.erase(v.begin()+m, v.end());
    n = m;

    // cout << n << "\nReduced: ";
    // for (int t=0; t<n; t++) {cout<<"("<<v[t].x<<", "<<v[t].y<<") ";} cout<<"\n";
    // cout << "Reduced size: " << v.size();

    if (n < 3)  return 0;

    stack <point> ss;
    ss.push(v[0]);
    ss.push(v[1]);
    ss.push(v[2]);

    for (int i=3; i<n; i++)
    {
        while (orientation(ss.top(), StackSecondElement(ss), v[i]) != 2)
            ss.pop();

        ss.push(v[i]);
    }

    cout<<"("<<ppf.x<<", "<<ppf.y<<")\n";
    while (ss.size()!=1)
    {
        cout<<"("<<ss.top().x<<", "<<ss.top().y<<")\n";
        ss.pop();
    }

    return 0;
}
