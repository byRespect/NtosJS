const { EncryptAes, DecryptAes } = require("../../build/Release/NtosJS.node");

//https://www.allkeysgenerator.com/Random/Security-Encryption-Key-Generator.aspx
const AES_KEY = "fTjWmZq4t7w!z%C*F-JaNdRgUkXp2r5u"; // 256-bit
const AES_IV = "$B&E)H@McQfTjWnZ"; // 128-bit

const encryptSTR = EncryptAes("Hello World", AES_KEY, AES_IV);
const decryptSTR = DecryptAes(encryptSTR, AES_KEY, AES_IV);

console.log("encryptSTR: ", encryptSTR);
console.log("decryptSTR: ", decryptSTR);
