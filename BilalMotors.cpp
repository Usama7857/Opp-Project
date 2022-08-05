#include "BilalMotors.h"
#include <fstream>

bool matchStr(const char* dest, const char* src)
{
	int size1 = strLength(dest);
	int size2 = strLength(src);
	if (size1 == size2)
	{
		for (int i = { 0 }; i < size1; ++i)
		{
			if (src[i] != dest[i])
				return false;
		}
		return true;
	}
	return false;
}
BilalMotors::BilalMotors()
{
	count = 0;
	for (int i = 0; i < 50; ++i)
	{
		arr[i] = nullptr;		//assigning nullptr to every pointer in the array
	}
}

void BilalMotors::addVehicle(Vehicle *obj)
{
	arr[count] = obj;			//addding vehicles in the array
	count++;
}
int BilalMotors::length() const
{
	return count;
}
void BilalMotors::searchVehicle(char* type)
{
	for (int i = { 0 }; i < count; ++i)
	{
		if (matchStr(arr[i]->getTypeOfVehicle(), type))
		{
			arr[i]->display();				searching vehicle
		}
	}
}

bool BilalMotors::saveData(const char* fileName) const
{
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "File Not Open" << endl;
		return false;
	}

	fout << "Company Name\tType\tColor\tPower" << endl;			//writing data into the file
	for (int i = { 0 }; i < count; ++i)
	{
		fout << arr[i]->getCompanyName() << "\t" << arr[i]->getTypeOfVehicle() << "\t" << arr[i]->getColor() << "\t" << arr[i]->getPowerCC() << endl;
	}

	return true;
}

Vehicle& BilalMotors::operator[](int i)		//indexing operators
{
	if (i >= 0 && i < count)
		return *arr[i];

	return *arr[0];
}

const Vehicle& BilalMotors::operator[](int i) const
{
	if (i >= 0 && i < count)
		return *arr[i];

	return *arr[0];
}


BilalMotors::~BilalMotors()
{
	if (arr)
	{
		for (int i = 0; i < 50; ++i)
		{
			arr[i] = nullptr;			//assigning nullptr because its aggregations
		}
	}
}