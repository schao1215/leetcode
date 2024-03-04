#include <iostream>
#include <string>
#include <sstream>
#include <stack>


using namespace std;

class Solution {
public:

    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        stack<string> words;
        string new_sentence;
        while(ss >> word){
            if(new_sentence.size() == 0)
                new_sentence = word;
            else
                new_sentence = word + " " + new_sentence;
            // words.push(word);
        }
        // new_sentence += words.top();
        // words.pop();
        // while(!words.empty()){
        //     new_sentence += " ";
        //     new_sentence += words.top();
        //     words.pop();
        // }
        return new_sentence;
        
    }
};

int main(){
    string s = "   hello  world  ";
    Solution sol;
    string ans = sol.reverseWords(s);
    cout<<ans<<endl;
}