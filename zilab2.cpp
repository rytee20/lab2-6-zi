#include <Windows.h>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

// Функция для шифрования по формуле Ti = Ci^29 mod 91
int encrypt(int charCode) {
    return static_cast<int>(pow(charCode, 5)) % 91;
}

// Функция для расшифрования по формуле Ti = Ci^61 mod 91
int decrypt(int encryptedChar) {
    long long result = 1;
    for (int i = 0; i < 29; ++i) {
        result = (result * encryptedChar) % 91;
    }
    return static_cast<int>(result);
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Таблица соответствия букв и их кодов
    map<char, int> charTableForward = {
        {'А', 1}, {'Б', 2}, {'В', 3}, {'Г', 4}, {'Д', 5}, {'Е', 6}, {'Ё', 7},
        {'Ж', 8}, {'З', 9}, {'И', 10}, {'Й', 11}, {'К', 12}, {'Л', 13}, {'М', 14},
        {'Н', 15}, {'О', 16}, {'П', 17}, {'Р', 18}, {'С', 19}, {'Т', 20}, {'У', 21},
        {'Ф', 22}, {'Х', 23}, {'Ц', 24}, {'Ч', 25}, {'Ш', 26}, {'Щ', 27}, {'Ъ', 28},
        {'Ы', 29}, {'Ь', 30}, {'Э', 31}, {'Ю', 32}, {'Я', 33}, {' ', 34}, {'0', 35},
        {'1', 36}, {'2', 37}, {'3', 38}, {'4', 39}, {'5', 40}, {'6', 41}, {'7', 42},
        {'8', 43}, {'9', 44}
    };

    map<int, char> charTableBackward = {
        {1, 'А'}, {2, 'Б'}, {3, 'В'}, {4, 'Г'}, {5, 'Д'}, {6, 'Е'}, {7, 'Ё'},
        {8, 'Ж'}, {9, 'З'}, {10, 'И'}, {11, 'Й'}, {12, 'К'}, {13, 'Л'}, {14, 'М'},
        {15, 'Н'}, {16, 'О'}, {17, 'П'}, {18, 'Р'}, {19, 'С'}, {20, 'Т'}, {21, 'У'},
        {22, 'Ф'}, {23, 'Х'}, {24, 'Ц'}, {25, 'Ч'}, {26, 'Ш'}, {27, 'Щ'}, {28, 'Ъ'},
        {29, 'Ы'}, {30, 'Ь'}, {31, 'Э'}, {32, 'Ю'}, {33, 'Я'}, {34, ' '}, {35, '0'},
        {36, '1'}, {37, '2'}, {38, '3'}, {39, '4'}, {40, '5'}, {41, '6'}, {42, '7'},
        {43, '8'}, {44, '9'}
    };

    int counter = 0;
    string message;
    int encrypted[100];

    // Ввод сообщения
    cout << "Введите сообщение для шифрования: ";
    cin >> message;

    // Шифрование
    for (char ch : message)
        if (charTableForward.count(ch) > 0) {
            encrypted[counter] = encrypt(charTableForward[ch]);
            counter++;
        }

    cout << "Ti/Зашифрованное сообщение: ";
    for (int i = 0;i < counter;i++) cout << encrypted[i] << " ";
    cout << endl;

    // Расшифрование
    cout << "Ci: ";
    for (int i = 0;i < counter;i++) cout << decrypt(encrypted[i]) << " ";
    cout << endl;

    cout << "Расшифрованное сообщение: ";
    for (int i = 0;i < counter;i++)
        cout << charTableBackward[decrypt(encrypted[i])];
    cout << endl;

    return 0;
}
