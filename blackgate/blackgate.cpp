#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>


using namespace std;

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
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
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
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
int stringToInt(string s)
{
	int newint = 0;
	stringstream string1(s);
	string1 >> newint; 
	return newint;
}

// Convert string to double
double stringToDouble(string s)
{
	double newdouble = 0.0;
	newdouble = atof(s.c_str());
	return newdouble;
}

// We need to find if there's a loop
int nthSubstr(int n, const string& s, const string& p) {
   string::size_type i = s.find(p);     // Find the first occurrence
   int j;
   for (j = 1; j < n && i != string::npos; ++j){
      i = s.find(p, i+1); // Find the next occurrence
   }
   if (j == n){
     return(i);
   }
   else{
     return(-1);
   }
}

void readInputs(string inputs, int Number)
{
	int m = 0;
    int heights[Number];
	vector<string> Names;
	for(int i=1; i<=Number; i++)
	{
		string s = inputs.substr(nthSubstr(m+1,inputs,"\n")+1,nthSubstr(m+2,inputs,"\n")-nthSubstr(m+1,inputs,"\n"));
		m = m+1;
		Names.push_back(s.substr(0,s.find_first_of(" ")));
		heights[i - 1] = (stringToDouble(s.substr(nthSubstr(1,s," "))));
	}
    for(int i=0; i<Number; i++)
    {
        cout<<"Name: "<<Names[i]<<" and height: "<<heights[i]<<endl;
    }
    quickSort(heights, 0, Number - 1);
    for(int i = 0; i < Number; i++){
        cout << "index: "<< i << " " << heights[i] << endl;
    }
}



int main(int argc,const char *argv[])
{
	string line,lin;
	ifstream file("input.txt");
	lin = "";
	if (file.is_open())
    {
    while(getline(file, line))
        {
            lin =lin + line + "\n";
        }
        file.close();
    }
    string s = lin.substr(0,lin.find_first_of("\n")); 
    int NumberOfPeople = stringToInt(s); 
    cout<<NumberOfPeople<<endl;
    readInputs(lin, NumberOfPeople);
	return 0;
}
