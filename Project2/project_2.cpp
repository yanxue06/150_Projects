#include <iostream> 
#include <cassert>

// int main();  
void pattern(unsigned int n);
unsigned int log10(unsigned int n);
unsigned int count(unsigned int n, unsigned int bit ); 
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1); 

// int main() {
//     // unsigned int pattern_size{};   
//     // std::cout << "submit the size of your pattern: "; 
//     // std::cin >> pattern_size; 
//     // std::cout << std::endl; 
//     // pattern(pattern_size);

//     // unsigned int log_number{};
//     // std::cout << "submit a number for log calculation: "; 
//     // std::cin >> log_number; 
//     // unsigned int m = log10(log_number); 
//     // std::cout << m << std::endl; 

//      std::cout << (0xff45f112 == swap_bytes(0xf145ff12, 1, 3)) << std::endl;

// }

unsigned int log10(unsigned int n) {
    assert(n!=0);
    unsigned int m{0}; 
    while (n>=10) {
        n=n/10; 
        ++m;
    }
    return m; 
}

void pattern(unsigned int n) {
    unsigned int longest_astrix{n*2+1}; 
    unsigned int spaces{};  
    unsigned int astrix_nums{}; 
    unsigned int loop_num{n}; 
    //first half of the triangle
    for (unsigned int i=loop_num; i>=0; --i) {
        astrix_nums=i*2+1; 
        spaces=(longest_astrix-astrix_nums)/2; 
        for (unsigned int j=0; j<spaces; j++) {
            std::cout << " ";
        }
        for (unsigned int k=0; k<astrix_nums; k++) { 
            std::cout << "*"; 
        } 
        std::cout << std::endl;
        if (i==0) {
            break; 
        }
    }
    //second half of the triangle
    //used <= because it has to loop once extra to print the first astrix
    for (unsigned int i=1; i<=loop_num; ++i) {
        astrix_nums=i*2+1; 
        spaces=(longest_astrix-astrix_nums)/2; 
        for (unsigned int j=0; j<spaces; j++) {
            std::cout << " ";
        }
        for (unsigned int k=0; k<astrix_nums; k++) { 
            std::cout << "*"; 
        } 
        std::cout << std::endl;
    }
    //may need to print extra endl "print endl, including the last line"
}

unsigned int count(unsigned int n, unsigned int bit ) {
    unsigned int count1{0}; 
    assert(bit==1 || bit==0); 
    for (unsigned int k{1}; k != 0; k <<= 1 ) {
        if ((n&k) == k) {
            count1++; 
        }
    }
    if (bit==1) {
        return count1; 
    }
    return 32-count1; 
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
    assert((b0>=0 && b0<=3) && (b1>=0 && b1<=3)); 
    unsigned int MASK1{0xff}; 
    unsigned int MASK2{0xff}; 
    unsigned int Combo_MASK{}; 
    unsigned int byte1{}; 
    unsigned int byte2{}; 
    unsigned int Combo_byte{}; 
    
    //shifts the masks 
    MASK1 <<= (b0*8);
    MASK2 <<= (b1*8); 
    
    byte1 = n & MASK1; 
    byte2 = n & MASK2; 
    //now swap 1 and swap 2 are there correct bits
    //we want to take n and manipulate it so that we swap byte1 and byte2
    Combo_MASK = MASK1 | MASK2; 
    n = n & ~Combo_MASK; //swapped values places are now zeroes

    
    byte1 >>= (b0 * 8);  // move back to original location
    byte2 >>= (b1 * 8); 

    byte1 <<= (b1 * 8); // move to byte 2's location
    byte2 <<= (b0 * 8); // move to byte 1's location

    Combo_byte = byte1 | byte2; 
    n = n | Combo_byte; 

    return n; 
}