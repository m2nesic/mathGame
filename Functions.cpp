/*Implementations of various functions*/
#include "Functions.h"

int function1(int var1)
{
	return (var1 * 2) + 2;			// 2x + 2
}

int function2(int var2)
{
	return (var2 * 3) - 6;			// 3x - 6
}

int function3(int var3)
{
	return var3 + 15;				// x + 15
}

int function4(int var4)
{
	return (var4 * var4);			// x ^ 2
}

int function5(int var5)
{
	return var5 - 9;				// x - 9
}

int function6(int var6)
{
	return (var6 * var6 * var6) ;	// x ^ 3
}

int function7(int var7)				
{
	return (var7 * var7) - (3 * var7); // x ^ 2 - 3x
}

int function8(int var8)
{
	return (var8 * var8) + (2 * var8) + 2;		// x ^ 2 + 2x + 2			
}

int function9(int var9)
{
	return (var9 * var9 * var9) - 2 * (var9 * var9);	//x^3 - 2(x^2)
}

