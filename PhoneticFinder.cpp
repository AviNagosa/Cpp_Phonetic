#include <stdexcept>
#include <iostream>
#include <vector>
#include "PhoneticFinder.hpp"

using namespace std;

string phonetic::find(string text,string word){

    int count = 0, flag = 1;
    char c1,c2;
    size_t pos = 0;
    string token, del = " ";

    while ((pos = text.find(del)) != string::npos) {
        token = text.substr(0, pos);
        text.erase(0, pos + del.length());

        if(token.compare(word) == 0)return token;
        if((token.compare(word) != 0) && (token.size() == word.size())){
            for(int i = 0; i < token.size(); i++){
                if(token[i] == word[i])count++;
                else if((token[i]-word[i]==32) || (word[i]-token[i]==32))count++;
                else{
                    if(flag == 1){
                        c1 = token[i];
                        c2 = word[i];
                        flag = 0;
                        count++;
                    }
                    else {
                        if((c1 == token[i] && c2 == word[i])||(c1 == word[i] && c2 == token[i]))count++;
                        else break;
                    }
                }
            }
            if(count == token.size())return token;
        } 
    }
    return "not Found";
}