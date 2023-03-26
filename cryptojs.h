
#include <string>
#include <aes.h>
#include <cryptlib.h>
#include <base64.h>
#include <modes.h>
namespace CryptoJS
{
    using namespace std;
    typedef unsigned char BYTE;
    using CryptoPP::AES;
    using CryptoPP::Base64Decoder;
    using CryptoPP::Base64Encoder;
    using CryptoPP::CFB_Mode;
    using CryptoPP::StreamTransformationFilter;
    using CryptoPP::StringSink;
    using CryptoPP::StringSource;

    string EncryptAes(string Text, string CipherKey, string IvKey);
    string DecryptAes(string Text, string CipherKey, string IvKey);
}
