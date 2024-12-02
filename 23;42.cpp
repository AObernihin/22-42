
#include <iostream>
using namespace std;
class Human 
{
	string *PIB ;
    int *age;
	
public:
	Human(int age, string PIB)
	{
		this->age = new int(age);
		this->PIB = new string(PIB);
	}

	Human(const Human& other) {
		this->age = new int(*other.age); 
		this->PIB = new string(*other.PIB);  
	}

	~Human() {
		delete age;
		delete PIB;
	}

	void Show() 
	{
		cout << "age:" << *age << "PIB:" << *PIB << endl;
	}
};



class Apartment {
private:
    Human** humans;
    int numHumans;

public:
   
    Apartment(int numHumans, Human** humansArray) : numHumans(numHumans) {
        humans = new Human * [numHumans];
        for (int i = 0; i < numHumans; ++i) {
            humans[i] = new Human(*humansArray[i]);
        }
    }

   
    Apartment(const Apartment& other) : numHumans(other.numHumans) {
        humans = new Human * [numHumans];
        for (int i = 0; i < numHumans; ++i) {
            humans[i] = new Human(*other.humans[i]);
        }
    }

  
    ~Apartment() {
        for (int i = 0; i < numHumans; ++i) {
            delete humans[i];
        }
        delete[] humans;
    }

    void Show() const {
        for (int i = 0; i < numHumans; ++i) {
            humans[i]->Show();
        }
    }
};

class House {
private:
    Apartment** apartments;
    int numApartments;

public:
   
    House(int numApartments, Apartment** apartmentsArray) : numApartments(numApartments) {
        apartments = new Apartment * [numApartments];
        for (int i = 0; i < numApartments; ++i) {
            apartments[i] = new Apartment(*apartmentsArray[i]);
        }
    }

    
    House(const House& other) : numApartments(other.numApartments) {
        apartments = new Apartment * [numApartments];
        for (int i = 0; i < numApartments; ++i) {
            apartments[i] = new Apartment(*other.apartments[i]);
        }
    }

   
    ~House() {
        for (int i = 0; i < numApartments; ++i) {
            delete apartments[i];
        }
        delete[] apartments;
    }

    void Show() const {
        for (int i = 0; i < numApartments; ++i) {
            apartments[i]->Show();
        }
    }
};



    int main() {
        // Створення людей
        Human* a = new Human(2347, "2347");
        Human* b = new Human(2347, "2347");

        // Створення масиву людей для квартири
        Human* humansArray[] = { a, b };

        // Створення квартири
        Apartment* a1 = new Apartment(2347, humansArray);

        // Створення масиву квартир для будинку
        Apartment* apartmentsArray[] = { a1 };

        // Створення будинку
        House house(1, apartmentsArray);

        // Відображення вмісту будинку
        house.Show();

        // Звільнення пам'яті
        delete a;
        delete b;
        delete a1;

        return 0;
    }



