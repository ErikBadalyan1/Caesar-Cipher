#include <iostream>
#include <string>

std::string encryptCaesar(std::string text, int shift) {
    std::string result = "";

    for (char c : text) {
        if (isalpha(c)) { 
            char base = islower(c) ? 'a' : 'A'; 
            result += char(int(base + (c - base + shift) % 26)); 
        } else {
            result += c; 
        }
    }

    return result;
}

std::string decryptCaesar(std::string text, int shift) {
    return encryptCaesar(text, 26 - shift); 
}

int main() {
    std::string text;
    int shift;

    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);

    std::cout << "Введите сдвиг (ключ): ";
    std::cin >> shift;

    std::string encrypted = encryptCaesar(text, shift);
   std:: cout << "Зашифрованный текст: " << encrypted <<std:: endl;

    std::string decrypted = decryptCaesar(encrypted, shift);
    std::cout << "Расшифрованный текст: " << decrypted <<std:: endl;

    return 0;
}
