/*Jonathan Ayala
Chada Tech
CS210
January 23 2026*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int LOWEST_VALID_SELECTION = 1; // min valid menu selection
const int HIGHEST_VALID_SELECTION = 4; // max valid menu selection
const int EXIT_SELECTION = HIGHEST_VALID_SELECTION; // to exit program
const int CLOCK_WIDTH = 26;

struct TimeClock {
	int hour = 0; // stores hours
	int minutes = 0; // stores minutes
	int seconds = 0; // stores seconds
	TimeClock() = default;
};

void displayMenu();
int getMenuSelection(const string&);
void processSelection(int, TimeClock&);
int getInteger(string, int, int);
void clearScreen();
void incHour(TimeClock&);
void incMinutes(TimeClock&);
void incSeconds(TimeClock&);
void displayClock(TimeClock&);
string formatTwoDigits(int);
string centerText(string text, int length, char fill = ' ');
TimeClock getInitialTime();

int main() {
	int selection = 0; // stores the user menu choice
	struct TimeClock theTime; // stores time
	theTime = getInitialTime();

	do {
		clearScreen(); // to clear screen
		displayClock(theTime); // display current time
		selection = getMenuSelection("Please make a selection: "); // get the users menu choice
		if (selection != EXIT_SELECTION) {
			processSelection(selection, theTime);
		}
	} while (selection != EXIT_SELECTION);

	return 0;
}

void displayMenu() { // displays menu for user

	string stars(26, '*'); // number of stars printed

	cout << stars << endl;

	cout << "* 1 - Add One Hour     *" << endl;
	cout << "* 2 - Add One Minute   *" << endl;
	cout << "* 3 - Add One Second   *" << endl;
	cout << "* 4 - Exit Program     *" << endl;
	cout << stars << endl;
}

int getMenuSelection(const string& prompt) {
	bool needSelection = false;
	int selection = 0;

	do {
		displayMenu();
		cout << prompt;
		cin >> selection;
		needSelection = ((selection < LOWEST_VALID_SELECTION) || (selection > HIGHEST_VALID_SELECTION));
		if (needSelection) {
			cout << "Invalid Selection - Please re-enter" << endl;
		}
	} while (needSelection);
	return selection;
}

void processSelection(int selection, TimeClock& oneClock) {
	switch (selection) {
	case 1:
		incHour(oneClock);
		break;
	case 2:
		incMinutes(oneClock);
		break;
	case 3:
		incSeconds(oneClock);
		break;
	case 4:
		break; // exit case
	default:
		cout << "Invalid Selection" << endl;
	}
}

TimeClock getInitialTime() { // prompts the user input values for time
	TimeClock theTime; // stores the time to return
	theTime.hour = getInteger("Please enter the hour", 0, 23);
	theTime.minutes = getInteger("Please enter minutes", 0, 59);
	theTime.seconds = getInteger("Please enter seconds", 0, 59);
	return theTime;
}

int getInteger(string prompt, int lowest, int highest) {
	int number = 0;
	bool needNumber = true;
	string fullprompt = prompt + " between " + to_string(lowest) + " and " + to_string(highest) + ": ";
	do {
		cout << fullprompt;
		cin >> number;
		needNumber = ((number < lowest) || (number > highest)); // check if in bounds
		if (needNumber) {
			cout << "Invalid number - please enter" << endl;
		}

	} while (needNumber);
	return number;
} // getInteger

void clearScreen() {
	cout << "\033[2J\033[1;1H"; // clears screen
}

void incHour(TimeClock& theClock) { theClock.hour = (theClock.hour + 1) % 24; }

void incMinutes(TimeClock& theClock) {
	if (theClock.minutes == 59) {
		theClock.minutes = 0;
		incHour(theClock);
	}
	else {
		theClock.minutes++;
	}
}

void incSeconds(TimeClock& theClock) {
	if (theClock.seconds == 59) {
		theClock.seconds = 0;
		incMinutes(theClock);
	}
	else {
		theClock.seconds++;
	}
}

string formatTwoDigits(int n) {
	if (n < 10) return "0" + to_string(n);
	return to_string(n);
}

void displayClock(TimeClock& theClock) { // converts 24hr  to 12hr format
	int h12 = theClock.hour % 12;
	if (h12 == 0) h12 = 12;
	string amPm = (theClock.hour < 12) ? "AM" : "PM";

	string time12 = formatTwoDigits(h12) + ":" + formatTwoDigits(theClock.minutes) + ":" + formatTwoDigits(theClock.seconds) + " " + amPm;
	string time24 = formatTwoDigits(theClock.hour) + ":" + formatTwoDigits(theClock.minutes) + ":" + formatTwoDigits(theClock.seconds);

	// defining widths (recommended to fix format)
	const int innerWidth = 24;
	string sideStars = "*************************";

	cout << sideStars << " " << sideStars << endl;

	// Header Row
	cout << "*" << centerText("12-Hour Clock", innerWidth) << "* ";
	cout << "*" << centerText("24-Hour Clock", innerWidth) << "*" << endl;

	// Time Row
	cout << "*" << centerText(time12, innerWidth) << "* ";
	cout << "*" << centerText(time24, innerWidth) << "*" << endl;

	cout << sideStars << " " << sideStars << endl;
}

string centerText(string text, int length, char fill) {
	if (text.length() >= (size_t)length) return text;
	int totalPadding = length - text.length();
	int leftPadding = totalPadding / 2;
	int rightPadding = totalPadding - leftPadding;

	return string(leftPadding, fill) + text + string(rightPadding, fill);
}


