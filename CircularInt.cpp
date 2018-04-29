#include <vector>
#include <set>
#include <iostream>
#include <string>
#include "CircularInt.h"

CircularInt::CircularInt(int x, int y)
{
	if (x > y)
	{
		this->last = x;
		this->first = y;
	}
	else
	{
		this->first = x;
		this->last = y;
	}
	this->current = this->first;
}

CircularInt::CircularInt(const CircularInt& hour)
{
	this->first = hour.first;
	this->last = hour.last
	this->current = hour.current;
}

CircularInt& CircularInt::operator-=(const int number) {
	this->current = this->current - number;
	if (this->current < first)
	{
		this->current = this->current % last + last;
	}
	return *this;
}

CircularInt& CircularInt::operator-=(const CircularInt& hour) {
	this->current = this->current - hour.current;
	if (this->current < first)
	{
		this->current = this->current % last + last;
	}
	return *this;
}

CircularInt& CircularInt::operator+=(const int number) {
	this->current = this->current + number;
	if (this->current > last)
	{
		this->current = this->current % last;
	}
	return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& hour) {
	this->current = this->current + hour.current;
	if (this->current > last)
	{
		this->current = this->current % last;
	}
	return *this;
}
CircularInt CircularInt::operator--(const int) {
	CircularInt temp(*this);
	operator--();
	return temp;
}
CircularInt& CircularInt::operator--() {
	current--;
	while (current<first) {
		current = current + last;
	}
	return *this;
}

CircularInt CircularInt::operator++(int) {
	CircularInt temp(*this);
	operator++();
	return temp;
}

CircularInt& CircularInt::operator++() {
	current++;
	if (current > last)
	{
		current = current % last;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const int number) {

	current = number;
	if (current > last)
	{
		current = current % last;
	}
	while (current<first) {
		current += last;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const CircularInt& hour) {
	current = hour.current;
	if (current > last)
	{
		current = current % last;
	}
	while (current<first) {
		current += last;
	}
	return *this;

}

CircularInt& CircularInt::operator*=(const int number) {

	this->current *= number;

	while (current > last)
	{
		current -= last;
	}
	while (current < first)
	{
		current += last;
	}

	return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& hour) {
	this->current *= hour.current;

	while (current > last)
	{
		current -= last;
	}
	while (current < first)
	{
		current += last;
	}

	return *this;
}

CircularInt& CircularInt::operator/=(const int number) {

	for (int i = this->first; i < this->last; i++)
	{
		int temp = i * number;
		while (temp>this->last) {
			temp -= this->last;
		}

		while (temp<this->first) {
			temp += this->last;
		}

		if (temp == this->current)
		{
			this->current = i;
			return *this;
		}
	}

	throw string("There is no number x in {" + to_string(this->first) + "," + to_string(this->last) + "} such that x*" + to_string(number) + "=" + to_string(this->current));
}

CircularInt& CircularInt::operator/=(const CircularInt& hour) {
	CircularInt Object(hour);
	for (int i = this->first; i < this->last; i++)
	{
		int temp = i * Object.current;
		while (temp>this->last) {
			temp -= this->last;
		}

		while (temp<this->first) {
			temp += this->last;
		}

		if (temp == Object.current)
		{
			this->current = i;
			return *this;
		}
	}

	throw string("There is no number x in {" + to_string(this->first) + "," + to_string(this->last) + "} such that x*" + to_string(Object.current) + "=" + to_string(this->current));
}