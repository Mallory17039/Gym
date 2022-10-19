#include "Membership.h"
#include <iostream>
#include <list>
// transform, remove_if, for_each functions
#include <algorithm>
#include <chrono>
#include <ctime>



int Membership::next_ID = 0;

Membership::Membership() : name(""), sex(""), age(0), MembershipID(next_ID++), y1(0), y2(0), m1(0), m2(0), d1(0), d2(0), Info_info(nullptr)
{
}

Membership::Membership(string name, string sex, int age, int y1, int m1, int d1, int y2, int m2, int d2) :
	name(name), sex(sex), age(age), MembershipID(next_ID++), y1(y1), y2(y2), m1(m1), m2(m2), d1(d1), d2(d2), Info_info(nullptr)
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

	Membership Membership{ name, sex, age, y1, m1, d1, y2, m2, d2 };

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

// This logic inspired by https://stackoverflow.com/questions/14218894/number-of-days-between-two-dates-c/14219008#14219008
int Membership::cal_period(list<Membership>& member_list) {

	auto now = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(now);

	cout << "Enter and ID to search for: ";
	cin >> MembershipID;
	list<Membership>::iterator it;
	it = find_ID(member_list, MembershipID);

	if (it == member_list.end()) {
		cout << "*** Can't find the ID *** " << endl;
		return 0;
	}

	y1 = y1 - 1900;
	y2 = y2 - 1900;

	m1 = m1 - 1;
	m2 = m2 - 1;

	struct std::tm a = { 0,0,0,d1,m1,y1 };
	struct std::tm b = { 0,0,0,d2,m2,y2 };
	std::time_t x = std::mktime(&a);
	std::time_t y = std::mktime(&b);

	if (current_time > y) {
		cout << "Your membership already expired";
		return 0;
	}

	if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
	{
		double remain = std::difftime(y, current_time) / (60 * 60 * 24);
		std::cout << "Current Date: " << std::ctime(&current_time);
		std::cout << "End Date: " << std::ctime(&y);
		std::cout << "Total Remaining Membership Days = " << remain << " days" << std::endl;

		double difference = std::difftime(y, x) / (60 * 60 * 24);
		//std::cout << std::ctime(&x);
		//std::cout << std::ctime(&y);
		std::cout << "Total membership period = " << difference << " days" << std::endl;

		return (int)difference;
	}
	return 0;
}

void Membership::display() const
{
	cout << "Membership ID: " << MembershipID << " Name: " << name << " Sex: " << sex << " Age: " << age << endl;
	cout << "     Membership Start Date: " << y1 << "/" << m1 << "/" << d1 << endl;
	cout << "     Membership End Date: " << y2 << "/" << m2 << "/" << d2 << endl;
	if (Info_info != nullptr)
	{
		Info_info->cdisplay();
	}
}

void Membership::add_Info(list<Membership>& member_list) {
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

	it->Info_info = std::make_shared<Info>();
	it->Info_info->initialize();
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

