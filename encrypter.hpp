#ifndef ENCRYPTER_HPP
#define ENCRYPTER_HPP

#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/rijndael.h>
#include <string>

class Encrypter
{
public:
    std::string encrypt(std::string encrstr, int size);
    Encrypter();
};

#endif // ENCRYPTER_HPP
