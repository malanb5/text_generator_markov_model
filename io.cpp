//
// Created by Matthew Bladek on 10/24/18.
//

#include<iostream>
#include<string>
#include "io.h"

/**
 * utility function to obtain a file stream from a given file name
 * (both passed by reference)
 * @param file_name the string representation of a file name
 * @param file_stream the input stream on which to be opened on
 * @return the ifstream opened on the file_name
 * @exception catches an exception of the file does not open properly
 */

ifstream & FileIO::get_file_name(string &file_name, ifstream &file_stream){
    try{
        file_stream.open(file_name);

        if(!file_stream.is_open()){
            throw "File did not open properly!";
        }
        return file_stream;
    }
    catch(const char * e){
        cout << e << endl;
        exit(EXIT_FAILURE);
    }
}