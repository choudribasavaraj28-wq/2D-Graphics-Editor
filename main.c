#include<stdio.h>
#include<stdlib.h>
#define ROWS 35
#define COLS 80
char canvas[ROWS][COLS];
void clearCanvas()
{
  int i,j;
  for(i=0;i<ROWS;i++)
    {
      for(j=0;j<COLS;j++)
      {
      canvas[i][j]=' ';
      }
    }
}
void putPixel(int x,int y,char ch)
{
  if(x>=0 && x<COLS && y>=0 && y<ROWS)
  {
  canvas[y][x]=ch;
  }
}  
void displayCanvas()
{
  int i,j;
  for(i=0;i<ROWS;i++)
    {
      for(j=0;j<COLS;j++)
        {
          printf("%c",canvas[i][j]);
        }
      printf("\n");
    }
}
void drawLineCanvas(int x1,int y1,
                    int x2,int y2,
                    char ch)
{
  int dx=abs(x2-x1);
  int dy=abs(y2-y1);

  int sx=(x1<x2)?1:-1;
  int sy=(y1<y2)?1:-1;

  int err=dx-dy;
  while(1){
    putPixel(x1,y1,ch);
    if(x1==x2&&y1==y2)
      break;
    int e2=2*err;
    if(e2>-dy){
      err-=dy;
      x1+=sx;
    }
    if(e2<dx){
      err+=dx;
      y1+=sy;
    }
  }
    
}
void drawRectangleCanvas(int x1,int y1,
                        int x2,int y2,
                        char ch)
{
  drawLineCanvas(x1,y1,x2,y1,ch);
  drawLineCanvas(x2,y1,x2,y2,ch);
  drawLineCanvas(x2,y2,x1,y2,ch);
  drawLineCanvas(x1,y2,x1,y1,ch);
}
void drawTriangleCanvas(int x1,int y1,
                        int x2, int y2,
                        int x3,int y3,
                        char ch)
{
  drawLineCanvas(x1,y1,x2,y2,ch);
  drawLineCanvas(x2,y2,x3,y3,ch);
  drawLineCanvas(x3,y3,x1,y1,ch);
}
int main()
{
  clearCanvas();
  drawLineCanvas(2,2,15,10,'*');
  drawRectangleCanvas(5,12,20,18,'*');
  drawTriangleCanvas(25,5,35,15,15,15,'*');
  displayCanvas();
  return 0;
}
  
