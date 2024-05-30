#include <bits/stdc++.h>
using namespace std;
void format(double number)
{
    string num = to_string(number);
    // num.erase(num.find_last_not_of('0') + 1, std::string::npos);
    // num.erase(num.find_last_not_of('.') + 1, std::string::npos);

    for (int i = 0; i < num.length(); i++)
    {
        cout << num[i] << " ";
    }

    vector<char> F = {0};
    vector<char> I = {0};
    bool flag = false;
    int i = 0;

    // for F
    while (num[i] != '.')
    {
        if (num[i] != '0')
            F.push_back(num[i]);
        else
        {
            // check for next digits if any of them is greater than zero till then count the number of zeroes
            int j = i;
            char next_digit;
            int count = 0;
            do
            {

                if (num[j] != '0')
                {
                    for (int i = 0; i < count; i++)
                    {
                        if (count > 0 && num[j] != '.')
                            F.push_back('0');
                    }
                    break;
                }
                else if (num[j] == '0')
                {

                    count++;
                    j++;
                }

            } while (j < 5);
        }
        i++;
    }
    i = i + 1;
    // cout << i << endl;
    // for I

    while (i < num.size() - 2)
    {

        int count = 0;
        if (num[i] != '0')
        {
            I.push_back(num[i]);
            flag = true;
        }
        else if (num[i] == '0' && flag == true)
        {
            I.push_back(num[i]);
        }
        i++;
    }

    // for (int i = 0; i < I.size(); i++)
    // {
    //     cout << I[i];
    // }
    // for (int i = 0; i < 5 - I.size(); i++)
    // {
    //     cout << "#";
    // }
    // cout << ".";
    // for (int i = 0; i < F.size(); i++)
    // {
    //     cout << F[i];
    // }

    cout << endl;
}
int main()
{
    format(990.0080);

    // format(101.11111);
    return 0;
}