#include <bits/stdc++.h>
using namespace std;
void convert_to_base(int number, int base)
{
    if (base == 10)
    {
        cout << number << endl;
        return;
    }
    vector<int> res;
    while (base <= number)
    {
        res.push_back(number % base);
        number = number / base;
    }
    cout << number << " ";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (base >10 && res[i] > 9)
        {
            cout << char(res[i]+55) << " ";
        }
        else
            cout << res[i] << " ";
    }
}
int main()
{
    convert_to_base(25,16);

    return 0;
}