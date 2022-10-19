#include "Info.h"
#include "Membership.h"
#include <iostream>
#include <list>
#include <algorithm>

int Info::next_InfoID = 0;

Info::Info() : description(""), update_date(""), InfoID(next_InfoID++)
{
}

Info::Info(string description, string update_date) :
	description(description), update_date(update_date), InfoID(next_InfoID++)
{
}

//input method
void Info::initialize() {
	cout << "Enter the description: ";
	std::getline(std::cin >> std::ws, description);
	cout << "Enter the cancle date(mm/dd/yyyy): ";
	std::getline(std::cin >> std::ws, update_date);
	cout << "Membership Cancled.";
	InfoID = +InfoID;
}

//output method
void Info::cdisplay() const
{
	cout << "     + Cancelation Date: " << update_date << endl;
	cout << "       Description: " << description << endl;
}

void Info::display_all(list<Info>& member_list) {
	list<Info>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		it->cdisplay();
	}
}