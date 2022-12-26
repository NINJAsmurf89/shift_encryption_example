// Author: Haley Richardson
// File:   encoder.h
//version: 1.0.0

#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>

using namespace std;

class encoder
{
  private:
    // This holds the key for the shift that the file goes through
    int key;

    // This is the character that is being mutated before it's written to the file
    char c;

    // This is the name of the INPUT file for the ENCRYPTION file.
    string filename;

  public:
    // This is the encrypt function. It opens the file at filename
    // and shifts each character in the file by the value of key. This 
    // also works with new lines and puncuations.
    //
    // PRE: The input file has been validated by the getFileFromUser function
    //   and the key has been provided using the getKeyFromUser function.
    //
    // POST: A file called encrypt.txt will be made in the working directory.
    void encrypt();

    // This function is the decrypt function. It opens a file called encrypt.txt
    // and performs the inverse shift that was done in the encryption function.
    // 
    // PRE: The file encrypt.txt must exist. The file must be generated by the
    //   encryption function OR the shift key must be the first character followed
    //   by a hyphen (-) and no white space.
    //
    // POST: A file called decrypt.txt will be created with the decrypted message
    //   in it. The key is not in the file and it will not have any added characters.
    bool decrypt();

    // This is the function that checks and the given file exists in the directory.
    // If the file doesn't exist, it will ask again for the user to input a file
    // that is in the working directory.
    //
    // PRE: N/A
    //
    // POST: The file stored in filename in the class will be a valid filename
    //   that lives in the working directory.
    void getFileFromUser(string file);

    // This is the function that checks that the given key will be valid. The
    // key must be greater than 5 and less than 30.
    //
    // PRE: N/A
    //
    // POST: The value stored in key will be valid.
    void getKeyFromUser(int K);
};

#endif