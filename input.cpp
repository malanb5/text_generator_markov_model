//
// Created by Matthew Bladek on 10/24/18.
//

#include<iostream>
#include<string>
#include "input.h"


ifstream & FileParse::getFileName(string & FileName, ifstream & file_stream){
    try{
        file_stream.open(FileName);

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