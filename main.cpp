// InfoDefence.cpp : Defines the entry point for the console application.
//
#include "Caesar.h"
#include "Decryptor.h"


int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    //setlocale(LC_ALL, "ru_RU.UTF-8");

    Caesar cs;
    //setlocale(0, "");
    Decryptor dc;
    string text;
	string keyword;
    string cypher_text;
    string dec;
	int n;
	text = Caesar::readFromFile("text.txt");
	if (text.empty()) { return 0 ; }
	cout << "Input keyword"<<endl;
	cin >> keyword;
	cout << "Input key N"<<endl;
	cin >> n;
	if (cs.checkKeyWord(keyword,n) ) {
        Caesar::toLower(text);
        cs.makeNewAlphabet(keyword,n);
        cypher_text = cs.MakeEncryption(text);
        dec = cs.MakeDecryption(cypher_text);
		Caesar::writeToFile(cypher_text,"result.txt");
	}
	else { cout << "Not valid keyword or key"; }

    dc.countFrequencies(cypher_text);
    string freq_decrypted = dc.tryToDecrypt(cypher_text);
    dc.countFrequencies(freq_decrypted);
	cin >> n;


    return 0;
}








