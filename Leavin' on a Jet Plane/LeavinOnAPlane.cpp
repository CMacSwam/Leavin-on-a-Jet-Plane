#include <iostream>
#include <string>

using namespace std;

const int ROWS = 8;
const int COLS = 13;
const char ERROR = -1;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][COLS], int column);
void displaySeatingChart(char seats[][COLS]);

int main() {
    char airplaneSeats[ROWS][COLS] = {
        {'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', ' '},
        {'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1'},
        {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    };

    displaySeatingChart(airplaneSeats);

    while (true) {
        string seatInput;
        cout << "Enter a seat or Q to quit: ";
        cin >> seatInput;
        if (seatInput == "Q") break;

        int row = findRowIndex(stoi(seatInput.substr(0, seatInput.size() - 1)));
        int col = findSeatIndex(seatInput.back());

        if (row == ERROR || col == ERROR || (row == 12 && (col == 2 || col == 3))) {
            cout << "Sorry, no such seat exists on the CRJ 200." << endl;
        }
        else if (airplaneSeats[col][row] == 'X') {
            cout << "Sorry, that seat is already reserved." << endl;
        }
        else {
            airplaneSeats[col][row] = 'X';
            displaySeatingChart(airplaneSeats);
        }
    }

    return 0;
}

int findRowIndex(int thisRow) {
    if (thisRow >= 1 && thisRow <= 13) {
        return thisRow - 1;
    }
    return ERROR;
}

int findSeatIndex(char thisSeat) {
    switch (thisSeat) {
    case 'A': return 7;
    case 'B': return 6;
    case 'C': return 1;
    case 'D': return 0;
    default: return ERROR;
    }
}

void displaySeatColumn(char seats[][ROWS], int column) {
    for (int r = 0; r < ROWS; ++r) {
        if (column < COLS && seats[r][column] != ' ') {
            cout << seats[r][column] << " ";
        }
    }
    cout << endl;
}

void displaySeatingChart(char seats[][COLS]) {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            cout << seats[r][c] << " ";
        }
        cout << endl;
    }
}