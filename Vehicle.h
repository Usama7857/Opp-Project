#pragma once
#include<iostream>
using namespace std;

int strLength(const char* src)
{
	int length = { 0 };
	for (length; src[length] != '\0'; length++);

	return length;
}

void deepCopy(char* &dest, const char* src)
{
	if (src)
	{
		int size = strLength(src);
		dest = new char[size + 1];

		for (int i = 0; i < size; i++)
		{
			dest[i] = src[i];
		}

		dest[size] = '\0';
	}

	else
	{
		dest = nullptr;
	}
}

class Vehicle
{
private:
	char * companyName;
	char * color;
	int numberOfWheels;
	int powerCC;
	char * typeOfVehicle;
public:
	Vehicle(char * name = nullptr, char * _color = nullptr, int number = 0, int power = 0, char * type = nullptr);	//parameterized ctr with default arguments
	Vehicle(const Vehicle& obj);
	void setCompanyName(const char * name);
	void setColor(const char * _color);
	void setNumberOfWheels(int number);
	void setPowerCC(int power);
	void setTypeOfVehicle(const char * type);
	char * getCompanyName() const;
	char * getColor() const;
	int getNumberOfWheels() const;			//getters should always be const
	int getPowerCC() const;
	char * getTypeOfVehicle() const;
	virtual void checkType() = 0;			//pure virtual function to make abstract class
	virtual void display()const;
	virtual ~Vehicle();			//virtual destructor for parent class
};