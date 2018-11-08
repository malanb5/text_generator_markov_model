<<<<<<< HEAD
//
// Created by Matthew Bladek on 10/24/18.
//

#include "markov.h"
#include <iostream>
#include <string>

// priority queue
// unordered map

/**
 * takes the input stream and inserts it into markov_counts
 * calls helper function insert_into_map
 *  @param text_stream the input text stream
 */

void Markov::parse_stream(ifstream &text_stream) {

    string new_line;
    string left_over;

    char ch;
    int counter = 0;
    string key_to_insert;
    string next_key;

    while(text_stream >> noskipws >> ch){

        if(counter > k -1) {
            insert_into_map(next_key, ch);
            next_key = next_key.substr(1, k - 1);
            next_key += ch;
        }
        else{
            next_key += ch;
            counter ++;
        }
    }
}

/**
 * generates the probability of each string (order k)  : character entry
 * stores it in markov_counts
 */

void Markov::make_markov_probs(){
    int max = INT_MIN;

    // outer loop iterator: key is the k sized string  | value is a dictionary with the key being the following character and the count
    // being the number of entries with this key - value pair

    unordered_map<string, unordered_map<char, int> >::iterator iter = markov_counts.begin();


    while(iter != markov_counts.end()){
        // inner loop iterator is the dictionary iterator of each k-sized string and the corresponding characters which follow it and the the number
        unordered_map<char, int> key_map = iter -> second;
        unordered_map<char, int>::const_iterator iter1;
        iter1 = key_map.begin();
        string temp = iter -> first;
        int total_so_far = 0;

        // updates the max and adds to the total count for each string
        while(iter1 != key_map.end()){
            total_so_far += iter1 -> second;

            if(iter1 -> second > max){
                max_string = temp;
                max = iter1 -> second;
            }
            iter1++;
        }

        // resets the iterator and creates a new dictionary to store the percentage of each character
        iter1 = key_map.begin();
        unordered_map<char, double> probs;

        while(iter1 != key_map.end()){
            // inserts into the new percentage dictionary the character and the corresponding percentage
            probs.insert({iter1 -> first, (double) iter1->second / (double) total_so_far});
            iter1++;
        }
        // inserts the newly created percentage dictionary into the main dictionary of probabilities of each string of k-characters
        markov_probs.insert({iter -> first, probs});
        iter++;
    }
}

/**
 * helper function which takes the k-number of characters (key_to_insert) as a string and then inserts them into the main
 * data structure markov_probs.  The character after the k-characters is after_ch.
 * Creates a new entry if not found.  Increments the number if found.
 * @param key_to_insert
 * @param after_ch
 */

void Markov::insert_into_map(string &key_to_insert, char after_ch) {

    unordered_map<string, unordered_map<char, int> >::iterator iter = markov_counts.find(key_to_insert);
    unordered_map<char, int> ch_dict;

    if(iter == markov_counts.end()){
        ch_dict.insert({after_ch, 1});
        markov_counts.insert({key_to_insert, ch_dict});
    }
    else{
        ch_dict = markov_counts.at(key_to_insert);
        unordered_map<char, int>::iterator iter1;
        iter1 = ch_dict.find(after_ch);
        if(iter1 == ch_dict.end()){
            ch_dict.insert({after_ch, 1});
        }
        else{
            int current_num = ch_dict.at(after_ch);
            current_num++;
            iter1 -> second = current_num;
        }
        markov_counts.at(key_to_insert) = ch_dict;
    }
}

void Markov::print(){
    unordered_map<string, unordered_map<char, int> >::const_iterator iter;
    iter = markov_counts.begin();

    while(iter != markov_counts.end()){
        unordered_map<char, int> key_map = iter -> second;
        unordered_map<char, int>::const_iterator iter1;
        iter1 = key_map.begin();
        cout << iter -> first << " : {";
        while(iter1 != key_map.end()){
            cout << iter1 -> first << " : " << iter1 -> second <<endl;
            iter1++;
        }
        iter++;
        cout << "}" << endl;

    }
=======
//
// Created by Matthew Bladek on 10/24/18.
//

#include "markov.h"
#include <iostream>
#include <string>

// priority queue
// unordered map

/**
 *  l = 6
 *  k =2
 *   abbraa
 *     ^
 *   "a:
 *   "ab" :1
 *   "br" : 1
 * @param text_stream
 */

void Markov::parseStream(ifstream & text_stream) {

    string new_line;
    string left_over;

    char ch;
    int counter = 0;
    string key_to_insert;
    string next_key;
    /**
     * Hello World
     *    ^
     */
    while(text_stream >> noskipws >> ch){

        if(counter > k -1) {
            insertIntoMap(next_key, ch);
            next_key = next_key.substr(1, k - 1);
            next_key += ch;
        }
        else{
            next_key += ch;
            counter ++;
        }
    }
}

void Markov::insertIntoMap(string &key_to_insert, char ch) {

    unordered_map<string, unordered_map<char, int> >::iterator iter = markov_probs.find(key_to_insert);
    unordered_map<char, int> key_dict;

    if(iter == markov_probs.end()){
        key_dict.insert({ch, 1});
        markov_probs.insert({key_to_insert, key_dict});
    }
    else{
        key_dict = markov_probs.at(key_to_insert);
        unordered_map<char, int>::iterator iter1;
        iter1 = key_dict.find(ch);
        if(iter1 == key_dict.end()){
            key_dict.insert({ch, 1});
        }
        else{
            int current_num = key_dict.at(ch);
            current_num++;
            iter1 -> second = current_num;
        }
        markov_probs.at(key_to_insert) = key_dict;
    }
}

void Markov::print(){
    unordered_map<string, unordered_map<char, int> >::const_iterator iter;
    iter = markov_probs.begin();

    while(iter != markov_probs.end()){
        unordered_map<char, int> key_map = iter -> second;
        unordered_map<char, int>::const_iterator iter1;
        iter1 = key_map.begin();
        cout << iter -> first << " : {";
        while(iter1 != key_map.end()){
            cout << iter1 -> first << " : " << iter1 -> second <<endl;
            iter1++;
        }
        iter++;
        cout << "}" << endl;

    }
>>>>>>> 35a3b498fd72967a4b19b18df03ada2b9196b05e
}