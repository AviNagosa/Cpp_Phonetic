#include <stdexcept>
#include <iostream>
#include "PhoneticFinder.hpp"


using namespace std;


class MyException : public std::exception
{
    string s;
    public:

    MyException(const string& word)
    {
        s = "Did not find the word "+word+" file in the text";
    }

	const char * what () const throw ()
    {
    	return s.c_str();
    } 

};




int index_(char c)
{
    string  letter[8]={"vw","bfp","gj","ckq","sz","dt" ,"ou","iy"};

    for(int i=0;i<8;i++)
    {
       for(int j=0;j<letter[i].size();j++)
       {
           if(letter[i].at(j)==c)
           {
               return i;
           }

       }
    }
    return -1;
}




bool check(string k,string w)
{
 
    if(k.size()!=w.size()){
       
        return false;
    }

      for(int i=0;i<k.size();i++)
    {
        k.at(i)=tolower(k.at(i));
        w.at(i)=tolower(w.at(i));
    }

    int count=0;
    for(int i=0;i<k.length();i++)
    {

        int k_index=index_(k.at(i));
        int w_index=index_(w.at(i));

        if(k_index==w_index)
        {
            count++;
        }
    
    }
 
    if(count==k.size())
    {
        return true;
    }
    
    return false;

}




string phonetic::find(string text,string word){

    // Calculate the size of array we will need for the sentence 
    int array_size=1;
    for(int i=0;i<text.length();i++)
    {
         if(text.at(i)==' '){
             array_size++;  
         }
    }

    string str[array_size];
    string temp="";
    int start=0;
    int end=0;
    int index=0;

     //Separates the string by the space character (like spilt)
    for(int i=0;i<text.length();i++)
    {

        if(text.at(i)==' ')
        {
            temp+=text.substr(start,end);
            start=i+1;
            end=-1;
            str[index++]=temp;
            temp="";
        }

        end++;
    }
 
    temp+=text.substr(start,end);
    str[index++]=temp;
    //Send every word to a function that checks for a match
    for(int i=0;i<array_size;i++)
    {

        //if true return the word else contiue
        if(check(str[i],word))
        {
            return str[i];
        }  

    }

    throw MyException(word);

}