/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include "pch.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

void ProjectsObjDll::Project22Calc(bool qs)
{
    // First version will try scanning through and inserting each element in order
    fstream inputData("Data\\Project 22.txt");
    if (!inputData.is_open())
    {
        throw "Unable to open file";
    }
    vector<string> nameList;
    nameList.reserve(6000);     // reserve 6000 as challenge says over 5000
    string name;

    while (getline(inputData, name, ','))
    {
        bool inserted = false;
        Project22Trim(&name, '"');
        if (!qs)
        {
            for (int i = 0; i < nameList.size(); i++)
            {
                if (Project22IsBefore(name, nameList[i]))
                {
                    nameList.insert(nameList.begin() + i, name);
                    inserted = true;
                    break;
                }
            }
        }
        if (!inserted)
            nameList.push_back(name);
    }

    if (qs)
        Project22Quicksort(&nameList, 0, nameList.size() - 1);

    int score = 0;
    
    for (int i = 0; i < nameList.size(); i++)
    {
        score += Project22NameScore(nameList[i]) * (i + 1);
    }

    cout << "The name score is " << score << "\n";
}
void ProjectsObjDll::Project22Trim(string *inp, char ch)
{
    char first = inp->c_str()[0];
    char last = inp->c_str()[inp->size() - 1];
    if (first == ch)
        inp->erase(inp->begin());
    if (last == ch)
        inp->erase(inp->end() - 1);
}
// Check if str1 is earlier in the alphabet than str2
bool ProjectsObjDll::Project22IsBefore(string str1, string str2)
{
    const char* ch1 = str1.c_str();
    const char* ch2 = str2.c_str();
    int lmax = min(str1.size(), str2.size());

    for (int i = 0; i < lmax; i++)
    {
        if (ch1[i] < ch2[i])
        {
            return true;
        }
        if (ch1[i] > ch2[i])
        {
            return false;
        }
    }
    if (str1.size() <= str2.size())
        return true;

    return false;
}
int ProjectsObjDll::Project22NameScore(string str)
{
    const char* ch = str.c_str();

    int sub = (int)'A' - 1; // Subtract this from every letter so A is worth 1, B = 2 etc.
    int score = 0;
    for (int i = 0; i < str.size(); i++)
    {
        score += (int)ch[i];
    }
    score -= sub*str.size();
    return score;
}
void ProjectsObjDll::Project22Quicksort(vector<string> *strs, int low, int high)
{
    if (low < high)
    {
        int p = Project22Partition(strs, low, high);
        Project22Quicksort(strs, low, p - 1);
        Project22Quicksort(strs, p + 1, high);
    }
}
int ProjectsObjDll::Project22Partition(vector<string> *strs, int low, int high)
{
          // Lomuto Partition
    string pivot = strs->at(high);
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (Project22IsBefore(strs->at(j), pivot))
        {
            string swap = strs->at(j);
            strs->at(j) = strs->at(i);
            strs->at(i) = swap;
            i++;
        }
    }
    string swap = strs->at(i);
    strs->at(i) = strs->at(high);
    strs->at(high) = swap;
    return i;
    

    // Hoare Partition
    //string pivot = strs->at(low);
}