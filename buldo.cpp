// aceasta este o rezolvare in complexitate logaritmica O(n + n*log(n)) a problemei
// numarul 1 de la OJI 2020 clasa a noua.
// se ia mai intai elementul cel mai mare din vector, iar apoi,
// utilizandu-ne de functia check(), verificam cu DIVIDE ET IMPERA
// toate valorile pe un interval left, right care se injumatateste la fiecare
// parcurgere. solutia trece de toate testele si ia 100 de puncte.


#include <fstream>

using namespace std;

int n, v[100001], o = 0;

bool check(int v[], int n, int h) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] >= h)
            c += (v[i] - h);
        else {
            int dif = h - v[i];
            if (c < dif)
                return false;
            else
                c -= dif;
        }
    }
    return true;
}

int getmax(int v[], int n) {
    int nrmax = -1;
    for (int i = 1; i <= n; i++)
        if (v[i] > nrmax) nrmax = v[i];
    return nrmax;
}

//divide et impera -> log n
int hmax(int v[], int n, int left, int right) {
    if (left + 1 == right) return left;
    else {
        int middle = (left + right)/2;
        if (check(v, n, middle)) return hmax(v, n, middle, right);
        else return hmax(v, n, left, middle);
    }
}

ifstream fin("buldo.in");
ofstream fout("buldo.out");

void citire() {
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
}

void afisare() {
    fout << hmax(v, n, 0, getmax(v, n));
}

int main() {
    citire();
    afisare();
}
