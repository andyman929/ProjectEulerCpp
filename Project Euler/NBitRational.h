#pragma once

#include <iostream>
#include <string>
#include "NBitInt.h"

// Track value of a fraction x/y
template<int N>
class Rational
{
public:
	Rational() {
		x = 1; y = 1;
	};
	Rational(int a) {
		x = a; y = 1;
	};
	Rational(__int64 a, __int64 b) {
		NBitInt<N> gcm = gcd(a, b);
		x = a / gcm;
		y = b / gcm;
	};
	Rational(NBitInt<N> a, NBitInt<N> b) {
		NBitInt<N> gcm = gcd(a, b);
		x = a / gcm;
		y = b / gcm;
	};
	~Rational() {};
	Rational operator= (__int64 a) {
		Rational z(a);
		return z;
	};
	friend Rational operator+ (Rational r, __int64 a) {
		Rational z(a * r.y + r.x, r.y);
		return z;
	};
	friend Rational operator+ (__int64 a, Rational r) {
		return r + a;
	};
	friend Rational operator+ (Rational a, Rational b) {
		Rational z((a.x * b.y + a.y * b.x), (a.y * b.y));
		return z;
	};
	friend Rational operator* (Rational a, Rational b) {
		Rational z((a.x * b.x), (a.y * b.y));
		return z;
	};
	friend Rational operator* (Rational a, __int64 b) {
		Rational z((a.x * b), a.y);
		return z;
	};
	friend Rational operator* (__int64 a, Rational b) {
		return b * a;
	};
	friend Rational operator/ (Rational a, Rational b) {
		Rational z((a.x * b.y) / (a.y * b.x));
		return z;
	};
	friend Rational operator/ (Rational a, __int64 b) {
		Rational z(a.x, (a.y * b));
		return z;
	};
	friend Rational operator/ (__int64 a, Rational b) {
		if (a == 1)
		{
			return Rational(b.y, b.x);
		}
		Rational z(a * b.y, b.x);
		return z;
	};
	friend Rational operator- (Rational a) {
		Rational z(-a.x, a.y);
		return z;
	};
	
	std::string print() {
		std::string temp;
		temp = x.to_string() + "/" + y.to_string();
		return temp;
	};
	
	NBitInt<N> Numerator() {
		return x;
	};

private:
	NBitInt<N> x;
	NBitInt<N> y;
	NBitInt<N> gcd(NBitInt<N> a, NBitInt<N> b) {
		if (b.GetBitset().none())
			return a;
		return gcd(b, a % b);
	};
};