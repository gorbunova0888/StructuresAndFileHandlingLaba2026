/****************************
* Автор: Горбунова Настя    *
* Задание: Работа с файлами *
* Вариант: 5                *
****************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Student {
  string lastName;
  string firstName;
  int height;
  int weight;
};

int main() {
  int minHeight;
  cout << "Enter minimum height: ";
  cin >> minHeight;


  ifstream input("C:\Users\dnsi\StructuresAndFileHandlingLaba\ConsoleApplication1\x64\Debug");
  if (!input) {
	cout << "ERROR file\n";
	return 1;
  }

  vector <Student> students;
  string line;

  while (getline(input, line)) {
	if (line.empty()) continue;

	istringstream ss(line);
	string heightStr, weightStr;
	Student studentList;

	getline(ss, studentList.lastName, ';');
	getline(ss, studentList.firstName, ';');
	getline(ss, heightStr, ';');
	getline(ss, weightStr, ';');

	studentList.height = stoi(heightStr);
	studentList.weight = stoi(weightStr);
	students.push_back(studentList);
  }
  ostringstream report;
  int count = 0;
  double sumHeight = 0.0, sumWeight = 0.0;
  int maxHeight = -1;
  string tallestName = "";

  report << "Filtered students:\n";

  for (size_t studentIndex = 0; studentIndex < students.size(); ++studentIndex) {
	if (students[studentIndex].height > maxHeight) {
	  maxHeight = students[studentIndex].height;
	  tallestName = students[studentIndex].lastName + " " + students[studentIndex].firstName;
	}

	if (students[studentIndex].height > minHeight) {
	  count++;
	  sumHeight += students[studentIndex].height;
	  sumWeight += students[studentIndex].weight;
	}
  }

  if (count == 0) {
	report << "EMPTY\nAverage height: NONE\nAverage weight: NONE\n";
  } else {
	report << "Average height: " << sumHeight / count << "\n";
	report << "Average weight: " << sumWeight / count << "\n";
  }
  report << "Tallest: " << tallestName << " (" << maxHeight << ")\n";

  cout << report.str();

  ofstream output("output.txt");
  if (!output) {
	output << report.str();
  }

  return 0;
}