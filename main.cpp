#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
using namespace Records;
int displayMenu();
void doFix(Database& inDB);
void doUnfix(Database& inDB);
void doincRepairCost(Database& inDB);
void dodecRepairCost(Database& inDB);
int main(int argc, char** argv)
{
 Database employeeDB;
 bool done = false;
 while (!done) {
 	int selection = displayMenu();
 	switch (selection) { 	case 1:
 	doUnfix(employeeDB);
 	break;
 	case 2:
 	doFix(employeeDB);
 	break;
 	case 3:
 	doincRepairCost(employeeDB);
 	break;
 	case 4:
 	employeeDB.displayAllDefects();
 	break;
 	case 5:
 	employeeDB.displayUnfixed();
 	break;
 	case 6:
 	employeeDB.displayFixed();
 	break;
 	case 0:
 	done = true;
 	break;
 	default:
 	cerr << "Unknown command." << endl;  }
 }
}
int displayMenu()
{
 int selection;
 cout << endl;
 cout << "Defect Database" << endl;
 cout << "-----------------" << endl;
 cout << "1) Add a new Defect" << endl;
 cout << "2) Exclude Defect(was fixed)" << endl;
 cout << "3) Increase price" << endl;
 cout << "4) List all Defects" << endl;
 cout << "5) List unfixed Defects" << endl;
 cout << "6) List fixed Defects" << endl;
 cout << "0) Quit" << endl;
 cout << endl;
 cout << "---> ";
 cin >> selection;
 return selection;
}
void doUnfix(Database& inDB)
{
 int model;
 string firstName;
 string lastName;
 cout << "model code? ";
 cin >> model;
 cout << "desciption? ";
 cin >> firstName;
 cout << "Methods? ";
 cin >> lastName;
 try {
 inDB.addDefect(model, firstName, lastName);
 } catch (std::exception ex) {
 cerr << "Unable to add new Defect" << endl;
 }
}
void doFix(Database& inDB)
{
 int defectCode;
 cout << "Defect code? ";
 cin >> defectCode;
 try {
 Defect& def = inDB.getDefect(defectCode);
 def.fix();
 cout << "Defect " << defectCode << " was fixed" << endl;
   } catch (std::exception ex) {
 cerr << "Eror" << endl;
 }
}
void doincRepairCost(Database& inDB)
{
 int defectCode;
 int raiseAmount;
 cout << "Defect code? ";
 cin >> defectCode;
 cout << "How much increase price? ";
 cin >> raiseAmount;
 try {
 Defect& def = inDB.getDefect(defectCode);
 def.incRepairCost(raiseAmount);
 } catch (...) {
 cerr << "Unable increase Defect!" << endl;
 }
}