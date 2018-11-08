<<<<<<< HEAD
//
// Created by Matthew Bladek on 10/24/18.
//

#ifndef MARKOV_H
#define MARKOV_H

#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Markov{

private:

    /**
     * main data structure is a hash map of hash maps which will be in the following structure.
     * As stated in the main, we are trying to come up with a deterministic model based upon
     * k characters which precede the character.  An example will presented and then a description of how that example works follows.
     *
     * Order 3 (k = 3):
     * Example input: aabaabaab   ->   { aab : { a : 2},
     *                                   aba : { a: 2 },
     *                                   baa : { b :2 }}
     *
     * In this example a character which follows 3 (the order) characters increments the counter for that entry.
     * So after aab the next character is a--therefore, the entry aab: (a : 1) does not exist to the entry is created
     * After aba, the next character is a, the entry aba : a is incremented.
     *
     * More generally the format is:
     * Variables:
     * key_1: the k number of characters before the character in question
     * value1: another dictionary
     *    key_2: the character after the k characters
     *    value_2: the number of instances key_2 follows key_1
     *
     */
    unordered_map<string, unordered_map<char, int> > markov_counts;
    unordered_map<string, unordered_map<char, double> > markov_probs;
    int k; // the order of the markov model -- order in this case is the number of characters which precede the character
    // whose probability is being taken. See above for a description

    void insert_into_map(string &, char);
    void parse_stream(ifstream &);
    void make_markov_probs();
    string max_string;

public:

    Markov(ifstream & text_stream, int k){
        this -> k = k;
        parse_stream(text_stream);
        make_markov_probs();

    }

    unordered_map<string, unordered_map<char, int> > & get_counts(){
        return markov_counts;
    }

    void print();

};

#endif //MARKOV_H
=======
//
// Created by Matthew Bladek on 10/24/18.
//

#ifndef MARKOV_H
#define MARKOV_H

#include <queue>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Markov{

private:
    priority_queue<pair<int, string> > first_k_characters;
    unordered_map<string, unordered_map<char, int> > markov_probs;
    int k;

    void insertIntoMap(string &, char);
    void parseStream(ifstream &);

public:

    Markov(ifstream & text_stream, int k){
        this -> k = k;
        parseStream(text_stream);

    }


    void print();


};

#endif //MARKOV_H
>>>>>>> 35a3b498fd72967a4b19b18df03ada2b9196b05e
