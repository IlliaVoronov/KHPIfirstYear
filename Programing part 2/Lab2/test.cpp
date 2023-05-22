#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using std::strlen;
using std::strcpy;  
using std::cout;
using std::endl;

const int MAX_COUNT = 100; // Maximum number of cities

// The class must be declared so that the pointer can be created:
class Country;

// Class to represent the city
class City
{
    // Overloaded operator to output to a stream
    friend std::ostream& operator<<(std::ostream& out, const City& city);
private:
    char *name = nullptr;      // city name
    Country *country = nullptr;// pointer to the location country
    char *region = nullptr;    // the name of the region
    int population = 0;        // population
public:
    // Constructors:
    City() { }
    City(const char* name, Country* country, const char* region, int population);
    City(const City& city);

    ~City(); // destructor

    // Getters:
    const char* getName() const { return name; }
    Country* getCountry() const { return country; }
    const char* getRegion() const { return region; }
    int getPopulation() const { return population; }

    // Setters:
    void setName(const char* name);
    void setRegion(const char* region);
    void setCountry(Country* country) { this->country = country; }
    void setPopulation(int population) { this->population = population; }

    // Overloaded assignment operator
    const City& operator=(const City& city);
};

// Constructor with parameters is implemented by calling setters
City::City(const char* name, Country* country, const char* region, int population)
{
    setName(name);
    setCountry(country);
    setRegion(region);
    setPopulation(population);
}

// Copy constructor
City::City(const City& city)
{
    name = new char[strlen(city.name) + 1];
    strcpy(name, city.name);
    region = new char[strlen(city.region) + 1];
    strcpy(region, city.region);
    country = city.country;
    population = city.population;
}

// Remove city and region names from memory (if arrays were created)
City::~City() 
{
    if (name != nullptr)
    {
        delete[] name;
    }
    if (region != nullptr)
    {
        delete[] region;
    }
}

// Remove the previous name of the city, create a new array and put the new name
void City::setName(const char* name)
{
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Remove the previous name of the region, create a new array and put the new name
void City::setRegion(const char* region)
{
    if (this->region != nullptr)
    {
        delete[] this->region;
    }
    this->region = new char[strlen(region) + 1];
    strcpy(this->region, region);
}

// We implement an overloaded assignment operator by calling setters
const City& City::operator=(const City& city)
{
    if (&city != this)
    {
        setName(city.name);
        setCountry(city.country);
        setRegion(city.region);
        setPopulation(city.population);
    }
    return *this;
}

// Overloaded operation of comparing two cities
bool operator>(const City& c1, const City& c2)
{
    return c1.getPopulation() > c2.getPopulation();
}

// Class to represent the country
class Country
{
    // Overloaded operator to output to a stream
    friend std::ostream& operator<<(std::ostream& out, const Country& country)
    {
        out << country.name << endl;
        for (int i = 0; i < country.count; i++)
        {
            out << *(country.cities[i]) << endl;
        }
        out << endl;
        return out;
    }
private:
    char name[40];                 // name of country
    City *cities[MAX_COUNT] = { }; // array of pointers to cities
    int count = 0;                 // number of pointers in the array
public:
    // Constructors:
    Country() { }
    Country(const char* name) { setName(name); }

    const char* getName() const { return name; } // getter

    // Overloaded operator for getting array elements
    City* operator[](int index) const { return cities[index]; }

    // Setters:
    void setName(const char* name) { strcpy(this->name, name); }
    void setStites(City* cities[], int  count);

    void sortByPopulation(); // Sort by population
};

// Fill the array of cities
void Country::setStites(City* cities[], int  count)
{
    this->count = count;
    for (int i = 0; i < count; i++)
    {
        this->cities[i] = cities[i];
        this->cities[i]->setCountry(this);
    }
}

// Sort by population
void Country::sortByPopulation()
{
    bool mustSort = true; // repeat sorting 
                          // if mustSort is true
    do
    {
        mustSort = false;
        for (int i = 0; i < count - 1; i++)
        {
            // Dereferencing 
            // because we can compare objects, not pointers:
            if (*(cities[i]) > *(cities[i + 1]))
                // Exchange items
            {
                City* temp = cities[i];
                cities[i] = cities[i + 1];
                cities[i + 1] = temp;
                mustSort = true;
            }
        }
    } while (mustSort);
}

// Overloaded operator for output to a stream
std::ostream& operator<<(std::ostream& out, const City& city)
{
    char buffer[300];
    sprintf(buffer, "City: %s.\tCountry: %s.\tRegion: %s.\tPopulation: %d",
        city.name, city.country->getName(), city.region, city.population);
    out << buffer;
    return out;
}

// Helper function for filling an array of pointers to cities
void createStites(City *cities[])
{
    cities[0] = new City("Kharkiv", nullptr, "Kharkiv region", 1421125);
    cities[1] = new City("Poltava", nullptr, "Poltava region", 284942);
    cities[2] = new City("Lozova", nullptr, "Kharkiv region", 54618);
    cities[3] = new City("Sumy", nullptr, "Sumy region", 264753);
}

int main()
{
    const int realCount = 4;     // we work with four cities
    City *cities[realCount];     // create an array of pointers to cities   
    createStites(cities);        // fill the array
    Country country = "Ukraine"; // create the Country object,
                                 // call the constructor with one parameter
    country.setStites(cities, realCount); // copy the cities to the Country object
    cout << country << endl;     // output all data
    cout << *country[0] << endl; // display information about the city by index
    country.sortByPopulation();  // sort
    cout << country << endl;     // output all data
    // Remove cities stored in array of pointers to cities
    for (int i = 0; i < realCount; i++)
    {
        delete cities[i];
    }
    return 0;
}