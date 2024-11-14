#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int const ROWS = 13;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);

int main()
{
	char airplaneSeats[8][13] = { { 'D','D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'},
								  { 'C','C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C'},
							      { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1'},
								  { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3'},
								  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  { 'B','B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
								  { 'A','A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}};
	while (true) {
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 13; c++) {
				cout << airplaneSeats[r][c] << " ";
				if (c == 12) cout << endl;
			}
		}

		string seatInput;
		cout << "Enter a seat or Q to quit: ";
		cin >> seatInput;

		char row;
		int column;
		for (int i = 0; i < seatInput.length(); i++) {
			if (i == 1) row = seatInput[i];
			if (i == 0) column = seatInput[i] - '0';
		}

		int seatRow = findRowIndex(column);
		int seatNumber = findSeatIndex(row);
		airplaneSeats[seatNumber][seatRow] = 'X';
	}


}

int findRowIndex(int thisRow) {
	if (thisRow >= 0 || thisRow <= 13) {
		return thisRow - 1;
	}
	else {
		cout << "Error, invalid row input" << endl;
	}
}

int findSeatIndex(char thisSeat) {
	switch (thisSeat) {
	case 'A': return 7;
	case 'B': return 6;
	case 'C': return 1;
	case 'D': return 0;
	}
	cout << "Error, invalid seat index" << endl;
}

void displaySeatColumn(char seats[][ROWS], int column) {
		int r = ROWS;
		for (int c = 0; c < column; c++) {
			cout << seats[r][c] << " ";
			if (seats[r][c] == column-1) {
				break;
			}
		}
}