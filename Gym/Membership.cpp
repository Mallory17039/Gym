#include "Membership.h"
#include <iostream>
#include <list>
// transform, remove_if, for_each functions
#include <algorithm>
#include <chrono>
#include <ctime>



int Membership::next_ID = 0;

Membership::Membership() : name(""), sex(""), age(0), MembershipID(next_ID++), y1(0), y2(0), m1(0), m2(0), d1(0), d2(0), health_info(nullptr)
{
}

Membership::Membership(string name, string sex, int age) :
	name(name), sex(sex), age(age), MembershipID(next_ID++), y1(y1), y2(y2), m1(m1), m2(m2), d1(d1), d2(d2), health_info(nullptr)
{
}

void Membership::create_membership(list<Membership>& member_list) {
	cout << "Enter the name: ";
	std::getline(std::cin >> std::ws, name);
	cout << "Enter your sex (F/M): ";
	cin >> sex;
	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter the start year(yyyy): ";
	cin >> y1;
	cout << "Enter the start year's month(m): ";
	cin >> m1;
	cout << "Enter the start month's date(d): ";
	cin >> d1;

	cout << "Enter the End year(yyyy): ";
	cin >> y2;
	cout << "Enter the End year's month(m): ";
	cin >> m2;
	cout << "Enter the End month's date(d): ";
	cin >> d2;

	cout << "Membership Created.";
	MembershipID += next_ID;

	Membership Membership{ name, sex, age };

	member_list.push_back(Membership);
}

list<Membership>::iterator find_ID(list<Membership>& member_list, int MembershipID) {
	list<Membership>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		if (it->get_id() == MembershipID)
		{
			return it;
		}
	}
	return it;
}

int Membership::cal_period(list<Membership>& member_list) {
	cout << "Enter and ID to search for: ";
	cin >> MembershipID;		
	list<Membership>::iterator it;
	it = find_ID(member_list, MembershipID);
	if (it != member_list.end()) {
		y1 = y1 - 1900;
		y2 = y2 - 1900;

		struct std::tm a = { 0,0,0,d1,m1,y1 };
		struct std::tm b = { 0,0,0,d2,m2,y2 };
		std::time_t x = std::mktime(&a);
		std::time_t y = std::mktime(&b);
		if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
		{
			double difference = std::difftime(y, x) / (60 * 60 * 24);
			std::cout << std::ctime(&x);
			std::cout << std::ctime(&y);
			std::cout << "difference = " << difference << " days" << std::endl;
			return (int)difference;
		}
	
	}
		else {
			cout << "*** Can't find the ID *** " << endl;
		}
	return 0;
}

void Membership::display() const
{
	cout << "Membership ID: " << MembershipID << " Name: " << name << " Sex: " << sex << " Age: " << age << endl;
	if (health_info != nullptr)
	{
		health_info->cdisplay();
	}
}

void Membership::add_Health(list<Membership>& member_list) {
	cout << "Enter and ID to search for: ";
	cin >> MembershipID;
	list<Membership>::iterator it;
	it = find_ID(member_list, MembershipID);

	if (it != member_list.end()) {
		// found a member with that ID
		cout << "*** Found the ID ***" << endl;
		it->display();
	}
	else {
		cout << "*** Can't find the ID *** " << endl;
	}

	it->health_info = std::make_shared<Health>();
	it->health_info->initialize();
}

void Membership::display_all(list<Membership>& member_list) {
	list<Membership>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		it->display();
	}

}

int Membership::get_id() const {
	return MembershipID;
}

void Membership::quit()
{
	cout << "*** You have selected quit program ***";
}

