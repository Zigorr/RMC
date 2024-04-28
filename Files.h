
#include <string>
#include <vector>
#include"City.h"
using namespace std;
class Files {
public:
   vector<string> readLines(const string& filename); // Function declaration
   void writeCity(vector<City>);
  // Files();
  //Files(const string& filename);
   
private:
	ofstream fileStream;
	ifstream filestr;
};


