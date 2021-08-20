#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

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
	vector<Lead> second_leads;

	string file1;
	cout << "Enter the name of the first file: ";
	getline(cin, file1);
	string file2;
	cout << "Enter the name of the second file: ";
	getline(cin, file2);

	//to store each row of elements
	vector<string> variables;


	string line; // to store each line
	string word;

	// open 1st file
	ifstream firstFile(file1);
	if (firstFile.is_open())
	{
		while (getline(firstFile, line))
		{
			variables.clear();
			stringstream s(line);
			while (getline(s, word, ','))
			{
				variables.push_back(word);
			}

			Lead lead;
			lead.first_name = variables[0];
			lead.last_name = variables[1];
			lead.description = variables[2];
			lead.phone_number = variables[3];
			first_leads.push_back(lead);
		}
		firstFile.close();
	}
	else
		cout << "Could not open file: " << file1 << endl;


	ifstream secondFile(file2);

	if (secondFile.is_open())
	{
		while (getline(secondFile, line))
		{
			variables.clear();
			stringstream s(line);
			while (getline(s, word, ','))
			{
				variables.push_back(word);
			}

			Lead lead;
			lead.first_name = variables[0];
			lead.last_name = variables[1];
			lead.description = variables[2];
			lead.phone_number = variables[3];
			second_leads.push_back(lead);
		}

		secondFile.close();
	}
	else
		cout << "Could not open file: " << file1 << endl;

	cout << "Read " << first_leads.size() << " leads from first file and " << second_leads.size() << " from second file" << endl;



	vector<Lead> first_unique;
	vector<Lead> second_unique;
	vector<Lead> common;


	bool found;
	for (int i = 0; i < first_leads.size(); i++)
	{
		Lead leadi = first_leads[i];
		found = false;

		// Iterate  leads from second file
		for (int s = 0; s < second_leads.size(); s++)
		{
			Lead leads = second_leads[s];

			// check if there is a lead in common
			if (leadi.phone_number.compare(leads.phone_number) == 0)
			{
				found = true;
				break;
			}

		}

		if (!found) // unique for first file if lead1 is not in second file
		{
			first_unique.push_back(leadi);
		}
		else // it is common
		{
			bool found = false;
			for (int c = 0; c < common.size(); c++)
			{
				Lead lead = common[c];
				if (lead.phone_number.compare(leadi.phone_number) == 0)
				{
					found = true;
					break;
				}
			}
			if (!found)
				common.push_back(leadi);
		}
	}
	cout << "There are " << first_unique.size() << " unique leads in first file, " << second_unique.size() << " unique leads in second file and " << common.size() << " common leads." << endl;



	string output_file1_name = "file1_unique.csv";
	ofstream outputFile1(output_file1_name);
	for (int i = 0; i < first_unique.size(); i++)
	{
		Lead lead = first_unique[i];
		outputFile1 << lead.first_name << "," << lead.last_name << "," << lead.description << "," << lead.phone_number << endl;
	}
	outputFile1.close();

	string output_file2 = "file2_unique.csv";
	ofstream outputFile2(output_file2);
	for (int i = 0; i < second_unique.size(); i++)
	{
		Lead lead = second_unique[i];
		outputFile2 << lead.first_name << "," << lead.last_name << "," << lead.description << "," << lead.phone_number << endl;
	}

	outputFile2.close();

	string output_common = "common.csv";
	ofstream outputFile(output_common);
	for (int i = 0; i < common.size(); i++)
	{
		Lead lead = common[i];
		outputFile << lead.first_name << "," << lead.last_name << "," << lead.description << "," << lead.phone_number << endl;
	}

	outputFile.close();

}

