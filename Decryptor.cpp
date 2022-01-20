//
// Created by rlego on 19.01.2022.
//
#include "Decryptor.h"


void Decryptor::countFrequencies(const string& text) {
    for (auto ch:text)
    {
        string s(1,ch);
        if (contains(ALPHABET_VEC,s)) {
            alphabet_freq->at(findIndex(ALPHABET_VEC, s))++;
        }
    }
    int max = alphabet_freq->at(0);
    int maxIndex =0;
    for (int i =0; i<alphabet_freq->size();i++){
        if (alphabet_freq->at(i)>max)
        {
            max =alphabet_freq->at(i);
            maxIndex = i;
        }
    }
    offset =(maxIndex - findIndex(ALPHABET_VEC,"e"));
    cout<< "Most common letter: " << ALPHABET_VEC[maxIndex] << ", then most common letter in source alphabet is 'e' which index is "
    << ALPHABET_VEC[findIndex(ALPHABET_VEC,"e")]<< " then offset is kikely: "<< offset <<endl;
}
int Decryptor::findIndex(const vector<string> &vec, const string &elem) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) == elem) { return i; }
    }
    return -1;
}

template<class c, class s>
bool Decryptor::contains(c str, const s& key) {
    for (auto ch :str) {
        if (ch == key) {
            return true;
        }
    }
    return false;
}

string Decryptor::tryToDecrypt(const string& text) {
    string result;
    for (auto ch:text)
    {
        string s(1,ch);
        if (contains(ALPHABET_VEC,s))
        {
            int newIndex =(findIndex(ALPHABET_VEC,s)-offset);
            if (newIndex<0)
            {
                result+=ALPHABET_VEC[(ALPHABET_LENGTH + newIndex)%ALPHABET_LENGTH];
            }
            else
            {
                result+=ALPHABET_VEC[newIndex%ALPHABET_LENGTH];
            }

        }
        else {result+=ch;}
    }
    return result;
}


