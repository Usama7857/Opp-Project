#pragma once
#include"Vehicle.h"

class Bike : public Vehicle
{
private:
	double height;
	bool selfStart;
	bool diskBrake;
	static int numberOfBikes;

public:
	Bike(char * name = nullptr, char * _color = nullptr, int number = 0, int power = 0, char * type = nullptr, double _height = 0, bool start = {}, bool brake = {});
	Bike(const Bike& obj);
	Bike& operator = (const Bike& obj);
	void setHeight(double _height);
	void setSelfStart(bool start);
	void setDiskBrake(bool brake);
	double getHeight() const;
	bool getSelfStart() const;
	bool getDiskBrake() const;
	int getNumberOfBike() const;
	virtual void checkType();
	virtual void display() const;
	virtual ~Bike();
};

