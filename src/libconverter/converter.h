#ifndef CONVERTER_LIB
#define CONVERTER_LIB
#include <sstream>
#include <string>
#include <vector>
typedef char gchar;

std::string from_double_to_char(std::vector<double> elements, int i);

double Kelvin_Celsius(double parametr, bool mable);

double In_Fahrenheit(double parametr, bool temp);

double From_Fahrenheit(double parametr, bool temp);

void temp(
        std::vector<double>& elements,
        const char* input_char,
        int position_of_element);

void coeff_param(
        std::vector<double>& elements,
        double input_element,
        int position_of_element,
        int file_num);

int check_strock(std::string str);

int check(
        std::vector<double>& elements,
        const char* a,
        int position_of_element,
        int& file_num);
#endif
