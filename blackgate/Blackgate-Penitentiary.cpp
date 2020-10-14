#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// A utility function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Convert string to int
int stringToInt(std::string s) {
    int newint = 0;
    std::stringstream string1(s);
    string1 >> newint;
    return newint;
}

// Convert string to double
double stringToDouble(std::string s) {
    double newdouble = 0.0;
    newdouble = atof(s.c_str());
    return newdouble;
}

// We need to find if there's a loop
int nthSubstr(int n, const string &s, const string &p) {
    // Find the first occurrence
    string::size_type i = s.find(p);
    int j;
    for (j = 1; j < n && i != string::npos; ++j) {
        i = s.find(p, i + 1); // Find the next occurrence
    }
    if (j == n) {
        return (i);
    } else {
        return (-1);
    }
}

bool compareLengthOfStrings(string a, string b) { return a < b; }

// Sort alphabatically
vector<string> alphabaticallySort(vector<string> a) {
    int n = a.size();
    sort(a.begin(), a.end(), compareLengthOfStrings);
    return a;
}

// Read the inputs from the input file
// And return the output that we need
void readInputs(string inputs, int numberOfPeople) {
    int m = 0, l = 0;
    int heights[numberOfPeople];
    vector<string> names, subStrings;

    // Find the heights of the people through our file
    for (int i = 1; i <= numberOfPeople; i++) {
        string s = inputs.substr(nthSubstr(m + 1, inputs, "\n") + 1,
                                 nthSubstr(m + 2, inputs, "\n") -
                                     nthSubstr(m + 1, inputs, "\n"));
        m = m + 1;
        subStrings.push_back(s);
        heights[i - 1] = (stringToDouble(s.substr(nthSubstr(1, s, " "))));
    }

    // Sort the heights of the people
    quickSort(heights, 0, numberOfPeople - 1);

    for (int i = 1; i <= numberOfPeople; i++) {
        if (heights[i - 1] != heights[i]) {
            for (int k = 0; k < numberOfPeople; k++) {

                string s = subStrings[k];
                string t = to_string(heights[i - 1]);
                size_t pos = s.find(t);

                if (pos != string::npos) {
                    names.push_back(subStrings[k].substr(0, pos));
                }
            }

            l++;
            names = alphabaticallySort(names);

            for (int i = 0; i <= names.size() - 1; i++) {
                cout << names[i];
            }

            int m = 0;

            if (names.size() < 2) {
                cout << l << " " << l;
            } else {
                m = names.size() - 1;
                cout << l << " " << l + m;
            }

            names.clear();
            l = l + m;
            cout << endl;
        }
    }
}

int main(int argc, const char *argv[]) {
    string line, lin;
    ifstream file("input.txt");
    lin = "";

    if (file.is_open()) {
        while (getline(file, line)) {
            lin = lin + line + "\n";
        }
        file.close();
    }

    string s = lin.substr(0, lin.find_first_of("\n"));
    int numberOfPeople = stringToInt(s);
    readInputs(lin, numberOfPeople);

    return 0;
}
