#ifndef CONVERTER_LIB
#define CONVERTER_LIB

#include <gtk/gtk.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void weight_calc (vector<double>& elements, double input_element, int position_of_element);

void from_double_to_char (vector<double> elements, int i, const gchar* input_char, GtkEntry* output);

void time (vector<double>& elements, double input_element, int position_of_element);

#endif