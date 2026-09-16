#include <iostream>


int customStrLen(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}


bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}


int getAlphabetValue(char c) {
    if (isUpper(c)) {
        return c - 'A' + 1;
    } else if (isLower(c)) {
        return c - 'a' + 1;
    }
    return 0; // Karakter non-alfabet
}


char shiftCharacter(char current, int shiftVal) {
    if (isUpper(current)) {
        int pos = current - 'A';
        int newPos = (pos + shiftVal) % 26;
        return 'A' + newPos;
    } else if (isLower(current)) {
        int pos = current - 'a';
        int newPos = (pos + shiftVal) % 26;
        return 'a' + newPos;
    }
    return current; 
}

int main() {
    char inputMsg[500];
    char encryptedMsg[500];
    
    std::cout << "========================================" << std::endl;
    std::cout << "           ALIEN-IN-THE-MIDDLE      " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Masukkan pesan rahasia (contoh: ALIENS): ";
    std::cin >> inputMsg;
    
    int len = customStrLen(inputMsg);
    
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            
            encryptedMsg[i] = inputMsg[i];
        } else {
           
            char prevChar = inputMsg[i - 1];
            int shiftVal = getAlphabetValue(prevChar);
            encryptedMsg[i] = shiftCharacter(inputMsg[i], shiftVal);
        }
    }
    encryptedMsg[len] = '\0'; 
    
    std::cout << "\nPesan Ter-sandi (Hasil Enkripsi): " << encryptedMsg << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}
