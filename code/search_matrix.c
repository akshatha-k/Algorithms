#include <stdio.h>
#include <stdlib.h>
void search(int[][] mat, int fromRow, int toRow,
						int fromCol, int toCol, int key)
{
	int i = fromRow + (toRow-fromRow )/2;
	int j = fromCol + (toCol-fromCol )/2;
	if (mat[i][j] == key)
	printf("Found key at %d %d",i,j);
	else
	{
		if (i!=toRow || j!=fromCol)
		search(mat,fromRow,i,j,toCol,key);
		if (fromRow == toRow && fromCol + 1 == toCol)
		if (mat[fromRow][toCol] == key)
			printf("Found %d at %d %d", key,fromRow, toCol);
		if (mat[i][j] < key)
		{

			if (i+1<=toRow)
			search(mat, i+1, toRow, fromCol, toCol, key);
		}
		else
		{
			if (j-1>=fromCol)
			search(mat, fromRow, toRow, fromCol, j-1, key);
		}
	}
}
}

int main()
	{
		int mat[][] = { {10, 20, 30, 40},
									{15, 25, 35, 45},
									{27, 29, 37, 48},
									{32, 33, 39, 50}};
		int rowcount = 4,colCount=4,key=50;
		for (int i=0; i<rowcount; i++)
		for (int j=0; j<colCount; j++)
			search(mat, 0, rowcount-1, 0, colCount-1, mat[i][j]);
	}
