#pragma once
#include "Info.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Membership
{
private:

	int IDinput;
	string name;
	string sex;
	int age;
	int MembershipID = 1;
	static int next_ID;
	float period;
	int days;

	int choice;
	string confirm = "n";

	std::shared_ptr<Info> Info_info;

	int y1;
	int y2;
	int m1;
	int m2;
	int d1;
	int d2;

public:

	Membership();

	Membership(string name, string sex, int age, int y1, int m1, int d1, int y2, int m2, int d2);

	int get_id() const;

	int cal_period();

	void create_membership(list<Membership>& member_list);

	void display() const;

	void add_Info();

	void display_all(list<Membership>& member_list);

	void quit();

};
