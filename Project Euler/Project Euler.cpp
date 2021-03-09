// Project Euler.cpp
// Base function for console app that calls all projects as needed

#include "pch_euler.h"
#include "UNBitInt.h"

using namespace std;

int main()
{
    int chosenProject;
    ProjectsObj MyBestFriend;
    Timer timing;

    while (true)
    {
        std::cout << "Enter a number to choose a project: \n";
        cin >> chosenProject;
        string input = "";
        int inp = 0;
        __int64 inp64 = 0;
        double inpdbl = 0;
        if (chosenProject <= 20 || chosenProject == 67)
        { 
            Run1_20(chosenProject);
        }
        else if (chosenProject <= 40)
        {
            Run21_40(chosenProject);
        }
        else
        {
            timing.StartTimer();
            switch (chosenProject)
            {
            case 58:
                MyBestFriend.Project58Calc(10);
                break;
            case 60:
                MyBestFriend.Project60CalcNoMap();
                break;
            case 65:
                MyBestFriend.Project65Calc(100);
                break;
            case 219:
                inp = 6;//(int)pow(10, 9);
                //inpdbl = pow(10, 100000);
                MyBestFriend.Project219Calc2(inp);
                //MyBestFriend.Ld219Calc(inpdbl);
                break;
            case 373:
                inp64 = (__int64)pow(10, 5); //(__int64)pow(10, 7);
                std::cout << "Enter number: \n";
                cin >> inp;
                std::cout << "\n";
                //MyBestFriend.Project373Calc(inp64);
                //MyBestFriend.Project373TriangleCaller(inp64);
                //Project373Pyth(inp);
                //MyBestFriend.Project373Gauss(inp);
                MyBestFriend.Project373Heron(inp);
                break;
            default:
                std::cout << "No valid project selected\n";
            }
            timing.EndTimer();
        }
        std::cout << "\n";
    }
    
    std::cin.get();
}

void Run1_20(int project)
{
    Timer timing;
    DllManager dll;

    typedef IProjectsObj* (__cdecl* dll_factory)();

    dll_factory factory_func = reinterpret_cast<dll_factory>(dll.LoadFunction("Proj1_20.dll", "Create_ProjectsObj"));
    if (!factory_func)
        cerr << "Unable to load factory function";

    IProjectsObj* NewBFF = factory_func();

    string input = "";
    int inp = 0;
    timing.StartTimer();
    switch (project)
    {
    case 1:
        NewBFF->Project1Calc();
        break;
    case 2:
        NewBFF->Project2Calc(4000000);
        break;
    case 3:
        NewBFF->Project3Calc(600851475143L);
        break;
    case 4:
        NewBFF->Project4Calc();
        break;
    case 5:
        NewBFF->Project5Calc(20);
        break;
    case 6:
        NewBFF->Project6Calc(100);
        break;
    case 7:
        NewBFF->Project7Calc(10001);
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

        NewBFF->Project8Calc(13, input);
        break;
    case 9:
        NewBFF->Project9Calc(1000);
        break;
    case 10:
        NewBFF->Project10Calc(2000000);
        break;
    case 11:
        NewBFF->Project11Calc(4);
        break;
    case 12:
        NewBFF->Project12Calc(500);
        break;
    case 13:
        NewBFF->Project13Calc();
        break;
    case 14:
        inp = 1000000;
        //NewBFF->Project14PrintCollatz(inp);
        NewBFF->Project14Calc(inp);                // 0.331423
        //NewBFF->Project14CalcBM(inp);              // 2.10445
        //NewBFF->Project14CalcBF(inp);
        break;
    case 15:
        NewBFF->Project15Calc(20);
        break;
    case 16:
        NewBFF->Project16Calc(1000);
        break;
    case 17:
        NewBFF->Project17Calc(1, 1000);
        break;
    case 18:
        // 0 = small proj 13, 1 = large proj 18, 2 = proj 67
        NewBFF->Project18Calc(1);
        break;
    case 19:
        NewBFF->Project19Calc();
        break;
    case 20:
        NewBFF->Project20Calc(100);
        break;
    case 67:
        // 0 = small proj 13, 1 = large proj 18, 2 = proj 67
        NewBFF->Project18Calc(2);
        break;
    default:
        // Shouldn't be reachable be for safe keeping
        std::cout << "No valid project selected\n";
        break;
    }
    timing.EndTimer();
}

void Run21_40(int project)
{
    Timer timing;
    DllManager dll;

    typedef IProjectsObj2* (__cdecl* dll_factory)();

    dll_factory factory_func = reinterpret_cast<dll_factory>(dll.LoadFunction("Proj21_40.dll", "Create_ProjectsObj"));
    if (!factory_func)
        cerr << "Unable to load factory function";

    IProjectsObj2* NewBFF = factory_func();

    string input = "";
    int inp = 0;
    timing.StartTimer();
    switch (project)
    {
    case 21:
        NewBFF->Project21Calc(10000);
        break;
    case 22:
        // true enables a quicksort method, false sorts as the names are added
        // true reduces the time from 30+ seconds to 0.5
        NewBFF->Project22Calc(true);
        break;
    case 23:
        NewBFF->Project23Calc();
        break;
    case 24:
        NewBFF->Project24Calc(10, 1000000);
        break;
    case 25:
        NewBFF->Project25Calc(1000);
        break;
    case 26:
        NewBFF->Project26Calc(1000);
        break;
    default:
        std::cout << "No valid project selected\n";
        break;
    }
    timing.EndTimer();
}