#include<iostream>
#include<algorithm>


using namespace std;

int map[4000][4000] = {0};

void f(int posy , int posx, int n){
    if (n != 1)
    {
          f(posy,posx + (n/2)*6 , n/2);
          f(posy,posx, n/2);
          f(posy + (n/2)*3 , posx + (n*6)/4 , n/2);
          return;
    }
    map[posx][posy] = 1;
    map[posx+1][posy]= 1;
    map[posx+2][posy]= 1;
    map[posx+3][posy]= 1;
    map[posx+4][posy]= 1;
    map[posx+1][posy+1]= 1;
   
    map[posx+2][posy + 2]= 1;
    map[posx+3][posy+1]= 1;
    return;
}
   


int main(){
    int n;
    scanf("%d" , &n);
   
    f(0,0,n/3);
    for (int i = n-1; i>= 0 ; i--){
        for (int j = 0 ; j < n/3 *6; j++){
            if (map[j][i] == 1){
                          printf("*");
            }
            else {
                 printf(" ");
            }
        }
	printf("\n");
    }
}

