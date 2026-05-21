#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <conio.h>


using namespace std;

// Функция для установки цвета текста в консоли
void setColor(int color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#endif
}

// Функция для очистки консоли
void clearScreen() {
    system("cls");
}

// Функция для выделения слова
string highlightWord(const string& word) {
    return "***" + word + "***";
}

// Функция для поиска последнего слова, начинающегося с заданной буквы
pair<int, string> findWordsStartingWith(const string& text, char letter) {
    stringstream ss(text);
    string word;
    int count = 0;
    string lastFoundWord = "";
    
    while (ss >> word) {
        // Очищаем слово от знаков препинания в конце
        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }
        
        // Проверяем первый символ (без учета регистра)
        if (!word.empty() && tolower(word[0]) == tolower(letter)) {
            count++;
            lastFoundWord = word;
        }
    }
    
    return make_pair(count, lastFoundWord);
}

// Функция для вывода текста с выделением указанного слова
void printTextWithHighlight(const string& text, const string& wordToHighlight) {
    stringstream ss(text);
    string token;
    bool first = true;
    
    while (ss >> token) {
        if (!first) {
            cout << " ";
        }
        first = false;
        
        // Очищаем токен от знаков препинания для сравнения
        string cleanToken = token;
        while (!cleanToken.empty() && ispunct(cleanToken.back())) {
            cleanToken.pop_back();
        }
        
        if (cleanToken == wordToHighlight) {
            // Выделяем слово цветом и звездочками
            setColor(14); // Желтый цвет
            cout << highlightWord(token);
            setColor(7);  // Сброс цвета
        } else {
            cout << token;
        }
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    const string filename = "text.txt";
    ifstream checkFile(filename);
    if (!checkFile) {
        ofstream createFile(filename);
        createFile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                   << "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                   << "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                   << "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
                   << "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
                   << "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
                   << "culpa qui officia deserunt mollit anim id est laborum.";
        createFile.close();
        cout << "Файл " << filename << " создан.\n";
    } else {
        checkFile.close();
    }
    
    // Чтение содержимого файла
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return 1;
    }
    
    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();
    file.close();
    
    // Вывод исходного текста
    cout << "Исходный текст:\n";
    cout << "========================================\n";
    cout << text << endl;
    cout << "========================================\n\n";
    
    // Ввод буквы от пользователя
    char letter;
    cout << "Введите букву для поиска слов: ";
    cin >> letter;
    
    // Подсчет слов и поиск последнего найденного
    auto result = findWordsStartingWith(text, letter);
    int count = result.first;
    string lastWord = result.second;
    
    cout << "\nКоличество слов, начинающихся с буквы '" << letter << "': " << count << endl;
    cout << "Последнее найденное слово: " << (lastWord.empty() ? "(нет)" : lastWord) << endl;
    
    cout << "\nНажмите любую клавишу для выделения последнего найденного слова...";
    _getch();  // Ожидание нажатия клавиши
    
    // Очистка консоли и вывод с выделением
    clearScreen();
    
    cout << "Исходный текст с выделенным последним найденным словом:\n";
    cout << "========================================\n";
    
    if (!lastWord.empty()) {
        printTextWithHighlight(text, lastWord);
    } else {
        cout << text << endl;
        cout << "\n(Слов, начинающихся с буквы '" << letter << "', не найдено)\n";
    }
    
    cout << "========================================\n";
    cout << "\nПрограмма завершена. Нажмите любую клавишу для выхода...";
    _getch();
    
    return 0;
}