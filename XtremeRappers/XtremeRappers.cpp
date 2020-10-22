#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>


using namespace std;

// Convert string to int
long long int stringToInt(string s)
{
	long long int newint = 0;
	stringstream string1(s);
	string1 >> newint; 
	return newint;
}

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

int main(int argc,const char *argv[])
{
	string line,lin;
	ifstream file("inputx3.txt");
	lin = "";
	if (file.is_open())
    {
    while(getline(file, line))
        {
            lin =lin + line + "\n";
        }
        file.close();
    }
  long long int CrissyChris = stringToInt((lin.substr(0,lin.find_first_of(" "))));
	long long int JaCe = stringToInt(lin.substr(nthSubstr(1,lin," ")));
    cout<<CrissyChris<<"  "<<JaCe<<endl;
    long long int Output = 0;
    if((JaCe !=0 && CrissyChris !=0))
    {
    long long int Total = CrissyChris + JaCe;
    Output = Total / 3; 
    }else Output =0;
    //readInputs(lin, NumberOfPeople);
    cout<<Output<<endl;
	return 0;
}