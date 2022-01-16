#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void are_anagram(string str1,string str2,string str3,string str4,string str5){

      int n1 = str1.length();

    string word1 = str1;
    string word2 = str2;
    string word3 = str3;
    string word4 = str4;
    string word5 = str5;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    sort(str3.begin(), str3.end());
    sort(str4.begin(), str4.end());
    sort(str5.begin(), str5.end());
     bool ang_tr = false;
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i] && str1[i] != str3[i] && str1[i] != str4[i] && str1[i] != str5[i])
        {
        break;
        }
    else{
        ang_tr=true;
    }
        if(ang_tr == true){
            fstream anagram;
            anagram.open("odp_4b.txt", ios::app | ios::out);
            anagram<< word1 << " " << word2 << " " << word3 << " " <<word4 << " " << word5 << " " <<endl;
            anagram.close();
        }

        
}

void are_equal_in_lenght(string word1, string word2, string word3, string word4, string word5){
    if(word1.size() == word2.size() && word2.size() == word3.size() && word3.size() == word4.size() && word4.size() == word5.size()){
    fstream equal_lenght;
    equal_lenght.open("odp_4a.txt", ios::app | ios::out);
    equal_lenght << word1 <<" "<< word2 <<" "<< word3 <<" "<< word4 <<" "<< word5 <<endl;
    equal_lenght.close();
    are_anagram(word1,word2,word3,word4,word5);
    }
}

int main(){
    vector<string> possible_anagrams;
    fstream input_file;
    input_file.open("anagram.txt", ios::in);
    if(input_file.good()==false){
        cout<<"File does not exist!";
        return 0;
    }
    string word;
    while (input_file >> word){
        possible_anagrams.push_back(word);
    }
    
    int n = possible_anagrams.size();
    for(int i = 0; i<n; i = i + 5){
    are_equal_in_lenght(possible_anagrams[i],possible_anagrams[i+1],possible_anagrams[i+2],possible_anagrams[i+3],possible_anagrams[i+4]);
    }
    input_file.close();
    return 0;
}