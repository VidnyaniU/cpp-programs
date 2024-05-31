#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<double>> mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<double>> rowReduction(vector<vector<double>> mat, int rows, int cols)
{
    int i, j;
    int r = 0;

    // cout << rows << "::" << cols << endl;
    while (r < rows)
    {
        double pivot = mat[r][r];
        if (pivot != 0) // Ensure pivot is not zero
        {
            for (i = 0; i < cols; i++)
            {
                mat[r][i] = mat[r][i] / pivot;
            }

            for (i = r + 1; i < rows; i++)
            {
                double temp = mat[i][r];
                for (j = r; j < cols; j++)
                {
                    mat[i][j] = mat[i][j] - (temp * mat[r][j]);
                }
            }
        }
        r++;
    }
   
    return mat;
}
int main()
{

    return 0;
}