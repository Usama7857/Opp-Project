#pragma once
#include"Vehicle.h"

class BilalMotors
{
private:
	Vehicle *arr[50];			//array of pointers
	int count;				// for indexing and current size
public:
	BilalMotors();
	void addVehicle(Vehicle *);
	void searchVehicle(char*);
	int length() const;
	bool saveData(const char* fileName) const;
	Vehicle& operator[](int index);
	const Vehicle& operator[](int index) const;
	~BilalMotors();
};

