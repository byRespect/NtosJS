/**
 * @author YUNUS YOSUNKAYA
 * @date 3/26/2023
 */
#include <node.h>
#include "cryptojs.h"

namespace NtosJS
{
    using namespace std;
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    /**
     * @param args: const FunctionCallbackInfo<Value> &args
     * @param mustLength: integer
     * @return true or false
     */
    bool CheckArgsLength(const FunctionCallbackInfo<Value> &args, int mustLength)
    {
        if (args.Length() != mustLength)
        {
            return true;
        }
        return false;
    }

    /**
     * @param args: const FunctionCallbackInfo<Value> &args
     * @return true or false
     */
    bool CheckArgsTypeForAes(const FunctionCallbackInfo<Value> &args)
    {
        if (!args[0]->IsString() || !args[1]->IsString() || !args[2]->IsString())
        {
            return true;
        }
        return false;
    }

    /**
     * @param text: encrypted text
     * @param key: encrypt key
     * @param iv: encrypt iv
     * @return decrypted text
     */
    void DecryptAes(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        // Check the number of arguments passed.
        if (CheckArgsLength(args, 3))
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Number of arguments must be 3").ToLocalChecked()));
            return;
        }
        // Check the argument types
        if (CheckArgsTypeForAes(args))
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }
        // Getting text
        String::Utf8Value _inText(isolate, args[0]);
        string EncryptedText(*_inText);
        // Geting key
        String::Utf8Value _key(isolate, args[1]);
        string EncryptKey(*_key);
        // Getting iv
        String::Utf8Value _iv(isolate, args[2]);
        string EncryptIv(*_iv);
        // Decrypt process
        string DecryptText = CryptoJS::DecryptAes(EncryptedText, EncryptKey, EncryptIv);
        // Set the return value
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, DecryptText.c_str()).ToLocalChecked());
    }

    /**
     * @param text: decrypted|none text
     * @param key: encrypt key
     * @param iv: encrypt iv
     * @return encrypted text
     */
    void EncryptAes(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        // Check the number of arguments passed.
        if (CheckArgsLength(args, 3))
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Number of arguments must be 3").ToLocalChecked()));
            return;
        }

        // Check the argument types
        if (CheckArgsTypeForAes(args))
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Getting text
        String::Utf8Value _inText(isolate, args[0]);
        string DecryptedText(*_inText);
        // Geting key
        String::Utf8Value _key(isolate, args[1]);
        string EncryptKey(*_key);
        // Getting iv
        String::Utf8Value _iv(isolate, args[2]);
        string EncryptIv(*_iv);
        // Decrypt process
        string EncryptText = CryptoJS::EncryptAes(DecryptedText, EncryptKey, EncryptIv);
        // Set the return value
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, EncryptText.c_str()).ToLocalChecked());
    }

    /**
     * Initialized for native function to js
     */
    void Init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "DecryptAes", DecryptAes);
        NODE_SET_METHOD(exports, "EncryptAes", EncryptAes);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
}