#pragma once
#include "Health.h"
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
	string start_date;
	string current_date;
	int days;

	int choice;
	string confirm = "n";

	std::shared_ptr<Health> health_info;

	int y1;
	int y2;
	int m1;
	int m2;
	int d1;
	int d2;

public:

	Membership();

	Membership(string name, string sex, int age);

	int get_id() const;

	int cal_period(list<Membership>& member_list);

	//void update_member(list<Membership>& member_list);

	void create_membership(list<Membership>& member_list);

	void display() const;

	void add_Health(list<Membership>& member_list);

	void display_all(list<Membership>& member_list);

	void quit();

	// void cal_period();

};
