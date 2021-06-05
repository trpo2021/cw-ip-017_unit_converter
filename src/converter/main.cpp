#include <glib.h>
#include <gtk/gtk.h>
#include <iostream>
#include <libconverter/converter.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#define UI_FILE "../src/converter/Unit_converter.glade"
GtkBuilder* builder;
GtkWidget* mainflow;
GtkFixed* chest;
GtkButton* calc_button;
GtkButton* change_button;
GtkEntry* input;
GtkEntry* output;
GtkComboBox* types;
GtkComboBoxText* object_of_types1;
GtkComboBoxText* object_of_types2;
GtkListStore* liststore1;
GtkImage* thing;
GtkCellRendererText* lenght1;
GtkCellRendererText* temp1;
GtkCellRendererText* area1;
GtkCellRendererText* volume1;
GtkCellRendererText* weight1;
GtkCellRendererText* time_not_timeh;

GtkComboBoxText *Types[2] = { object_of_types1, object_of_types2 };



int size_units[6] = { 11, 3, 11, 17, 10, 11 };


const gchar* Lenght[11]
        = {"Meter",
           "Kilometer",
           "Centimeter",
           "Milimeter",
           "Micrometer",
           "Nanometer",
           "Mile",
           "Yard",
           "Foot",
           "Inch",
           "Light Year"};
const gchar* Temp[3] = {"Celsius", "Kelvin", "Fahrenheit"};
const gchar* Area[11]
        = {"Squer Meter",
           "Squer Kilometer",
           "Squer Centimeter",
           "Squer Milimeter",
           "Squer Micrometer",
           "Hectare",
           "Squer Mile",
           "Squer Yard",
           "Squer Foot",
           "Squer Inch",
           "Acre"};
const gchar* Volume[17]
        = {"Cubic Meter",
           "Cubic Kilometer",
           "Cubic Centimeter",
           "Cubic Milimeter",
           "Liter",
           "Mililiter",
           "US Gallon",
           "US Quart",
           "US Pint",
           "US Cup",
           "US Fluid Ounce",
           "US Table Spoon",
           "US Tea Spoon",
           "Cubic Mile",
           "Cubic Yard",
           "Cubic Foot",
           "Cubic Inch"};
const gchar* Weight[10]
        = {"Kilogram",
           "Gram",
           "Miliram",
           "Metric Ton",
           "Long Ton",
           "Short Ton",
           "Pound",
           "Ounce",
           "Carrat",
           "Atomic Mass Unit"};
const gchar* Time[11]
        = {"Second",
           "Milisecond",
           "Microsecond",
           "Nanosecond",
           "Picosecond",
           "Minute",
           "Hour",
           "Day",
           "Week",
           "Month",
           "Year"};


const gchar** Units[6] = {Lenght, Temp, Area, Volume, Weight, Time};

#define UNUSED(x) (void)(x);

void change_button_clicked(GtkWidget* widget, gpointer data)
{
	gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);
	
	int type = gtk_combo_box_get_active(types);

	for(int i = 0; i < size_units[type] ; ++i)
			gtk_combo_box_text_append_text(object_of_types1, Units[type][i]);
	for(int i = 0; i < size_units[type] ; ++i)
			gtk_combo_box_text_append_text(object_of_types2, Units[type][i]);
    UNUSED(widget);
    UNUSED(data);
}

void calc_button_clicked(GtkWidget* widget, gpointer data)
{
	if (gtk_combo_box_text_get_active_text(object_of_types1) != NULL && gtk_combo_box_text_get_active_text(object_of_types2) != NULL){
	int type = gtk_combo_box_get_active(types);
	int i;
	std::string input_string;
        const char* input_char = gtk_entry_get_text(input);
	std::vector<double> elements(1);
	bool pass = true;
		
	for(i = 0; i < size_units[type]; ++i){

		if(strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Units[type][i]) == 0){
			
			if(type!=1){ if(check(elements,input_char,i,type)){ gtk_entry_set_text(output, "Uncorrectly input");pass = false;}}
			else
			{temp(elements, input_char, i); 
			input_string = input_char;
                        if (check_strock(input_string) == 0 || input_string == ""){
				gtk_entry_set_text(output, "Uncorrectly input"); 
				pass = false;
				}
			}
		}
	}
	for(i = 0; i < size_units[type]; ++i){
		if(strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Units[type][i]) == 0 && pass == true){
			input_string = from_double_to_char(elements, i);
			input_char = input_string.c_str();
			gtk_entry_set_text(output, input_char);
	}
	}
    UNUSED(widget);
    UNUSED(data);
	}
}

static gboolean cb_delete(GtkWidget* window, gpointer data)
{
    gtk_main_quit();
    return FALSE;
    UNUSED(window);
    UNUSED(data);
}

int main(int argc, char* argv[])
{

    GError* error = NULL;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    if (!gtk_builder_add_from_file(builder, UI_FILE, &error)) {
        g_warning("%s", error->message);
        g_free(error);
        return 1;
    }
    mainflow = GTK_WIDGET(gtk_builder_get_object(builder, "mainflow"));
    chest = GTK_FIXED(gtk_builder_get_object(builder, "chest"));
    calc_button = GTK_BUTTON(gtk_builder_get_object(builder, "calc_button"));
    change_button
            = GTK_BUTTON(gtk_builder_get_object(builder, "change_button"));
    input = GTK_ENTRY(gtk_builder_get_object(builder, "input"));
    output = GTK_ENTRY(gtk_builder_get_object(builder, "output"));
    types = GTK_COMBO_BOX(gtk_builder_get_object(builder, "types"));
    object_of_types1 = GTK_COMBO_BOX_TEXT(
            gtk_builder_get_object(builder, "object_of_types1"));
    object_of_types2 = GTK_COMBO_BOX_TEXT(
            gtk_builder_get_object(builder, "object_of_types2"));
    liststore1 = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));
    thing = GTK_IMAGE(gtk_builder_get_object(builder, "thing"));
    lenght1 = GTK_CELL_RENDERER_TEXT(gtk_builder_get_object(builder, "lenght"));
    temp1 = GTK_CELL_RENDERER_TEXT(gtk_builder_get_object(builder, "temp"));
    area1 = GTK_CELL_RENDERER_TEXT(gtk_builder_get_object(builder, "area"));
    volume1 = GTK_CELL_RENDERER_TEXT(gtk_builder_get_object(builder, "volume"));
    weight1 = GTK_CELL_RENDERER_TEXT(gtk_builder_get_object(builder, "weight"));
    time_not_timeh = GTK_CELL_RENDERER_TEXT(
            gtk_builder_get_object(builder, "time_not_timeh"));

    gtk_builder_connect_signals(builder, NULL);

    g_signal_connect(
            G_OBJECT(calc_button),
            "clicked",
            G_CALLBACK(calc_button_clicked),
            NULL);
    g_signal_connect(
            G_OBJECT(change_button),
            "clicked",
            G_CALLBACK(change_button_clicked),
            NULL);
    g_signal_connect(
            G_OBJECT(mainflow), "delete-event", G_CALLBACK(cb_delete), NULL);

    gtk_widget_show(mainflow);
    gtk_main();
    return 0;
}
