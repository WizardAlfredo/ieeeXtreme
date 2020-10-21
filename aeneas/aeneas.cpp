// Input
//
// First input is a single int that contains
// the distance between the center and each letter 1, 100 range
//
// Next up we have the letters with a number in degrees
// withc counterclockwise from the x-axis tells as where
// the letters are 0.0, 360.0 range
//
// Last we have a phrase in english with max 10 ^ 6
// If it has special chars -> ignore them
// small letters -> convert to Capital
//
// Output
//
// A intiger which is the length in cm of the thread needed to
// express the message given in the input as stated above as a decimal, rounded
// up

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<double> convertInputStringToDegrees(string, double *);
int findElements(int, string);
int nthSubstr(int, const string &, const string &);
int computeFinalDistance(int, vector<double>);
double computeDistanceOfTwoPoints(int, double, double);
double calculateDegreesBetweenTwoNodes(double, double);

// function for conbersions
int stringToInt(string);
double stringToDouble(string);

int main(int argc, const char *argv[]) {

    string line, lin;
    lin = "";
    int numOfIterations = 26;

    // Fetch the data from our the input file
    // Store the data in the string called lin
    ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            lin = lin + line + "\n";
        }
        file.close();
    }

    // Find and store the radius from the lin string to the radius variable

    // For testing purposes
    findElements(numOfIterations, lin);

    return 0;
}

// This function replaces all the non alphabetic chars of the string to nothing
// And
// Returns an array of the degrees that corespond with the chars in the string
vector<double> convertInputStringToDegrees(string inputLine, double *degrees) {

    vector<double> d;
    int j = 0;

    // Iterate through the input string and
    // Convert special chars to ''
    // Store the degrees in the d array
    for (int i = 0; i < inputLine.size(); ++i) {
        if ((inputLine[i] >= 'a' && inputLine[i] <= 'z') ||
            (inputLine[i] >= 'A' && inputLine[i] <= 'Z')) {
            if (inputLine[i] >= 'a' && inputLine[i] <= 'z') {
                int tmp = int(inputLine[i]) - 97;
                d.push_back(degrees[tmp]);
                j++;
            } else {
                int tmp = int(inputLine[i]) - 65;
                d.push_back(degrees[tmp]);
                j++;
            }
        }
    }
    return d;
}

double calculateDegreesBetweenTwoNodes(double firstDegree,
                                       double secondDegree) {
    double degreeBetweenTwoNodes = 0.0;

    degreeBetweenTwoNodes = secondDegree - firstDegree;
    if (degreeBetweenTwoNodes < 0) {
        degreeBetweenTwoNodes = -degreeBetweenTwoNodes;
    }
    if (degreeBetweenTwoNodes > 180) {
        degreeBetweenTwoNodes = 360 - degreeBetweenTwoNodes;
    }
    return degreeBetweenTwoNodes;
}

double computeDistanceOfTwoPoints(int radius, double firstDegree,
                                  double secondDegree) {
    double degreesBetweenTwoNodes, distanceBetweenTwoNodes = 0.0;

    degreesBetweenTwoNodes =
        calculateDegreesBetweenTwoNodes(firstDegree, secondDegree);
    degreesBetweenTwoNodes = (180 - degreesBetweenTwoNodes) / 2;
    degreesBetweenTwoNodes = degreesBetweenTwoNodes * 3.14159 / 180;
    distanceBetweenTwoNodes = 2 * radius * cos(degreesBetweenTwoNodes);

    if (distanceBetweenTwoNodes < 0) {
        distanceBetweenTwoNodes = -distanceBetweenTwoNodes;
    }
    return distanceBetweenTwoNodes;
}

int computeFinalDistance(int radius, vector<double> degrees) {

    double final_sum, distanceBetweenTwoNodes = 0.0;

    // Take our degrees vector/ array
    // Iterate through the degrees inside it
    // We need the length of the degrees array
    for (int i = 0; i < degrees.size() - 1; i++) {
        if (degrees[i + 1] != degrees[i]) {
            // Take i and (i + 1) and find the distance between them
            distanceBetweenTwoNodes =
                computeDistanceOfTwoPoints(radius, degrees[i], degrees[i + 1]);
            // Add the distance to our final_sum
            final_sum += distanceBetweenTwoNodes;
        } else
            continue;
    }
    cout << "Final sum: " << final_sum << endl;
    final_sum = ceil(final_sum);
    return final_sum;
}

// We need to find if there's a loop
int nthSubstr(int n, const string &s, const string &p) {
    string::size_type i = s.find(p); // Find the first occurrence
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

// Convert string to int
int stringToInt(string s) {
    int newint = 0;
    stringstream string1(s);
    string1 >> newint;
    return newint;
}

// Convert string to double
double stringToDouble(string s) {
    double newdouble = 0.0;
    newdouble = atof(s.c_str());
    return newdouble;
}

int findElements(int numOfIterations, string inputs) {
    int m = 0;
    double degrees[numOfIterations];

    for (int i = 1; i <= numOfIterations; i++) {
        string s = inputs.substr(nthSubstr(m + 1, inputs, "\n") + 1,
                                 nthSubstr(m + 2, inputs, "\n") -
                                     nthSubstr(m + 1, inputs, "\n"));
        m = m + 1;
        string letter = s.substr(0, 2);
        degrees[i - 1] = stringToDouble(s.substr(nthSubstr(1, s, " ")));
    }
    string testInputString =
        inputs.substr(nthSubstr(numOfIterations + 1, inputs, "\n") + 1,
                      nthSubstr(numOfIterations + 2, inputs, "\n") -
                          nthSubstr(numOfIterations + 1, inputs, "\n"));
    testInputString =
        testInputString.substr(0, testInputString.find_first_of("\n"));
    cout << "Input string: " << testInputString << endl;

    string radiusString = inputs.substr(0, inputs.find_first_of("\n"));
    int radius = stringToInt(radiusString);
    cout << "radius: " << radius << endl;

    vector<double> newDegrees;
    newDegrees = convertInputStringToDegrees(testInputString, degrees);

    double distance = 0.0;

    for (int i = 0; i < newDegrees.size() - 1; i++) {
        distance =
            computeDistanceOfTwoPoints(52, newDegrees[i], newDegrees[i + 1]);
        cout << "The distance: " << distance << endl;
    }

    int finalDistance = computeFinalDistance(radius, newDegrees);
    finalDistance += radius;
    cout << "The final score: " << finalDistance << endl;

    return finalDistance;
}
