// inputData
// The first number will be an int t, the number of test cases to follow
//
// 2 int's n, m where n is the number of vertices and m the number of edges
//
// m pairs of ints separated by a space. Each pair shows a two way connection
// between vertex a and vertex b
//
// Output
// For each test case you will have to write one line that contains an int,
// in the case where is a loop you will write 1 or else 0
// 1 ≤ t ≤ 1000
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ 10000
// 0 ≤ a,b ≤ n−1
// There can be multiple edges or self-loops.
// In this case we consider the graph to contain a loop.

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

class Graph {
    int numVertices;
    std::list<int> *adjLists;
    bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    std::list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    std::list<int>::iterator i;

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end();
             ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

std::string getInputFileData() {
    std::string line, inputData;
    inputData = "";

    // Fetch the data from our the inputData file
    // Store the data in the string called lin
    std::ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            inputData = inputData + line + "\n";
        }
        file.close();
    }
    return inputData;
}

// We need to find if there's a loop
int nthSubstr(int n, const std::string &s, const std::string &p) {
    std::string::size_type i = s.find(p); // Find the first occurrence
    int j;
    for (j = 1; j < n && i != std::string::npos; ++j) {
        i = s.find(p, i + 1); // Find the next occurrence
    }
    if (j == n) {
        return (i);
    } else {
        return (-1);
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

void calculateResult(std::string inputData) {

    int m = 1;
    int p = 1;
    int tmpNumOfTestCases = 0;
    std::vector<int> adjMatrix, marks;

    std::string s = inputData.substr(0, inputData.find_first_of("\n"));
    tmpNumOfTestCases = stringToInt(s);

    int output[tmpNumOfTestCases];

    for (int i = 1; i <= tmpNumOfTestCases; i++) {
        std::string s = inputData.substr(nthSubstr(m, inputData, "\n"),
                                         nthSubstr(m + 2, inputData, "\n"));
        m = m + 2;
        int numOfNodes = stringToInt(s.substr(0));
        int numOfVertices = stringToInt(s.substr(nthSubstr(1, s, " ")));
        std::string k = inputData.substr(nthSubstr(p + 1, inputData, "\n") + 1,
                                         nthSubstr(p + 2, inputData, "\n") -
                                             nthSubstr(p + 1, inputData, "\n"));
        for (char &c : k) {
            if (c != ' ' && c != '\n') {
                marks.push_back(c - '0');
            }
        }
        for (int i = 0; i < marks.size(); i++) {
            std::cout << marks[i] << " ";
        }
        std::cout << std::endl;
        p = p + 2;
        marks.clear();
    }
}

int main(int argc, const char *argv[]) {

    std::string inputData = "";

    inputData = getInputFileData();
    calculateResult(inputData);

    return 0;
}
