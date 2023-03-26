
#include "cryptojs.h"
namespace CryptoJS
{
    string EncryptAes(string Text, string CipherKey, string IvKey)
    {
        string Output;
        CFB_Mode<AES>::Encryption Encryption((BYTE *)CipherKey.c_str(), CipherKey.length(), (BYTE *)IvKey.c_str());
        StringSource Encryptor(Text, true, new StreamTransformationFilter(Encryption, new Base64Encoder(new StringSink(Output), false)));
        return Output;
    }

    string DecryptAes(string Text, string CipherKey, string IvKey)
    {
        string Output;
        CFB_Mode<AES>::Decryption Decryption((BYTE *)CipherKey.c_str(), CipherKey.length(), (BYTE *)IvKey.c_str());
        StringSource Decryptor(Text, true, new Base64Decoder(new StreamTransformationFilter(Decryption, new StringSink(Output))));
        return Output;
    }
}