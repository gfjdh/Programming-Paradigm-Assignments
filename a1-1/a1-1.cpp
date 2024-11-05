#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int countWords(const string &filename, const string &word) {
    ifstream file(filename);
    if (!file.is_open()) 
        return -1; // 文件打开失败返回-1
    int count = 0;
    string line, target = word;

    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        while (iss >> token) 
            if (token == target) 
                count++; // 逐词比较并计数
    }
    file.close();
    return count;
}

int main() {
    cout << countWords("file.txt", "that") << endl;
    return 0;
}