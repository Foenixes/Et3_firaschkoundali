/**
* @file utilitaire.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "utilitaire.h"
//vie p1:
/**
* @brief To initialize the text T .
* @param T the text
* @return int 
*/
int initTextviep1(Text* T)
{    int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;
    strcpy(T->txt,"vie : 3");
    T->positionText.x =100;
    T->positionText.y =20; 
    testload=loadFontviep1(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;
}
/**
* @brief To load the font T .
* @param T the text
* @param path the font 
* @return int
*/
int loadFontviep1(Text* T, char* path)
{
   

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police = TTF_OpenFont(path,60);
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To update vie  .
* @param T the text of vie.
* @param vie nomber of life.
* @param col .
* @return Nothing
*/
void update_viep1(Text* T, int *vies,collision col)
{
    if(col.colenigme==1)
     {
     if(*vies>0)
     	(*vies)--;
    sprintf(T->txt,"*** VIES : %d ***",(*vies));
    }
    
    
   T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
}
/**
* @brief To display life   .
* @param T the text of vie.
* @param screen .
* @return Nothing
*/
void displayviep1(Text T,SDL_Surface *screen)
{       
    
     //T.textSurface=TTF_RenderText_Solid(T.police,T.txt,T.couleurTxt);
     SDL_BlitSurface(T.textSurface,NULL,screen,&(T.positionText));

}
/**
* @brief To free text vie   .
* @param T the text of vie.
* @return Nothing
*/
void freeTextviep1(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}
//vie p2:
/**
* @brief To initialize the text T .
* @param T the text
* @return int 
*/
int initTextviep2(Text* T)
{    int testload;
    T->couleurTxt.r = 200; 
    T->couleurTxt.g = 200; 
    T->couleurTxt.b = 200;
    strcpy(T->txt,"vie : 3");
    T->positionText.x =100;
    T->positionText.y =70; 
    testload=loadFontviep2(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;
}
/**
* @brief To load the font T .
* @param T the text
* @param path the font 
* @return int
*/
int loadFontviep2(Text* T, char* path)
{
   

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police = TTF_OpenFont(path,60);
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To update vie  .
* @param T the text of vie.
* @param vie nomber of life.
* @param col .
* @return Nothing
*/
void update_viep2(Text* T, int *vies,collision col)
{
    if(col.colenigme==1)
     {
     if(*vies>0)
     	(*vies)--;
    sprintf(T->txt,"*** VIES : %d ***",(*vies));
    }
    
    
   T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
}
/**
* @brief To display life   .
* @param T the text of vie.
* @param screen .
* @return Nothing
*/
void displayviep2(Text T,SDL_Surface *screen)
{       
    
     //T.textSurface=TTF_RenderText_Solid(T.police,T.txt,T.couleurTxt);
     SDL_BlitSurface(T.textSurface,NULL,screen,&(T.positionText));

}
/**
* @brief To free text vie   .
* @param T the text of vie.
* @return Nothing
*/
void freeTextviep2(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}
//time : 
/**
* @brief To count Time .
* @param tempsdebut
* @return nothing 
*/
void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}
/**
* @brief To initialize the time .
* @param t the time 
* @return nothing
*/
void inittemps(Time *t)
{   int test; 
	t->tempsdebut=00;
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}
/**
* @brief To initialize the text T .
* @param T the text 
* @return int
*/
int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;

    strcpy(T->txt, "");
    T->positionText.x = 850;
    T->positionText.y = 20; 
    testload=loadFonttime(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;   
}
/**
* @brief To load the font T .
* @param T the text
* @param path the font 
* @return int
*/
int loadFonttime(Text* T, char* path)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(path,60);
    if (police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To update time  .
* @param T the text of time.
* @return Nothing
*/
void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    //T->ss=T->ss+ts;
    //if(T->ss>60)
    T->mm=ts/ 60;
    T->ss=ts % 60;
    //printf("ts : %d , mm : %d , ss : %d\n\n",ts,T->mm,T->ss);
    /*if((ts<60)&&(T->ss<60))
    {
    T->ss=T->ss+ts;
    }
    else
    {
    T->mm=T->mm+(ts / 60);
    T->ss=T->ss+(ts % 60);
    }*/
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt,"*** time :0%d:0%d  ***",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt,"*** time :0%d:%d  ***",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt,"*** time :%d:0%d  ***",T->mm,T->ss);
    /*else
         sprintf(T->temps.txt,"*** time :%d:%d  ***",T->mm,T->ss); */
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
}
/**
* @brief To display time   .
* @param T the text of time.
* @param screen .
* @return Nothing
*/
void displaytime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));

}
/**
* @brief To free text time   .
* @param T the text of time.
* @return Nothing
*/
void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}

//score p1:
/**
* @brief To initialize the text T .
* @param T the text
* @return int 
*/
int initTextscorep1(Text* T)/**
* @brief To update score  .
* @param T the text of score.
* @param col
* @return Nothing
*/
{    int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;
    strcpy(T->txt,"0");
    T->positionText.x = 600;
    T->positionText.y = 20; 
    testload=loadFontscorep1(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;
}
/**
* @brief To load the font T .
* @param T the text
* @param path the font 
* @return int
*/
int loadFontscorep1(Text* T, char* path)
{
   

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police = TTF_OpenFont(path,60);
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To update score  .
* @param T the text of score.
* @param col
* @return Nothing
*/
void update_scorep1(Text* T, int *score,collision col)
{
    if(col.colcoin==1)
    {(*score)=(*score)+10;}
    sprintf(T->txt,"*** score : %d ***",*score);
    T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
}
/**
* @brief To display score   .
* @param T the text of score.
* @param screen .
* @return Nothing
*/
void displayscorep1(Text T,SDL_Surface *screen)
{       
    SDL_BlitSurface(T.textSurface,NULL,screen,&(T.positionText));

}
/**
* @brief To free text score.
* @param T the text of score.
* @return Nothing
*/
void freeTextscorep1(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}
//score p2:
/**
* @brief To initialize the text T .
* @param T the text
* @return int 
*/
int initTextscorep2(Text* T)
{    int testload;
    T->couleurTxt.r = 200; 
    T->couleurTxt.g = 200; 
    T->couleurTxt.b = 200;
    strcpy(T->txt,"0");
    T->positionText.x = 600;
    T->positionText.y = 70; 
    testload=loadFontscorep2(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;
}
/**
* @brief To load the font T .
* @param T the text
* @param path the font 
* @return int
*/
int loadFontscorep2(Text* T, char* path)
{
   

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police = TTF_OpenFont(path,60);
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To update score  .
* @param T the text of score.
* @param col
* @return Nothing
*/
void update_scorep2(Text* T, int *score,collision col)
{
    if(col.colcoin==1)
    {(*score)=(*score)+10;}
    sprintf(T->txt,"*** score : %d ***",*score);
    T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
}
/**
* @brief To display score   .
* @param T the text of score.
* @param screen .
* @return Nothing
*/
void displayscorep2(Text T,SDL_Surface *screen)
{       
    SDL_BlitSurface(T.textSurface,NULL,screen,&(T.positionText));

}
/**
* @brief To free text score.
* @param T the text of score.
* @return Nothing
*/
void freeTextscorep2(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}
