//#include <windows.h>
#include <stdio.h>

void swap(char* a, char* b) 
{     
	char m;     
	m = *a;     
	*a = *b;     
	*b = m; 
}
/************************************************************************
 * Tip: Hidden bug of "swap_xor" as opposed to "swap"
 ************************************************************************
 * If "a" is equal to "b" ("a" and "b" are all pointer variables), we 
 * can't use XOR to exchange "*a" and "*b", or the final results of "*a"
 * and "*b"  are both '\0'. This is the biggest difference between these 
 * two swapping methods above. What a pity that XOR method has such a 
 * hidden bug. However XOR method runs very much faster.      
 ************************************************************************/
void swap_xor(char* a, char* b) 
{   

	if(a == b)
	{
		return;
	}
	*a ^= (*b);
	*b ^= (*a);
	*a ^= (*b);
	// Full xor version for comprehension:
	// (*a) = (*a) ^ (*b);
	// (*b) = (*a) ^ (*b);
	// (*a) = (*a) ^ (*b);
}
/***********************************************************************
 * Print the permutation of a string
 ***********************************************************************
 * Input: pStr   - input string
 *        pBegin - points to the begin char of string which 
 *                 we want to permutate in this recursion
 **********************************************************************/
void permutation(char* pStr, char* pBegin)
{
	// count of Full Permutation results
	static int cnt = 0;
	char *pCh;
	if(!pStr || !pBegin)
	{
		return;
	}
	if(*pBegin == '\0')
	{
		// Full Permutation result
		printf("%3d: %s\n", ++cnt, pStr);
	}
	else
	{       
	    	for(pCh = pBegin; *pCh != '\0'; pCh++)
		{
			swap_xor(pCh, pBegin);
			permutation(pStr, pBegin+1);
			swap_xor(pCh, pBegin);
		}
	}
}
int main(int argc, char* argv[])
{
	char str[10];
	scanf("%s", str);
	permutation(str, str);
	
	/////////////////////////////////////////////////////////////////////////
	// getchar() or system("pause") is for showing computation results
	// for a long time, or the console will flash away in no time.
	// In Visual Studio, you can use system("pause") including <windows.h>,
	// else, you can use getchar().
	/////////////////////////////////////////////////////////////////////////
	
	// system("pause");
	// getchar();
	return 0;    
}

