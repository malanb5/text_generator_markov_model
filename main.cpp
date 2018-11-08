#include <iostream>
#include <queue>
#include <unordered_map>
#include "io.h"
#include <fstream>
#include "markov.h"
#include "WordGenerator.h"
#include <string>


using namespace std;

/**
 *   Input:
 *   astringofcharacters
 *
 *   Variables:
 *   The order k - enum {1, 10}
 *
 *   Data Structures
 *   class MarkovModel
 *
 *   {the k-characters : { character after k-characters: # occurrences}}
 *
 *
 *   {as : {a, 1}
 *         {b, 2}
 *         {c, 1}} -> % of occurence
 *
 *
 *   Iterate through
 *
 *
 *   Keep then update a tertiary priority queue that keeps the max occurrence
 *
 *   priority queue - max based on value
 *     {aa : 33}
 *
 *
 *   parse lines:
 *   1) take k characters at a time
 *          - store k characters
 *          - find next character in sequence and increment or add new key value for the character and single occurance
 *
 *   Functions:
 *
 *   getUserInput()
 *      getFileName()
 *      getOrder()
 *
 *   parseUserInput()
 *       takeKCharacters()
 *          insertIntoMap()
 *       takeCharacterAfter()
 *          checkToSeeIfInMapAlready()
 *          if not insertIntoMap()
 *          else makeNewKeyEntry()
 *       if at the end of line get next characters the beginning of the newline
 *              getline(in, line)
 *       <--- loop
 *       if end of file end
 *
 *    generateRandomWords()
 *          choose top word from PQ
 *          choose letter based on top word
 *          <-- loop for 2000 characters or eof()
 *
 * @return
 */

/**
 * main greeting for entry into the program
 */
void greeting(){
    cout << "Welcome!   Please enter the file path of the text file from which the Markov model will be constructed from" << endl;

}


/**
 * gets the user input for which text to use
 * @return  the file path to the selected text
 */
string get_user_input_text(){
    string option;
    string options_intro = "The two options are 1) Melville or 2) Poe (q to exit):  ";

    string file_path_to_text = "/Users/matthewbladek/root/education/pa1/";
//    string file_path_to_text = "D:\\root\\education\\stanford\\programming_abstractions\\pa_1_test\\";



    cout << options_intro;
    bool sentinel = true;

    string file_name;

    while(sentinel){
        cin >> option;

        if(option == "1"){
            file_name = file_path_to_text + "melville.txt";
            sentinel = false;
        }
        else if(option == "2"){
            file_name = file_path_to_text + "poe.txt";
            sentinel = false;
        }
        else if(option == "q"){
            exit(EXIT_SUCCESS);
        }
        else{
            printf("Invalid option.  %s\n", options_intro.c_str());
        }
    }

    return file_name;
}


/**
 * gets the user input and sets it to term k
 * @return the user-inputed term k
 */
int get_user_input_order(){
    int k;
    do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "What should be the order of the Markov model? (1 -10) k =  " << endl;
        cin >> k;
    }while(k <= 0 || k > 10);

    return k;
}



int main() {

    /**
     * greeting/introduction
     */
    greeting();
    string file_name = get_user_input_text();

    int k = get_user_input_order();

    ifstream file_stream;

    ifstream & my_file = FileIO::get_file_name(file_name, file_stream);

    Markov model(my_file, k);

    unordered_map<string, unordered_map<char, int> > markov_counts = model.get_counts();

    int num_words = 20;

    WordGenerator wg(markov_counts, num_words);

    string max_string = wg.make_markov_probs();

    cout << "The max String is: " + max_string << endl;

//    wg.generateLine();

    model.print();

    /**
     *  Generate the random words.
     *
     *  baa : {b : 2
                }
        aab : {a : 2
        }
        aba : {a : 2
        }

        Take the probabilities of each entry:
                Sum of each entry of entry
                Take the percentage of each entry based upon the total
        Could either create an adjacent data structure
        or calculate it on demand


     */



    my_file.close();

    return 0;
}