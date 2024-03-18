#include "retezec.h"
#include <iostream>
#include <iomanip>

// Konstruktor bez parametrů
retezec::retezec() {
    arr = new char[1];
    arr[0] = '\0';
    pocet = 0;
}

// Konstruktor s parametrem
retezec::retezec(const char *n) {
        pocet = 0;
        while (n[pocet] != '\0') {
            ++pocet;
        }
        arr = new char[pocet + 1]; // +1 pro binární nulu
        for (int i = 0; i <= pocet; ++i) { // <= pro zahrnutí binární nuly
            arr[i] = n[i];
        }
arr[pocet] = '\0';
}

// Kopírovací konstruktor
retezec::retezec(const retezec &p) {

        pocet = p.delka();
        arr = new char[pocet + 1]; // +1 pro binární nulu
        for (int i = 0; i <= pocet; ++i) { // <= pro zahrnutí binární nuly
            arr[i] = p[i];
        }
    arr[pocet] = '\0';
}

// Destruktor
retezec::~retezec() {
    delete[] arr;
    this->pocet = 0;
}

// Metoda pro získání délky řetězce
int retezec::delka() const {
    return pocet;
}



// Přetížený operátor +=
retezec &retezec::operator+=(const retezec &p) {

        char *tmp = new char[pocet + p.delka() + 1]; // +1 pro binární nulu
        for (int i = 0; i < pocet; ++i) {
            tmp[i] = arr[i];
        }
        for (int i = 0; i <= p.delka(); ++i) { // <= pro zahrnutí binární nuly
            tmp[pocet + i] = p[i];
        }
        delete[] arr;
        arr = tmp;
        pocet += p.delka();

    return *this;
}

// Přetížený operátor =
retezec &retezec::operator=(const retezec &p) {
    if (this != &p) {
        delete[] arr;

            pocet = p.delka();
            arr = new char[pocet + 1]; // +1 pro binární nulu
            for (int i = 0; i <= pocet; ++i) { // <= pro zahrnutí binární nuly
                arr[i] = p[i];
            }
            arr[pocet] = '\0';

    }
    return *this;
}

// Přetížený operátor +
retezec retezec::operator+(const retezec &p) const {
    retezec tmp(*this);
    tmp += p;
    return tmp;
}

void retezec::vypis() {
std::cout << arr << std::endl;
}

char retezec::operator[](unsigned int index) const {
        if (index >= 0 && index < pocet) {
            return arr[index];
        }
    return arr[pocet - 1];
    }


char &retezec::operator[](unsigned int index) {
        if (index >= 0 && index < this->delka()) {
            return this->arr[index];
        }
    return arr[pocet - 1];

}

void retezec::set(const char *cizi) {
    delete[]this->arr;
    this->arr = new char[delka() + 1];
    // naplneni nove vytvoreneho pole prichazejicim stringem
    for (int i = 0; i <= delka(); ++i) {
        this->arr[i] = cizi[i];
    }
    // prirazeni binarni nuly do bonusoveho mista
    this->arr[delka() + 1] = '\0';
}

// Přetížený operátor <<
std::ostream &operator<<(std::ostream &os, const retezec &p) {
    os << std::setw(3) << p.delka() << " : ";
    for (int i = 0; i < p.delka(); ++i) {
        os << p[i]; //
    }
    os << std::endl;
    return os;
}
