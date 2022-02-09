#include <iostream>
using namespace std;
class manager
{
protected:
int total;
string id;
struct person
{
string name, ID, address;
int contact, cash;
} person[100];
};
class Bank : public manager
{
public:
Bank()
{
total = 0;
}
void choice();
void eachData();
void display();
void updateinfo();
void searchacc();
void trans();
void del();
};
void Bank::choice()
{
char choice;
while (1)
{
cout << "\n\nChoose an option: " << endl;
cout << "1. Create new account" << endl;
cout << "2. View customers list" << endl;
cout << "3. update information of existing account" << endl;
cout << "4. Check the details of an existing account" << endl;
cout << "5. For transaction" << endl;
cout << "6. Remove existing account" << endl;
cout << "7. End" << endl;
cin >> choice;
switch (choice)
{
case '1':
Bank::eachData();
break;
case '2':
if (total == 0)
{
cout << "No data is entered" << endl;
}
else
{
Bank::display();
}
break;
case '3':
if (total == 0)
cout << "No data is entered" << endl;
else
Bank::updateinfo();
break;
case '4':
if (total == 0)
cout << "No data is entered" << endl;
else
Bank::searchacc();
break;
case '5':
if (total == 0)
cout << "No data is entered" << endl;
else
Bank::trans();
break;
case '6':
if (total == 0)
cout << "No data is entered" << endl;
else
Bank::del();
break;
case '7':
exit(0);
break;
default:
cout << "Invalid Input" << endl;
break;
}
}
}
void Bank::eachData()
{
cout << "Enter data of User " << total + 1 << endl;
cout << "Name: ";
cin >> person[total].name;
cout << "ID: ";
cin >> person[total].ID;
cout << "Address: ";
cin >> person[total].address;
cout << "Contact: ";
cin >> person[total].contact;
cout << "Total Cash: ";
cin >> person[total].cash;
total++;
}
void Bank::display()
{
for (int i = 0; i < total; i++)
{
cout << "Data of person " << i + 1 << endl;
cout << "Name: " << person[i].name << endl;
cout << "ID: " << person[i].ID << endl;
cout << "Address: " << person[i].address << endl;
cout << "Contact: " << person[i].contact << endl;
cout << "Cash: " << person[i].cash << endl;
}
}
void Bank::updateinfo()
{
cout << "Enter id of student those data you want to updateinfo" << endl;
cin >> id;
for (int i = 0; i < total; i++)
{
if (id == person[i].ID)
{
cout << "Previous data" << endl;
cout << "Data of person " << i + 1 << endl;
cout << "Name: " << person[i].name << endl;
cout << "ID: " << person[i].ID << endl;
cout << "Address: " << person[i].address << endl;
cout << "Contact: " << person[i].contact << endl;
cout << "Cash: " << person[i].cash << endl;
cout << "\nEnter new data" << endl;
cout << "Enter name: ";
cin >> person[i].name;
cout << "ID: ";
cin >> person[i].ID;
cout << "Address: ";
cin >> person[i].address;
cout << "Contact: ";
cin >> person[i].contact;
cout << "Total Cash: ";
cin >> person[i].cash;
break;
}
if (i == total - 1)
{
cout << "No such record found" << endl;
}
}
}
void Bank::searchacc()
{
cout << "Enter id of student those data you want to searchacc" << endl;
cin >> id;
for (int i = 0; i < total; i++)
{
if (id == person[i].ID)
{
cout << "Name: " << person[i].name << endl;
cout << "ID: " << person[i].ID << endl;
cout << "Address: " << person[i].address << endl;
cout << "Contact: " << person[i].contact << endl;
cout << "Cash: " << person[i].cash << endl;
break;
}
if (i == total - 1)
{
cout << "No such record found" << endl;
}
}
}
void Bank::trans()
{
int cash;
char ch;
cout << "Enter id of student those data you want to transaction" << endl;
cin >> id;
for (int i = 0; i < total; i++)
{
if (id == person[i].ID)
{
cout << "Name: " << person[i].name << endl;
cout << "Address: " << person[i].address << endl;
cout << "Contact: " << person[i].contact << endl;
cout << "\nExisting Cash " << person[i].cash << endl;
cout << "Press 1 to deposit" << endl;
cout << "Press 2 to withdraw" << endl;
cin >> ch;
switch (ch)
{
case '1':
cout << "How much cash you want to deposit??" << endl;
cin >> cash;
person[i].cash += cash;
cout << "Your new cash is " << person[i].cash << endl;
break;
case '2':
back:
cout << "How much cash you want to withdraw??" << endl;
cin >> cash;
if (cash > person[i].cash)
{
cout << "Your existing cash is just " << person[i].cash << endl;
goto back;
}
person[i].cash -= cash;
cout << "Your new cash is " << person[i].cash << endl;
break;
default:
cout << "Invalid input" << endl;
break;
}
break;
}
if (i == total - 1)
{
cout << "No such record found" << endl;
}
}
}
void Bank::del()
{
char ch;
cout << "Press 1 to remove specific record" << endl;
cout << "Press 2 to remove full record" << endl;
cin >> ch;
switch (ch)
{
case '1':
cout << "Enter id of student those data you want to remove" << endl;
cin >> id;
for (int i = 0; i < total; i++)
{
if (id == person[i].ID)
{
for (int j = i; j < total; j++)
{
person[j].name = person[j + 1].name;
person[j].ID = person[j + 1].ID;
person[j].address = person[j + 1].address;
person[j].contact = person[j + 1].contact;
person[j].cash = person[j + 1].cash;
total--;
cout << "Your required data is deleted" << endl;
break;
}
}
if (i = total - 1)
{
cout << "No such record found" << endl;
}
}
break;
case '2':
total = 0;
cout << "All record is deleted" << endl;
break;
default:
cout << "Invalid Input" << endl;
break;
}
}
int main()
{
Bank b;
b.choice();
return 0;
}
