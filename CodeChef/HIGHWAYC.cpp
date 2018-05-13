//Problem Link: https://www.codechef.com/problems/HIGHWAYC


#include <bits/stdc++.h>
using namespace std;
main()
{
    long int t;
    cin >> t;

    cout << fixed << showpoint;
    cout << setprecision(6);

    while (t--) {
        int n;
        double s, y;
        cin >> n >> s >> y;

        double p[n], v[n], d[n], l[n];

        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> l[i];

        double r[n], c[n];

        for (int i = 0; i < n; i++) {
            if ((d[i] == 1 && p[i] > 0) || (d[i] == 0 && p[i] < 0)) {
                r[i] = -1;
                c[i] = -1;
            }

            else if (p[i] == 0) {
                r[i] = 0;
                c[i] = (l[i] + pow(10, -6)) / v[i];
            }

            else {
                r[i] = (abs(p[i]) - pow(10, -6)) / v[i];
                c[i] = (abs(p[i]) + l[i] + pow(10, -6)) / v[i];
            }
        }

        double time = 0;
        double ntime;
        double lct = y / s;

        for (int i = 0; i < n; i++) {
            if (r[i] == -1)
                time = time + lct;

            else {

                if (((time + lct) < r[i]) || (time > c[i]))

                    time = time + lct;

                else

                    time = c[i] + lct;
            }
        }
        cout << time << "\n";
    }
}
