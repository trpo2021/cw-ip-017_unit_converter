#include "converter.h"
#include <fstream>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#define UNUSED(x) (void)(x);

typedef char gchar;

/*const gchar* from_double_to_char(
        vector<double> elements,
        int i)
{
	double element = elements[i];
	string input_string;
    string temprory;
    stringstream ss;
	cout << "lol" << endl;
    ss << element;

    ss >> input_string;
	
    return input_string.c_str();
}*/

string from_double_to_char(
        vector<double> elements,
        int i)
{
    string temprory;
    stringstream ss;
    ss << elements[i];
    ss >> temprory;
    return temprory;
}

int check(const char* a,vector<double>& elements, int position_of_element, int& file_num) {
	if (atof(a)) {
			coeff_param(elements, atof(a), position_of_element, file_num);
	}
	else return 1;
	return 0;
};

double Kelvin_Celsius(double parametr, bool mable)
{
    return parametr + pow(-1, mable) * 273;
}
double In_Fahrenheit(double parametr, bool temp)
{
    if (temp == true)
        parametr = Kelvin_Celsius(parametr, temp);
    return parametr * 1.8 + 32;
}
double From_Fahrenheit(double parametr, bool temp)
{
    if (temp == true)
        parametr += 459;
    else
        parametr -= 32;
    return parametr / 1.8;
}

void temp(
        vector<double>& elements, double input_element, int position_of_element)
{
    elements.resize(3);
    switch (position_of_element) {
    case 0: {
        elements[0] = input_element;
        elements[1] = Kelvin_Celsius(input_element, false);
        elements[2] = In_Fahrenheit(input_element, false);
        break;
    }
    case 1: {
        elements[0] = Kelvin_Celsius(input_element, true);
        elements[1] = input_element;
        elements[2] = In_Fahrenheit(input_element, true);
        break;
    }
    case 2: {
        elements[0] = From_Fahrenheit(input_element, false);
        ;
        elements[1] = From_Fahrenheit(input_element, true);
        elements[2] = input_element;
        break;
    }
    }
}
string filename[6] = { "..\\src\\res\\length.txt","..\\src\\res\\area.txt","..\\src\\res\\volume.txt","..\\src\\res\\weight.txt","..\\src\\res\\time.txt" };

void coeff_param(vector<double>& elements, double input_element, int position_of_element, int file_num) {
    string str;
    int i = 0;
    vector<double> coefficients;

    ifstream file(filename[file_num].c_str());
	cout << "lol" << endl;
    while (getline(file, str))
    {
		cout << "lol" << endl;
        coefficients.push_back(atof(str.c_str()));
    }

    elements.resize(coefficients.size());
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i];
    }
	int n = coefficients.size() - 1;
    for (i = position_of_element; i < n; i++) {
        elements[i + 1] = elements[i] / coefficients[i + 1];
    }
}
