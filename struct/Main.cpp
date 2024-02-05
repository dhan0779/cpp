#include <iostream>

struct PPN {
    unsigned int PFN : 22;
    int : 3;
    unsigned int CCA : 3;
    bool nonreachable : 1;
    bool dirty : 1;
    bool valid : 1; 
    bool global : 1;
}; // bit field used to represent certain fields

void part_VM(PPN* p) {
    if (p->dirty) {
        // copy to disk
        p->dirty = 0;
    }
}

// Surprisingly, using fields to pack in several variables into a single byte doesn't actually save space
// it does save DATA SPACE, but the size of the code needed to manipulate the data increases
// it is typically much faster to access a char than to access a field

int main() {

}