//
//  main.cpp
//  ProtobufDecompromizing
//
//  Created by Elisabeth Hoppe on 15.05.16.
//  Copyright © 2016 Elisabeth Hoppe. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int sizeCompressedBuffer = 3;
    int sizeDecompressedBuffer = 4;
    
    
    
    // compressed buffer (other order as in the document -> maybe turning around the bytes will be needed later)
    unsigned short compressedBuffer[sizeCompressedBuffer];
    compressedBuffer[0] = 0x63AB;
    compressedBuffer[1] = 0xF55E;
    compressedBuffer[2] = 0xA714;
    
    //decompressed buffer
    unsigned short decompressedBuffer[sizeDecompressedBuffer];
    for(int i = 0; i<sizeDecompressedBuffer; i++)
    {
        decompressedBuffer[i] = 0x0;
    }
    
    // first compressed short
    unsigned short firstUpper = (compressedBuffer[0] >> (8*0)) & 0xff;
    //unsigned short firstLower = (compressedBuffer[0] >> (8*1)) & 0xff;
    unsigned short firstLowerUp = (compressedBuffer[0] >> (4*3)) & 0xff;
    unsigned short firstLowerLow = (compressedBuffer[0] >> (4*3+1)) & 0xff;
    
    // second compressed short
    unsigned short secondUpper = (compressedBuffer[1] >> (8*0)) & 0xff;
    unsigned short secondLower = (compressedBuffer[1] >> (8*1)) & 0xff;
    
    
    // third compressed short
    unsigned short thirdUpper = (compressedBuffer[2] >> (8*0)) & 0xff;
    unsigned short thirdLower = (compressedBuffer[2] >> (8*1)) & 0xff;
    unsigned char thirdUpperHelp = (char)thirdUpper;
    unsigned short thirdUpperUp = thirdUpperHelp >> 4;
    unsigned short thirdUpperLow = thirdUpperHelp & 0xf;
    //unsigned short thirdUpperUp = (compressedBuffer[2] >> (4)) & 0xff;
    //unsigned short thirdUpperLow = (compressedBuffer[2] >> (4*2+1)) & 0xff;
    
    // copy to decompressed buffer
    unsigned short twoBytes = firstUpper << 8 | firstLowerUp;
    decompressedBuffer[0] = twoBytes;
    twoBytes = secondUpper << 8 | firstLowerLow;
    decompressedBuffer[1] = twoBytes;
    twoBytes = secondLower << 8 | thirdUpperUp;
    decompressedBuffer[2] = twoBytes;
    twoBytes = thirdLower << 8 | thirdUpperLow;
    decompressedBuffer[3] = twoBytes;
    
    std::cout << "Compressed buffer: " << std::hex << (int)compressedBuffer[0] << " " << std::hex << (int)compressedBuffer[1] << " " << std::hex << (int)compressedBuffer[2] << std::endl;

    std::cout << "Decompressed buffer: " << std::hex << (int)decompressedBuffer[0] << " " << std::hex << (int)decompressedBuffer[1] << " " << std::hex << (int)decompressedBuffer[2] << " " << std::hex << (int)decompressedBuffer[3] << std::endl;
    
    
    return 0;
}
