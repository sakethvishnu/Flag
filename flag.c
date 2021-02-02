#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
//Declaring functions.
void gotoxy(int,int);
void load();
int color(int);

//Main proccess.
int main(){
    system("cls");//Clearing the screen.
    gotoxy(30,10);
    load();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    gotoxy(0,25);
    return 0;
}

//Defining the gotoxy function.
void gotoxy(int x,int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//loading the flag image.
void load(){
    int i = 0,j,k = 10;
    for(i=0;i<=62;i++){
        if(i==21||i==42){
            k += 1;
            gotoxy(30,k);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color(i));
        printf("%c",178);
        for(j=0;j<10000000;j++){}
    }

}

//To give a flag color
int color(int i){
    if(i<=20)
        return 12;
    else if(i<=41 && i>20)
        return (i==30||i==31||i==32)?9:7;
    else
        return 2;
}