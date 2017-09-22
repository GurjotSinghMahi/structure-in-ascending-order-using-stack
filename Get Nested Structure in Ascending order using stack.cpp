/**
c++ program to sort a nested structure of Name, Date, Month and Year in ascending order using stack operations. It should sort on the basis of Year, if 2 year are equal then sort on the basis of Month, if Month are equal then sort on the basis of day and if day are equal then sort on the basis of Name.
Use push, pop, isempty and isfull functions of stack with the use of empty stack
**/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstring> 

using namespace std;

struct DOB
	{
		int day;
		int month;
		int year;
	};

struct database
	{
		string name;
		DOB dob;
	};

///////////////////////////<-----------------STACK SORT FUNCTION USING EMPTY STACK--------------->///////////////////////////
stack<database> sortStack(stack<database> &input_stack)
{
cout << "temporary " << endl;
	stack<database> tmpStack;

	while (!input_stack.empty())
	{
		database var = input_stack.top();
		input_stack.pop();

		if(tmpStack.size() == 0)
		{
		tmpStack.push(var);
		}

		else
		{
			database tmp_stack_var = tmpStack.top();
					
				if(var.dob.year < tmp_stack_var.dob.year)
				{
				tmpStack.push(var);		
				}
				else if (var.dob.year == tmp_stack_var.dob.year)
				{
					if(var.dob.month < tmp_stack_var.dob.month)
					{
					tmpStack.push(var);
					}
					else if (var.dob.month == tmp_stack_var.dob.month)
					{
						if(var.dob.day < tmp_stack_var.dob.day)
						{
						tmpStack.push(var);
						}
						else if (var.dob.day == tmp_stack_var.dob.day)
						{
							const char *var_name_char = var.name.c_str();
							const char *tmp_stack_char = tmp_stack_var.name.c_str();
							int i = strcmp(var_name_char,tmp_stack_char);
							if(i < 0)
							{
							tmpStack.push(var);
							}
							else
							{
								while(tmpStack.size() != 0 && i > 0)
								{
								database tmp_stack_var = tmpStack.top();
								tmpStack.pop();				
								input_stack.push(tmp_stack_var);	
								}
							tmpStack.push(var);
							}	
						}
						else
						{
						while(tmpStack.size() != 0 && var.dob.day > tmp_stack_var.dob.day)
						{
						database tmp_stack_var = tmpStack.top();
						tmpStack.pop();				
						input_stack.push(tmp_stack_var);	
						}

						tmpStack.push(var);
						}
					}

					else
					{
					while(tmpStack.size() != 0 && var.dob.month > tmp_stack_var.dob.month)
					{
					database tmp_stack_var = tmpStack.top();
					tmpStack.pop();				
					input_stack.push(tmp_stack_var);	
					}

					tmpStack.push(var);
					}
				}		
				else
				{
					while(tmpStack.size() != 0 && var.dob.year > tmp_stack_var.dob.year)
					{
					database tmp_stack_var = tmpStack.top();
					
					cout << "\n";
					tmpStack.pop();				
					input_stack.push(tmp_stack_var);	
					}

				tmpStack.push(var);
				}
		}
	}

return tmpStack;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Main Function
int main()
{   
int choice, number_of_entries;

std::stack<database> input_stack; //stack of entries to be made in Stack
database entries[50]; //array of objects for struct database

cout << "How many enteries you want to make: ";
cin >> number_of_entries;

for(int i=0; i<number_of_entries;i++)
	{
		cout << "Enter Full Name: ";
		cin >> entries[i].name;
		cout << "Enter DOB:" << endl;
		cout << "Enter day: ";
		cin >> entries[i].dob.day;
		cout << "Enter month: ";
		cin >> entries[i].dob.month;
		cout << "Enter year: ";
		cin >> entries[i].dob.year;
		input_stack.push(entries[i]);
		cout << "\n" << endl;
	}

cout << "There are " << input_stack.size () << " objects in stack" <<endl;
cout << "\n" << endl;

stack<database> tmpStack = sortStack(input_stack);
cout << "sortStack function is passed" <<endl;

while (!tmpStack.empty())
{
for (int i = 0; i<number_of_entries;i++)
	{
	cout << "The elements on the top " << i << " position are" <<  endl;
	database temp = tmpStack.top();
	cout << "Full Name: " << temp.name << endl;
	cout << "Day: " << temp.dob.day << endl;
	cout << "Month: " << temp.dob.month << endl;
	cout << "Year: " << temp.dob.year << endl;
	tmpStack.pop();
	}
}

return 0;
}
