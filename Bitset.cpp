#include "Bitset.h"
#include <iostream>

using namespace CPPLondonUni;


Bitset::Bitset(char bit) : bitfield{bit} {}

bool Bitset::test(int idx) { return (this->bitfield & (1<<idx)) > 0; }

bool Bitset::all() { return this->bitfield == (char)0xff; }

bool Bitset::any() {
    return static_cast<unsigned char>(this->bitfield) > 0;
}

bool Bitset::none() { return this->bitfield == 0; }

int Bitset::count() {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if(this->test(i)) {
            count++;
        }
    }
    return count;
}

int Bitset::size() { return sizeof(this->bitfield)* 8; }

void Bitset::set(int idx) {
    this->bitfield = this->bitfield | (char)(1<<idx);
}

void Bitset::reset(int idx) {
    this->bitfield = this->bitfield & (char)~(1<<idx);
}

void Bitset::flip() {
    this->bitfield = ~this->bitfield;
}
