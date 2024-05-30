#include <bits/stdc++.h>
using namespace std;

bool isEndOfSentence(char ch)
{
    return ch == '.' || ch == '!' || ch == '?';
}
void fileStats(string fileName)
{
    ifstream fin(fileName);

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    int sentenceCount = 0;

    string line;
    while (getline(fin, line))
    {

        ++lineCount;
        charCount += line.size() + 1;

        bool inWord = false;
        for (char ch : line)
        {
            if (isspace(ch))
            {
                inWord = false;
            }
            else
            {
                if (!inWord)
                {
                    ++wordCount;
                    inWord = true;
                }
                if (isEndOfSentence(ch))
                {
                    ++sentenceCount;
                }
            }
        }
    }
    if (fin.eof())
    {
        ++charCount;
    }
    cout << "Number of lines :: " << lineCount << endl;
    cout << "Number of words :: " << wordCount << endl;
    cout << "Number of characters :: " << charCount << endl;
    cout << "Number of sentences :: " << sentenceCount << endl;
}
int main()
{
    string fileName = "input.txt";
    fileStats(fileName);
    return 0;
}