#include <ctest.h>
#include <libconverter/converter.h>

CTEST(Conversion, length_conversion)
{
    int input = 1;

    int position = 0;

    vector<double> real_elements;

    length(real_elements, input, position);

    vector<double> elements = {
            1,
            0.001,
            1.e+2,
            1.e+3,
            1.e+6,
            1.e+9,
            1.e+9 / 1609350000000e+0,
            (1.e+9 / 1609350000000e+0) / (1 / 1760.0065617e+0),
            ((1.e+9 / 1609350000000e+0) / (1 / 1760.0065617e+0)) / (1 / 3.e+0),
            (((1.e+9 / 1609350000000e+0) / (1 / 1760.0065617e+0)) / (1 / 3.e+0))
                    / (1 / 12.e+0),
            ((((1.e+9 / 1609350000000e+0) / (1 / 1760.0065617e+0))
              / (1 / 3.e+0))
             / (1 / 12.e+0))
                    / 372466929133858300.e+0};

    ASSERT_DBL_NEAR(elements[0], real_elements[0]);
    ASSERT_DBL_NEAR(elements[1], real_elements[1]);
    ASSERT_DBL_NEAR(elements[2], real_elements[2]);
    ASSERT_DBL_NEAR(elements[3], real_elements[3]);
    ASSERT_DBL_NEAR(elements[4], real_elements[4]);
    ASSERT_DBL_NEAR(elements[5], real_elements[5]);
    ASSERT_DBL_NEAR(elements[6], real_elements[6]);
    ASSERT_DBL_NEAR(elements[7], real_elements[7]);
    ASSERT_DBL_NEAR(elements[8], real_elements[8]);
    ASSERT_DBL_NEAR(elements[9], real_elements[9]);
    ASSERT_DBL_NEAR(elements[10], real_elements[10]);
}

CTEST(Conversion, time_conversion)
{
    int input = 1;

    int position = 0;

    vector<double> real_elements;

    temp(real_elements, input, position);

    vector<double> elements
            = {1,
               1.e+3,
               1.e+6,
               1.e+9,
               1.e+12,
               1.e+12 / (6 * 1.e+13),
               1.e+12 / (36 * 1.e+14),
               1.e+12 / (36 * 1.e+14 * 24),
               1.e+12 / (36 * 1.e+14 * 24 * 7),
               1.e+12 / (36 * 1.e+14 * 24 * 7 * (29.5 / 7)),
               1.e+12 / (36 * 1.e+14 * 24 * 7 * (29.5 / 7) * 12)};

    ASSERT_DBL_NEAR(elements[0], real_elements[0]);
    ASSERT_DBL_NEAR(elements[1], real_elements[1]);
    ASSERT_DBL_NEAR(elements[2], real_elements[2]);
    ASSERT_DBL_NEAR(elements[3], real_elements[3]);
    ASSERT_DBL_NEAR(elements[4], real_elements[4]);
    ASSERT_DBL_NEAR(elements[5], real_elements[5]);
    ASSERT_DBL_NEAR(elements[6], real_elements[6]);
    ASSERT_DBL_NEAR(elements[7], real_elements[7]);
    ASSERT_DBL_NEAR(elements[8], real_elements[8]);
    ASSERT_DBL_NEAR(elements[9], real_elements[9]);
    ASSERT_DBL_NEAR(elements[10], real_elements[10]);
}

CTEST(Conversion, weight_conversion)
{
    int input = 1;

    int position = 0;

    vector<double> real_elements;

    weight_calc(real_elements, input, position);

    vector<double> elements = {
            1,
            1.e+3,
            1.e+6,
            1.e-3,
            1.e-3 / 1.01604608e+0,
            (1.e-3 * 1.12e+0) / 1.01604608e+0,
            (1.e-3 * 1.12e+0 * 2000e+0) / 1.01604608e+0,
            (1.e-3 * 1.12e+0 * 2000e+0 * 16e+0) / 1.01604608e+0,
            (1.e-3 * 1.12e+0 * 2000e+0 * 16e+0 * 141.7475e+0) / 1.01604608e+0,
            (1.e-3 * 1.12e+0 * 2000e+0 * 16e+0 * 141.7475e+0
             * 1.20442733033504e+23)
                    / 1.01604608e+0};

    ASSERT_DBL_NEAR(elements[0], real_elements[0]);
    ASSERT_DBL_NEAR(elements[1], real_elements[1]);
    ASSERT_DBL_NEAR(elements[2], real_elements[2]);
    ASSERT_DBL_NEAR(elements[3], real_elements[3]);
    ASSERT_DBL_NEAR(elements[4], real_elements[4]);
    ASSERT_DBL_NEAR(elements[5], real_elements[5]);
    ASSERT_DBL_NEAR(elements[6], real_elements[6]);
    ASSERT_DBL_NEAR(elements[7], real_elements[7]);
    ASSERT_DBL_NEAR(elements[8], real_elements[8]);
    ASSERT_DBL_NEAR(elements[9], real_elements[9]);
}

CTEST(Conversion, time_conversion)
{
    int input = 1;

    int position = 0;

    vector<double> real_elements;

    temp(real_elements, input, position);

    vector<double> elements
            = {1,
               1.e+3,
               1.e+6,
               1.e+9,
               1.e+12,
               1.e+12 / (6 * 1.e+13),
               1.e+12 / (36 * 1.e+14),
               1.e+12 / (36 * 1.e+14 * 24),
               1.e+12 / (36 * 1.e+14 * 24 * 7),
               1.e+12 / (36 * 1.e+14 * 24 * 7 * (29.5 / 7)),
               1.e+12 / (36 * 1.e+14 * 24 * 7 * (29.5 / 7) * 12)};

    ASSERT_DBL_NEAR(elements[0], real_elements[0]);
    ASSERT_DBL_NEAR(elements[1], real_elements[1]);
    ASSERT_DBL_NEAR(elements[2], real_elements[2]);
    ASSERT_DBL_NEAR(elements[3], real_elements[3]);
    ASSERT_DBL_NEAR(elements[4], real_elements[4]);
    ASSERT_DBL_NEAR(elements[5], real_elements[5]);
    ASSERT_DBL_NEAR(elements[6], real_elements[6]);
    ASSERT_DBL_NEAR(elements[7], real_elements[7]);
    ASSERT_DBL_NEAR(elements[8], real_elements[8]);
    ASSERT_DBL_NEAR(elements[9], real_elements[9]);
    ASSERT_DBL_NEAR(elements[10], real_elements[10]);
}
