#pragma once
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Health
{
private:
	int HealthID = -1;
	static int next_HealthID;
	int IDinput;

	string description;
	string update_date;
public:

	Health();
	Health(string description, string date);
	void initialize();
	void cdisplay() const;
	void display_all(list<Health>& member_list);

};