//
// Created by rlego on 19.01.2022.
//
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <clocale>

using namespace std;

#ifndef INFO_DEFENSE_CAESAR_CAESAR_H
#define INFO_DEFENSE_CAESAR_CAESAR_H
static const int ALPHABET_LENGTH = 33;

class Caesar {
public:

    static void toLower(string& s);

    bool checkKeyWord(const string& keyword,const int& n) ;

    string MakeEncryption(const string& text) ;
    string MakeDecryption(const string& text) ;

    static string readFromFile(const string& filename);

    static void writeToFile(const string& text,const string& result_file_name) ;

    void makeNewAlphabet(const string& keyword, const int& key);

private:

    vector<string> newAlpha;
    const int ALPHABET_LENGTH = 26;
    const  vector<string> ALPHABET_VEC ={ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
    const string ALPHABET_STRING = "abcdefghijklmnopqrstuvwxyz"  ;
    template<class c,class s>
    bool contains(c str, const s& key);

    template<class s>
    void deleteChar(vector<string>& str, const s& key) ;

    int findIndex(const vector<string>& vec, const string& elem) ;
};
#endif //INFO_DEFENSE_CAESAR_CAESAR_H
