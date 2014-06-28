# include <stdio.h>
# include <stdlib.h>
# define MaxSize 32767

static FILE *fps;					//¿¥‘¥Œƒº˛÷∏’Î
static FILE *fpr;					//ID_result.txt÷∏’Î
static char Filename[30];			//Œƒº˛√˚ª∫¥Êø’º‰
typedef struct 						//”√”⁄Ω¯––¥Æ±»ΩœµƒΩ·ππÃÂ
{
	char data[MaxSize];
	int length;
}SqString;

void Open();						//Œƒº˛¥Úø™≤Ÿ◊˜∫Ø ˝
void Help();						//∞Ô÷˙–≈œ¢∫Ø ˝
void Save();						//Œƒº˛±£¥Ê≤Ÿ◊˜∫Ø ˝
void Find();						//◊÷∑˚¥Æ≤È’“∫Ø ˝
void Replace();						//◊÷∑˚¥ÆÃÊªª∫Ø ˝
void Delete();						//◊÷∑˚¥Æ…æ≥˝∫Ø ˝
void Quit();						//ÕÀ≥ˆ∫Ø ˝

int KMPIndex(SqString s,SqString t);//”√”⁄±»Ωœµƒ∫Ø ˝£¨∑µªÿ∆•≈‰ ◊◊÷∑˚Œª÷√
void GetNext(SqString t,int next[]);//KMPIndex()µƒ∏®÷˙∫Ø ˝
