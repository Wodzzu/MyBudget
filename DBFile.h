#include <iostream>


using namespace std;

class DBFile {

 const string FILE_NAME;

 public:

    DBFile(string fileName): FILE_NAME(fileName) {};

    string getFileName();
};
