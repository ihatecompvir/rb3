#include "macros.h"
#include "KeyChain.h"

const unsigned char hiddenKeys[0x180] = {
    0x7f,0x95,0x5b,0x9d,0x94,0xba,0x12,0xf1,0xd7,0x5a,0x67,0xd9,0x16,0x45,0x28,0xdd,
    0x61,0x55,0x55,0xaf,0x23,0x91,0xd6,0x0a,0x3a,0x42,0x81,0x18,0xb4,0xf7,0xf3,0x04,
    0x78,0x96,0x5d,0x92,0x92,0xb0,0x47,0xac,0x8f,0x5b,0x6d,0xdc,0x1c,0x41,0x7e,0xda,
    0x6a,0x55,0x53,0xaf,0x20,0xc8,0xdc,0x0a,0x66,0x43,0xdd,0x1c,0xb2,0xa5,0xa4,0x0c,
    0x7e,0x92,0x5c,0x93,0x90,0xed,0x4a,0xad,0x8b,0x07,0x36,0xd3,0x10,0x41,0x78,0x8f,
    0x60,0x08,0x55,0xa8,0x26,0xcf,0xd0,0x0f,0x65,0x11,0x84,0x45,0xb1,0xa0,0xfa,0x57,
    0x79,0x97,0x0b,0x90,0x92,0xb0,0x44,0xad,0x8a,0x0e,0x60,0xd9,0x14,0x11,0x7e,0x8d,
    0x35,0x5d,0x5c,0xfb,0x21,0x9c,0xd3,0x0e,0x32,0x40,0xd1,0x48,0xb8,0xa7,0xa1,0x0d,
    0x28,0xc3,0x5d,0x97,0xc1,0xec,0x42,0xf1,0xdc,0x5d,0x37,0xda,0x14,0x47,0x79,0x8a,
    0x32,0x5c,0x54,0xf2,0x72,0x9d,0xd3,0x0d,0x67,0x4c,0xd6,0x49,0xb4,0xa2,0xf3,0x50,
    0x28,0x96,0x5e,0x95,0xc5,0xe9,0x45,0xad,0x8a,0x5d,0x64,0x8e,0x17,0x40,0x2e,0x87,
    0x36,0x58,0x06,0xfd,0x75,0x90,0xd0,0x5f,0x3a,0x40,0xd4,0x4c,0xb0,0xf7,0xa7,0x04,
    0x2c,0x96,0x01,0x96,0x9b,0xbc,0x15,0xa6,0xde,0x0e,0x65,0x8d,0x17,0x47,0x2f,0xdd,
    0x63,0x54,0x55,0xaf,0x76,0xca,0x84,0x5f,0x62,0x44,0x80,0x4a,0xb3,0xf4,0xf4,0x0c,
    0x7e,0xc4,0x0e,0xc6,0x9a,0xeb,0x43,0xa0,0xdb,0x0a,0x64,0xdf,0x1c,0x42,0x24,0x89,
    0x63,0x5c,0x55,0xf3,0x71,0x90,0xdc,0x5d,0x60,0x40,0xd1,0x4d,0xb2,0xa3,0xa7,0x0d,
    0x2c,0x9a,0x0b,0x90,0x9a,0xbe,0x47,0xa7,0x88,0x5a,0x6d,0xdf,0x13,0x1d,0x2e,0x8b,
    0x60,0x5e,0x55,0xf2,0x74,0x9c,0xd7,0x0e,0x60,0x40,0x80,0x1c,0xb7,0xa1,0xf4,0x02,
    0x28,0x96,0x5b,0x95,0xc1,0xe9,0x40,0xa3,0x8f,0x0c,0x32,0xdf,0x43,0x1d,0x24,0x8d,
    0x61,0x09,0x54,0xab,0x27,0x9a,0xd3,0x58,0x60,0x16,0x84,0x4f,0xb3,0xa4,0xf3,0x0d,
    0x25,0x93,0x08,0xc0,0x9a,0xbd,0x10,0xa2,0xd6,0x09,0x60,0x8f,0x11,0x1d,0x7a,0x8f,
    0x63,0x0b,0x5d,0xf2,0x21,0xec,0xd7,0x08,0x62,0x40,0x84,0x49,0xb0,0xad,0xf2,0x07,
    0x29,0xc3,0x0c,0x96,0x96,0xeb,0x10,0xa0,0xda,0x59,0x32,0xd3,0x17,0x41,0x25,0xdc,
    0x63,0x08,0x04,0xae,0x77,0xcb,0x84,0x5a,0x60,0x4d,0xdd,0x45,0xb5,0xf4,0xa0,0x05
};

unsigned char asciiDigitToHex(char digit){
    if(0x61 <= digit && digit <= 0x66){
        return digit - 0x57;
    }
    if(0x41 <= digit && digit <= 0x46){
        return digit - 0x37;
    }
    return digit - 0x30;
}

void parseHex16(const char* input, unsigned char* output){
    const char* src = input;
    unsigned int val;
    int i;
    
    for (i = 0; i < 0x10; i++, src += 2){
        val = asciiDigitToHex(src[1]) + (asciiDigitToHex(src[0]) << 4);
        *output++ = val;
    }
}

