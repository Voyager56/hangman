
#include <iostream>
using namespace std;

string hideWord(string word){
    string temp = "";
    for (unsigned int i = 1; i<word.size()+1; i++){
        temp += "#";
    }    
    return temp;
}
string hangmanCheck(string &hash,string word, char check){
    for(unsigned int i=0;i<hash.size();i++){
        if(check == word[i]){
            hash.replace(i,1,string(1,check));
        }
    }
    return hash;
}
int main(){
    string word = "kakapoop";
    string hash = hideWord(word);
    int score;
    int tries = 3;
    while(hash!=word){
        if(tries == 0){
            cout<<"დამარცხდით";
            break;
        }
        char letter;
        cout << "შეიყვანეთ ასო : ";
        cin>>letter;
        if(hash.find(letter)!=-1){
            cout << "ეს ასო უკვე გამოიცანით" << endl;
            continue;
        }
        cout <<hangmanCheck(hash,word,letter) << endl;
        if(word.find(letter)!=-1){
            score++;
        }else{
            tries--;
            cout << "არასწორი ასო გამოიცანი,ცდების რაჩენილი რაოდენობაა: " << tries <<endl;
        }
        if(hash == word){
            cout<< "გაიმარჯვეთ!";
        }
    }
}
