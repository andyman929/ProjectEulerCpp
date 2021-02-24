#pragma once

#include <iostream>
#include <string>

class RationalNumber
{
// Track value of a fraction x/y
public:
	RationalNumber() {
		x = 1; y = 1;
	};
	RationalNumber(int a) {
		x = a; y = 1;
	};
	RationalNumber(__int64 a, __int64 b) {
		__int64 gcm = gcd(a, b);
		x = a / gcm;
		y = b / gcm;
	};
	~RationalNumber() {};
	RationalNumber operator= (__int64 a) {
		RationalNumber z(a);
		return z;
	};
	friend RationalNumber operator+ (RationalNumber r, __int64 a) {
		RationalNumber z(a * r.y + r.x, r.y);
		return z;
	};
	friend RationalNumber operator+ (__int64 a, RationalNumber r) {
		return r + a;
	};
	friend RationalNumber operator+ (RationalNumber a, RationalNumber b) {
		RationalNumber z((a.x * b.y + a.y * b.x), (a.y * b.y));
		return z;
	};
	friend RationalNumber operator* (RationalNumber a, RationalNumber b) {
		RationalNumber z((a.x * b.x), (a.y * b.y));
		return z;
	};
	friend RationalNumber operator* (RationalNumber a, __int64 b) {
		RationalNumber z((a.x * b), a.y);
		return z;
	};
	friend RationalNumber operator* (__int64 a, RationalNumber b) {
		return b * a;
	};
	friend RationalNumber operator/ (RationalNumber a, RationalNumber b) {
		RationalNumber z((a.x * b.y) / (a.y * b.x));
		return z;
	};
	friend RationalNumber operator/ (RationalNumber a, __int64 b) {
		RationalNumber z(a.x, (a.y * b));
		return z;
	};
	friend RationalNumber operator/ (__int64 a, RationalNumber b) {
		RationalNumber z(a*b.y, b.x);
		return z;
	};
	friend RationalNumber operator- (RationalNumber a) {
		RationalNumber z(-a.x, a.y);
		return z;
	};
	std::string print() {
		std::string temp;
		temp = std::to_string(x) + "/" + std::to_string(y);
		return temp;
	};
	int Numerator() {
		return x;
	};

private:
	__int64 x;
	__int64 y;
	__int64 gcd(__int64 a, __int64 b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	};
};