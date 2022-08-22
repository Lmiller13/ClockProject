#include <iostream>
#include <time.h>
#include <stdlib.h>
#include<string>
#include <iomanip>
using namespace std;


//add hour
int addOneHour12(int clock12hr, int clock24hr, string merid) {
	if (clock12hr == 12) {
		clock12hr = 1;
	}
	else {
		clock12hr = clock12hr + 1;
	}
	return clock12hr;
}
int addOneHour24(int clock12hr, int clock24hr, string merid) {
		if (clock24hr == 23) {
			clock24hr = 0;
		}
		else {
			clock24hr = clock24hr + 1;
		}
		return clock24hr;

}
//Flip meridian
string flipMerid(string merid) {
	if (merid == "A.M.") {
		merid = "P.M.";
	}
	else {
		merid = "P.M.";
	}
	return merid;
}
//add minute
int addOneMin(int clock12hr, int clock24hr, int clockMin, string merid) {
	if (clockMin == 59) {
		clockMin = 0;
		addOneHour12(clock12hr, clock24hr, merid);
		addOneHour24(clock12hr, clock24hr, merid);
	}
	else {
		clockMin = clockMin + 1;
	}
	return clockMin;
}

//add second
int addOneSec(int clock12hr, int clock24hr, int clockMin, int clockSec, string merid) {
	if (clockSec == 59) {
		clockSec = 0;
		addOneMin(clock12hr, clock24hr, clockMin, merid);
	}
	else {
		clockSec = clockSec + 1;
	}
	return clockSec;
}


//display time
void displayTime(int clock12hr, int clock24hr, int clockMin, int clockSec, string merid) {
	cout << "*************************    **************************" << endl;
	cout << "*     12-Hour Clock" << "     *" << "     *     24-Hour Clock" << "     *" << endl;
	cout << "*     " << std::setfill('0') << std::setw(2) <<  clock12hr << ":" << std::setfill('0')<< std::setw(2) << clockMin << ":" << setfill('0')<< setw(2)<< clockSec<<" " << merid
		<< "     *     *     "<< setfill('0')<< setw(2) << clock24hr << ":" << setfill('0') << setw(2)<< clockMin << ":"<< setfill('0')<<setw(2)<< clockSec << "          *" << endl;
	cout << "*************************    **************************" << endl;
}

// main

void displayMenu() {
	cout << setfill(' ') << setw(13) << " " << setfill('*') << setw(26) << "*" << endl;
	cout << "             *1-Add One Hour          *" << endl;
	cout << "             *2-Add One Minute        *" << endl;
	cout << "             *3-Add One Second        *" << endl;
	cout << "             *4-Exit Program          *" << endl;
	cout << setfill(' ') << setw(13) << " " << setfill('*') << setw(26) << "*" << endl;
}

int main() {
	int clock12hr = 12;
	int clock24hr = 12;
	int clockMin = 59;
	int clockSec = 55;
	string merid = "A.M.";
	string exitString = " ";
	int userInput;
	bool exit = false;

	while (exit == false) {
		displayTime(clock12hr, clock24hr, clockMin, clockSec, merid);
		displayMenu();
		cin >> userInput;

		if (userInput == 1) {
			clock12hr = addOneHour12(clock12hr, clock24hr, merid);
			
			clock24hr = addOneHour24(clock12hr, clock24hr, merid);
			if (clock12hr == 12) {
				merid = flipMerid(merid);
			}
		}
		else if (userInput == 2) {
			clockMin = addOneMin(clock12hr, clock24hr, clockMin, merid);
			if (clockMin == 0) {
				clock12hr = addOneHour12(clock12hr, clock24hr, merid);
				clock24hr = addOneHour24(clock12hr, clock24hr, merid);
			}
		}
		else if (userInput == 3) {
			clockSec = addOneSec(clock12hr, clock24hr, clockMin, clockSec, merid);
			if (clockSec == 0) {
				clockMin = addOneMin(clock12hr, clock24hr, clockMin, merid);
				if (clockMin == 0) {
					clock12hr = addOneHour12(clock12hr, clock24hr, merid);
					clock24hr = addOneHour24(clock12hr, clock24hr, merid);
				}
			}
		}
		else if (userInput == 4) {
			exit = true;

		}
		else {
			cout << "invalid input" << endl;
		}
	}
}


