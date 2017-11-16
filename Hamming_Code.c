#include <stdio.h>

int frame[12] = {0};
int data[7] = {0};

void _setup()
{
	int d1,d2,d3,d4,d5,d6,d7;
	int r1,r2,r3,r4;
	int index = -1,i = 0;

	//setting up di's 
	d1 = frame[3] = data[++index];
	d2 = frame[5] = data[++index];
	d3 = frame[6] = data[++index];
	d4 = frame[7] = data[++index];
	d5 = frame[9] = data[++index];
	d6 = frame[10] = data[++index];
	d7 = frame[11] = data[++index];

	//setting up ri's
	r1 = d1 ^ d2 ^ d4 ^ d5 ^ d7;frame[1] = r1;
	r2 = d1 ^ d3 ^ d4 ^ d6 ^ d7;frame[2] = r2;
	r3 = d2 ^ d3 ^ d4;frame[4] = r3;
	r4 = d5 ^ d6 ^ d7;frame[8] = r4;
	
	printf("\nThe data set frame is : ");
	for(i = 1;i < 12;i++) printf("%d",frame[i]);
	printf("\n\n\n");
}

void check(int bit)
{
	int i = 0;frame[bit] = !frame[bit];
	printf("\nThe new data set frame is : ");
	for(i = 1;i < 12;i++) printf("%d",frame[i]);
	
	int r1,r2,r3,r4;
	r1 = frame[1] ^ frame[3] ^ frame[5] ^ frame[7] ^ frame[9] ^ frame[11];
	r2 = frame[2] ^ frame[3] ^ frame[6] ^ frame[7] ^ frame[10] ^ frame[11];
	r3 = frame[4] ^ frame[5] ^ frame[6] ^ frame[7];
	r4 = frame[8] ^ frame[9] ^ frame[10] ^ frame[11];

	printf("\n\npositon of bit change : %d%d%d%d\n\n\n",r1,r2,r3,r4);
}

int main()
{
	printf("\nWelcome to Hamming Code checking of errors : \n Give the data : ");
	char inp[8] = {'\0'};
	scanf("%s",inp);int i = 0;
	for(i = 0;i < 7;i++)
	{
		if(inp[i] == '0') data[i] = 0;
		else data[i] = 1;
	}
	_setup();
	printf("\nNow it's time to test the Hamming Code Method\nGive the bit position to be fliped (1 <= bit <= 11) : ");
	int bit = 0;scanf("%d",&bit);
	check(bit);
	return 0;
}
