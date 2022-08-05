#include "Car.h"
int Car::numberOfCars;	//static attribute

Car::Car(char * name, char * _color, int number, int power, char * type, int doors, char * trans, int seats) : Vehicle(name, _color, number, power, type)
{
	noOfDoors = doors;								//using base initializer list
	deepCopy(trasmission, trans);
	noOfSeats = seats;
	numberOfCars++;				//maintaining number of cars available
}
Car::Car(const Car& obj) : Vehicle(obj)
{
	noOfDoors = obj.noOfDoors;
	deepCopy(trasmission, obj.trasmission);
	noOfSeats = obj.noOfSeats;
	numberOfCars++;
}
Car& Car::operator = (const Car& obj)
{
	if (this != &obj)
	{
		noOfDoors = obj.noOfDoors;
		deepCopy(trasmission, obj.trasmission);
		noOfSeats = obj.noOfSeats;
	}

	return *this;
}
void Car::setNoOfDoors(int doors)
{
	noOfDoors = doors;
}
void Car::setTrasmission(char* trans)
{
	if (trasmission)
	{
		delete[] trasmission;
		trasmission = nullptr;
	}
	deepCopy(trasmission, trans);
}

void Car::setNoOfSeats(int NoOfSeats)
{
	noOfSeats = NoOfSeats;
}

int Car::getNoOfDoors() const
{
	return noOfDoors;
}

char* Car::getTrasmission() const
{
	char * temp = { nullptr };
	deepCopy(temp, trasmission);
	return temp;
}

int Car::getNoOfSeats() const
{
	return noOfSeats;
}

void Car::checkType()
{
	if (getNumberOfWheels() == 4)
	{
		char * ptr = new char[4]{ "Car" };
		setTypeOfVehicle(ptr);
		delete[] ptr;
		ptr = nullptr;
	}
}

void Car::display() const
{
	cout << noOfDoors << endl;
	cout << trasmission << endl;
	cout << noOfSeats << endl;
	cout << numberOfCars << endl;
}


Car::~Car()
{
	numberOfCars--;
}