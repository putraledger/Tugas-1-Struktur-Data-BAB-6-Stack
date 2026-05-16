#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

stack<int> A, B, C;

void tampilStack(stack<int> s, char nama) {
    int arr[100], i = 0;
    stack<int> temp = s;
    while (!temp.empty()) {
        arr[i++] = temp.top();
        temp.pop();
    }
    cout << nama << ": ";
    if (i == 0) cout << "kosong";
    else for (int j = i-1; j >= 0; j--) cout << arr[j] << " ";
    cout << endl;
}

void tampilSemua() {
    cout << "\n=== Keadaan Tiang ===" << endl;
    tampilStack(A, 'A');
    tampilStack(B, 'B');
    tampilStack(C, 'C');
    cout << endl;
}

void pindah(char asal, char tujuan) {
    stack<int>* dari = nullptr;
    stack<int>* ke = nullptr;

    switch (toupper(asal)) {
        case 'A': dari = &A; break;
        case 'B': dari = &B; break;
        case 'C': dari = &C; break;
        default: cout << "Tiang asal tidak valid!\n"; return;
    }
    switch (toupper(tujuan)) {
        case 'A': ke = &A; break;
        case 'B': ke = &B; break;
        case 'C': ke = &C; break;
        default: cout << "Tiang tujuan tidak valid!\n"; return;
    }

    if (dari->empty()) {
        cout << "Tiang asal kosong!\n";
        return;
    }
    int nilai = dari->top();
    dari->pop();
    ke->push(nilai);
    cout << "Memindahkan " << nilai << " dari " << (char)toupper(asal) << " ke " << (char)toupper(tujuan) << endl;
}

int main() {
    A.push(100);
    A.push(75);
    A.push(50);

    cout << "=== TOWER OF HANOI (tanpa aturan ukuran) ===" << endl;
    cout << "Ikuti langkah soal: \n";
    cout << "1. A C  2. A C  3. A B  4. C B  5. C B\n";
    cout << "------------------------------------------------\n";

    char asal, tujuan;
    do {
        tampilSemua();
        cout << "Perintah (contoh: A C) atau 'X' keluar: ";
        cin >> asal;
        if (toupper(asal) == 'X') break;
        cin >> tujuan;
        pindah(asal, tujuan);
    } while (true);

    cout << "Program selesai.\n";
    return 0;
}