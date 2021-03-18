#pragma once

#include <string>
#include <vector>

class ProjInterface {
	// Proj41_80
public:
	virtual void Project41Calc() { ErrFunc(); };
	virtual void Project42Calc() { ErrFunc(); };
	virtual void Project43Calc() { ErrFunc(); };
	virtual void Project44Calc() { ErrFunc(); };
	virtual void Project45Calc() { ErrFunc(); };
	virtual void Project46Calc() { ErrFunc(); };
	virtual void Project47Calc(const int size) { ErrFunc(); };
	virtual void Project48Calc(const int lim) { ErrFunc(); };
	virtual void Project49Calc() { ErrFunc(); };
	virtual void Project50Calc(const int limit) { ErrFunc(); };
	virtual void Project52Calc() { ErrFunc(); };

	virtual void Project58Calc(int thresholdPC) { ErrFunc(); };

	virtual void Project60Calc() { ErrFunc(); };
	virtual void Project60CalcNoMap() { ErrFunc(); };
	virtual void Project60Calc4p() { ErrFunc(); };

	virtual void Project65Calc(int count) { ErrFunc(); };


	// Proj700Plus
public:
	virtual void Project740Calc(const int n) { ErrFunc(); };
	virtual void Project741Calc(const int n) { ErrFunc(); };

	// Proj1_20
public:
	virtual void Project1Calc() { ErrFunc(); };
	virtual void Project2Calc(int upperLimit) { ErrFunc(); };
	virtual void Project3CalcRecMethod(int num) { ErrFunc(); };
	virtual void Project3Calc(long long num) { ErrFunc(); };
	virtual void Project4Calc() { ErrFunc(); };
	virtual void Project5Calc(int lim) { ErrFunc(); };
	virtual void Project6Calc(int lim) { ErrFunc(); };
	virtual void Project7Calc(int pNumber) { ErrFunc(); };
	virtual void Project8Calc(int digits, std::string input) { ErrFunc(); };
	virtual void Project9Calc(int sumrequired) { ErrFunc(); };
	virtual void Project10Calc(int lim) { ErrFunc(); };
	virtual void Project11Calc(int line) { ErrFunc(); };
	virtual void Project12Calc(int divs) { ErrFunc(); };
	virtual void Project12CalcOld(int divs) { ErrFunc(); };
	virtual void Project13Calc() { ErrFunc(); };
	virtual void Project14Calc(int lim) { ErrFunc(); };
	virtual void Project14CalcBM(int lim) { ErrFunc(); };
	virtual void Project14CalcBF(int lim) { ErrFunc(); };
	virtual void Project14PrintCollatz(int lim) { ErrFunc(); };
	virtual void Project15Calc(int gridSize) { ErrFunc(); };
	virtual void Project16Calc(int exp) { ErrFunc(); };
	virtual void Project17Calc(int minN, int maxN) { ErrFunc(); };
	virtual void Project18Calc(int data) { ErrFunc(); };
	virtual void Project19Calc() { ErrFunc(); };
	virtual void Project20Calc(int fact) { ErrFunc(); };

	// Proj21_40
public:
	virtual void Project21Calc(int count) { ErrFunc(); };
	virtual void Project22Calc(bool qs) { ErrFunc(); };
	virtual void Project23Calc() { ErrFunc(); };
	virtual void Project24Calc(int objects, int req) { ErrFunc(); };
	virtual void Project25Calc(int digits) { ErrFunc(); };
	virtual void Project26Calc(int digits) { ErrFunc(); };
	virtual void Project27Calc(int limits) { ErrFunc(); };
	virtual void Project28Calc(int sides) { ErrFunc(); };
	virtual void Project29Calc(const int limit) { ErrFunc(); };
	virtual void Project30Calc(const int power) { ErrFunc(); };
	virtual void Project31Calc(const int pounds) { ErrFunc(); };
	virtual void Project32Calc() { ErrFunc(); };
	virtual void Project33Calc() { ErrFunc(); };
	virtual void Project34Calc() { ErrFunc(); };
	virtual void Project35Calc(const int limit) { ErrFunc(); };
	virtual void Project36Calc(const int limit) { ErrFunc(); };
	virtual void Project37Calc(const int limit) { ErrFunc(); };
	virtual void Project38Calc() { ErrFunc(); };
	virtual void Project39Calc(const int limit) { ErrFunc(); };
	virtual void Project40Calc() { ErrFunc(); };

private:
	void ErrFunc() { std::cout << "Error: function not overrided in the DLL" << std::endl; };
};