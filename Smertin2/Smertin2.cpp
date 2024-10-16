#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <vector>
#include <clocale>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;
void showdq(deque <int> d) {
    cout << "Дек D содержит: ";
    deque<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}
void showdqstr(deque <string> d) {
    cout << "Дек D содержит: ";
    for (const auto& wr:d) {
        cout << wr << " ";
    }
    cout << endl;
}
void showlist(list <int> l) {
    cout << "Лист L содержит: ";
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}
void showvr(vector <int> p) {
    cout << "Вектор P содержит: ";
    vector<int>::iterator it;
    for (it = p.begin(); it != p.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}

//#1 - 4
void num1(deque <int> d) {
    for (int i = 1; i <= 10; ++i) {
        d.push_back(i);
    }
    showdq(d);
    // Вывод первой половины в обратном порядке
    auto mid = d.begin() + d.size() / 2 - 1;
    deque <int> ::iterator rev_it = mid;
    cout << "Первая половина в обратном порядке: ";
    for (; rev_it != d.begin(); rev_it--) {
        cout << *rev_it << " ";
    }
    cout << *rev_it;
    cout << endl;

    // Вывод второй половины в обратном порядке
    rev_it = d.end() - 1;
    cout << "Вторая половина в прямом порядке: ";
    for (; rev_it != mid; rev_it--) {
        cout << *rev_it << " ";
    }
    cout << endl;
}

//#2 - 5
void insertLastFiveElements(list<int>& l, deque<int>& d) {
    showlist(l);
    showdq(d);
    auto it = l.end();
    it--;
    it--;
    it--;
    it--;
    it--;
    // Получаем последние 5 элементов дек D
    deque<int> lastFiveElements(d.begin() + (d.size() - 5), d.end());

    // Вставляем эти элементы в список L в обратном порядке
    l.insert(it, lastFiveElements.rbegin(), lastFiveElements.rend());
}

//#3 - 3
void num3(list <int>& l, vector<int>& p) {
    cout << "Исходные данные:" << endl;
    showlist(l);
    showvr(p);
    auto it = l.begin();
    advance(it, l.size() / 2);
    p.push_back(*it);
    l.erase(it);
    cout << "Итоговые данные:" << endl;
    showlist(l);
    showvr(p);
}
//#4 - 6
char doubleChar(char c) {
    return static_cast<char>(static_cast<unsigned char>(c) * 2);
}

//#5 - 4
void num5(list<int>& L) {
    // Поиск первого отрицательного элемента
    auto firstNegative = find_if(L.begin(), L.end(), [](int x) { return x < 0; });
    if (firstNegative == L.end()) {
        return;
    }
    // Поиск второго отрицательного элемента
    auto secondNegative = find_if(next(firstNegative), L.end(), [](int x) { return x < 0; });
    if (secondNegative == L.end()) {
        L.erase(next(firstNegative), L.end());
    }
    else {
        // Удаляем все элементы между первым и вторым отрицательными
        L.erase(next(firstNegative), secondNegative);
    }
}

//#6 - 13
void num6(list<int>& l) {
    list<int>newList;
    auto mid = l.begin();
    advance(mid, l.size() / 2);
    auto result = remove_copy_if(mid, l.end(), back_inserter(newList), [](int x) {return x < 0; });
    for (auto it = newList.rbegin(); it != newList.rend(); ++it) {
        l.push_front(*it);
    }
}

//#8 - 2
//struct Pair {
//    char left;
//    char right;
//};
//Pair createPair(const string& word1, const string& word2) {
//    return { word1[word1.length() - 1], word2[0] };
//}
//deque<string> buildDeque(const vector<string>& words) {
//    deque<Pair> result;
//    vector<Pair> pairs;
//
//    // Создаем пары из слов
//    for (size_t i = 0; i < words.size() - 1; ++i) {
//        pairs.emplace_back(createPair(words[i], words[i + 1]));
//    }
//
//    // Применяем алгоритм adjacent_difference
//    adjacent_difference(pairs.begin(), pairs.end(),
//        inserter(result, result.begin()),
//        [](const Pair& p1, const Pair& p2) -> Pair {
//            return { p1.left, p2.right };
//        });
//
//    // Преобразуем пары обратно в строки
//    vector<string> resultStrings;
//    for (const auto& pair : result) {
//        resultStrings.emplace_back(1, pair.left);
//        resultStrings.emplace_back(1, pair.right);
//    }
//
//    // Сортируем строки по длине (если необходимо)
//    sort(resultStrings.begin(), resultStrings.end());
//
//    return deque<string>(resultStrings);
//}


int main() {
    setlocale(LC_ALL, "rus");
    //#1 - 4
    cout << "#1 - 4" << endl;
    deque<int> d;
    num1(d);

    //#2 - 5
    cout << "#2 - 5" << endl;
    deque<int> D = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list<int> L = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    insertLastFiveElements(L, D);
    // Выводим результат
    for (const auto& elem : L) {
        cout << elem << " ";
    }
    cout << endl;

    //#3 - 3
    cout << "#3 - 3" << endl;
    vector <int> p = { 10,11,12,13,14,15 };
    list <int> l = { 1,2,3,4,5 };
    num3(l, p);

    //#4 - 6
    //cout << "#4 - 6" << endl;
    //string name;
    //cout << "Введите имя файла без расширения: ";
    //cin >> name;
    //// Получаем набор символов из стандартного ввода
    //set <char> chars;
    //char symbol;
    //int count;
    //cout << "Введите кол-во символов: ";
    //cin >> count;

    //while (count > 0) {
    //    cin >> symbol;
    //    chars.insert(symbol);
    //    count--;

    //}
    //// Создаем пустую строку для хранения результата
    //string result;

    //// Применяем преобразование ко всем символам
    //transform(chars.begin(), chars.end(), back_inserter(result),
    //    doubleChar);

    //// Записываем результат в файл
    //ofstream outFile(name + ".txt");
    //if (!outFile.is_open()) {
    //    cerr << "Ошибка при открытии файла!" << endl;
    //    return 1;
    //}

    //outFile << result << endl;

    //cout << "Результат успешно записан в файл." << endl;

    //#5 - 4
    cout << "#5 - 4" << endl;
    list <int> l5_1 = { 1,2,3,4,5 };
    list <int> l5_2 = { 1,-2,3,4,5,6,-7,11,12,34 };
    list <int> l5_3 = { 1,2,3,-4,5,6,7,8,9,0,1 };
    cout << "Нет отрицательных чисел:" << endl;
    showlist(l5_1);
    num5(l5_1);
    showlist(l5_1);
    cout << "Два отрицательных числа:" << endl;
    showlist(l5_2);
    num5(l5_2);
    showlist(l5_2);
    cout << "Одно отрицательное число:" << endl;
    showlist(l5_3);
    num5(l5_3);
    showlist(l5_3);
    //#6 - 13
    cout << "#6 - 13" << endl;
    list<int> l6 = { -1,-2,-3,4,-5,6,7,-8,9,10 };
    showlist(l6);
    num6(l6);
    showlist(l6);
    //#7 - 10
    cout << "#7 - 10" << endl;
    deque<string> d7;
    d7.push_back("apple");
    d7.push_back("button");
    d7.push_back("banana");
    d7.push_back("cherry");
    d7.push_back("date");
    d7.push_back("wilderries");
    showdqstr(d7);
    sort(d7.begin(), d7.end());
    showdqstr(d7);
    stable_sort(d7.begin(),d7.end(),
        [](const std::string& a, const std::string& b) {
        return a.length() < b.length(); });
    showdqstr(d7);

    //#8 - 2
    //cout << "#8 - 2" << endl;
    //vector<string> words = { "ABC", "DEF", "KLM", "XYZ" };
    //deque<string> dequeResult = buildDeque(words);
    //// Выводим результаты
    //for (const auto& str : dequeResult) {
    //    cout << str << " ";
    //}
    //cout << endl;

    //#9 - 1
    //cout << "#9 - 1" << endl;

    //#10 - 1
    //cout << "#10 - 1" << endl;

    return 0;
}
