#include<stdio.h>
#define ROWS 20
#define COLS 40
char canvas[ROWS][COLS];
void clearcanvas()
{
  int i,j;
  for(int i=0;i<n;i++)
    {
      canvas[i][j]='_';
    }
}
void putPixel(int x,int y,char ch)
{
  if(x>=0 && x<COLS && y>=0 && y<ROWS)
  {
  canvas[y][x]=ch;
  }
}  
void display()
{
  int i,j;
  for(i=o;i<ROWS;i++)
    {
      for(j=0;j<COLS;j++)
        {
          printf("%c",canvas[i][j]);
        }
      printf("\n");
    }
}
int main()
{
  clearcanvas();
  putPixel(5,5,'*');
  putPixel(10,10,'*');
  displayCanvas();
  return 0;
}
  
