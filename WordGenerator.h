//
// Created by malan on 10/30/2018.
//
#include <unordered_map>
#include <string>
#include <random>


#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H

using namespace std;

/**
 * ""aa"" basis
 * based on the basis what is the next most likely character given these two characters beforehand
 *  1) look up ""aa""
 *  2) load characters into a probability { .25 : " a ", .5, "b", .25, "c"}
 *  3) generate a number which corresponds to this probability at random
 *  4) retrieve the result
 *  5) append that to the newly created string
 *  6) pop off the front of the basis and add the new character to the basis
 *  7) loop
 */

class WordGenerator{

    unordered_map<string, unordered_map<char, int> > markov_counts;
    int max_num_words;

    int line_length = 5;

public:
    WordGenerator(unordered_map<string, unordered_map<char, int> > markov_probs, int num_words) {
        this -> markov_counts = markov_probs;
        max_num_words = num_words;
    }

    /**
     *
     * @return the most common
     */
    string make_markov_probs();

    string generateLine();
};

#endif
