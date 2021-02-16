// Project Euler.cpp
// Base function for console app that calls all projects as needed

#include <iostream>
#include "ProjectHeads.h"

using namespace std;

int main()
{
    int chosenProject;

    ProjectsObj MyBestFriend;

    while (true)
    {
        cout << "Enter a number to choose a project: \n";
        cin >> chosenProject;
        switch (chosenProject)
        {
        case 1:
            MyBestFriend.Project1Calc();
            break;
        case 2:
            MyBestFriend.Project2Calc(4000000);
            break;
        case 3:
            /*
            long i;
            while (true) {
                cin >> i;
                */
                MyBestFriend.Project3Calc(600851475143L);
            //MyBestFriend.Project3Calc(600851475143);
            break;
        default:
            cout << "No project selected";
        }
        cout << "\n";
    }
    
    std::cin.get();
}
