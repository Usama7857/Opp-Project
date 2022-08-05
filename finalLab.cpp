#include<iostream>
using namespace std;
#include"Vehicle.h"
#include"Bike.h"
#include"Car.h"
#include"Truck.h"
#include"BilalMotors.h"

void print(const BilalMotors &obj)
{
	for (int i = 0; i < obj.length(); i++)
		obj[i].display();
}
int main()
{
	BilalMotors obj;
	Vehicle * objPtr = nullptr;
	char opt = {};
	cout << "Press S to show vehicles list \nPress E to Create a data file \nPress B to add a bike \nPress C to add a car";
	cout << "\nPress T to add a truck \nPress F to find a vehicle by type \nPress Q to exit \n";
	cin >> opt;
	while (opt != 'Q')
	{
		if (opt == 'S')
		{
			print(obj);
		}
		if (opt == 'E')
		{
			char *file = nullptr;
			cout << "Enter File Name: "; 
			cin >> file;
			if (obj.saveData(file) == true)
			{
				cout << "File Created." << endl;
			}
			else
			{
				cout << "File Not Open" << endl;
			}
			
		}
		if (opt == 'B')
		{
			char * name = nullptr;
			char * color = nullptr;
			int number = 0;
			int power = 0;
			char * type = nullptr;
			double _height = {};
			bool self = {};
			bool brake = {};

			cout << "Enter Company Name: ";
			cin >> name;
			cout << "Enter Color: ";
			cin >> color;
			cout << "Enter Number of Wheels: ";
			cin >> number;
			cout << "Enter Horse Power: ";
			cin >> power;
			cout << "Enter Type: ";
			cin >> type;
			cout << "Enter Height: ";
			cin >> _height;
			cout << "Press 1 if bike is self start else 0: ";
			cin >> self;
			cout << "Press 1 if bike has disk brakes: ";
			cin >> brake;
	
			objPtr = new Bike(name, color, number, power, type, _height, self, brake);
			obj.addVehicle(objPtr);
			delete[] name;
			name = nullptr;
			delete[] color;
			color = nullptr;
			delete[] type;
			type = nullptr;
		}
		if (opt == 'C')
		{
			char * name = nullptr;
			char * color = nullptr;
			int number = 0;
			int power = 0;
			char * type = nullptr;
			int doors = 0;
			char* transmission = nullptr;
			int seats = 0;

			cout << "Enter Company Name: ";
			cin >> name;
			cout << "Enter Color: ";
			cin >> color;
			cout << "Enter Number of Wheels: ";
			cin >> number;
			cout << "Enter Horse Power: ";
			cin >> power;
			cout << "Enter Type: ";
			cin >> type;
			cout << "Enter Number Of Doors: ";
			cin >> doors;
			cout << "Enter Transmission: ";
			cin >> transmission;
			cout << "Enter Number Of Seats: ";
			cin >> seats;

			objPtr = new Car(name, color, number, power, type, doors, transmission, seats);
			obj.addVehicle(objPtr);

			delete[] name;
			name = nullptr;
			delete[] color;
			color = nullptr;
			delete[] type;
			type = nullptr;
			delete[] transmission;
			transmission = nullptr;
		}
		if (opt == 'T')
		{
			char * name = nullptr;
			char * color = nullptr;
			int number = 0;
			int power = 0;
			char * type = nullptr;
			double size = 0;
			char* category = nullptr;
			bool drive = {};

			cout << "Enter Company Name: ";
			cin >> name;
			cout << "Enter Color: ";
			cin >> color;
			cout << "Enter Number of Wheels: ";
			cin >> number;
			cout << "Enter Horse Power: ";
			cin >> power;
			cout << "Enter Type: ";
			cin >> type;
			cout << "Enter Container Size: ";
			cin >> size;
			cout << "Enter Category: ";
			cin >> category;
			cout << "Press 1 if its four wheel drive else 0: ";
			cin >> drive;

			objPtr = new Truck(name, color, number, power, type, size, category, drive);
			obj.addVehicle(objPtr);

			delete[] name;
			name = nullptr;
			delete[] color;
			color = nullptr;
			delete[] type;
			type = nullptr;
			delete[] category;
			category = nullptr;
		}
		if (opt == 'F')
		{
			char * type = nullptr;
			cout << "Enter Vehicle Type: ";
			cin >> type;
			obj.searchVehicle(type);
		}
		cout << "Press S to show vehicles list \nPress E to Create a data file \nPress B to add a bike \nPress C to add a car";
		cout << "\nPress T to add a truck \nPress F to find a vehicle by type \nPress Q to exit \n";
		cin >> opt;
	}

	return 0;
}