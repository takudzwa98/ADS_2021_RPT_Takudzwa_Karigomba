#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#include <vector>

struct Lead
{
	string first_name;
	string last_name;
	string description;
	string phone_number;
};

int main()
{
	vector<Lead> first_leads;

	cout << "Name of file 1: ";
	getline(cin, file1);

	vector<string> filerow;
	string line; 
	string word;

	ifstream firstFile(file1);
	if (firstFile.is_open())
	{
		while (getline(firstFile, line))
		{
			stringstream s(line);
			while (getline(s, word, ','))
			{
				firstrow.push_back(word);
			}

			Lead lead;
			lead.first_name = filerow[0];
			lead.last_name = filerow[1];
			lead.description = filerow[2];
			lead.phone_number = filerow[3];
			first_leads.push_back(lead);
		}
	else
		cout << "Could not open file: " << file1 << endl;

	
	vector<Lead> second_leads;

ifstream secondFile(file2);
	if (secondFile.is_open())
	{
		while (getline(secondFile, line))
		{
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			Lead lead;
			lead.first_name = row[0];
			lead.last_name = row[1];
			lead.description = row[2];
			lead.phone_number = row[3];
			second_leads.push_back(lead);
		}

		secondFile.close();
	}
	else
		cout << "Could not open file: " << file1 << endl;

	cout << "Read " << first_leads.size() << " leads from first file and " << second_leads.size() << " from second file" << endl;

	

	}