#pragma once
#include"Vehicle.h"

class Car : public Vehicle
{
	int noOfDoors;
	char* trasmission;
	int noOfSeats;
	static int numberOfCars;

public:
	Car(char * name = nullptr, char * _color = nullptr, int number = 0, int power = 0, char * type = nullptr, int doors = 0, char * trans = nullptr, int seats = 0);
	Car(const Car& obj);
	Car& operator = (const Car& obj);
	void setNoOfDoors(int doors);
	void setTrasmission(char* trans);
	void setNoOfSeats(int seats);
	int getNoOfDoors() const;
	char* getTrasmission() const;
	int getNoOfSeats() const;
	void checkType();
	void display() const;
	~Car();
};