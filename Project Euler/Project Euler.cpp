// Project Euler.cpp
// Base function for console app that calls all projects as needed

#include <iostream>
#include <string>
#include <chrono>
#include "ProjectHeads.h"

using namespace std;
using namespace std::chrono;

int main()
{
    int chosenProject;

    ProjectsObj MyBestFriend;

    while (true)
    {
        cout << "Enter a number to choose a project: \n";
        cin >> chosenProject;
        string input = "";
        int inp = 0;
        __int64 inp64 = 0;
        double inpdbl = 0;
        auto start = high_resolution_clock::now();
        switch (chosenProject)
        {
        case 1:
            MyBestFriend.Project1Calc();
            break;
        case 2:
            MyBestFriend.Project2Calc(4000000);
            break;
        case 3:
            MyBestFriend.Project3Calc(600851475143L);
            break;
        case 4:
            MyBestFriend.Project4Calc();
            break;
        case 5:
            MyBestFriend.Project5Calc(20);
            break;
        case 6:
            MyBestFriend.Project6Calc(100);
            break;
        case 7:
            MyBestFriend.Project7Calc(10001);
            break;
        case 8:
            input += "73167176531330624919225119674426574742355349194934";
            input += "96983520312774506326239578318016984801869478851843";
            input += "85861560789112949495459501737958331952853208805511";
            input += "12540698747158523863050715693290963295227443043557";
            input += "66896648950445244523161731856403098711121722383113";
            input += "62229893423380308135336276614282806444486645238749";
            input += "30358907296290491560440772390713810515859307960866";
            input += "70172427121883998797908792274921901699720888093776";
            input += "65727333001053367881220235421809751254540594752243";
            input += "52584907711670556013604839586446706324415722155397";
            input += "53697817977846174064955149290862569321978468622482";
            input += "83972241375657056057490261407972968652414535100474";
            input += "82166370484403199890008895243450658541227588666881";
            input += "16427171479924442928230863465674813919123162824586";
            input += "17866458359124566529476545682848912883142607690042";
            input += "24219022671055626321111109370544217506941658960408";
            input += "07198403850962455444362981230987879927244284909188";
            input += "84580156166097919133875499200524063689912560717606";
            input += "05886116467109405077541002256983155200055935729725";
            input += "71636269561882670428252483600823257530420752963450";

            MyBestFriend.Project8Calc(13, input);
            break;
        case 9:
            MyBestFriend.Project9Calc(1000);
            break;
        case 10:
            MyBestFriend.Project10Calc(2000000);
            break;
        case 11:
            MyBestFriend.Project11Calc(4);
            break;
        case 12:
            MyBestFriend.Project12Calc(500);
            break;
        case 13:
            MyBestFriend.Project13Calc();
            break;
        case 14:
            inp = 1000000;
            //MyBestFriend.Project14PrintCollatz(inp);
            MyBestFriend.Project14Calc(inp);                // 0.331423
            //MyBestFriend.Project14CalcBM(inp);              // 2.10445
            //MyBestFriend.Project14CalcBF(inp);
            break;
        case 15:
            MyBestFriend.Project15Calc(20);
            break;
        case 16:
            MyBestFriend.Project16Calc(1000);
            break;
        case 17:
            MyBestFriend.Project17Calc(1, 1000);
            break;
        case 18:
            // 0 = small proj 13, 1 = large proj 18, 2 = proj 67
            MyBestFriend.Project18Calc(1);
            break;
        case 60:
            MyBestFriend.Project60CalcNoMap();
            break;
        case 67:
            // 0 = small proj 13, 1 = large proj 18, 2 = proj 67
            MyBestFriend.Project18Calc(2);
            break;
        case 219:
            inp = 6;//(int)pow(10, 9);
            //inpdbl = pow(10, 100000);
            MyBestFriend.Project219Calc2(inp);
            //MyBestFriend.Ld219Calc(inpdbl);
            break;
        case 373:
            inp64 = (__int64)pow(10, 5); //(__int64)pow(10, 7);
            //MyBestFriend.Project373Calc(inp64);
            MyBestFriend.Project373TriangleCaller(inp64);
            break;
        default:
            cout << "No valid project selected\n";
        }
        auto finish = high_resolution_clock::now();
        cout << "\n";
        duration<double> diff = finish - start;
        cout << "Time to complete task (seconds): " << diff.count() << "\n";
        cout << "\n";
    }
    
    std::cin.get();
}
