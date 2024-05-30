#include <bits/stdc++.h>
using namespace std;

void sorter(vector<double> &nums, char choice)
{
    if (choice == 'A')
    {
        sort(nums.begin(), nums.end());
    }
    else if (choice == 'D')
    {
        sort(nums.begin(), nums.end(), greater<double>());
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    string input;
    cout << "Enter the numbers followed by the choice (A/D): ";
    getline(cin, input);
    stringstream ss(input);
    vector<double> nums;
    double number;
    char choice;

    while (ss >> number)
    {
        nums.push_back(number);
    }

    ss.clear();
    ss >> choice;
    sorter(nums, choice);
    return 0;
}