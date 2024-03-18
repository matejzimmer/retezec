#ifndef RETEZEC_H
#define RETEZEC_H

#include <iostream>
#include <ostream>



class retezec {
public:
    retezec();

    retezec(const char *);

    retezec(const retezec &);

    ~retezec();

    retezec &operator=(const retezec &);

    retezec &operator+=(const retezec &);

    retezec operator+(const retezec &) const;

    char operator[](unsigned int) const;

    char &operator[](unsigned int);

    int delka() const;

    void vypis();

    void set(const char *);



private:
    char *arr;
    int pocet;

};
std::ostream &operator<<(std::ostream &, const retezec &);


#endif
