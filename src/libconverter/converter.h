#ifndef CONVERTER_LIB
#define CONVERTER_LIB
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef char gchar;

string from_double_to_char(vector<double> elements, int i);

double Kelvin_Celsius(double parametr, bool mable);

double In_Fahrenheit(double parametr, bool temp);

double From_Fahrenheit(double parametr, bool temp);

void temp(
        vector<double>& elements,
        const char* input_char,
        int position_of_element);

void coeff_param(
        vector<double>& elements,
        double input_element,
        int position_of_element,
        int file_num);

int check_strock(string str);

int check(
        vector<double>& elements,
        const char* a,
        int position_of_element,
        int& file_num);
#endif
