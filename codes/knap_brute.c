#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int size;
int capacity;
int *weight,*profit,*selected;

int bruteforce();
int readInput();
int main(int argc, char ** argv){
	int i,totalProfit=0,totalWeight=0;
	readInput();

	totalProfit = bruteforce();

	/*Prints the output*/
	printf("\nSelected Items: {");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=weight[i];
			printf(" (Item%d, %d, %d),",i+1,weight[i],profit[i]);
		}
	}
	printf(" }\n");

	printf("Total Profit = %d\n",totalProfit);
	printf("Total Weight = %d\n\n",totalWeight);

	/*Free the allocated memory*/
	free(selected);
	free(weight);
	free(profit);
	return 0;
}

int bruteforce() {
	int i,j,isSelected=1,maxWt,maxProfit;
	int iter=pow(2.0,size);
	int result=0;
	int temp[size];
	/*Initialize the temp array */
	for(i =0;i<size;i++)
		temp[i]=0;

	for(i=0;i<iter;i++) {
		isSelected=1;
		maxProfit=0;
		maxWt=0;

		for(j=0;j<size;j++){
			if(temp[j]==1){
				maxWt+=weight[j];
				maxProfit+= profit[j];
			}
		}
		if( maxWt <= capacity && maxProfit>result){
			/*Copies the selected item in array. */
			for(j=0;j<size;j++)
				selected[j]=temp[j];
			result=maxProfit;
		}

		/*Calculate the next subset */
		for(j=0;j<size;j++){
			temp[j]=temp[j]+isSelected;
			isSelected = temp[j]/2;
			temp[j]=temp[j]%2;
		}
	}
	return result;
}


int readInput(){
    printf("Enter size: \n");
    scanf("%d",&size);
		//Create weight and profit array
		weight = (int*) malloc(sizeof(int)*size);
		profit = (int*) malloc(sizeof(int)*size);
		selected = (int*) malloc(sizeof(int)*size);
		for(int i =0; i< size; i++)
      scanf("%d\n", &weight[i]);
    for(int i =0; i< size; i++)
      scanf("%d\n", &profit[i]);
    printf("Enter capacity: \n");
    scanf("%d",&capacity);  
	return 0;
}
