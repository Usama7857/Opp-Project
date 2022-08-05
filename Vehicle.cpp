#include "Vehicle.h"

Vehicle::Vehicle(char * name, char * _color, int number, int power, char * type)
{
	deepCopy(companyName, name);
	deepCopy(color, _color);
	numberOfWheels = number;
	powerCC = power;
	deepCopy(typeOfVehicle, type);
}
Vehicle::Vehicle(const Vehicle& obj)
{
	deepCopy(companyName, obj.companyName);
	deepCopy(color, obj.color);
	numberOfWheels = obj.numberOfWheels;
	powerCC = obj.powerCC;
	deepCopy(typeOfVehicle, obj.typeOfVehicle);
}
void Vehicle::setCompanyName(const char * name)
{
	if (companyName)
	{
		delete[] companyName;
		companyName = nullptr;
	}
	deepCopy(companyName, name);
}
void Vehicle::setColor(const char * _color)
{
	if (color)					//handling memory leakage
	{
		delete[] color;
		color = nullptr;
	}
	deepCopy(color, _color);
}
void Vehicle::setNumberOfWheels(int number)
{
	numberOfWheels = number;
}
void Vehicle::setPowerCC(int power)
{
	powerCC = power;
}
void Vehicle::setTypeOfVehicle(const char * type)
{
	if (typeOfVehicle)
	{
		delete[] typeOfVehicle;
		typeOfVehicle = nullptr;
	}
	deepCopy(typeOfVehicle, type);
}
char * Vehicle::getCompanyName() const
{
	char * temp = { nullptr };				//not returning original memory handler
	if (companyName)
		deepCopy(temp, companyName);

	return temp;
}
char * Vehicle::getColor() const
{
	char * temp = { nullptr };
	if (color)
		deepCopy(temp, color);

	return temp;
}
int Vehicle::getNumberOfWheels() const
{
	return numberOfWheels;
}
int Vehicle::getPowerCC() const
{
	return powerCC;
}
char * Vehicle::getTypeOfVehicle() const
{
	char * temp = { nullptr };
	if (typeOfVehicle)
		deepCopy(temp, typeOfVehicle);

	return temp;
}
void Vehicle::display()const
{
	cout << companyName << "   " << color << "   " << numberOfWheels << "   " << powerCC << "   " << typeOfVehicle << endl;
}
Vehicle::~Vehicle()
{
	if (companyName)
	{
		delete[] companyName;
		companyName = nullptr;
	}
	if (color)
	{
		delete[] color;
		color = nullptr;
	}
	if (typeOfVehicle)
	{
		delete[] typeOfVehicle;
		typeOfVehicle = nullptr;
	}
}