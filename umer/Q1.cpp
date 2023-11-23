#include<iostream>
#include<limits.h>
#include<string>
using namespace std;
// using Selection Sort
class Swings {
public:
	string name;
	int number;

	Swings() {
		name = "";
		number = 0;
	}
	Swings(string name, int number) {
		this->name = name;
		this->number = number;
	}
	void Display() {
		cout << "Name:   " << name << endl;
		cout << "Number:  " << number << endl;
	}
};
void Swap(Swings& obj1, Swings& obj2) {

	int tempnum = obj1.number;
	string tempname = obj1.name;

	obj1.name = obj2.name;
	obj1.number = obj2.number;

	obj2.name = tempname;
	obj2.number = tempnum;
}
int main()
{

	Swings Obj[6];
	Obj[0] = Swings("A", 108);
	Obj[1] = Swings("B", 113);
	Obj[2] = Swings("C", 110);
	Obj[3] = Swings("D", 111);
	Obj[4] = Swings("E", 112);


	// Selection Sort Algoithm //
	// Number Wise Sorting //
	for (int i = 0; i < 5; i++) {
		int maxi = 222220;
		int minIndex = -1;
		for (int j = i; j < 5; j++) {

			if (Obj[j].number < maxi) {
				maxi = Obj[j].number;
				minIndex = j;
			}
		}

		Swap(Obj[i], Obj[minIndex]);
	}

	for (int i = 0; i < 5; i++) {
		cout << endl;
		cout << " ----------------------- " << endl;
		Obj[i].Display();
		cout << endl;
	}

}
