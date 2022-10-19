// Author : Mallory Lee

#include <iostream>
#include "Membership.h"
#include <list>
#include <algorithm>
#include <numeric>
#include "cal_date.h"

using namespace std;

int main()
{
	Membership mem;
	int choice;
	string name;
	list<Membership> members;

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
		cout << " 5. Add health information to an Membership\n";
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
			float remove_id;
			cout << "Enter Membership ID to remove: ";
			cin >> remove_id;
			auto new_end = remove_if(members.begin(), members.end(), [remove_id](auto& mem) {
				return mem.get_id() == remove_id;
				}
			);
			members.erase(new_end, members.end());
			break;
		}
		case 4:
			// Calculate Memebrship period
			mem.cal_period(members);
			break;
		case 5:
			mem.add_Health(members);
			break;
		case 0:
			mem.quit();
			break;
		}
	} while (choice != 0);
	return 0;
}