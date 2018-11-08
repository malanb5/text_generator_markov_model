//
// Created by Matthew Bladek on 10/24/18.
//
/**
 *
 * get and return a fileStream with the given fileName
 */
#include <fstream>

#ifndef INPUT_H
#define INPUT_H

using namespace std;


class FileParse{
private:

public:

    static ifstream & getFileName(string & FileName, ifstream & file_stream);

};



#endif //INPUT_H