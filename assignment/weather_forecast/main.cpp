/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ostream>


// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
template<typename T>
double convert_f_to_c(T f) {
    return (f - 32) * 5 / 9;
}

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    std::vector<double> result;
    for (auto i = 0; i < readings.size(); i++) {
        result.push_back(fn(readings[i]));
    }
    return result;
}

void output_to_file(std::string filename, std::string title, std::vector<double> data) {
    std::ofstream file(filename, std::ios::app);
    file << title << std::endl;
    for (auto i = 0; i < data.size(); i++) {
        file << data[i] << " ";
    }
    file << std::endl;
}

template<typename T>
double vector_average(const std::vector<T>& day) {
    double sum = 0;
    for (auto i = 0; i < day.size(); i++) {
        sum += day[i];
    }
    return sum / day.size();
}

double getMax(const std::vector<int>& day) {
    return *std::max_element(day.begin(), day.end());
}

double getMin(const std::vector<int>& day) {
    return *std::min_element(day.begin(), day.end());
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    using namespace std;

    // TODO: Convert temperatures to Celsius and output to output.txt
    string filename = "output.txt";
    ofstream file(filename);
    file << "Temperatures in Celsius" << endl;
    for (auto i = 0; i < readings.size(); i++) {
        for (auto j = 0; j < readings[i].size(); j++) {
            readings[i][j] = convert_f_to_c(readings[i][j]);
            file << readings[i][j] << " ";
        }
        file << endl;
    }

    // TODO: Find the maximum temperature for each day and output to output.txt
    vector<double> max_temps = get_forecast(readings, getMax);

    // How to use lambda function?
    // get_forecast(readings, [](vector<int> day) { 
    //     return *max_element(day.begin(), day.end()); }
    // );

    output_to_file(filename, "Maximum Temperatures", max_temps);


    // TODO: Find the minimum temperature for each day and output to output.txt
    vector<double> min_temps = get_forecast(readings, getMin);
    output_to_file(filename, "Minimum Temperatures", min_temps);

    // TODO: Find the average temperature for each day and output to output.txt
    vector<double> avg_temps = get_forecast(readings, vector_average<int>);
    output_to_file(filename, "Average Temperatures", avg_temps);
    return 0;
}