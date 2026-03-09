/*Jonathan Ayala
* CS210
* Project 3
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class GroceryFrequency {
public:

	// reads input file
	void procssInputFile(string filename) {
		ifstream input(filename);

		if (input.fail()) {
			cout << "Error! Could not open file" << filename << endl;
			return;
		}

		string item;
		while (input >> item) {
			freqData[item]++;
		}
		input.close();
	}

	int getItemFrequency(string item) {
		return freqData[item];
	}

	// prints a list of all items & frequencies
	void printFrequencyList() {
		for (auto it = freqData.begin(); it != freqData.end(); ++it) {
			cout << it->first << ": " << it->second << endl;
		}
	}

	// prints a histogram of all items and their frequencies
	void printFrequencyHistogram() {
		for (auto it = freqData.begin(); it != freqData.end(); ++it) {
			cout << it->first << " ";
			for (int i = 0; i < it->second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}

	// writes the frequency data to a backup file
	void backupFrequencyData(string filename) {
		ofstream output(filename);
		if (output.fail()) {
			cout << "Error! Could not open file " << filename << endl;
			return;
		}
		for (auto it = freqData.begin(); it != freqData.end(); ++it) {
			output << it->first << ": " << it->second << endl;
		}
		output.close();
	}

private:
	map<string, int> freqData;
};

int main() {
	GroceryFrequency grocery;

	// process the input file
	grocery.procssInputFile("CS210P3.txt");

	//main menu loop
	bool running = true;
	while (running) {

		// display menu options
		cout << endl;
		cout << "Please select an option:" << endl;
		cout << "1. Look up an item's frequency" << endl;
		cout << "2. Print list of all items and frequencies" << endl;
		cout << "3. Print histogram of item frequencies" << endl;
		cout << "4. Exit the program" << endl;

		// get user input
		int choice;
		cout << "Enter your choice (1-4): ";
		cin >> choice;

		// perform action based on use input
		switch (choice) {
		case 1: {
			string item;
			cout << "Enter the item to look up: ";
			cin >> item;
			int freq = grocery.getItemFrequency(item);
			cout << "Frequency of " << item << ": " << freq << endl;
			break;
		}
		case 2: {
			grocery.printFrequencyList();
			break;
		}
		case 3: {
			grocery.printFrequencyHistogram();
			break;
		}
		case 4: {
			grocery.backupFrequencyData("frequency.dat");
			running = false;
			break;
		}
		default: {
			cout << "Invalid choice! Please enter a number between 1-4." << endl;
			break;
		}
		}
	} 
	return 0;

}
		


