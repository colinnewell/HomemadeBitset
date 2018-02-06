#include "Bitset.h"

using namespace CPPLondonUni;

Bitset::Bitset(char bit) : bitfield{bit} {}

bool Bitset::test(int idx) { return bitfield & (1 << idx); }

bool Bitset::all() { return bitfield == static_cast<char>(0xFF); }

bool Bitset::any() { return static_cast<unsigned char>(bitfield) > 0; }

bool Bitset::none() { return bitfield == 0; }

int Bitset::count() {
	int ret;
	for(int i = 0; i < 8; ++i)
		if(test(i))
			ret++;
	return ret;
}

int Bitset::size() { return 8; }

void Bitset::set(int idx) {
	bitfield |= (1 << idx);
}

void Bitset::reset(int idx) {
	bitfield &= ~(1 << idx);
}

void Bitset::flip() {
	bitfield = ~bitfield;
}
