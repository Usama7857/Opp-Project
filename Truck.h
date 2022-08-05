#pragma once
#include"Vehicle.h"

class Truck : public Vehicle
{
private:
	double containerSize;
	char* category;
	bool fourWheelDrive;
	static int numberOfTrucks;

public:
	Truck(char * name = nullptr, char * _color = nullptr, int number = 0, int power = 0, char * type = nullptr, double size = 0, char* categ = nullptr, bool drive = {});
	Truck(const Truck& obj);
	Truck& operator = (const Truck& obj);
	void setContainerSize(double);
	void setCategory(char*);
	void setFourWheelDrive(bool);
	double getContainerSize() const;
	char* getCategory() const;
	bool getFourWheelDrive() const;
	virtual void checkType();
	virtual void display() const;
	virtual ~Truck();
};