int random(long l){
    static long s_seed = 0xEB;
    if(l != 0) s_seed = l;
    s_seed = s_seed * 0x19660E + 0x3C6EF35F;
    return s_seed;
}

// could even be a class, see: https://decomp.me/scratch/3ZAu1
#define NEEDS_BYTESWAP(p, v) (*(((unsigned char*)(p)) + 3) == (v))
#define BYTESWAP_32BIT(v) do {    \
    unsigned char t0, t1;    \
    t0 = *((unsigned char*)(v) + 0);    \
    t1 = *((unsigned char*)(v) + 3);    \
    *((unsigned char*)(v) + 0) = t1;    \
    *((unsigned char*)(v) + 3) = t0;    \
    t0 = *((unsigned char*)(v) + 1);    \
    t1 = *((unsigned char*)(v) + 2);    \
    *((unsigned char*)(v) + 1) = t1;    \
    *((unsigned char*)(v) + 2) = t0;    \
} while (0);

void KeyChain::getMasher(unsigned char* uc){
    unsigned int* masher_p = reinterpret_cast<unsigned int*>(uc);
    unsigned int m = 1;
    int needs_byteswap = NEEDS_BYTESWAP(&m, 1);
    
    for(int i = 0; i < 8; i++){
        *masher_p = random((i == 0) ? 0xEB : 0);

        if (needs_byteswap) {
            BYTESWAP_32BIT(masher_p);
        }

        masher_p++;
    }
}

void mash(unsigned char* uc1, unsigned char* uc2){
    unsigned int* ui1 = (unsigned int*)uc1;
    unsigned int* ui2 = (unsigned int*)uc2;
    for(int i = 0; i < 8; i++){
        ui1[i] = ui1[i] ^ ui2[i];
    }
}

int roll(int i){
    unsigned int a = i + 19;
    unsigned int b = a << 27;
    a >>= 31;
    b = ROTATE_LEFT(b - a, 5); // ROTATE_RIGHT(b - a, 27)
    return b + a;
    // return (i + 19) % 32; // is apparently simpler
}

void swap(char& c1, char& c2){
    char tmp = c1;
    c1 = c2;
    c2 = tmp;
}

void shuffle1(char* c){
    for(int i = 0; i < 8; i++){
        swap(c[roll(i * 4)], c[i * 4 + 2]);
        swap(c[roll(i * 4 + 3)], c[i * 4 + 1]);
    }
}

void shuffle2(char* c){
    for(int i = 0; i < 8; i++){
        swap(c[(7 - i) * 4 + 1], c[i * 4 + 2]);
        swap(c[(7 - i) * 4], c[i * 4 + 3]);
    }
}

void shuffle3(char* c){
    for(int i = 0; i < 8; i++){
        swap(c[roll((7 - i) * 4 + 1)], c[i * 4 + 2]);
        swap(c[(7 - i) * 4], c[i * 4 + 3]);
    }
}

void shuffle4(char* c){
    for(int i = 0; i < 8; i++){
        swap(c[(7 - i) * 4 + 1], c[i * 4 + 2]);
        swap(c[roll((7 - i) * 4)], c[i * 4 + 3]);
    }
}

void shuffle5(char* c){
    for(int i = 0; i < 8; i++){
        swap(c[(7 - i) * 4 + 1], c[roll(i * 4 + 2)]);
        swap(c[(7 - i) * 4], c[i * 4 + 3]);
    }
}

void shuffle6(char* c){
    for(int i = 0; i < 8; i++){
        swap(c[(7 - i) * 4 + 1], c[i * 4 + 2]);
        swap(c[(7 - i) * 4], c[roll(i * 4 + 3)]);
    }
}

void supershuffle(char* c){
    shuffle1(c);
    shuffle2(c);
    shuffle3(c);
    shuffle4(c);
    shuffle5(c);
    shuffle6(c);
}

void opaquePredicate(){
    static int nTimesCalled = 0;
    nTimesCalled++;
}

void memcpy_cs(unsigned char* uc, const unsigned char* cuc, int i){
    for(int x = 0; x < i; x++){
        opaquePredicate();
        uc[x] = cuc[x];
    }
}

void revealKey(long* lp, unsigned char* uc){
    for(int i = 0; i < 0xE; i++){
        supershuffle((char*)lp);
    }
    mash((unsigned char*)lp, uc);
}

void getKeyImpl(unsigned char* uc1, char* c, unsigned char* uc2){
    revealKey((long*)uc1, uc2);
    memcpy_cs((unsigned char*)c, uc1, 0x20);
}

void KeyChain::getKey(int i, unsigned char* uc1, unsigned char* uc2){
    unsigned char uchar_arr[32];
    char char_arr[32];

    memcpy_cs(uchar_arr, &hiddenKeys[i * 0x20], 0x20);
    getKeyImpl(uchar_arr, char_arr, uc2);
    parseHex16(char_arr, uc1);
}

int KeyChain::getNumKeys(){ return 0xC; }
