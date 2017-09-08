#include <stdio.h>
#define bucketCapacity 20
#define outputRate 10
#define read(i) fscanf(stdin,"%d",&i);

int main(){
	int nowContained = 0;
	FILE *filePtr;
	filePtr = fopen("tmp.dat" , "w");
	fprintf(filePtr,"\nInput Output  Bucket  Discarded");
	
	#include <stdbool.h>
	bool resume = true;
	while(resume){
		int data = 0;
		printf("Give the packet : ");
		read(data);
		nowContained += data;

		int d = (nowContained > bucketCapacity)?
				(nowContained - bucketCapacity):0;
		if(d) nowContained = bucketCapacity;
		int output = (nowContained >= outputRate)?
			     (outputRate):0;
		if(output) nowContained -= outputRate;

		fprintf(filePtr,"\n%d\t%d\t%d\t%d",data,output,nowContained,d);
		printf("Do you want to continue ? (1/0) : ");
		read(data);resume = (data)?true:false;
	}

        fclose(filePtr);printf("\n\n");
	filePtr = fopen("tmp.dat" , "r");

        char c = fgetc(filePtr);
	while(c != EOF){
		printf("%c",c);
		c = fgetc(filePtr);
	}
	printf("\n\n");

	return 0;
}
