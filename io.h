//
// Created by Matthew Bladek on 10/24/18.
//
/**
 *
 * get and return a fileStream with the given fileName
 */
#include <fstream>
#include "WordGenerator.h"

#ifndef IO_H
#define IO_H

using namespace std;


class FileIO{
private:

public:

    static ifstream & FileIO::get_file_name(string &file_name, ifstream &file_stream);

    static ofstream & FileIO::generateOutput(WordGenerator & word_gen, ofstream & output);

};


#endif IO_H
