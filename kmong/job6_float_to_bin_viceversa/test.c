#include <stdio.h>

#define BYNARY_FMT "%u%u%u%u%u%u%u%u"
#define BYTE_TO_BIN(b) ((b) & 0x80 ? 1 : 0),\
	                       ((b) & 0x40 ? 1 : 0),\
                       ((b) & 0x20 ? 1 : 0),\
                       ((b) & 0x10 ? 1 : 0),\
                       ((b) & 0x08 ? 1 : 0),\
                       ((b) & 0x04 ? 1 : 0),\
                       ((b) & 0x02 ? 1 : 0),\
                       ((b) & 0x01 ? 1 : 0)
					   
#define BIT_FMT "%u"
#define NTH_BIT(b, n) ((b) & (1 << n) ? 1 : 0)

union FloatingPointIEEE754 {
	struct {
		unsigned int m: 23;
		unsigned int e: 8;
		unsigned int s: 1;
	} raw;
	float f;
} ieee754;

int main() {
	scanf("%f", &ieee754.f);
	printf("%x , %x , %x\n", ieee754.raw.s, ieee754.raw.e, ieee754.raw.m);

	printf(
	BIT_FMT " "
	BYNARY_FMT " "
	BIT_FMT BIT_FMT BIT_FMT BIT_FMT BIT_FMT BIT_FMT BIT_FMT BYNARY_FMT BYNARY_FMT "\n\n",

	// SIGN
	(ieee754.raw.s & (1<<0)?1:0),

	//NTH_BIT    (ieee754.raw.s      , 0),

	// EXPONENT
		BYTE_TO_BIN(ieee754.raw.e         ),

		// MANTISSA
		NTH_BIT    (ieee754.raw.m >> 16, 6), // (ieee754.raw.m>>16) & (1<<6)
		NTH_BIT    (ieee754.raw.m >> 16, 5),
		NTH_BIT    (ieee754.raw.m >> 16, 4),
		NTH_BIT    (ieee754.raw.m >> 16, 3),
		NTH_BIT    (ieee754.raw.m >> 16, 2),
		NTH_BIT    (ieee754.raw.m >> 16, 1),
		NTH_BIT    (ieee754.raw.m >> 16, 0),
		BYTE_TO_BIN(ieee754.raw.m >> 8    ),
		BYTE_TO_BIN(ieee754.raw.m         )
	);

	return 0;
}
