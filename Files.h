#pragma once
#include <string>
#include <vector>
#include"City.h"
#include"Edge.h"
using namespace std;
template<class T>
class Files {
public:
	//template void Files<Edge>::writeVectorToFile(const vector<Edge>& vec, const string& filename);

	void writeVectorToFile(const vector<Edge>& vec, const string& filename);
	 vector<Edge>readVectorFromFile(const string& filename);
	
	unordered_map<string, City> readMapFromFile(const string& filename);
	template<class T>
	void writeMapoFile(unordered_map<string, City>& cities, const string& filename);


  // Files();
  //Files(const string& filename);
   
private:
	ofstream fileStream;
	ifstream filestr;
};


