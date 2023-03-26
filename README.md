# 🔥 NtosJS - Native JS Library for now only AES256

<center>

![](./assets/NtosJS.png)

> Native JS Library for now only AES256

![](https://img.shields.io/github/stars/byRespect/NtosJS)
![](https://img.shields.io/github/forks/byRespect/NtosJS)
![](https://img.shields.io/github/issues/byRespect/NtosJS)
<!-- ![](https://img.shields.io/github/tag/byRespect/NtosJS)
![](https://img.shields.io/github/release/byRespect/NtosJS) -->

</center>

## 📖 Project Overview

This project allows you to easily use AES256 encryption on JavaScript/TypeScript. This project is open source, you can easily customize it according to you and use it as a reference for you to write new native JavaScript/TypeScript libraries.

## 🚀 Getting Started

```bash
$ git clone --recurse-submodules https://github.com/byrespect/ntosjs
$ cd ntosjs
$ cd cryptopp && make && cd ..
$ node-gyp configure build
$ node module/javascript/test.js
```

## 🧪 Example

```javascript
// index.js
const { EncryptAes, DecryptAes } = require("./build/Release/NtosJS");

//https://www.allkeysgenerator.com/Random/Security-Encryption-Key-Generator.aspx
const AES_KEY = "fTjWmZq4t7w!z%C*F-JaNdRgUkXp2r5u"; // 256-bit
const AES_IV = "$B&E)H@McQfTjWnZ"; // 128-bit

const encryptSTR = EncryptAes("Hello World", AES_KEY, AES_IV); // Gkkv0CjIKytncyU=
const decryptSTR = DecryptAes(encryptSTR, AES_KEY, AES_IV); // Hello World

console.log("encryptSTR: ", encryptSTR); // encryptSTR:  Gkkv0CjIKytncyU=
console.log("decryptSTR: ", decryptSTR); // decryptSTR:  Hello World
```

```typescript
// index.ts
import NtosJS from "./ntosjs";

//https://www.allkeysgenerator.com/Random/Security-Encryption-Key-Generator.aspx
const AES_KEY: string = "fTjWmZq4t7w!z%C*F-JaNdRgUkXp2r5u"; // 256-bit
const AES_IV: string = "$B&E)H@McQfTjWnZ"; // 128-bit

const encryptSTR: string = NtosJS.EncryptAes("Hello World", AES_KEY, AES_IV); // Gkkv0CjIKytncyU=
const decryptSTR: string = NtosJS.DecryptAes(encryptSTR, AES_KEY, AES_IV); // Hello World

console.log("encryptSTR: ", encryptSTR); // encryptSTR:  Gkkv0CjIKytncyU=
console.log("decryptSTR: ", decryptSTR); // decryptSTR:  Hello World
```

## 🔎 References

- [Nodejs Official Documentation](https://nodejs.org/api/addons.html)
- [CryptoPP](https://github.com/weidai11/cryptopp)

> ⚠️ Don't forget to change the AES_KEY and AES_IV variables for production 🤓
