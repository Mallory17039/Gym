#pragma once
#include "date.h"
#include<chrono>
#include <iostream>

int cal() {
	using namespace date;
	using namespace std;
	string start_date;
	string current_date;
	int y1;
	int y2;
	int m1;
	int m2;
	int d1;
	int d2;
	auto a = 2012_y / 1 / 24;
	auto b = 2013_y / 1 / 8;
	cout << "Enter the start year: ";
	cin >> y1;
	cout << "Enter the start year's month: ";
	cin >> m1;
	cout << "Enter the start month's date: ";
	cin >> d1;
	auto a = year(y1)/month(m1)/day(d1);
	cout << "Enter the current year: ";
	cin >> y2;
	cout << "Enter the current year's month: ";
	cin >> m2;
	cout << "Enter the current month's date: ";
	cin >> d2;
	auto b = year(y2) / month(m2) / day(d2);
	cout << "Thank you for joining the membership for " << (sys_days{ b } - sys_days{ a }).count() << " day(s)\n";
	return (sys_days{ b } - sys_days{ a }).count();
}