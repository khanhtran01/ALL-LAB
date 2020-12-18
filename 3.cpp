/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07002_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Mon Apr 22 17:09:40 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07002_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer {
	int value;
public:
    Integer () {}
	// Methods prototypes only
    Integer(int _value);
    Integer operator+(Integer );
    Integer operator+(int );
    Integer operator=(Integer );
    Integer operator=(int );
    Integer operator=(Integer* );
    bool operator==(int );
    bool operator<(Integer );
    bool operator>(Integer );
    operator int() const
    {
        return this->value;
    }
    Integer operator[](Integer k)
    {
        k.operator int();
        return *(this+k);
    }
};

/**
 * Student implement Integer's methods here
*/
Integer::Integer(int _value)
{
    this->value = _value;
}
Integer Integer::operator+(int num)
{
    this->value += num;
    return *this;
}
Integer Integer::operator+(Integer obj)
{
    this->value += obj.value;
    return *this;
}
Integer Integer::operator=(Integer obj)
{
    this->value = obj.value;
    return *this;
}
Integer Integer::operator=(int num)
{
    this->value = num;
    return *this;
}
Integer Integer::operator=(Integer* obj)
{
    this->value = obj->value;
    return *this;
}
bool Integer::operator==(int num)
{
    if (this->value == num)
        return true;
    return false;
}
bool Integer::operator<(Integer obj)
{
    if (this->value < obj.value)
        return true;
    return false;
}
bool Integer::operator>(Integer obj)
{
    if (this->value > obj.value)
        return true;
    return false;
}

Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include"};
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail()) ifs.open(FILENAME, ios::in);
    if (ifs.fail()) return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char* fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char* todoSegment = strstr(fileContent ,"// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char*);
    for (int i = 0; i < numberOfForbiddenKeyword; i++) { if (strstr(todoSegment, forbiddenKeyword[i])) return false; }
    delete[] fileContent;
    return true;
}

int main(int argc, char* argv[]) {
    if (codeCheck() == false) {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }
    // Section: read testcase
    ///Student may comment out this section for local testing
    if (argc < 2) return 0;
    ifstream fileIn;
    try {
        fileIn.open(argv[1]);
        if (fileIn.fail()) throw "Failed to open file.";
        int numberOfElements;
        fileIn >> numberOfElements;
        Integer* arr = new Integer[numberOfElements];
        int temp;
        for (int i = 0; i < numberOfElements; i++) {
            fileIn >> temp;
            arr[i] = temp;
        }
        cout << max(arr, numberOfElements);
        delete[] arr;
        fileIn.close();
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}