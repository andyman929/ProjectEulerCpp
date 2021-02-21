/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

#include <iostream>
#include <limits>
#include <vector>
#include <fstream>
#include "ProjectHeads.h"

//#define Round2Int64(x) (__int64)(x > 0 ? (x + 0.5) : (x - 0.5))

//using namespace std;

void ProjectsObj::Project18Calc(int data)
{
    
    std::vector<std::vector<int>> pyramid;
    pyramid = Project18GetData(data);
    std::vector<int> lastLayerCosts;
    for (int i = 0; i < pyramid.size(); i++)
    {
        std::vector<int> layer = pyramid[i];
        int layerSize = layer.size();
        std::vector<int> layerCosts(layerSize);
        if (i == 0)
        {
            lastLayerCosts = layer;
            continue;
        }
        layerCosts[0] = layer[0] + lastLayerCosts[0];
        layerCosts[layerSize - 1] = layer[layerSize - 1] + lastLayerCosts[layerSize - 2];

        for (int j = 1; j < layerSize - 1; j++)
        {
            int opt1 = layer[j] + lastLayerCosts[j - 1];
            int opt2 = layer[j] + lastLayerCosts[j];
            layerCosts[j] = std::max(opt1, opt2);
        }

        lastLayerCosts = layerCosts;
    }

    int max = INT_MIN;
    for (int j = 0; j < lastLayerCosts.size(); j++)
    {
        if (lastLayerCosts[j] > max)
            max = lastLayerCosts[j];
    }

    std::cout << "Maximum path: " << max << "\n";
}


std::vector<std::vector<int>> ProjectsObj::Project18GetData(int data)
{
    std::string path;
    switch (data)
    {
    case 0:
        path = "Data\\Project 18 small.txt";
        break;
    case 1:
        path = "Data\\Project 18 large.txt";
        break;
    default:
        path = "Data\\Project 67.txt";
        break;
    }

    std::ifstream inputData(path);
    if (!inputData.is_open())
    {
        throw "Unable to open file";
    }
    std::string line;
    int columnNum = 0;
    int columns = 0;
    std::vector<int> row;
    std::vector<std::vector<int>> pyramid;
    // Special handling of first line
    getline(inputData, line);
    row.push_back(stoi(line));
    pyramid.push_back(row);
    row.clear();
    columns = 1;
    while (getline(inputData, line, ' '))
    {
        row.push_back(stoi(line));
        if (++columnNum == columns)
        {
            getline(inputData, line);
            row.push_back(stoi(line));
            columns++;
            columnNum = 0;
            pyramid.push_back(row);
            row.clear();
        }

    }

    return pyramid;
}