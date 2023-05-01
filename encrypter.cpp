//#include "encrypter.hpp"

//Encrypter::Encrypter()
//{
//    using namespace CryptoPP;
//    HexEncoder encoder(new FileSink(std::cout));
//}

//std::string Encrypter::encrypt(std::string encrstr)
//{
//    using namespace CryptoPP;

//    AutoSeededRandomPool prng;

//    prng.GenerateBlock(key, key.size());
//    prng.GenerateBlock(iv, iv.size());

//    std::string plain = encrstr;
//    std::string cipher, recovered;

//    std::cout << "plain text: " << plain << std::endl;

//    try {
//        CBC_Mode<AES>::Encryption e;
//        e.SetKeyWithIV(key, key.size(), iv);

//        StringSource s(plain,
//                       true,
//                       new StreamTransformationFilter(e,
//                                                      new StringSink(
//                                                          cipher)) // StreamTransformationFilter
//        );                                                         // StringSource
//    } catch (const Exception &e) {
//        std::cerr << e.what() << std::endl;
//        exit(1);
//    }

//    std::cout << "key: ";
//    encoder.Put(key, key.size());
//    encoder.MessageEnd();
//    std::cout << std::endl;

//    std::cout << "iv: ";
//    encoder.Put(iv, iv.size());
//    encoder.MessageEnd();
//    std::cout << std::endl;

//    std::cout << "cipher text: ";
//    encoder.Put((const byte *) &cipher[0], cipher.size());
//    encoder.MessageEnd();
//    std::cout << std::endl;

//    return cipher;
//}

//std::string Encrypter::decript(std::string ciphedrtext)
//{
//    using namespace CryptoPP;

//    try {
//        CBC_Mode<AES>::Decryption d;
//        d.SetKeyWithIV(key, key.size(), iv);

//        StringSource s(cipher,
//                       true,
//                       new StreamTransformationFilter(d,
//                                                      new StringSink(
//                                                          recovered)) // StreamTransformationFilter
//        );                                                            // StringSource

//        std::cout << "recovered text: " << recovered << std::endl;
//        return recovered;
//    } catch (const Exception &e) {
//        std::cerr << e.what() << std::endl;
//    }
//}
