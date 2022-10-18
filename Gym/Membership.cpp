#include "Membership.h"
#include <iostream>
#include <list>
// transform, remove_if, for_each functions
#include <algorithm>



int Membership::next_ID = 0;

Membership::Membership() : name(""), sex(""), age(0), MembershipID(next_ID++), health_info(nullptr)
{
}

Membership::Membership(string name, string sex, int age) :
	name(name), sex(sex), age(age), MembershipID(next_ID++), health_info(nullptr)
{
}

void Membership::create_membership(list<Membership>& member_list) {
	cout << "Enter the name: ";
	std::getline(std::cin >> std::ws, name);
	cout << "Enter your sex (F/M): ";
	cin >> sex;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Membership Created.";
	MembershipID += next_ID;

	Membership Membership{ name, sex, age };

	member_list.push_back(Membership);
}

void Membership::display() const
{
	cout << "Membership ID: " << MembershipID << " Name: " << name << " Sex: " << sex << " Age: " << age << endl;
	if (health_info != nullptr)
	{
		health_info->cdisplay();
	}
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

//void Membership::update_member(list<Membership>& member_list) {
//	cout << "Enter and ID to search for: ";
//	cin >> MembershipID;
//	list<Membership>::iterator it;
//	it = find_ID(member_list, MembershipID);
//
//	if (it != member_list.end()) {
//		// found a member with that ID
//		cout << "*** Found the ID ***" << endl;
//		it->display();
//		cout << "Update your age: ";
//		cin >> age;
//		it->Membership(name, sex, age);
//
//	}
//	else {
//		cout << "*** Can't find the ID *** " << endl;
//	}
//}


void Membership::quit()
{
	cout << "*** You have selected quit program ***";
}

