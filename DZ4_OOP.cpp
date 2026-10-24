#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class Human
{
private:
	char* name;
	int age;
public:
	
	Human& operator=(const Human& other)
	{
		if (this == &other)
			return *this;

		delete[] name;

		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);

		age = other.age;

		return *this;
	}
	
	Human() :Human("Unknown", 0)
	{
		cout << "\nConstructor" << this << endl;

	}

	Human(const char* name) :Human(name, 0)
	{
		cout << "\nConstructor" << this << endl;

	}

	Human(int age) :Human("Unknown", age)
	{
		cout << "\nConstructor" << this << endl;
	}

	Human(const char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
		cout << "\nConstructor" << this << endl;
	}

	Human(const Human& other)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->age = other.age;
		cout << "\nCopy Constructor" << this << endl;

	}

	~Human()
	{
		cout << "\nDestructor" << this << endl;
		delete[] name;
	}

};

class Apartment
{
private:
	int floor;
	int apt;
	Human* arrHum;
	int countHuman;
public:
	Apartment& operator=(const Apartment& other)
	{
		if (this == &other)
			return *this;

		delete[] arrHum;

		floor = other.floor;
		apt = other.apt;
		countHuman = other.countHuman;
		arrHum = nullptr;

		if (other.arrHum != nullptr && countHuman > 0)
		{
			arrHum = new Human[countHuman];

			for (int i = 0; i < countHuman; i++)
			{
				arrHum[i] = other.arrHum[i];
			}
		}

		return *this;
	}

	Apartment()
	{
		floor = 0;
		apt = 0;
		countHuman = 0;
		arrHum = nullptr;
	}

	Apartment(int floor, int apt, Human* arrHum, int countHuman)
	{
		this->floor = floor;
		this->apt = apt;
		this->countHuman = countHuman;
		this->arrHum = nullptr;

		if (arrHum != nullptr && countHuman > 0)
		{
			this->arrHum = new Human[countHuman];

			for (int i = 0; i < countHuman; i++)
			{
				this->arrHum[i] = arrHum[i];
			}
		}
	}

	Apartment(const Apartment& other)
	{
		this->floor = other.floor;
		this->apt = other.apt;
		this->countHuman = other.countHuman;
		this->arrHum = nullptr;

		if (other.arrHum != nullptr && other.countHuman > 0)
		{
			this->arrHum = new Human[other.countHuman];

			for (int i = 0; i < other.countHuman; i++)
			{
				this->arrHum[i] = other.arrHum[i];
			}
		}
	}

	~Apartment()
	{
		delete[] arrHum;
	}
};

class ApartmentBuilding
{
private:
	char* street;
	int houseNo;
	int entrance;
	Apartment* arrApt;
	int countApt;
public:
	ApartmentBuilding(): ApartmentBuilding("Unknown", 0, 0, nullptr, 0)
	{}
	
	ApartmentBuilding(const char* street, int houseNo, int entrance, Apartment* arrApt, int countApt)
	{
		this->street = new char[strlen(street) + 1];
		strcpy_s(this->street, strlen(street) + 1, street);
		this->houseNo = houseNo;
		this->entrance = entrance;
		this->arrApt = nullptr;

		if (arrApt != nullptr && countApt > 0)
		{
			this->arrApt = new Apartment[countApt];
			for (int i = 0; i < countApt; i++)
			{
				this->arrApt[i] = arrApt[i];
			}
		}

		this->countApt = countApt;
	}

	ApartmentBuilding(const ApartmentBuilding& other)
	{
		this->street = new char[strlen(other.street) + 1];
		strcpy_s(this->street, strlen(other.street) + 1, other.street);

		this->houseNo = other.houseNo;
		this->entrance = other.entrance;
		this->countApt = other.countApt;

		this->arrApt = nullptr;

		if (other.arrApt != nullptr && other.countApt > 0)
		{
			this->arrApt = new Apartment[this->countApt];

			for (int i = 0; i < this->countApt; i++)
			{
				this->arrApt[i] = other.arrApt[i];
			}
		}
	}
	~ApartmentBuilding()
	{
		delete[] street;
		delete[] arrApt;
	}

	
};

int main()
{
	Human humans[1] = { Human("Nazar", 16) };
	Apartment apts[1] = { Apartment(5, 20, humans, 1) };

	ApartmentBuilding b1("Shevchenka", 10, 1, apts, 1);

	ApartmentBuilding b2(b1); 

	return 0;
}
