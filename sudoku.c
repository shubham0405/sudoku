#include<stdio.h>
#include<stdlib.h>
int sudokuSolver();
int findCell();
int isValid();
void printarr();
long count=0;
int arr[9][9]=  {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 9, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 1, 0}};
int row,col;
void main()
{
    int i,j,solution=0;
    printf("The Entered Sudoku puzzle is: \n");
    printarr();
    solution=sudokuSolver();
    if(solution)
    {
      printf("\nThe Solved Sudoku is: \n\n");
      printarr();
    }
    else{
    printf("\nNo Possible Solution!!\n\n");
    printf("%d",count);
    }
    return;
}

int findCell(){
 for(int i=row;i<=8;i++)
     for(int j=0;j<=8;j++)
        {
  if(arr[i][j]==0)
   {
   row=i;col=j;
   return 1;
   }
     }
   return 0;

}

int isValid(int cellRow, int cellCol, int num){
     int rowStart = (cellRow/3) * 3;
    int colStart = (cellCol/3) * 3;
   for(int j=0;j<=8;j++){
       if(arr[cellRow][j]==num)
    return 0;
       if(arr[j][cellCol]==num)
    return 0;

   }
    for(int i=rowStart;i<rowStart+3;i++)
        for(int j=colStart;j<colStart+3;j++)
             if(arr[i][j]==num)
                return 0;
    return 1;
}
int sudokuSolver(){
    count++;
     int digit;
     int pRow,pCol;
     if(!findCell())
         return 1;

for(digit=1;digit<=9;digit++)
{
  if(isValid(row,col,digit))
    {
       arr[row][col]=digit;
        pRow=row;pCol=col;
        if(sudokuSolver())
            return 1;
       row=pRow;col=pCol;
       arr[row][col]=0;
     }
}
return 0;

}
void printarr(){

 int i,j;

 printf(" ----------------------- \n");
 for(i=0;i<9;i++)
{
    for(j=0;j<9;j++)
    {
       if(j==0)
             printf("| ");
       if(arr[i][j]==0)
             printf("0 ");
       else
            printf("%d ",arr[i][j]);
       if((j+1)%3==0 )
            printf("| ");

   }
   if((i+1)%3==0 )
       printf("\n ----------------------- ");
   printf("\n");
 }
 if(count!=0)
    printf("%d",count);
}


