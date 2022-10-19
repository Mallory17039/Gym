#include "Health.h"
#include "Membership.h"
#include <iostream>
#include <list>
#include <algorithm>

int Health::next_HealthID = 0;

Health::Health() : description(""), update_date(""), HealthID(next_HealthID++)
{
}

Health::Health(string description, string update_date) :
	description(description), update_date(update_date), HealthID(next_HealthID++)
{
}

//input method
void Health::initialize() {
	cout << "Enter the description: ";
	std::getline(std::cin >> std::ws, description);
	cout << "Enter the update date(mm/dd/yyyy): ";
	std::getline(std::cin >> std::ws, update_date);
	cout << "Information Updated.";
	HealthID = +HealthID;
}

//output method
void Health::cdisplay() const
{
	cout << "     + Health Information Updated on: " << update_date << endl;
	cout << "       Description: " << description << endl;
}

void Health::display_all(list<Health>& member_list) {
	list<Health>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		it->cdisplay();
	}
}