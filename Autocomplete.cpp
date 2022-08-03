#include<bits/stdc++.h>
#include "Tries.h"
using namespace std;
int main(){
    Trie obj;
    fstream new_file;
    string word;
    new_file.open("dictionary.txt");
    while(getline(new_file, word)){
        obj.insert(word);
    }
    new_file.close();
    while(true){
        string prefix;
        cout<<"Enter : ";
        cin>>prefix;
        vector<string> answer;
        answer = obj.autocomplete(prefix);
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<endl;
        }
        cout<<"\n=============================================\n\n";
        
    }
}