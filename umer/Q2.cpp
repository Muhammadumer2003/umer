#include<iostream>
#include<limits.h>
#include<string>
using namespace std;
// Using Singly Circular Linked List
int bonus = 0;
class City {
public:
	string name;
	int coin1;
	int coin2;
	bool ChangeTaken; // To Keep Track Of Visited Cities
	City* next;

	City(string name, int coin1, int coin2) {
		this->name = name;
		this->coin1 = coin1;
		this->coin2 = coin2;
		ChangeTaken = false;
		this->next = NULL;
	}
	void InsertatEnd(City*& head, City*& tail, string name, int coin1, int coin2) {
		City* newCity = new City(name, coin1, coin2);

		if (!head) {
			head = newCity;
			tail = newCity;
			return;
		}

		tail->next = newCity;
		newCity->next = head;
		tail = newCity;
	}
	void ShowCities(City *head , City *tail) {

		
		do {

			cout << "City name: " << head->name << endl;
			cout << "Coin 1:    " << head->coin1 << endl;
			cout << "Coin 2:    " << head->coin2 << endl;
			head = head->next;
		} while (head != tail->next);

	}

	void StartJourney(City* head, City* tail) {
		int person = 24; // Required Change //

		do
		{

			if (head->coin1 + head->coin2 == person) {
				if (bonus != 3) { // bonus should not be > 3
					head->ChangeTaken = true;
					bonus++;
				}

			}

			head = head->next;

		} while (head != tail->next);
	}

	void Change(City* head, City* tail) {
		cout << " ------------- Visisted Cities ----------" << endl;
		cout << endl;
		cout << "Total bonus :   " << bonus << endl;
		cout << endl;
		do {

			if (head->ChangeTaken) {
				cout << "City name: " << head->name << endl;
				cout << "Coin 1:    " << head->coin1 << endl;
				cout << "Coin 2:    " << head->coin2 << endl;
			}
			head = head->next;
		} while (head != tail->next);

	}
	void NOChange(City* head, City* tail) {
		cout << " ------------- Un Visisted Cities ----------" << endl;
	
		cout << endl;
		do {

			if (!head->ChangeTaken) {
				cout << "City name: " << head->name << endl;
				cout << "Coin 1:    " << head->coin1 << endl;
				cout << "Coin 2:    " << head->coin2 << endl;
			}
			head = head->next;
		} while (head != tail->next);

	}

};

int main() {
	City* Start = NULL;
	City* End = NULL;
	Start->InsertatEnd(Start, End, "A", 11, 12);
	Start->InsertatEnd(Start, End, "B", 11, 13);
	Start->InsertatEnd(Start, End, "C", 11, 13);
	Start->InsertatEnd(Start, End, "D", 11, 14);
	Start->InsertatEnd(Start, End, "E", 11, 19);
	cout << " -------- Total Cities ---------- " << endl;
	Start->InsertatEnd(Start, End, "F", 11, 13);
	Start->ShowCities(Start, End);
	// Starts main Process of Coin Change
	Start->StartJourney(Start, End);


	// will print Cities which gave the change
	Start->Change(Start, End);
	// will print Cities which did not gave the change
	Start->NOChange(Start, End);

}