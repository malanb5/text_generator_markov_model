//
// Created by malan on 10/30/2018.
//

#include<iostream>
#include "WordGenerator.h"


string WordGenerator::generateLine() {

    int so_far = 0;

    do{
        so_far += line_length;
        int curr_line_length = 0;

        if(so_far > max_num_words){
            curr_line_length = max_num_words - (so_far - line_length);
        }else{
            curr_line_length = line_length;
        }
        cout << curr_line_length << endl;
    } while(so_far < max_num_words);

    return "done";
}