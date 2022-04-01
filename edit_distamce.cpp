// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

// class Solution
// {
// public:
//     int mini(int x, int y, int z)
//     {
//         return min(min(x, y), z);
//     }

//     int editDist(string s, string t, int m, int n)
//     {
//         if (m == 0)
//             return n;

//         if (n == 0)
//             return m;

//         if (s[m - 1] == t[n - 1])
//             return editDist(s, t, m - 1, n - 1);

//         return 1 + mini(editDist(s, t, m, n - 1), editDist(s, t, m - 1, n), editDist(s, t, m - 1, n - 1));
//     }

//     int editDistance(string s, string t)
//     {
//         int m = s.size();
//         int n = t.size();

//         return editDist(s, t, m, n);
//     }
// };

class Solution
{
public:
    int mini(int x, int y, int z)
    {
        return min(x, min(y, z));
    }

    int editDistDp(string s, string t, int n, int m)
    {
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }

                else if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + mini(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
    int editDistance(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        return editDistDp(s, t, n, m);
    }
};
