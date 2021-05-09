//#include <Windows.h>
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

const gchar* Kg = "Kilogram";
const gchar* G = "Gram";
const gchar* Mg = "Miliram";
const gchar* Mt = "Metric Ton";
const gchar* Lt = "Long Ton";
const gchar* St = "Short Ton";
const gchar* Pound = "Pound";
const gchar* Ounce = "Ounce";
const gchar* Car = "Carrat";
const gchar* AMU = "Atomic Mass Unit";

const gchar* M = "Meter";
const gchar* Km = "Kilometer";
const gchar* Cm = "Centimeter";
const gchar* Mm = "Milimeter";
const gchar* Mcm = "Micrometer";
const gchar* Nm = "Nanometer";
const gchar* Mile = "Mile";
const gchar* Yard = "Yard";
const gchar* Foot = "Foot";
const gchar* Inch = "Inch";
const gchar* LY = "Light Year";

const gchar* C = "Celsius";
const gchar* K = "Kelvin";
const gchar* F = "Fahrenheit";

const gchar* SM = "Squer Meter";
const gchar* SKm = "Squer Kilometer";
const gchar* SCm = "Squer Centimeter";
const gchar* SMm = "Squer Milimetern";
const gchar* SMcm = "Squer Micrometer";
const gchar* Hec = "Hectare";
const gchar* SMile = "Squer Mile";
const gchar* SYard = "Squer Yard";
const gchar* SFoot = "Squer Foot";
const gchar* SInch = "Squer Inch";
const gchar* Ac = "Acre";

const gchar* CM = "Cubic Meter";
const gchar* CKm = "Cubic Kilometer";
const gchar* CCm = "Cubic Centimeter";
const gchar* CMm = "Cubic Milimeter";
const gchar* Lit = "Liter";
const gchar* Mlit = "Mililiter";
const gchar* USGallon = "US Gallon";
const gchar* USQuart = "US Quart";
const gchar* USPint = "US Pint";
const gchar* USCup = "US Cup";
const gchar* USFOunce = "US Fluid Ounce";
const gchar* USTableSpoon = "US Table Spoon";
const gchar* ImpGallon = "Imperial Gallon";
const gchar* ImpQuart = "Imperial Quart";
const gchar* ImpPint = "Imperial Pint";
const gchar* ImpFOunce = "Imperial Fluid Ounce";
const gchar* ImpTableSpoon = "Imperial Table Spoon";
const gchar* ImpTeaSpoon = "Imperial Tea Spoon";
const gchar* CMile = "Cubic Mile";
const gchar* CYard = "Cubic Yard";
const gchar* CFoot = "Cubic Foot";
const gchar* CInch = "Cubic Inch";

const gchar* Sec = "Second";
const gchar* Msec = "Milisecond";
const gchar* Mcsec = "Microsecond";
const gchar* Nsec = "Nanosecond";
const gchar* Psec = "Picosecond";
const gchar* Min = "Minute";
const gchar* Hour = "Hour";
const gchar* Day = "Day";
const gchar* Week = "Week";
const gchar* Month = "Month";
const gchar* Year = "Year";

#define UNUSED(x) (void)(x);

