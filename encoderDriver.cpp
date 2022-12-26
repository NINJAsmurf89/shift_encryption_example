// Author: Haley Richardson
// File:   encoderDriver.cpp
//version: 1.0.0

#include <iostream>
#include <string>
#include "encoder.h"

using namespace std;

int main()
{
  encoder Enc;
  string file;
  bool flag;
  int choice;
  int temp;

  cout << "Enter your choice:" << endl;
  cout << "1. Encrypt" << endl;
  cout << "2. Decrypt" << endl;
  cout << "Choice -> ";
  cin >> choice;
  cin.ignore();
  cout << endl << endl;

  switch (choice)
  {
  case 1:
    cout << "Input the key: ";
    cin >> temp;
    cin.ignore();
    cout << endl;
    Enc.getKeyFromUser(temp);
    cout << "Input the filename: ";
    cin >> file;
    cin.ignore();
    cout << endl << endl;
    Enc.getFileFromUser(file);
    Enc.encrypt();
    cout << "File written to directory!" << endl << endl;
    break;
  case 2:
    flag = Enc.decrypt();
    if(flag){
      cout << "File writen to directory!" << endl << endl;
    }else{
      remove("decrypt.txt");
      cout << "No file written" << endl << endl;
    }
    
    break;
  }

  return 0;
}