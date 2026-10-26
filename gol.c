#include <stdio.h>
int main(){
    int i,j;
    int grid[10][10];
    int newgrid[10][10];
    int x,y;
    int count;
    int gen;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            grid[i][j]=0;
            newgrid[i][j]=0;
        }
    }

    grid[4][5]=1;
    grid[4][6]=1;
    grid[4][7]=1;
    grid[0][4]=1;
    grid[1][2]=1;
    grid[1][3]=1;
    grid[0][3]=1;

//printing of the gird;
for(gen=1;gen<=10;gen++){
    printf("\n\n\n %dth generation \n",gen);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            count=0;
            for(x=-1;x<=1;x++){
                for(y=-1;y<=1;y++){
                    if(x==0 && y==0){
                        continue;
                    }else{
                      if(i+x>=0 && i+x<10 &&
                         j+y>=0 && j+y<10){
                            if(grid[i+x][j+y]==1){
                                count++;
                            }
                         }
                    }
                }
            }
            if(grid[i][j]==1){
                if(!(count==2 || count==3)){
                    newgrid[i][j]=0;
                }else{
                    newgrid[i][j]=1;
                }
            }else{
                if(count==3){
                    newgrid[i][j]=1;
                }else{
                    newgrid[i][j]=0;
                }
            }
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            grid[i][j]=newgrid[i][j];
        }
    }
}
    return 0;
}