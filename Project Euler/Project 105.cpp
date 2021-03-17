/*
Special subset sums: Testing
*/

#include "pch_euler.h"

void ProjectsObj::Project105Calc()
{
    std::fstream inputData("Data\\Project 105.txt");
    if (!inputData.is_open())
    {
        throw "Unable to open file";
    }
    
    std::string rowstr;
    sequence row;
    sols solutions;
    int sum = 0;
    while (std::getline(inputData, rowstr))
    {
        row = SplitRow(rowstr);
        SetCheck(row, solutions, false);
        // Only using map so I can reuse the old function.
        // Add to sum and delete the map to avoid overlap of sizes
        if (solutions.size() > 0)
        {
            sum += solutions.begin()->first;
            solutions.clear();
        }
    }

    std::cout << "Sum of all special sets is: " << sum << std::endl;
}

sequence ProjectsObj::SplitRow(std::string r)
{
    std::string delim = ",";

    int pos = 0;
    std::string token;
    sequence lst;
    while ((pos = r.find(delim)) != std::string::npos)
    {
        token = r.substr(0, pos);
        lst.push_back(std::stoi(token));
        r.erase(0, pos + delim.length());
    }
    lst.push_back(std::stoi(r));
    return lst;
}