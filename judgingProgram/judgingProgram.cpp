#include <iostream>
#include <fstream>

#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
  string left = "result.txt";
  string right = "output.txt";
  
  if(argc == 3) {
    string str1(argv[1]);
    string str2(argv[2]);
    left = str1;
    right = str2;
  }

  vector<string> lefts;
  vector<string> rights;
  
  ifstream left_file(left);
  ifstream right_file(right);
  bool fileExitFlag = true;

  if(!left_file.is_open()) {
    cout << left << " does not exist. please check the filename again.\n";
    fileExitFlag = false;
  }
  if(!right_file.is_open()) {
    cout << right << " does not exit. please check the filename again.\n";
    fileExitFlag = false;
  }

  bool successFlag = true;
  if(fileExitFlag) {
    string line;
    while(getline(left_file, line)) lefts.push_back(line);
    while(getline(right_file, line)) rights.push_back(line);
    int left_length = lefts.size();
    int right_length = rights.size();

    if(left_length == right_length) {
      for(int i = 0; i < left_length; i++) {
        if(lefts[i].compare(rights[i]) != 0) {
          cout << "line number: " << i + 1 << " file name: " << left << " " << lefts[i] << " and file name: " << right << " " << rights[i] << "\n";
          successFlag = false;
        }
      }

    }
    
    else { 
      successFlag = false;
      bool mostBiggest = true; //left is default;
      int length = right_length;
      int max_length = left_length;

      if(left_length < right_length) {
        length = left_length;
        max_length = right_length;
        mostBiggest = false;
      } 
     

      int index;
      for(index = 0; index < length; index++) {
        if(lefts[index].compare(rights[index]) != 0) 
          cout << "line number: " << index + 1 << " \nfile name: " << left << " " << lefts[index] << " \nfile name: " << right << " " << rights[index] << "\n";

      }

      for(; index < max_length; index++) {
        if(mostBiggest) cout << "line number: " << index + 1 << "\nfile name: " << left << " content: " << lefts[index] << "\n";
        else cout << "line number: " << index + 1 << "\nfile name: " << right << " content: " << rights[index] << "\n";
      } 
       
    }

  }

  if(successFlag) cout << "Success!\n";
  return 0;

}
