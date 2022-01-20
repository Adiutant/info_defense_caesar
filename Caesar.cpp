#include "Caesar.h"


   void  Caesar::toLower(string& s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return tolower(c); }
        );
    }


    template<class c,class k>
    bool Caesar::contains(c str, const k& key) {
        for (auto ch : str) {
            //string s(1,ch);
            if (ch == key) {
                return true;
            }
        }
        return false;
    }

    template<class s>
    void Caesar::deleteChar(vector<string>& str, const s& key) {


        for (int i = 0; i < str.size(); i++) {
            if (str.at(i) == string(key)) {
                str.erase(str.begin() + i);
            }
        }

    }

    int Caesar::findIndex(const vector<string>& vec, const string& elem) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i) == elem) { return i; }
        }
        return -1;
    }

    bool Caesar::checkKeyWord( const string& keyword,const int& n) {
        if (keyword.length() > ALPHABET_LENGTH|| n > ALPHABET_LENGTH || n < 0) { return false; }
        string check;
        for (auto c : keyword) {
            //string s(1,c);
            if (contains(check, c)) {
                return false;
            }
            check +=  c;

        }
        return true;
    }
    void Caesar::makeNewAlphabet(const string& keyword, const int& key) {
        vector<string> pureAlpha = ALPHABET_VEC;
        vector<string> alpha = ALPHABET_VEC;
        newAlpha = ALPHABET_VEC;
//        vector<string> pureAlpha = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш","щ","ъ","ы","ь","э","ю","я"};
//        vector<string> alpha = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш","щ","ъ","ы","ь","э","ю","я" };
//       vector<string> newAlpha = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш","щ","ъ","ы","ь","э","ю","я" };
        for (int i = 0; i < keyword.length(); i++) {
            newAlpha[(i+key) % ALPHABET_LENGTH] = keyword[i];
            deleteChar(alpha, newAlpha[(i+key) % ALPHABET_LENGTH]);
        }
        for (int i = keyword.length()+key; i % ALPHABET_LENGTH != key ; i++) {
            sort(alpha.begin(), alpha.end());
            newAlpha[i % ALPHABET_LENGTH] = alpha[0];
            deleteChar(alpha, alpha[0]);
        }
        cout<< "New alphabet is: ";
       for (auto  item:newAlpha)
       {
           cout<<item;
       }
       cout<<endl;


}

    string Caesar::MakeEncryption(const string& text) {
        string result;
        for (char i : text) {
            string s(1,i);
            if (contains(ALPHABET_STRING, i)) {
                result += newAlpha.at(findIndex(ALPHABET_VEC, s));
            }
            else { result += i; }

        }
        return result;
    }
string Caesar::MakeDecryption(const string& text) {
    string result;
    for (char i : text) {
        string s(1,i);

        if (contains(newAlpha, s)) {
            result += ALPHABET_VEC.at(findIndex(newAlpha, s));
        }
        else { result += i; }

    }
    return result;
}

     string Caesar::readFromFile(const string& filename) {
        string text;
        string line;

        ifstream in(filename);
        if (in.is_open()) {
            while (getline(in, line)) {
                text += line;
            }
        } else {
            cout << "File error";
            return "";
        }
        in.close();
        return text;

    }

    void Caesar::writeToFile(const string& text,const string& result_file_name) {
        ofstream out;
        out.open(result_file_name);

        if (out.is_open()) {
            out << text;
        }
    }
