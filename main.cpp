#include <iostream>
#include <algorithm>

using namespace std;

int countOf(string str, char regex)
{
    int regCount = 0;
    int strLen = str.length();
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == regex)
        {
            regCount++;
        }
    }
    return regCount;
}

string* split(string str, char regex, int *size)
{
    int regCount = countOf(str, regex) + 1;
    *size = regCount;
    int strLen = str.length();
    int j = 0;
    char ch;
    string* strArr = new string[regCount];
    strArr[0] = "";
    for (int i = 0; i < strLen; i++)
    {
        ch = str[i];
        if (ch != regex)
        {
            strArr[j] += ch;
        }
        else
        {
            j++;
            strArr[j] = "";
        }
    }
    return strArr;
}

void display(string* a, int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << "_";
    }
    cout << endl;
}

void findPermutations(string* a, int n)
{
    sort(a, a + n);

    cout << "Possible permutations are:\n";
    do {
        display(a, n);
    } while (next_permutation(a, a + n));
}


int main() {
    string inputStr;
    cin >> inputStr;
    int sizeOfArr;
    string* strArr = split(inputStr,'_', &sizeOfArr);
    findPermutations(strArr, sizeOfArr);
    return 0;

}
