#include "Truck.h"
int Truck::numberOfTrucks;

Truck::Truck(char * name, char * _color, int number, int power, char * type, double size, char* categ, bool drive) : Vehicle(name, _color, number, power, type)
{
	containerSize = size;
	deepCopy(category, categ);
	fourWheelDrive = drive;
	numberOfTrucks++;
}
Truck::Truck(const Truck& obj) : Vehicle(obj)
{
	containerSize = obj.containerSize;
	deepCopy(category, obj.category);
	fourWheelDrive = obj.fourWheelDrive;
	numberOfTrucks++;
}
Truck& Truck::operator = (const Truck& obj)
{
	if (this != &obj)
	{
		containerSize = obj.containerSize;
		deepCopy(category, obj.category);
		fourWheelDrive = obj.fourWheelDrive;
	}

	return *this;
}
void Truck::setContainerSize(double ContainerSize)
{
	containerSize = ContainerSize;
}

void Truck::setCategory(char* Category)
{
	if (category)
	{
		delete[] category;
		category = nullptr;
	}
	deepCopy(category, Category);
}

void Truck::setFourWheelDrive(bool FourWheelDrive)
{
	fourWheelDrive = FourWheelDrive;
}

double Truck::getContainerSize() const
{
	return containerSize;
}

char* Truck::getCategory() const
{
	char * temp = { nullptr };
	deepCopy(temp, category);
	return temp;
}

bool Truck::getFourWheelDrive() const
{
	return fourWheelDrive;
}

void Truck::checkType()
{
	if (getNumberOfWheels() == 6)
	{
		char * ptr = new char[6]{ "Truck" };
		setTypeOfVehicle(ptr);
		delete[] ptr;
		ptr = nullptr;
	}
}

void Truck::display() const
{
	cout << containerSize << endl;
	cout << category << endl;
	cout << fourWheelDrive << endl;
	cout << numberOfTrucks << endl;
}

Truck::~Truck()
{
	numberOfTrucks--;
}