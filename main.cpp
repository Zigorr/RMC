#include <iostream>
using namespace std;
int main() {

    if (lines.empty()) {
        cerr << "Error: No lines read from input file." << endl;
        return 0; // Exit with error code
    }

    // Display lines read from input file
    cout << "Lines read from " << inputFilename << ":" << endl;
    for (const string& line : lines) {
        cout << line << endl;
}



