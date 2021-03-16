#pragma once

#include <string>
#include <vector>

class ProjInterface {
	// Proj41_80
public:
	virtual void Project41Calc() {};
	virtual void Project42Calc() {};
	virtual void Project43Calc() {};
	virtual void Project44Calc() {};
	virtual void Project45Calc() {};

	virtual void Project58Calc(int thresholdPC) {};

	virtual void Project60Calc() {};
	virtual void Project60CalcNoMap() {};
	virtual void Project60Calc4p() {};

	virtual void Project65Calc(int count) {};


	// Proj700Plus
public:
	virtual void Project740Calc(const int n) {};
	virtual void Project741Calc(const int n) {};

	// Proj1_20
public:
	virtual void Project1Calc() {};
	virtual void Project2Calc(int upperLimit) {};
	virtual void Project3CalcRecMethod(int num) {};
	virtual void Project3Calc(long long num) {};
	virtual void Project4Calc() {};
	virtual void Project5Calc(int lim) {};
	virtual void Project6Calc(int lim) {};
	virtual void Project7Calc(int pNumber) {};
	virtual void Project8Calc(int digits, std::string input) {};
	virtual void Project9Calc(int sumrequired) {};
	virtual void Project10Calc(int lim) {};
	virtual void Project11Calc(int line) {};
	virtual void Project12Calc(int divs) {};
	virtual void Project12CalcOld(int divs) {};
	virtual void Project13Calc() {};
	virtual void Project14Calc(int lim) {};
	virtual void Project14CalcBM(int lim) {};
	virtual void Project14CalcBF(int lim) {};
	virtual void Project14PrintCollatz(int lim) {};
	virtual void Project15Calc(int gridSize) {};
	virtual void Project16Calc(int exp) {};
	virtual void Project17Calc(int minN, int maxN) {};
	virtual void Project18Calc(int data) {};
	virtual void Project19Calc() {};
	virtual void Project20Calc(int fact) {};

	// Proj21_40
public:
	virtual void Project21Calc(int count) {};
	virtual void Project22Calc(bool qs) {};
	virtual void Project23Calc() {};
	virtual void Project24Calc(int objects, int req) {};
	virtual void Project25Calc(int digits) {};
	virtual void Project26Calc(int digits) {};
	virtual void Project27Calc(int limits) {};
	virtual void Project28Calc(int sides) {};
	virtual void Project29Calc(const int limit) {};
	virtual void Project30Calc(const int power) {};
	virtual void Project31Calc(const int pounds) {};
	virtual void Project32Calc() {};
	virtual void Project33Calc() {};
	virtual void Project34Calc() {};
	virtual void Project35Calc(const int limit) {};
	virtual void Project36Calc(const int limit) {};
	virtual void Project37Calc(const int limit) {};
	virtual void Project38Calc() {};
	virtual void Project39Calc(const int limit) {};
	virtual void Project40Calc() {};
};