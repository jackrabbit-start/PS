#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

string s;
ld midx, midy;
ld pii;

void findCircumcenter(ld a1, ld b1, ld a2, ld b2, ld a3, ld b3)
{
    double A = a2 - a1;
    double B = b2 - b1;
    double C = a3 - a1;
    double D = b3 - b1;
    double E = A * (a1 + a2) + B * (b1 + b2);
    double F = C * (a1 + a3) + D * (b1 + b3);
    double G = 2.0 * (A * (b3 - b2) - B * (a3 - a2));
    if (G == 0)
    {
        midx = a1;
        midy = b1;
        return;
    }

    midx = (D * E - B * F) / G;
    midy = (A * F - C * E) / G;
    return;
}

ld cal_x(ld a1, ld b1, ld cx, ld cy, ld a3, ld b3)
{
    ld aa, bb, cc, temp, ang;
    aa = sqrt(pow(a1 - a3, 2) + pow(b1 - b3, 2));
    bb = sqrt(pow(a1 - cx, 2) + pow(b1 - cy, 2));
    cc = sqrt(pow(cx - a3, 2) + pow(cy - b3, 2));

    temp = (pow(bb, 2) + pow(cc, 2) - pow(aa, 2)) / (2.0 * bb * cc);
    ang = acos(temp);

    return ang;
}

bool fraction(double f, int n)
{
    return fabs(f * n - round(f * n)) < 0.0000001;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    pii = acos(-1);

    while (1)
    {
        ld x1, x2, x3, yy1, y2, y3;
        cin >> s;
        if (s == "END")
        {
            break;
        }
        else
        {
            x1 = stod(s);
        }
        cin >> yy1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        findCircumcenter(x1, yy1, x2, y2, x3, y3);
        ld a = cal_x(x1, yy1, midx, midy, x2, y2);

        ld b = cal_x(x2, y2, midx, midy, x3, y3);

        ld c = cal_x(x3, y3, midx, midy, x1, yy1);
        ll ans = 0;
        for (ll i = 3; i <= 1000; i++)
        {
            ld tmp = (ld)pii / (ld)(i);
            ld aa = (a / tmp);
            ld bb = (b / tmp);
            ld cc = (c / tmp);
            // cout << "<" << aa << " " << bb << " " << cc << " " << tmp << ">";
            if (fraction(a, i) && fraction(b, i) && fraction(c, i))
            {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}