#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        sort(a.begin(), a.end());

        int max_len = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int min_val = a[i];
                int max_val = a[j];
                if ((min_val + max_val) % 2 == 0)
                {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        cout << n - max_len << "\n";
    }

    return 0;
}
