#pragma once
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Info
{
private:
	int InfoID = -1;
	static int next_InfoID;
	int IDinput;

	string description;
	string update_date;
public:

	Info();
	Info(string description, string date);
	void initialize();
	void cdisplay() const;
	void display_all(list<Info>& member_list);

};