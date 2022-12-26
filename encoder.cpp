// Author: Haley Richardson
// File:   encoder.cpp
//version: 1.0.0

#include <iostream>
#include <fstream>
#include <string>
#include "encoder.h"

using namespace std;

void encoder::encrypt()
{
  fstream infile;
  fstream outfile;

  infile.open(filename);
  outfile.open("encrypt.txt", ios::app);

  outfile << key << '-';

  while(infile >> noskipws >> c){
    int temp = (c + key);

    outfile << (char)temp;
  }

  infile.close();
  outfile.close();
}

bool encoder::decrypt()
{
  fstream infile;
  fstream outfile;
  string tempKey;

  infile.open("encrypt.txt");
  outfile.open("decrypt.txt", ios::app);

  if(infile.fail()){
    cout << "There is no file to decrypt in the current directory." << endl;
    cout << "Please encrypt a file before running this command." << endl;
    outfile.close();
    return false;
  }
  getline(infile, tempKey, '-');
  key = stoi(tempKey, nullptr);

  while(infile >> noskipws >> c){
    int temp = (c - key);

    outfile << (char)temp;
  }

  infile.close();
  outfile.close();
  return true;
}

void encoder::getKeyFromUser(int K)
{
  int temp;

  if(K >= 5 && K <= 30){
    key = K;
  }else{
    temp = K;
    while(temp < 5 || temp > 30){
      cout << "Bad key. Keys must be between 5 and 30" << endl;
      cout << "Key: ";
      cin >> temp;
      cin.ignore();
      cout << endl;
    }
    key = temp;
  }
}

void encoder::getFileFromUser(string file)
{
  fstream infile;
  string fileName;
  infile.open(file);
  
  if(!infile.fail()){
    filename = file;
    return;
  }
  while(infile.fail())
  {
    cout << "File not found. Please try a file that is in the current directory." << endl;
    cout << "Please enter a file name: ";
    getline(cin, fileName);
    infile.open(fileName);
  }
  infile.close();
  filename = fileName;
}