void change_button_clicked(GtkWidget* widget, gpointer data)
{
    if (gtk_combo_box_get_active(types) == 0) {
        gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);

        gtk_combo_box_text_append_text(object_of_types1, M);
        gtk_combo_box_text_append_text(object_of_types1, Km);
        gtk_combo_box_text_append_text(object_of_types1, Cm);
        gtk_combo_box_text_append_text(object_of_types1, Mm);
        gtk_combo_box_text_append_text(object_of_types1, Mcm);
        gtk_combo_box_text_append_text(object_of_types1, Nm);
        gtk_combo_box_text_append_text(object_of_types1, Mile);
        gtk_combo_box_text_append_text(object_of_types1, Yard);
        gtk_combo_box_text_append_text(object_of_types1, Foot);
        gtk_combo_box_text_append_text(object_of_types1, Inch);
        gtk_combo_box_text_append_text(object_of_types1, LY);

        gtk_combo_box_text_append_text(object_of_types2, M);
        gtk_combo_box_text_append_text(object_of_types2, Km);
        gtk_combo_box_text_append_text(object_of_types2, Cm);
        gtk_combo_box_text_append_text(object_of_types2, Mm);
        gtk_combo_box_text_append_text(object_of_types2, Mcm);
        gtk_combo_box_text_append_text(object_of_types2, Nm);
        gtk_combo_box_text_append_text(object_of_types2, Mile);
        gtk_combo_box_text_append_text(object_of_types2, Yard);
        gtk_combo_box_text_append_text(object_of_types2, Foot);
        gtk_combo_box_text_append_text(object_of_types2, Inch);
        gtk_combo_box_text_append_text(object_of_types2, LY);
    }
    if (gtk_combo_box_get_active(types) == 1) {
        gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);

        gtk_combo_box_text_append_text(object_of_types1, C);
        gtk_combo_box_text_append_text(object_of_types1, K);
        gtk_combo_box_text_append_text(object_of_types1, F);

        gtk_combo_box_text_append_text(object_of_types2, C);
        gtk_combo_box_text_append_text(object_of_types2, K);
        gtk_combo_box_text_append_text(object_of_types2, F);
    }
    if (gtk_combo_box_get_active(types) == 2) {
        gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);

        gtk_combo_box_text_append_text(object_of_types1, SM);
        gtk_combo_box_text_append_text(object_of_types1, SKm);
        gtk_combo_box_text_append_text(object_of_types1, SCm);
        gtk_combo_box_text_append_text(object_of_types1, SMm);
        gtk_combo_box_text_append_text(object_of_types1, SMcm);
        gtk_combo_box_text_append_text(object_of_types1, Hec);
        gtk_combo_box_text_append_text(object_of_types1, SMile);
        gtk_combo_box_text_append_text(object_of_types1, SYard);
        gtk_combo_box_text_append_text(object_of_types1, SFoot);
        gtk_combo_box_text_append_text(object_of_types1, SInch);
        gtk_combo_box_text_append_text(object_of_types1, Ac);

        gtk_combo_box_text_append_text(object_of_types2, SM);
        gtk_combo_box_text_append_text(object_of_types2, SKm);
        gtk_combo_box_text_append_text(object_of_types2, SCm);
        gtk_combo_box_text_append_text(object_of_types2, SMm);
        gtk_combo_box_text_append_text(object_of_types2, SMcm);
        gtk_combo_box_text_append_text(object_of_types2, Hec);
        gtk_combo_box_text_append_text(object_of_types2, SMile);
        gtk_combo_box_text_append_text(object_of_types2, SYard);
        gtk_combo_box_text_append_text(object_of_types2, SFoot);
        gtk_combo_box_text_append_text(object_of_types2, SInch);
        gtk_combo_box_text_append_text(object_of_types2, Ac);
    }
    if (gtk_combo_box_get_active(types) == 3) {
        gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);

        gtk_combo_box_text_append_text(object_of_types1, CM);
        gtk_combo_box_text_append_text(object_of_types1, CKm);
        gtk_combo_box_text_append_text(object_of_types1, CCm);
        gtk_combo_box_text_append_text(object_of_types1, CMm);
        gtk_combo_box_text_append_text(object_of_types1, Lit);
        gtk_combo_box_text_append_text(object_of_types1, Mlit);
        gtk_combo_box_text_append_text(object_of_types1, USGallon);
        gtk_combo_box_text_append_text(object_of_types1, USQuart);
        gtk_combo_box_text_append_text(object_of_types1, USPint);
        gtk_combo_box_text_append_text(object_of_types1, USCup);
        gtk_combo_box_text_append_text(object_of_types1, USFOunce);
        gtk_combo_box_text_append_text(object_of_types1, USTableSpoon);
        gtk_combo_box_text_append_text(object_of_types1, ImpGallon);
        gtk_combo_box_text_append_text(object_of_types1, ImpQuart);
        gtk_combo_box_text_append_text(object_of_types1, ImpPint);
        gtk_combo_box_text_append_text(object_of_types1, ImpFOunce);
        gtk_combo_box_text_append_text(object_of_types1, ImpTableSpoon);
        gtk_combo_box_text_append_text(object_of_types1, ImpTeaSpoon);
        gtk_combo_box_text_append_text(object_of_types1, CMile);
        gtk_combo_box_text_append_text(object_of_types1, CYard);
        gtk_combo_box_text_append_text(object_of_types1, CFoot);
        gtk_combo_box_text_append_text(object_of_types1, CInch);

        gtk_combo_box_text_append_text(object_of_types2, CM);
        gtk_combo_box_text_append_text(object_of_types2, CKm);
        gtk_combo_box_text_append_text(object_of_types2, CCm);
        gtk_combo_box_text_append_text(object_of_types2, CMm);
        gtk_combo_box_text_append_text(object_of_types2, Lit);
        gtk_combo_box_text_append_text(object_of_types2, Mlit);
        gtk_combo_box_text_append_text(object_of_types2, USGallon);
        gtk_combo_box_text_append_text(object_of_types2, USQuart);
        gtk_combo_box_text_append_text(object_of_types2, USPint);
        gtk_combo_box_text_append_text(object_of_types2, USCup);
        gtk_combo_box_text_append_text(object_of_types2, USFOunce);
        gtk_combo_box_text_append_text(object_of_types2, USTableSpoon);
        gtk_combo_box_text_append_text(object_of_types2, ImpGallon);
        gtk_combo_box_text_append_text(object_of_types2, ImpQuart);
        gtk_combo_box_text_append_text(object_of_types2, ImpPint);
        gtk_combo_box_text_append_text(object_of_types2, ImpFOunce);
        gtk_combo_box_text_append_text(object_of_types2, ImpTableSpoon);
        gtk_combo_box_text_append_text(object_of_types2, ImpTeaSpoon);
        gtk_combo_box_text_append_text(object_of_types2, CMile);
        gtk_combo_box_text_append_text(object_of_types2, CYard);
        gtk_combo_box_text_append_text(object_of_types2, CFoot);
        gtk_combo_box_text_append_text(object_of_types2, CInch);
    }
    if (gtk_combo_box_get_active(types) == 4) {
        gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);

        gtk_combo_box_text_append_text(object_of_types1, Kg);
        gtk_combo_box_text_append_text(object_of_types1, G);
        gtk_combo_box_text_append_text(object_of_types1, Mg);
        gtk_combo_box_text_append_text(object_of_types1, Mt);
        gtk_combo_box_text_append_text(object_of_types1, Lt);
        gtk_combo_box_text_append_text(object_of_types1, St);
        gtk_combo_box_text_append_text(object_of_types1, Pound);
        gtk_combo_box_text_append_text(object_of_types1, Ounce);
        gtk_combo_box_text_append_text(object_of_types1, Car);
        gtk_combo_box_text_append_text(object_of_types1, AMU);

        gtk_combo_box_text_append_text(object_of_types2, Kg);
        gtk_combo_box_text_append_text(object_of_types2, G);
        gtk_combo_box_text_append_text(object_of_types2, Mg);
        gtk_combo_box_text_append_text(object_of_types2, Mt);
        gtk_combo_box_text_append_text(object_of_types2, Lt);
        gtk_combo_box_text_append_text(object_of_types2, St);
        gtk_combo_box_text_append_text(object_of_types2, Pound);
        gtk_combo_box_text_append_text(object_of_types2, Ounce);
        gtk_combo_box_text_append_text(object_of_types2, Car);
        gtk_combo_box_text_append_text(object_of_types2, AMU);
    }
    if (gtk_combo_box_get_active(types) == 5) {
        gtk_combo_box_text_remove_all(object_of_types1);
        gtk_combo_box_text_remove_all(object_of_types2);

        gtk_combo_box_text_append_text(object_of_types1, Sec);
        gtk_combo_box_text_append_text(object_of_types1, Msec);
        gtk_combo_box_text_append_text(object_of_types1, Mcsec);
        gtk_combo_box_text_append_text(object_of_types1, Nsec);
        gtk_combo_box_text_append_text(object_of_types1, Psec);
        gtk_combo_box_text_append_text(object_of_types1, Min);
        gtk_combo_box_text_append_text(object_of_types1, Hour);
        gtk_combo_box_text_append_text(object_of_types1, Day);
        gtk_combo_box_text_append_text(object_of_types1, Week);
        gtk_combo_box_text_append_text(object_of_types1, Month);
        gtk_combo_box_text_append_text(object_of_types1, Year);

        gtk_combo_box_text_append_text(object_of_types2, Sec);
        gtk_combo_box_text_append_text(object_of_types2, Msec);
        gtk_combo_box_text_append_text(object_of_types2, Mcsec);
        gtk_combo_box_text_append_text(object_of_types2, Nsec);
        gtk_combo_box_text_append_text(object_of_types2, Psec);
        gtk_combo_box_text_append_text(object_of_types2, Min);
        gtk_combo_box_text_append_text(object_of_types2, Hour);
        gtk_combo_box_text_append_text(object_of_types2, Day);
        gtk_combo_box_text_append_text(object_of_types2, Week);
        gtk_combo_box_text_append_text(object_of_types2, Month);
        gtk_combo_box_text_append_text(object_of_types2, Year);
    }
    UNUSED(widget);
    UNUSED(data);
}

