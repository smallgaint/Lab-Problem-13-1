#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);
int sumArray(int arr[], int size);

int main() {
	string filename;
	cout << "Enter filename: ";
	getline(cin, filename);
	if (readFromFile(filename)) {
		pressEnterToContinue();
		return 0;
	}
	else {
		pressEnterToContinue();
		return 1;
	}
}

bool readFromFile(string filename) {
	ifstream inFile;
	string thisLine;

	int letterCount[26] = { 0 };

	inFile.open(filename);

	if (inFile.fail()) {
		cout << "read error - sorry\n";
		return false;
	}

	while (true) {
		if (inFile.fail()) break;
		thisLine.clear();
		getline(inFile, thisLine);

		for (char c : thisLine) {
			if (isalpha(c)) {
				c = tolower(c);
				letterCount[c - 'a']++;
			}
		}
	}

	double totalLetters = sumArray(letterCount, 26);

	cout << "Total number of letters: " << totalLetters << endl;
	cout << "Frequency:" << endl;

	for (int i = 0; i < 26; i++) {
		char letter = 'A' + i;
		cout << "'" << letter << "': " << fixed << setprecision(3) << right << setw(6) << letterCount[i] / totalLetters * 100 << endl;
	}

	inFile.close();
	return true;
}

void pressEnterToContinue(void) {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}

int sumArray(int arr[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += arr[i];
	}
	return total;
}