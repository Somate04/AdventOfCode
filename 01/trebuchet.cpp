#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    ifstream file ("input.txt");
    string s;
    int sum = 0;
    while(file){
        int digit1 = 0;
        int digit2 = 0;
        int num = 0;
        string s1 = "";
        string s2 = "";
        getline(file, s);
        bool found1 = false;
        bool found2 = false;
        string temp = "";
        for(unsigned int i = 0; i < s.length(); i++){
            unsigned int j = i;
            s1 = "";
            if(isalpha(s[i])  && !found1){
                while(j < s.length()   && !found1)
                {
                    s1 += s[j];
                    string* index = find(begin(digits), end(digits), s1);
                    if(index != end(digits)){
                        found1 = true;
                        digit1 = distance(digits, index)+1;
                    }
                    j++;
                }
            }
            else if(isdigit(s[i]) && !found1){
                digit1 = s[i] - '0';
                found1 = true;
                break;
            }
        }
        for(int i = s.length()-1; i >= 0; i--){
            int j = i;
            s2 = "";
            if(isalpha(s[i])  && !found2){
                while(j >= 0 && !found2)
                {
                    s2 += s[j];
                    temp = s2;
                    reverse(temp.begin(), temp.end());
                    string* index = find(begin(digits), end(digits), temp);
                    if(index != end(digits)){
                        found2 = true;
                        digit2 = distance(digits, index)+1;
                    }
                    j--;
                }
            }
            else if(isdigit(s[i])  && !found2){
                digit2 = s[i] - '0';
                found2 = true;
                break;
            }
        }
        num = digit1 * 10 + digit2;
        sum += num;
    }
file.close();
cout << sum;
}