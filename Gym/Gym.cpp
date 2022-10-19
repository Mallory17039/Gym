// Author : Mallory Lee

#include <iostream>
#include "Membership.h"
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;


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

int main()
{
	Membership mem;
	int choice;
	string name;
	list<Membership> members;
	list<Membership>::iterator it;
	int membershipID;

	do
	{
		cout << "\n";
		cout << "===================================================== \n";
		cout << " \t\t Membership MENU \t \n ";
		cout << "==================================================== \n";
		cout << " 0. Quit Program \n";
		cout << " 1. Display  Members' Information\n";
		cout << " 2. Create the Member\n";
		cout << " 3. Delete the Member\n";
		cout << " 4. Calculate Remaining Membership Days\n";
		cout << " 5. Cancle the Membership\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (!members.empty())
			{
				mem.display_all(members);
			}
			else if (members.empty()) {
				cout << "There is no members\n";
			}
			break;
		case 2:
			mem.create_membership(members);
			break;
		case 3:
		{	//remove Membership
			cout << "Enter Membership ID to remove: ";
			cin >> membershipID;
			auto new_end = remove_if(members.begin(), members.end(), [membershipID](auto& mem) {
				return mem.get_id() == membershipID;
				}
			);
			members.erase(new_end, members.end());
			break;
		}
		case 4:
			// Calculate Memebrship period
			cout << "Enter and ID to search for: ";
			cin >> membershipID;
			it = find_ID(members, membershipID);

			if (it == members.end()) {
				cout << "*** Can't find the ID *** " << endl;
			}

			it->cal_period();
			break;
		case 5:
			cout << "Enter and ID to search for: ";
			cin >> membershipID;
			it = find_ID(members, membershipID);

			if (it == members.end()) {
				cout << "*** Can't find the ID *** " << endl;
			}
			cout << "*** Found the ID ***" << endl;
			it->add_Info();
			break;
		case 0:
			mem.quit();
			break;
		}
	} while (choice != 0);
	return 0;
}