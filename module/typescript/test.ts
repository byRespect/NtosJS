import NtosJS from "./ntosjs";

//https://www.allkeysgenerator.com/Random/Security-Encryption-Key-Generator.aspx
const AES_KEY: string = "fTjWmZq4t7w!z%C*F-JaNdRgUkXp2r5u"; // 256-bit
const AES_IV: string = "$B&E)H@McQfTjWnZ"; // 128-bit

const encryptSTR: string = NtosJS.EncryptAes("Hello World", AES_KEY, AES_IV);
const decryptSTR: string = NtosJS.DecryptAes(encryptSTR, AES_KEY, AES_IV);

console.log("encryptSTR: ", encryptSTR);
console.log("decryptSTR: ", decryptSTR);
