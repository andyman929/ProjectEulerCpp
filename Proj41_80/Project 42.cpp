/*
Coded triangle numbers
*/

#include "pch.h"

void Obj::Project42Calc()
{
    // Get full set of data as well as the longest string length
    std::fstream inputData("Data\\Project 42.txt");
    if (!inputData.is_open())
    {
        throw "Unable to open file";
    }
    std::vector<std::string> wordList;
    wordList.reserve(2000);     // reserve 2000 as challenge says nearly that
    std::string word;
    
    int maxLength = 0;
    while (std::getline(inputData, word, ','))
    {
        TrimCharacters(&word, '"');
        wordList.push_back(word);
        if (word.size() > maxLength)
            maxLength = word.size();
    }
    inputData.close();

    // Populate a bool vector with is/isn't triangle, look up to the maximum possible
    int maxEncode = 26 * maxLength;
    std::vector<bool> isTriangle(maxEncode + 1, false);
    int triangle = 1;
    for (int i = 2; triangle <= maxEncode; ++i)
    {
        isTriangle[triangle] = true;
        triangle += i;
    }

    // Loop through all the words and check their sum
    int triCount = 0;
    for (auto w : wordList)
    {
        int encode = WordCode(w);
        if (isTriangle[encode])
            triCount++;
    }
    std::cout << "The number of triangle words in the set is " << triCount << std::endl;
}

int Obj::WordCode(std::string word)
{
    int sum = 0;
    for (auto c : word)
    {
        sum += c - 'A' + 1;
    }
    return sum;
}

void Obj::TrimCharacters(std::string* inp, char ch)
{
    char first = inp->c_str()[0];
    char last = inp->c_str()[inp->size() - 1];
    if (first == ch)
        inp->erase(inp->begin());
    if (last == ch)
        inp->erase(inp->end() - 1);
}