void calc_button_clicked(GtkWidget* widget, gpointer data)
{
    const gchar* input_char = gtk_entry_get_text(input);
    vector<double> elements(1);
    double input_element = strtod(input_char, NULL);

    if (gtk_combo_box_get_active(types) == 0) {
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), M)
            == 0) {
            ;
        } // lenght(elements,input_element,0);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Km)
            == 0) {
            ;
        } // lenght(elements,input_element,1);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Cm)
            == 0) {
            ;
        } // lenght(elements,input_element,2);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mm)
            == 0) {
            ;
        } // lenght(elements,input_element,3);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mcm)
            == 0) {
            ;
        } // lenght(elements,input_element,4);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Nm)
            == 0) {
            ;
        } // lenght(elements,input_element,5);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mile)
            == 0) {
            ;
        } // lenght(elements,input_element,6);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Yard)
            == 0) {
            ;
        } // lenght(elements,input_element,7);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Foot)
            == 0) {
            ;
        } // lenght(elements,input_element,8);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Inch)
            == 0) {
            ;
        } // lenght(elements,input_element,9);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), LY)
            == 0) {
            ;
        } // lenght(elements,input_element,10);

        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), M)
            == 0) {
            ;
        } // from_double_to_char(elements, 0, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Km)
            == 0) {
            ;
        } // from_double_to_char(elements, 1, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Cm)
            == 0) {
            ;
        } // from_double_to_char(elements, 2, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mm)
            == 0) {
            ;
        } // from_double_to_char(elements, 3, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mcm)
            == 0) {
            ;
        } // from_double_to_char(elements, 4, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Nm)
            == 0) {
            ;
        } // from_double_to_char(elements, 5, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mile)
            == 0) {
            ;
        } // from_double_to_char(elements, 6, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Yard)
            == 0) {
            ;
        } // from_double_to_char(elements, 7, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Foot)
            == 0) {
            ;
        } // from_double_to_char(elements, 8, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Inch)
            == 0) {
            ;
        } // from_double_to_char(elements, 9, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), LY)
            == 0) {
            ;
        } // from_double_to_char(elements, 10, input_char, output);
        {
            ;
        }
    }
    if (gtk_combo_box_get_active(types) == 1) {
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), C)
            == 0) {
            ;
        } // temp(elements,input_element,0);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), K)
            == 0) {
            ;
        } // temp(elements,input_element,1);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), F)
            == 0) {
            ;
        } // temp(elements,input_element,2);

        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), C)
            == 0) {
            ;
        } // from_double_to_char(elements, 0, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), K)
            == 0) {
            ;
        } // from_double_to_char(elements, 1, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), F)
            == 0) {
            ;
        } // from_double_to_char(elements, 2, input_char, output);
        {
            ;
        }
    }
    if (gtk_combo_box_get_active(types) == 2) {
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SM)
            == 0) {
            ;
        } // area(elements,input_element,0);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SKm)
            == 0) {
            ;
        } // area(elements,input_element,1);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SCm)
            == 0) {
            ;
        } // area(elements,input_element,2);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SMm)
            == 0) {
            ;
        } // area(elements,input_element,3);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SMm)
            == 0) {
            ;
        } // area(elements,input_element,4);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Hec)
            == 0) {
            ;
        } // area(elements,input_element,5);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SMile)
            == 0) {
            ;
        } // area(elements,input_element,6);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SYard)
            == 0) {
            ;
        } // area(elements,input_element,7);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SFoot)
            == 0) {
            ;
        } // area(elements,input_element,8);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), SInch)
            == 0) {
            ;
        } // area(elements,input_element,9);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Ac)
            == 0) {
            ;
        } // area(elements,input_element,10);

        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SM)
            == 0) {
            ;
        } // from_double_to_char(elements, 0, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SKm)
            == 0) {
            ;
        } // from_double_to_char(elements, 1, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SCm)
            == 0) {
            ;
        } // from_double_to_char(elements, 2, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SMm)
            == 0) {
            ;
        } // from_double_to_char(elements, 3, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SMm)
            == 0) {
            ;
        } // from_double_to_char(elements, 4, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Hec)
            == 0) {
            ;
        } // from_double_to_char(elements, 5, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SMile)
            == 0) {
            ;
        } // from_double_to_char(elements, 6, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SYard)
            == 0) {
            ;
        } // from_double_to_char(elements, 7, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SFoot)
            == 0) {
            ;
        } // from_double_to_char(elements, 8, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), SInch)
            == 0) {
            ;
        } // from_double_to_char(elements, 9, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Ac)
            == 0) {
            ;
        } // from_double_to_char(elements, 10, input_char, output);
        {
            ;
        }
    }
    if (gtk_combo_box_get_active(types) == 3) {
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CM)
            == 0) {
            ;
        } // volume(elements,input_element,0);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CKm)
            == 0) {
            ;
        } // volume(elements,input_element,1);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CCm)
            == 0) {
            ;
        } // volume(elements,input_element,2);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CMm)
            == 0) {
            ;
        } // volume(elements,input_element,3);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Lit)
            == 0) {
            ;
        } // volume(elements,input_element,4);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mlit)
            == 0) {
            ;
        } // volume(elements,input_element,5);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   USGallon)
            == 0) {
            ;
        } // volume(elements,input_element,6);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   USQuart)
            == 0) {
            ;
        } // volume(elements,input_element,7);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), USPint)
            == 0) {
            ;
        } // volume(elements,input_element,8);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), USCup)
            == 0) {
            ;
        } // volume(elements,input_element,9);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   USFOunce)
            == 0) {
            ;
        } // volume(elements,input_element,10);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   USTableSpoon)
            == 0) {
            ;
        } // volume(elements,input_element,11);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   ImpGallon)
            == 0) {
            ;
        } // volume(elements,input_element,12);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   ImpQuart)
            == 0) {
            ;
        } // volume(elements,input_element,13);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   ImpPint)
            == 0) {
            ;
        } // volume(elements,input_element,14);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   ImpFOunce)
            == 0) {
            ;
        } // volume(elements,input_element,15);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   ImpTableSpoon)
            == 0) {
            ;
        } // volume(elements,input_element,16);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1),
                   ImpTeaSpoon)
            == 0) {
            ;
        } // volume(elements,input_element,17);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CMile)
            == 0) {
            ;
        } // area(elements,input_element,18);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CYard)
            == 0) {
            ;
        } // area(elements,input_element,19);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CFoot)
            == 0) {
            ;
        } // area(elements,input_element,20);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), CInch)
            == 0) {
            ;
        } // area(elements,input_element,21);

        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CM)
            == 0) {
            ;
        } // from_double_to_char(elements, 0, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CKm)
            == 0) {
            ;
        } // from_double_to_char(elements, 1, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CCm)
            == 0) {
            ;
        } // from_double_to_char(elements, 2, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CMm)
            == 0) {
            ;
        } // from_double_to_char(elements, 3, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Lit)
            == 0) {
            ;
        } // from_double_to_char(elements, 4, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mlit)
            == 0) {
            ;
        } // from_double_to_char(elements, 5, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   USGallon)
            == 0) {
            ;
        } // from_double_to_char(elements, 6, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   USQuart)
            == 0) {
            ;
        } // from_double_to_char(elements, 7, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), USPint)
            == 0) {
            ;
        } // from_double_to_char(elements, 8, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), USCup)
            == 0) {
            ;
        } // from_double_to_char(elements, 9, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   USFOunce)
            == 0) {
            ;
        } // from_double_to_char(elements, 10, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   USTableSpoon)
            == 0) {
            ;
        } // from_double_to_char(elements, 11, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   ImpGallon)
            == 0) {
            ;
        } // from_double_to_char(elements, 12, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   ImpQuart)
            == 0) {
            ;
        } // from_double_to_char(elements, 13, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   ImpPint)
            == 0) {
            ;
        } // from_double_to_char(elements, 14, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   ImpFOunce)
            == 0) {
            ;
        } // from_double_to_char(elements, 15, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   ImpTableSpoon)
            == 0) {
            ;
        } // from_double_to_char(elements, 16, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2),
                   ImpTeaSpoon)
            == 0) {
            ;
        } // from_double_to_char(elements, 17, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CMile)
            == 0) {
            ;
        } // from_double_to_char(elements, 18, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CYard)
            == 0) {
            ;
        } // from_double_to_char(elements, 19, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CFoot)
            == 0) {
            ;
        } // from_double_to_char(elements, 20, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), CInch)
            == 0) {
            ;
        } // from_double_to_char(elements, 21, input_char, output);
        {
            ;
        }
    }
    if (gtk_combo_box_get_active(types) == 4) {
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Kg)
            == 0)
            weight_calc(elements, input_element, 0);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), G)
            == 0)
            weight_calc(elements, input_element, 1);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mg)
            == 0)
            weight_calc(elements, input_element, 2);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mt)
            == 0)
            weight_calc(elements, input_element, 3);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Lt)
            == 0)
            weight_calc(elements, input_element, 4);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), St)
            == 0)
            weight_calc(elements, input_element, 5);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Pound)
            == 0)
            weight_calc(elements, input_element, 6);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Ounce)
            == 0)
            weight_calc(elements, input_element, 7);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Car)
            == 0)
            weight_calc(elements, input_element, 8);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), AMU)
            == 0)
            weight_calc(elements, input_element, 9);

        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Kg)
            == 0)
            from_double_to_char(elements, 0, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), G)
            == 0)
            from_double_to_char(elements, 1, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mg)
            == 0)
            from_double_to_char(elements, 2, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mt)
            == 0)
            from_double_to_char(elements, 3, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Lt)
            == 0)
            from_double_to_char(elements, 4, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), St)
            == 0)
            from_double_to_char(elements, 5, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Pound)
            == 0)
            from_double_to_char(elements, 6, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Ounce)
            == 0)
            from_double_to_char(elements, 7, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Car)
            == 0)
            from_double_to_char(elements, 8, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), AMU)
            == 0)
            from_double_to_char(elements, 9, input_char, output);
    }
    if (gtk_combo_box_get_active(types) == 5) {
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Sec)
            == 0)
            time(elements, input_element, 0);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Msec)
            == 0)
            time(elements, input_element, 1);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Mcsec)
            == 0)
            time(elements, input_element, 2);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Nsec)
            == 0)
            time(elements, input_element, 3);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Psec)
            == 0)
            time(elements, input_element, 4);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Min)
            == 0)
            time(elements, input_element, 5);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Hour)
            == 0)
            time(elements, input_element, 6);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Day)
            == 0)
            time(elements, input_element, 7);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Week)
            == 0)
            time(elements, input_element, 8);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Month)
            == 0)
            time(elements, input_element, 9);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types1), Year)
            == 0)
            time(elements, input_element, 10);

        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Sec)
            == 0)
            from_double_to_char(elements, 0, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Msec)
            == 0)
            from_double_to_char(elements, 1, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Mcsec)
            == 0)
            from_double_to_char(elements, 2, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Nsec)
            == 0)
            from_double_to_char(elements, 3, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Psec)
            == 0)
            from_double_to_char(elements, 4, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Min)
            == 0)
            from_double_to_char(elements, 5, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Hour)
            == 0)
            from_double_to_char(elements, 6, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Day)
            == 0)
            from_double_to_char(elements, 7, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Week)
            == 0)
            from_double_to_char(elements, 8, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Month)
            == 0)
            from_double_to_char(elements, 9, input_char, output);
        if (strcmp(gtk_combo_box_text_get_active_text(object_of_types2), Year)
            == 0)
            from_double_to_char(elements, 10, input_char, output);
    }
    UNUSED(input_element);
    UNUSED(widget);
    UNUSED(data);
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
    //::ShowWindow (::GetConsoleWindow (), SW_HIDE);

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