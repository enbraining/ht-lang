#include <iostream>
#include <fstream>

using namespace std;

enum ValueType {
    STRING,
    NUMBER
};

enum FunctionType {
    PRINT,
    UNKNOWN
};

struct Function {
    FunctionType function_type;
    ValueType value_type;
    char value[256];
};

void search(char arr[256], long index);
FunctionType get_function_name(char name[256]);
bool isEnter(char text[2]);

int main() {
    ifstream input_file;
    string name, file_name;

    input_file.open("/Users/enbraining/CLionProjects/untitled1/main.ht");
    if(!input_file) cout << "NOT FOUND";
    if(input_file.is_open()) {
        for(long i = 1; !input_file.eof(); i++){
            char arr[256];
            input_file.getline(arr, 256);
            search(arr, i);
        }
        input_file.close();
    }
}

FunctionType get_function_name(char name[256]) {
    for(int i = 0; i < 256; i++) {
        if(name[i] == 'p' && name[i + 1] == 'r' && name[i + 2] == 'i' && name[i + 3] == 'n' && name[i + 4] == 't')
            return PRINT;
    }

    return UNKNOWN;
}

bool isEnter(char a, char b) {
    if(a == '\\' && b == 'n') return true;
    return false;
}

void search(char arr[256], long index) {
    if(get_function_name(arr) == PRINT) {
        int length = 5;
        for(int j = 0; arr[2 + length + j] != '\"'; j++) {
            if(isEnter(arr[2 + length + j], arr[3 + length + j])) {
                cout << '\n';
                j++;
            } else cout << arr[2 + length + j];
        }
    } else {
        cout << "\n\n----------\n[error] " + std::to_string(index) + "번째 줄에서 에러가 생겼습니다.\n----------\n\n";
    }
}

