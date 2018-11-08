## Text Generator Using k-order Markov Model

### Introduction
Markov model follow the basic premise that a system's most likely state is based on the current state and conditional probabilities of the possible transitions.  We will use this concept to construct a text generator
which uses the conditional probabilities of previous text to infer the next most likely character.  How far back the model will look is variable and denoted by the order k.  A 0-order Markov model would be no model at all.
The characters would be generated at random.  1-order Markov model is when a character would be predicted from the 1 character before it.  The 2-order, 2 characters before it.  Where the kth-order Markov model would be the most likely character based on k-characters before said character.

### Breakdown of the Program
The program will be broken down into modules.

#### Getting and Parsing the User Input
The first module will concern itself with getting and parsing the user input.  The program will obtain and store the order of the Markov model as variable k and also the text file from which to base the Markov model off of.

#### Parsing and Storing the Data
The second part will take the user input and turn it into a data structure which will hold the k-order Markov model.  The data structure chosen is a Heap with key's being k-number of of characters which come before the value.
The value is another map which maps the character which proceeds the k-characters to the number of ocurrences.
An adjacent data structure is a max priority queue or heap which keeps track of the most frequently occuring k-term for fast lookup later in the random word generator.

#### Random Word Generator
After the data structures are in memory.  A random word generator will generate words up to a predefined character length.  
The first characters are the most common k-characters, which was stored by the heap.
The next character will then be determined by the probablitity of what the most likely character is afer the sequence of those k-characters.
For example, if we have  k-order Markov model with where k =2 and our data structure contained {"ad" : {s, 3}, {d, 1}}.  This means that after "ad" there is
a 25% chance that a d will occur and a 75% chance that an s will occur.  The character will be chosen based upon these probabilities.  
Say the most likely character was chosen 's', so the next k-term will then be updated to be {"ds"}.  "ds" will then be looked up in the map and the character chosen from
the possibilities that proceed "ds".  There is an option to exit early if the end of file proceeded those characters.
