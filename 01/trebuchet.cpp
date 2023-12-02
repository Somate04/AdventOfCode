#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
    ifstream file ("input.txt");
    string s;
    string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eigth", "nine", ""};
    int sum = 0;
    while(file){
        int digit1 = 0;
        int digit2 = 0;
        int num = 0;
        string s1 = "";
        string s2 = "";
        getline(file, s);
        for(unsigned int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                digit1 = s[i] - '0';
                break;
            }
        }
        for(int i = s.length()-1; i >= 0; i--){
            if(isdigit(s[i])){
                digit2 = s[i] - '0';
                break;
            }
        }
        num = digit1 * 10 + digit2;
        sum += num;
    }
file.close();
cout << sum;
}