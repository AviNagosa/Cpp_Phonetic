#include <stdexcept>
#include <iostream>
#include "PhoneticFinder.hpp"

using namespace std;

string phonetic::find(string text,string word){
    
    int count, flag;
    char c1,c2;
    string token, del = " ";
    size_t pos = pos = text.find(del);

    while ((pos = text.find(del)) != (string::npos)) {
        flag = 1;
        count = 0;
        token = text.substr(0, pos);
        text.erase(0, pos + del.length());

        if(token.compare(word) == 0)return token;
        if(token.size() == word.size()){
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
                        if(((c1 == token[i]) && (c2 == word[i]))||((c1 == word[i]) && (c2 == token[i])))count++;
                        else break;
                    }
                }
            }
            if(count == token.size())return token;
        } 
    }
    return "not Found";
}