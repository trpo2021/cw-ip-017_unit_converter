#include "converter.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#define UNUSED(x) (void)(x);

typedef char gchar;

std::string from_double_to_char(std::vector<double> elements, int i)
{
    std::string temprory;
    std::stringstream ss;
    ss << elements[i];
    ss >> temprory;
    return temprory;
}

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
        std::vector<double>& elements,
        const char* input_char,
        int position_of_element)
{
    std::string str = input_char;
    if (check_strock(str) == 1 && !str.empty()) {
        double input_element = stod(str);
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
}

std::string filename[6]
        = {"..\\src\\res\\length.txt",
           "",
           "..\\src\\res\\area.txt",
           "..\\src\\res\\volume.txt",
           "..\\src\\res\\weight.txt",
           "..\\src\\res\\time.txt"};

void coeff_param(
        std::vector<double>& elements,
        double input_element,
        int position_of_element,
        int file_num)
{
    std::string str;
    double i = 0;
    std::vector<double> coefficients;

    std::ifstream file(filename[file_num].c_str());

    while (getline(file, str)) {
        coefficients.push_back(std::stod(str.c_str()));
    }
    elements.resize(coefficients.size());
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i];
    }
    for (i = position_of_element; i < coefficients.size() - 1; i++) {
        elements[i + 1] = elements[i] / coefficients[i + 1];
    }
}

int check_strock(std::string str)
{
    std::string str_a = "0123456789,";
    std::string str_char;
    while (str != "") {
        str_char = str.substr(0, 1);
        str.erase(0, 1);
        if (str_a.find(str_char) == std::string::npos) {
            return 0;
        }
    }
    return 1;
}

int check(
        std::vector<double>& elements,
        const char* input_elements,
        int position_of_element,
        int& file_num)
{
    std::string str = input_elements;
    if (check_strock(str) == 1 && !str.empty()) {
        double input = stod(str);
        coeff_param(elements, input, position_of_element, file_num);
    } else
        return 1;
    return 0;
};
