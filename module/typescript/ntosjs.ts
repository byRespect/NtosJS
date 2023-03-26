const NativeNtosJS = require("../../build/Release/NtosJS.node");
export interface INtosJS {
  EncryptAes: (Text: string, CipherKey: string, IvKey: string) => string;
  DecryptAes: (Text: string, CipherKey: string, IvKey: string) => string;
}
export const { DecryptAes, EncryptAes }: INtosJS = NativeNtosJS;
const NtosJS = { DecryptAes, EncryptAes };
export default NtosJS;
