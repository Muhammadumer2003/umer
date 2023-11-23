#include<iostream>
#include<limits.h>
#include<string>
using namespace std;
int maxi = INT_MIN; // using INT_MIN which sets with lowest integer value
int answer[6][6] = { 0 }; // Global Arary For Result
bool IsSafe(char arr[][6], int path[][6], int r, int c, int x, int y) {
	return (x >= 0 && x < r && y >= 0 && y < c && arr[x][y] != 'X' && path[x][y] == 0);
}
void Solve(char arr[][6], int path[][6], int r, int c, int x, int y, int& health) {

	path[x][y] = 1;

	if (arr[x][y] == 'D' && x == 5 && y == 5) {

		if (health > maxi) {

			maxi = health;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					answer[i][j] = path[i][j];
				}
			}
		}

		return;
	}

	

	if (IsSafe(arr, path, r, c, x + 1, y)) {

		if (arr[x][y] == 'R') {
			// decrementing 2 when Red Zone is Encountered
			health -= 2;
		}

		Solve(arr, path, r, c, x + 1, y, health);

		if (arr[x][y] == 'R') {
			health += 2;
		}



	}
	if (IsSafe(arr, path, r, c, x, y - 1)) {

		if (arr[x][y] == 'R') {
			health -= 2;
		}


		Solve(arr, path, r, c, x, y - 1, health);

		if (arr[x][y] == 'R') {
			health += 2;
		}



	}
	if (IsSafe(arr, path, r, c, x, y + 1)) {

		if (arr[x][y] == 'R') {
			health -= 2;
		}

		Solve(arr, path, r, c, x, y + 1, health);


		if (arr[x][y] == 'R') {
			health += 2;
		}



	}
	if (IsSafe(arr, path, r, c, x - 1, y)) {


		if (arr[x][y] == 'R') {
			health -= 2;
		}


		Solve(arr, path, r, c, x - 1, y, health);


		if (arr[x][y] == 'R') {
			health += 2;
		}


	}


	path[x][y] = 0;
}

int main()
{
	int n = 6;
	char arr[6][6] = { {'H','S','S','X','R','R'},
					  {'S','S','S','X','S','R'},
					  {'S','R','S','S','S','X'},
					  {'S','X','S','X','S','S'},
					  {'S','S','S','R','S','X'},
					  {'S','X','S','S','S','D'} };

	int path[6][6] = { 0 };
	int health = 100; // Initial health //
	if (arr[0][0] != 'H'){
		cout << "Can not Enter The grid";
		exit(0);
	}
	Solve(arr, path, n, n, 0, 0, health);
	if (health != INT_MIN) {
		cout << "Maximum Health:   " << health << endl;
	}
	else
	cout << "health: " << 100 << endl;
	cout << endl;
	cout << "Path which leads to destination and maximizes the health:   " << endl << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << answer[i][j] << "   ";
		}
		cout << endl;
	}



}