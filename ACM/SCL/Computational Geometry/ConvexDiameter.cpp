double convex_diameter(polygon_convex &a, int &First, int &Second)
{
    vector<point> &p=a.p;
    int n = p.size();
    double maxd = 0.0;
    if (n == 1)
    {
        First = Second = 0;
        return maxd;
    }
    #define next(i) ((i+1)%n)
    for (int i=0,j=1;i<n;i++)
    {
        while (cmp(det(p[next(i)]-p[i],p[j]-p[i])-det(p[next(i)]-p[i],p[next(j)]-p[i]))<0)
        {
            j=next(j);
        }
        double d = dist(p[i],p[j]);
        if (d > maxd)
        {
            maxd = d;
            First = i;
            Second = j;
        }
        d = dist(p[next(i)],p[next(j)]);
        if (d > maxd)
        {
            maxd = d;
            First = i;
            Second = j;
        }
    }
    return maxd;
}
