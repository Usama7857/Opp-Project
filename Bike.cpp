#include "Bike.h"
int Bike::numberOfBikes;

Bike::Bike(char * name, char * _color, int number, int power, char * type, double _height, bool start, bool brake) : Vehicle(name, _color, number, power, type)
{
	height = _height;
	selfStart = start;
	diskBrake = brake;
	numberOfBikes++;
}
Bike::Bike(const Bike& obj) : Vehicle(obj)
{
	height = obj.height;
	selfStart = obj.selfStart;
	diskBrake = obj.diskBrake;
	numberOfBikes++;
}
Bike& Bike::operator = (const Bike& obj)
{
	if (this != &obj)
	{
		height = obj.height;
		selfStart = obj.selfStart;
		diskBrake = obj.diskBrake;
	}

	return *this;
}
void Bike::setHeight(double Height)
{
	height = Height;
}

void Bike::setSelfStart(bool SelfStart)
{
	selfStart = SelfStart;
}

void Bike::setDiskBrake(bool DiskBrake)
{
	diskBrake = DiskBrake;
}

double Bike::getHeight() const
{
	return height;
}

bool Bike::getSelfStart() const
{
	return selfStart;
}

bool Bike::getDiskBrake() const
{
	return diskBrake;
}
int Bike::getNumberOfBike() const
{
	return numberOfBikes;
}
void Bike::checkType()
{
	if (getNumberOfWheels() == 2)
	{
		char * ptr = new char[5]{ "Bike" };
		setTypeOfVehicle(ptr);
		delete[] ptr;
		ptr = nullptr;
	}
}

void Bike::display() const
{
	cout << height << endl;
	cout << selfStart << endl;
	cout << diskBrake << endl;
	cout << numberOfBikes << endl;
}
Bike::~Bike()
{
	numberOfBikes--;
}