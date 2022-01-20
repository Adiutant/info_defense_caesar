//
// Created by rlego on 19.01.2022.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#ifndef INFO_DEFENSE_CAESAR_DECRYPTOR_H
#define INFO_DEFENSE_CAESAR_DECRYPTOR_H
class Decryptor{
public:
    void countFrequencies(const string& text);
    string tryToDecrypt(const string& text);
private:
    int offset;
    const int ALPHABET_LENGTH = 26;
    int findIndex(const vector<string>& vec, const string& elem) ;
    template<class c,class s>
    bool contains( c str, const s& key);
    const vector<string> ALPHABET_VEC ={ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
    vector<int>* alphabet_freq = new vector<int>(ALPHABET_VEC.size());
};
#endif //INFO_DEFENSE_CAESAR_DECRYPTOR_H
