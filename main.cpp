
//DATE:26/3/2022

//ENONCE: FAIRE UN JEU DE WANCALA
//PRINCIPE:DEPLACER DES PION DANS LE SENS CONTRAIRE DES AIGUILLES D'UNE MONTRE

//G1 1 1 1 1 1 1
//  2 2 2 2 2 2 G2





//PRESENTATION: TATIEZE EMMANUEL  ET ONANA ANDELA








#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {int x;int y;}point;
int Tab1[7],Tab2[7],joueur=1;/*represente le  choisie du tableau*/;

int fin_du_jeu();


void initialiser_plateau()
{
    int i;

    for(i=0;i<=6;i++)
    {
        Tab2[i]=4;
        Tab1[i]=4;
    }

    Tab1[0]=0;
    Tab2[6]=0;
/*
    Tab2[0]=2;
    Tab1[1]=4;
    Tab2[1]=13;
    Tab2[2]=0;
    Tab1[2]=0;
    Tab2[3]=13;
    Tab1[3]=8;
    Tab2[4]=2;
    Tab1[4]=3;
    Tab2[5]=5;
    Tab1[5]=7;
    Tab1[6]=0;*/
}

void afficher_plateau()
{
    int i;
    for(i=0;i<=6;i++)
    {
        printf("%d\t",Tab1[i]);
    }
    printf("\n\t");
    for(i=0;i<=6;i++)
    {
        printf("%d\t",Tab2[i]);
    }
}

int nombre_pion(int case_choisie)
{
    int i=case_choisie;
    if(joueur==1)
    return Tab1[i];
    if(joueur==2)
    return Tab2[i];
}

void jouer(int case_choisie)
{
    int i,j,compteur,encore=0,a,b,joueur1=0,joueur2=0;
    if(nombre_pion(case_choisie)!=0)
    {

        if(joueur==1&&case_choisie!=0&&joueur1!=1)
        {

            compteur=Tab1[case_choisie];
            Tab1[case_choisie]=0;

            encore=0;
           do
            {
            if(compteur<=case_choisie)
              {

                  if(encore==0)
                  {
                    j=case_choisie-compteur;
                    for(i=case_choisie-1;i>=j;i--)
                   {
                     Tab1[i]=Tab1[i]+1;
                     compteur--;
                         if(compteur==0)
                         {
                          a=i;
                          b=1;

                         }

                      }
                    }
                  }
                  if(encore==1)
                  {

                      j=case_choisie-compteur+1;
                    for(i=case_choisie;i>=j;i--)
                   {
                     Tab1[i]=Tab1[i]+1;
                     compteur--;
                     if(compteur==0)
                         {
                          a=i;
                          b=1;

                         }
                     encore=0;
                    }
                  }





            if(compteur>case_choisie)
              {
                   if(encore==0)
                   {
                    for(i=case_choisie-1;i>=0;i--)
                    {
                     Tab1[i]=Tab1[i]+1;
                     compteur--;

                    }
                   }
                   if(encore==1)
                   {
                    for(i=case_choisie;i>=0;i--)
                    {
                     Tab1[i]=Tab1[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;
                     encore=0;
                    }
                   }


                 if(compteur<7)
                 {
                     j=compteur-1;
                     for(i=0;i<=j;i++)
                    {
                     Tab2[i]=Tab2[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;
                    }

                 }
                 if(compteur>=7)
                 {
                     for(i=0;i<=5;i++)
                    {
                     Tab2[i]=Tab2[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;
                    }
                    case_choisie=6;encore=1;

                 }

              }
              if(compteur==0)
                    {
                     joueur=2;joueur2=1;
                     if(Tab1[a]==1&&a!=0&&Tab2[a-1]!=0)
                      {
                       Tab1[0]=Tab1[0]+Tab2[a-1]+Tab1[a];
                       Tab2[a-1]=0;Tab1[a]=0;
                       joueur=2;

                      }


                    }
            if(compteur==0&&a==0&&b==1)
            {
                joueur=1;joueur1=1;
            }

            }while(compteur!=0);
        }





             if(joueur==2&&case_choisie!=6&&joueur2!=1)
        {
            compteur=Tab2[case_choisie];
            Tab2[case_choisie]=0;

            encore=0;
            do
            {
             if(compteur<=6-case_choisie)
               {
                   j=compteur;

                   if(encore==0)
                   {

                     for(i=case_choisie+1;i<=case_choisie+j;i++)
                     {
                      Tab2[i]=Tab2[i]+1;
                      compteur--;
                      if(compteur==0)
                      {
                          a=i;
                          b=2;
                      }



                     }
                   }
                   if(encore==1)
                   {
                     for(i=case_choisie;i<=j-1;i++)
                     {
                      Tab2[i]=Tab2[i]+1;
                      compteur--;
                      if(compteur==0)
                      {
                       a=i;
                       b=2;
                      }

                      encore=0;
                     }
                   }


               }

            if(compteur>6-case_choisie)
              {
                  if(encore==0)
                  {
                      for(i=case_choisie+1;i<=6;i++)
                   {
                     Tab2[i]=Tab2[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;
                    }
                  }
                  if(encore==1)
                  {
                      for(i=case_choisie;i<=6;i++)
                   {
                     Tab2[i]=Tab2[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;

                    }
                    encore=0;
                  }

                 if(compteur<=6)
                 {
                     i=6;
                     while(compteur!=0)
                    {
                     Tab1[i]=Tab1[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;
                     i--;
                    }
                 }
                 if(compteur>=7)
                 {

                     i=6;
                     while(i>0)
                    {
                     Tab1[i]=Tab1[i]+1;
                     compteur--;
                     if(compteur==0)
                        a=i;
                     i--;

                    }
                    case_choisie=0;encore=1;
                 }

              }
              if(compteur==0)
                    {
                     joueur=1;joueur1=1;
                     if(Tab2[a]==1&&a!=6&&Tab1[a+1]!=0)
                      {
                       Tab2[6]=Tab2[6]+Tab2[a]+Tab1[a+1];
                       Tab2[a]=0;Tab1[a+1]=0;

                      }

                    }
            if(compteur==0&&a==6&&b==2)
            {
                joueur=2;joueur2=1;
            }


            }while(compteur!=0);



             }



            }

        }

void afficher_case_selectionne(int i,int j,int x,int y,SDL_Rect dst2,SDL_Texture *texture2,SDL_Renderer *renderer,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16])
 {
     dst2.x=x;
     dst2.y=y;
     //if(j==0)
   // texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[i]]);
    // if(j==1)
    //texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab2[i-1]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);

              //afficher_case_selectionne(232+106*(i-1),180+127*j,dst2,texture2,renderer);
     SDL_RenderPresent(renderer);

 }
 void afficher_case_selectionne2(int i,int j,int x,int y,SDL_Rect dst2,SDL_Texture *texture2,SDL_Renderer *renderer,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16])
 {
     dst2.x=x;
     dst2.y=y;
     //if(j==0)
    //texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[i]]);
     //if(j==1)
    //texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab2[i-1]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);


              //afficher_case_selectionne(232+106*(i-1),180+127*j,dst2,texture2,renderer);
     SDL_RenderPresent(renderer);

 }

 void affichage_pions(SDL_Renderer *renderer,SDL_Texture *texture5,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst5,int Tab1[7],int Tab2[7] )
 {
     int i,j;
     for(j=0;j<2;j++)
         {
          for(i=1;i<=6;i++)
          {
              if(j==0)
              {
                  texture5=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[i]]);
                  afficher_case_selectionne(i,j,232+106*(i-1),180+127*j,dst5,texture5,renderer,Tab_img1,Tab_img2);
              }

              if(j==1)
              {
                  texture5=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab2[i-1]]);
                  afficher_case_selectionne(i-1,j,232+106*(i-1),180+127*j,dst5,texture5,renderer,Tab_img1,Tab_img2);

              }


          }
         }
 }
 void afficher_pion_grenier(int x0,int y0,int c,SDL_Renderer *renderer,SDL_Texture *texture4,SDL_Rect dst4)
 {
     int i,j,k=0;

     do
     {
         i=0;
          do
           {  j=0;
               while(j<3&&c!=0)
               {
                   if(k==0)
                   {
                    dst4.x=x0+j*27;
                    dst4.y=y0+i*24;
                   }
                   else
                   {
                    dst4.x=x0+(j+0.3)*27;
                    dst4.y=y0+(i+0.85)*24;
                   }

                 SDL_QueryTexture(texture4,NULL,NULL,&dst4.w,&dst4.h);
                 SDL_RenderCopy(renderer,texture4,NULL,&dst4);
                 j++;
                 c--;
               }
               i++;

           }while(c!=0&&dst4.y<394);
           k++;
     }while(c!=0);
     SDL_RenderPresent(renderer);
 }

   int fin_du_jeu()
        {
            int c=0,d=0,i;
            for(i=1;i<=6;i++)
            {
                if(Tab1[i]==0)
                {
                  c=c+1;
                }
            }
            for(i=0;i<6;i++)
            {
                if(Tab2[i]==0)
                {
                  d=d+1;
                }
            }
            if(c==6 && d!=6)
            {
                for(i=0;i<6;i++)
                {
                Tab2[6]=Tab2[6]+Tab2[i];
                Tab2[i]=0;
                }
            }
            if(d==6 && c!=6)
            {
                for(i=1;i<=6;i++)
                {
                Tab1[0]=Tab1[0]+Tab1[i];
                Tab1[i]=0;
                }
            }

           if((c==6&&d!=6)||(d==6&&c!=6))
                return 1;
            if(c!=6&&d!=6)
            return 0;

        }

int strategie0(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
 int i,MAX=6,MIN=1;
 do
 {
   i=(rand() % (MAX - MIN + 1)) + MIN;
 }while(Tab1[i]==0);

     dst2.x=232+106*(i-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[i]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[i]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

 return i;
}

int strategie1(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
    ////DERNIER PION DANS LE POT ; OBTENTION D'UN TOUR SUPPLEMENTAIRE
    int i,a=0;

        for(i=6;i>0;i--)
        {
          if(Tab1[i]-i==0)
          a=i;
        }

    if(a!=0)
    {
        dst2.x=232+106*(a-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

      return a;
    }
    else
      return 0;





}
int strategie2(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
    ////DERNIER PION DANS LA COUPE
    int i,j,a=0,b=0,c=0;

       i=6;
        do
        {
            b=i;
            c=Tab1[b];
            for(j=b-1;j>=1;j--)
            {
                c--;
                 if(c==0&&Tab1[b]!=0&&Tab1[1]==0&&j==1)
                   a=b;
            }

          i--;

        }while(i>1&&a==0);

    if(a!=0)
    {
        dst2.x=232+106*(a-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

      return a;
    }
    else
      return 0;
}

int strategie3(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
    ////CAPTURER PION
    int i,j,a=0,b=0,c=0,j2,ok=0;

      i=7;
        do
        {
            i--;
            if(Tab1[i]!=0)
             {
            b=i;
            c=Tab1[i];
            j=b-1;
            do
            {
                c--;
                j--;

             }while(j>=1&&c!=0);

             j++;
             if(b==1&&c>=7)
             {
               j=1;
               c++;
             }


             if(j>=1&&c==0)
                {
                    if(Tab2[j-1]>2&&Tab1[j]==0)
                    {
                     ok=1;
                     a=b;
                     j2=j;

                    }

                }
                if(j==1&&c>7)
                {
                    j=7-(c-7);
                    if(Tab2[j-1]>0&&Tab1[j]==0)
                    {
                     ok=1;
                     a=b;
                     j2=j;

                    }

                }
            }


        }while(i>1&&ok==0);

    if(a!=0)
    {
        dst2.x=232+106*(a-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

      return a;
    }
    else
      return 0;
}

int strategie4(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
    ////VIDER LA COUPE
    int a=0;


          if(Tab1[1]>1)
          a=1;

    if(a!=0)
    {
        dst2.x=232+106*(a-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

      return a;
    }
    else
      return 0;
}
int strategie5(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
    ////AVANCER PION
    int i,a=0;

       i=6;
        do
        {


            if((Tab1[i]<Tab1[i-1]&&Tab1[i]!=0)||(Tab1[i]>=Tab1[i+1]&&Tab1[i]!=0&&i!=6)||(i<6&&Tab1[i+1]>=3&&Tab1[i]!=0&&i!=1&&i!=2))
            {
              a=i;

            }

            i--;
        }while(i>1&&a==0);
        if(a==0)
        {
            i=6;
          do
         {


            if(Tab1[i]!=0)
            {
              a=i;

            }

         }while(i>1&&a==0);
        }

    if(a!=0)
    {
        dst2.x=232+106*(a-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

      return a;
    }
    else
      return 0;
}
int strategie6(SDL_Renderer *renderer,SDL_Texture *texture2,SDL_Surface *Tab_img1[16],SDL_Surface *Tab_img2[16],SDL_Rect dst2,int Tab1[7],int Tab2[7] )
{
    ////DEFENCE
    int i,j,a=0,c=0,b=0,c2,k,n,ok=0;

      i=0;
        do
        {
            b=i;
            c=Tab2[i];
            while(c!=0&&b<5)
            {
                c--;
                b++;
            }
            if(c==0&&Tab2[b]==0&&Tab1[b+1]>2)
            {
                 a=b+1;
                 ok=1;
            }


          i++;
        }while(i<=4&&ok==0);
    if(a!=0)
    {
        dst2.x=232+106*(a-1);
     dst2.y=180+127*0;
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);
     SDL_Delay(1000);
     texture2=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
     SDL_QueryTexture(texture2,NULL,NULL, &dst2.w, &dst2.h);
     SDL_RenderCopy(renderer, texture2, NULL, &dst2);
     SDL_RenderPresent(renderer);

      return a;
    }
    else
      return 0;
}

int main(int argc,char *argv[])
{
    int i,j,a=-1,b=-1,c,d,case_choisie,choix=0,choix_difficulte=0,retour_menu=0,fin=0,rejouer=0;
    int status=EXIT_FAILURE;
    SDL_Surface *Tab_img1[21],*Tab_img2[21];

     srand(time(NULL));

     //char title[20]={"MON PREMIER JEU"};
     point souri={0,0};
     point point={0,0};

    initialiser_plateau();

    afficher_plateau();
    //printf("\n\n%d",nombre_pion(3,2));
    //jouer(1,6);
    //printf("\n\n");
    //afficher_plateau();


     SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS|SDL_INIT_AUDIO);

    if(0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS|SDL_INIT_AUDIO))
      {
        fprintf(stderr, "Erreur SDL_Init : %s",SDL_GetError());
        return status;
      }


    SDL_Renderer *renderer=NULL;
    SDL_Window *window = NULL;
    SDL_Texture *texture=NULL,*texture2=NULL,*texture3=NULL,*texture4=NULL,*texture5=NULL;
    SDL_Color orange = {255, 127, 40, 255},rouge = {255, 255, 255, 255},bleu = {0, 0, 255, 255},violet = {155, 100, 155, 255};
    SDL_Rect rect = {100, 100, 100, 100}, dst0 = {90, 30, 0, 0},dst = {0, 0, 0, 0},dst4 = {0, 0, 0, 0},dst2 = {0, 0, 90, 106},dst5{0,0,90,106},dst6={0,0,0,0},dst7={0,0,0,0};
    SDL_Surface *tmp = NULL,*tmp2 = NULL,*tmp3 = NULL,*tmp4 = NULL,*tmp5 = NULL;
    SDL_Event event;


    window = SDL_CreateWindow("MANCALA", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1082, 600,SDL_WINDOW_SHOWN);
    //SDL_SetWindowTitle(window,title);

   if(NULL == window)
     {
       fprintf(stderr, "Erreur SDL_CreateWindow : %s",SDL_GetError());
       return status;
     }

    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
    if(NULL==renderer)
    {
        fprintf(stderr,"Erreur SDL_CreateRenderer: %s",SDL_GetError());
        return status;
    }

    texture=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,950, 750);
    if(NULL==texture)
    {
        fprintf(stderr,"Erreur SDL_CreateTexture: %s",SDL_GetError());
        return status;
    }

    tmp = SDL_CreateRGBSurface(0, 100, 200, 32, 0, 0, 0, 0);
   if(NULL==tmp)
    {
        fprintf(stderr,"Erreur SDL_CreateRGBSurface: %s",SDL_GetError());
        return status;
    }


    tmp = SDL_LoadBMP("plateau1.bmp");
    if(NULL == tmp)
      {
       fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
       return status;
      }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */

    if(NULL == texture)
      {
       fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
       return status;
      }
      tmp2 = SDL_LoadBMP("carre1.bmp");
    if(NULL == tmp2)
      {
       fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
       return status;
      }
    texture2 = SDL_CreateTextureFromSurface(renderer, tmp2);
    SDL_FreeSurface(tmp2); /* On libère la surface, on n’en a plusbesoin */

    if(NULL == texture2)
      {
       fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
       return status;
      }

      tmp3 = SDL_LoadBMP("carre2.bmp");
    if(NULL == tmp3)
      {
       fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
       return status;
      }
    texture3 = SDL_CreateTextureFromSurface(renderer, tmp3);
    SDL_FreeSurface(tmp3); /* On libère la surface, on n’en a plusbesoin */

    if(NULL == texture3)
      {
       fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
       return status;
      }

      tmp4 = SDL_LoadBMP("pion.bmp");
    if(NULL == tmp4)
      {
       fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
       return status;
      }
    texture4 = SDL_CreateTextureFromSurface(renderer, tmp4);
    SDL_FreeSurface(tmp4); /* On libère la surface, on n’en a plusbesoin */

    if(NULL == texture4)
      {
       fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
       return status;
      }

      tmp5 = SDL_LoadBMP("plateau1.bmp");
    if(NULL == tmp5)
      {
       fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
       return status;
      }
    texture5 = SDL_CreateTextureFromSurface(renderer, tmp5);
    SDL_FreeSurface(tmp5); /* On libère la surface, on n’en a plusbesoin */

    if(NULL == texture5)
      {
       fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
       return status;
      }
    Tab_img1[0] = SDL_LoadBMP("carre1.bmp");Tab_img1[1] = SDL_LoadBMP("carre1_1.bmp");Tab_img1[2] = SDL_LoadBMP("carre1_2.bmp");Tab_img1[3] = SDL_LoadBMP("carre1_3.bmp");Tab_img1[4] = SDL_LoadBMP("carre1_4.bmp");Tab_img1[5] = SDL_LoadBMP("carre1_5.bmp");Tab_img1[6] = SDL_LoadBMP("carre1_6.bmp");Tab_img1[7] = SDL_LoadBMP("carre1_7.bmp");Tab_img1[8] = SDL_LoadBMP("carre1_8.bmp");Tab_img1[9] = SDL_LoadBMP("carre1_9.bmp");Tab_img1[10] = SDL_LoadBMP("carre1_10.bmp");Tab_img1[11] = SDL_LoadBMP("carre1_11.bmp");Tab_img1[12] = SDL_LoadBMP("carre1_12.bmp");Tab_img1[13] = SDL_LoadBMP("carre1_13.bmp");Tab_img1[14] = SDL_LoadBMP("carre1_14.bmp");Tab_img1[15] = SDL_LoadBMP("carre1_15.bmp");Tab_img1[16] = SDL_LoadBMP("carre1_16.bmp");Tab_img1[17] = SDL_LoadBMP("carre1_17.bmp");Tab_img1[18] = SDL_LoadBMP("carre1_18.bmp");Tab_img1[19] = SDL_LoadBMP("carre1_19.bmp");Tab_img1[20] = SDL_LoadBMP("carre1_20.bmp");
    Tab_img2[0] = SDL_LoadBMP("carre2.bmp");Tab_img2[1] = SDL_LoadBMP("carre2_1.bmp");Tab_img2[2] = SDL_LoadBMP("carre2_2.bmp");Tab_img2[3] = SDL_LoadBMP("carre2_3.bmp");Tab_img2[4] = SDL_LoadBMP("carre2_4.bmp");Tab_img2[5] = SDL_LoadBMP("carre2_5.bmp");Tab_img2[6] = SDL_LoadBMP("carre2_6.bmp");Tab_img2[7] = SDL_LoadBMP("carre2_7.bmp");Tab_img2[8] = SDL_LoadBMP("carre2_8.bmp");Tab_img2[9] = SDL_LoadBMP("carre2_9.bmp");Tab_img2[10] = SDL_LoadBMP("carre2_10.bmp");Tab_img2[11] = SDL_LoadBMP("carre2_11.bmp");Tab_img2[12] = SDL_LoadBMP("carre2_12.bmp");Tab_img2[13] = SDL_LoadBMP("carre2_13.bmp");Tab_img2[14] = SDL_LoadBMP("carre2_14.bmp");Tab_img2[15] = SDL_LoadBMP("carre2_15.bmp");Tab_img2[16] = SDL_LoadBMP("carre2_16.bmp");Tab_img2[17] = SDL_LoadBMP("carre2_17.bmp");Tab_img2[18] = SDL_LoadBMP("carre2_18.bmp");Tab_img2[19] = SDL_LoadBMP("carre2_19.bmp");Tab_img2[20] = SDL_LoadBMP("carre2_20.bmp");


do
{
    system("cls");
    initialiser_plateau();
    afficher_plateau();
    retour_menu=0;


      tmp = SDL_LoadBMP("menu_2.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);
/*
SDL_SetRenderDrawColor(renderer, 146, 153, 154, 128);
SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
SDL_RenderFillRect(renderer, NULL);
SDL_RenderPresent(renderer);
SDL_Delay(5000);
*/

choix=0,choix_difficulte=0,retour_menu=0,fin=0,rejouer=0;
 do
 {
     SDL_WaitEvent(&event);


switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:
      souri.x = event.motion.x;
      souri.y = event.motion.y;
      if(souri.x>=404&&souri.x<=677&&souri.y>=287&&souri.y<=356)
      {
          tmp = SDL_LoadBMP("menu_2_option1.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);
      }

      else if(souri.x>=404&&souri.x<=677&&souri.y>=377&&souri.y<=445)
      {

          tmp = SDL_LoadBMP("menu_2_option2.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }
      else if(souri.x>=404&&souri.x<=677&&souri.y>=468&&souri.y<=536)
      {

          tmp = SDL_LoadBMP("menu_2_option3.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }
      else
      {
          tmp = SDL_LoadBMP("menu_2.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }
break;

case SDL_MOUSEBUTTONUP:
            souri.x = event.button.x;
            souri.y = event.button.y;
            if(souri.x>=404&&souri.x<=677&&souri.y>=287&&souri.y<=356)
            choix=1;
            else if(souri.x>=404&&souri.x<=677&&souri.y>=377&&souri.y<=445)
            choix=2;
            else if(souri.x>=404&&souri.x<=677&&souri.y>=468&&souri.y<=536)
            choix=3;
            else
            choix=0;






break;

 }
 }while(choix==0);


if(choix==1)
{
    do
    {
    //METTRE LE DO WHILE A PARTIR D'ICI POUR FAIRE LE REJOUER///////////////////////////////////////////////////////////////////////////////////
 system("cls");
 initialiser_plateau();
 afficher_plateau();
 tmp = SDL_LoadBMP("plateau1.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);

 affichage_pions(renderer,texture5,Tab_img1,Tab_img2,dst5,Tab1,Tab2);
 joueur=1;
 fin=0;
 rejouer=0;
 do
 {

    if(joueur==1)
    {
        tmp5 = SDL_LoadBMP("cache_2.bmp");
        dst6.x=349;
        dst6.y=468;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);

        if(choix==1)
        tmp5 = SDL_LoadBMP("player1.bmp");

        dst6.x=288;
        dst6.y=37;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
    }
    if(joueur==2)
    {
        tmp5 = SDL_LoadBMP("cache_1.bmp");
        dst6.x=240;
        dst6.y=0;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
        if(choix==1)
        tmp5 = SDL_LoadBMP("player2.bmp");

        dst6.x=405;
        dst6.y=502;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
    }



   SDL_WaitEvent(&event);
 switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:
      souri.x = event.motion.x;
      souri.y = event.motion.y;

      if(souri.x>=52&&souri.x<=110&&souri.y>=39&&souri.y<=106)
      {
        dst6.x=0;
        dst6.y=0;
        tmp5 = SDL_LoadBMP("retour_menu2.bmp");
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
      }
      else
      {
        dst6.x=0;
        dst6.y=0;
        tmp5 = SDL_LoadBMP("retour_menu1.bmp");
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
      }

      if(a!=-1&&b!=-1)
      {
          if(b==0)
              {
                  texture5=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
                  afficher_case_selectionne(a,b,232+106*(a-1),180+127*b,dst5,texture5,renderer,Tab_img1,Tab_img2);
                  a=-1;b=-1;
              }

              if(b==1)
              {
                  texture5=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab2[a-1]]);
                  afficher_case_selectionne(a-1,b,232+106*(a-1),180+127*b,dst5,texture5,renderer,Tab_img1,Tab_img2);
                  a=-1;b=-1;
              }
        //afficher_case_selectionne(a,b,232+106*(a-1),180+127*b,dst2,texture2,renderer,Tab_img1,Tab_img2);

      }


      for(j=0;j<2;j++)
      {
          for(i=1;i<=6;i++)
          {

              if((souri.x>=232+106*(i-1))&&(souri.x<=232+106*(i-1)+90)&&(souri.y>=180+127*j)&&(souri.y<=180+127*j+106)&&j==0)
              {
                  if(j==0&&joueur==1)
                  {
                    texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab1[i]]);
                    afficher_case_selectionne2(i,j,232+106*(i-1),180+127*j,dst2,texture2,renderer,Tab_img1,Tab_img2);
                    b=j;a=i;
                  }
              }

              if((souri.x>=232+106*(i-1))&&(souri.x<=232+106*(i-1)+90)&&(souri.y>=180+127*j)&&(souri.y<=180+127*j+106)&&j==1)
              {
                  if(j==1&&joueur==2)
                  {
                      texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab2[i-1]]);
                      afficher_case_selectionne2(i,j,232+106*(i-1),180+127*j,dst2,texture2,renderer,Tab_img1,Tab_img2);
                      b=j;a=i;
                  }
              }
              //if((souri.x<232+106*i)||(souri.x>232+106*i+90)||(souri.y<180+127*j)||(souri.y>180+127*j+106))
              //afficher_case_selectionne(232+106*a,180+127*b,dst2,texture2,renderer);



          }
      }


break;

case SDL_MOUSEBUTTONUP:
            souri.x = event.button.x;
            souri.y = event.button.y;

            if(souri.x>=52&&souri.x<=110&&souri.y>=39&&souri.y<=106)
            retour_menu=1;

            for(j=0;j<2;j++)
      {
          for(i=1;i<=6;i++)
          {

              if((souri.x>=232+106*(i-1))&&(souri.x<=232+106*(i-1)+90)&&(souri.y>=180+127*j)&&(souri.y<=180+127*j+106))
              {
                  if(j==0&&joueur==1)
                  {
                      jouer(i);
                    afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);
                    afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);

                    if(fin_du_jeu()==1)
                    fin=1;

                    afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);
                    afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);
                    system("cls");
                      printf("\n\n");
                   afficher_plateau();
                  }

                   if(j==1&&joueur==2)
                   {
                       jouer(i-1);
                       afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);
                       afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);

                       if(fin_du_jeu()==1)
                       fin=1;

                       afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);
                       afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);
                       system("cls");
                      printf("\n\n");
                      afficher_plateau();
                   }

                //SDL_Delay(500);
                affichage_pions(renderer,texture5,Tab_img1,Tab_img2,dst5,Tab1,Tab2);




              }
              //if((souri.x<232+106*i)||(souri.x>232+106*i+90)||(souri.y<180+127*j)||(souri.y>180+127*j+106))
              //afficher_case_selectionne(232+106*a,180+127*b,dst2,texture2,renderer);



          }
      }
break;

}

 }while(retour_menu==0&&fin==0);
system("cls");
afficher_plateau();

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 if(fin==1)
{

    if(Tab1[0]>Tab2[6])
    {
 tmp = SDL_LoadBMP("fin1.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
    if(Tab2[6]>Tab1[0])
    {
 tmp = SDL_LoadBMP("fin2.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
    do
 {

   SDL_WaitEvent(&event);
 switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:
      souri.x = event.motion.x;
      souri.y = event.motion.y;

      if(souri.x>=365&&souri.x<=520&&souri.y>=494&&souri.y<=557)
      {
          tmp = SDL_LoadBMP("fin_quitter.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          dst7.x=365;
          dst7.y=494;
          SDL_QueryTexture(texture,NULL,NULL, &dst7.w, &dst7.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst7);
          SDL_RenderPresent(renderer);

      }

     else if(souri.x>=574&&souri.x<=760&&souri.y>=494&&souri.y<=557)
      {

          tmp = SDL_LoadBMP("fin_rejouer.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          dst7.x=574;
          dst7.y=494;
          SDL_QueryTexture(texture,NULL,NULL, &dst7.w, &dst7.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst7);
          SDL_RenderPresent(renderer);


      }
    else
    {
      if(Tab1[0]>Tab2[6])
    {
 tmp = SDL_LoadBMP("fin1.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 dst.x=0;
 dst.y=0;
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
    if(Tab2[6]>Tab1[0])
    {
 tmp = SDL_LoadBMP("fin2.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 dst.x=0;
 dst.y=0;
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
}
 break;

 case SDL_MOUSEBUTTONUP:
      souri.x = event.button.x;
      souri.y = event.button.y;

      if(souri.x>=365&&souri.x<=520&&souri.y>=494&&souri.y<=557)
        retour_menu=1;

      if(souri.x>=574&&souri.x<=760&&souri.y>=494&&souri.y<=557)
      {
          rejouer=1;

      }


break;
 }
}while(rejouer==0&&retour_menu==0);





}
}while(rejouer==1&&retour_menu==0);
}


if(choix==2)
{
 choix_difficulte=0;
 tmp = SDL_LoadBMP("difficulte.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);


 do
 {

   SDL_WaitEvent(&event);
 switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:
      souri.x = event.motion.x;
      souri.y = event.motion.y;

      if(souri.x>=422&&souri.x<=657&&souri.y>=283&&souri.y<=339)
      {
          tmp = SDL_LoadBMP("difficulte1.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }

      else if(souri.x>=422&&souri.x<=657&&souri.y>=359&&souri.y<=413)
      {

          tmp = SDL_LoadBMP("difficulte2.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);


      }
      else if(souri.x>=422&&souri.x<=657&&souri.y>=435&&souri.y<=489)
      {

          tmp = SDL_LoadBMP("difficulte3.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }
      else if(souri.x>=59&&souri.x<=115&&souri.y>=34&&souri.y<=100)
      {

          tmp = SDL_LoadBMP("retour2.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }
      else
      {
          tmp = SDL_LoadBMP("difficulte.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

    }
 break;

 case SDL_MOUSEBUTTONUP:
      souri.x = event.button.x;
      souri.y = event.button.y;

      if(souri.x>=59&&souri.x<=115&&souri.y>=34&&souri.y<=100)
        retour_menu=1;

      if(souri.x>=422&&souri.x<=657&&souri.y>=283&&souri.y<=339)
      {
          choix_difficulte=1;

      }

      if(souri.x>=422&&souri.x<=657&&souri.y>=359&&souri.y<=413)
      {
          choix_difficulte=2;


      }
      if(souri.x>=422&&souri.x<=657&&souri.y>=435&&souri.y<=489)
      {

          choix_difficulte=3;

      }
      if(souri.x>=59&&souri.x<=115&&souri.y>=34&&souri.y<=100)
      {

        retour_menu=1;

      }
break;
 }
}while(choix_difficulte==0&&retour_menu==0);


if(choix_difficulte==1||choix_difficulte==2||choix_difficulte==3)
{
    do
    {

    //METTRE LE DO WHILE A PARTIE D'ICI POUR FAIRE LE REJOUER///////////////////////////////////////////////////////////////////////////////////
    system("cls");
    initialiser_plateau();
    afficher_plateau();
    tmp = SDL_LoadBMP("plateau2.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);

 affichage_pions(renderer,texture5,Tab_img1,Tab_img2,dst5,Tab1,Tab2);
 joueur=1;
 fin=0;
 rejouer=0;
 do
 {


if(joueur==2&&fin==0)
{
    tmp5 = SDL_LoadBMP("cache_1.bmp");
        dst6.x=240;
        dst6.y=0;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);

        tmp5 = SDL_LoadBMP("you.bmp");

        dst6.x=405;
        dst6.y=502;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);

   SDL_WaitEvent(&event);
 switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:

      souri.x = event.motion.x;
      souri.y = event.motion.y;

      if(souri.x>=52&&souri.x<=110&&souri.y>=39&&souri.y<=106)
      {
        dst6.x=0;
        dst6.y=0;
        tmp5 = SDL_LoadBMP("retour_menu2.bmp");
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
      }
      else
      {
        dst6.x=0;
        dst6.y=0;
        tmp5 = SDL_LoadBMP("retour_menu1.bmp");
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);
      }

      if(a!=-1&&b!=-1)
      {
          if(b==0)
              {
                  texture5=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab1[a]]);
                  afficher_case_selectionne(a,b,232+106*(a-1),180+127*b,dst5,texture5,renderer,Tab_img1,Tab_img2);
                  a=-1;b=-1;
              }

              if(b==1)
              {
                  texture5=SDL_CreateTextureFromSurface(renderer,Tab_img1[Tab2[a-1]]);
                  afficher_case_selectionne(a-1,b,232+106*(a-1),180+127*b,dst5,texture5,renderer,Tab_img1,Tab_img2);
                  a=-1;b=-1;
              }
        //afficher_case_selectionne(a,b,232+106*(a-1),180+127*b,dst2,texture2,renderer,Tab_img1,Tab_img2);

      }



          for(i=1;i<=6;i++)
          {
              j=1;


              if((souri.x>=232+106*(i-1))&&(souri.x<=232+106*(i-1)+90)&&(souri.y>=180+127*j)&&(souri.y<=180+127*j+106)&&joueur==2)
              {
                  if(j==1)
                  {
                      texture2=SDL_CreateTextureFromSurface(renderer,Tab_img2[Tab2[i-1]]);
                      afficher_case_selectionne2(i,j,232+106*(i-1),180+127*j,dst2,texture2,renderer,Tab_img1,Tab_img2);
                      b=j;a=i;
                  }
              }
              //if((souri.x<232+106*i)||(souri.x>232+106*i+90)||(souri.y<180+127*j)||(souri.y>180+127*j+106))
              //afficher_case_selectionne(232+106*a,180+127*b,dst2,texture2,renderer);



          }



break;

case SDL_MOUSEBUTTONUP:
            souri.x = event.button.x;
            souri.y = event.button.y;

            if(souri.x>=52&&souri.x<=110&&souri.y>=39&&souri.y<=106)
                retour_menu=1;

          for(i=1;i<=6;i++)
          {
              j=1;

              if((souri.x>=232+106*(i-1))&&(souri.x<=232+106*(i-1)+90)&&(souri.y>=180+127*j)&&(souri.y<=180+127*j+106))
              {

                   if(j==1&&joueur==2)
                   {
                       jouer(i-1);
                       afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);
                       afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);

                       if(fin_du_jeu()==1)
                        fin=1;

                       afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);
                       afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);
                       system("cls");
                      printf("\n\n");
                      afficher_plateau();
                   }

                //SDL_Delay(500);
                affichage_pions(renderer,texture5,Tab_img1,Tab_img2,dst5,Tab1,Tab2);





              //if((souri.x<232+106*i)||(souri.x>232+106*i+90)||(souri.y<180+127*j)||(souri.y>180+127*j+106))
              //afficher_case_selectionne(232+106*a,180+127*b,dst2,texture2,renderer);



          }
      }
break;

}


}


if(joueur==1&&fin==0)
{
    tmp5 = SDL_LoadBMP("cache_2.bmp");
        dst6.x=349;
        dst6.y=468;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);


        tmp5 = SDL_LoadBMP("computer.bmp");

        dst6.x=288;
        dst6.y=37;
        texture5=SDL_CreateTextureFromSurface(renderer, tmp5);
        SDL_QueryTexture(texture5,NULL,NULL, &dst6.w, &dst6.h);
        SDL_RenderCopy(renderer, texture5, NULL, &dst6);
        SDL_RenderPresent(renderer);


        SDL_PollEvent(&event);
        switch(event.type)
        {
         case SDL_QUIT:
             SDL_Quit();
             break;
         case SDL_MOUSEMOTION:
            break;
         case SDL_MOUSEBUTTONUP:
            break;


        }

SDL_Delay(1000);
if(choix_difficulte==1)
jouer(strategie0(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
if(choix_difficulte==2||choix_difficulte==3)
{

    if(choix_difficulte==3)
      {//SDL_Delay(7000);
    if(strategie1(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie1(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie6(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie6(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie3(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie3(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie2(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie2(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie4(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie4(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));

    else if(strategie5(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie5(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else
    jouer(strategie0(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));

      }
      if(choix_difficulte==2)
      {
    if(strategie6(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie6(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie1(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie1(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie3(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie3(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie4(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie4(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie2(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie2(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else if(strategie5(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2)!=0)
    jouer(strategie5(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));
    else
    jouer(strategie0(renderer,texture2,Tab_img1,Tab_img2,dst2,Tab1,Tab2));

      }

}

if(fin_du_jeu()==1)
fin=1;

afficher_pion_grenier(130,180,Tab1[0],renderer,texture4,dst4);
afficher_pion_grenier(870,180,Tab2[6],renderer,texture4,dst4);




system("cls");
printf("\n\n");
afficher_plateau();
affichage_pions(renderer,texture5,Tab_img1,Tab_img2,dst5,Tab1,Tab2);



  }

 }while(retour_menu==0&&fin==0);
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
system("cls");
afficher_plateau();

    if(fin==1)
{

    if(Tab1[0]>Tab2[6])
    {
 tmp = SDL_LoadBMP("fin3.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
    if(Tab2[6]>Tab1[0])
    {
 tmp = SDL_LoadBMP("fin.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
    do
 {

   SDL_WaitEvent(&event);
 switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:
      souri.x = event.motion.x;
      souri.y = event.motion.y;

      if(souri.x>=365&&souri.x<=520&&souri.y>=494&&souri.y<=557)
      {
          tmp = SDL_LoadBMP("fin_quitter.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          dst7.x=365;
          dst7.y=494;
          SDL_QueryTexture(texture,NULL,NULL, &dst7.w, &dst7.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst7);
          SDL_RenderPresent(renderer);

      }

      else if(souri.x>=574&&souri.x<=760&&souri.y>=494&&souri.y<=557)
      {

          tmp = SDL_LoadBMP("fin_rejouer.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          dst7.x=574;
          dst7.y=494;
          SDL_QueryTexture(texture,NULL,NULL, &dst7.w, &dst7.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst7);
          SDL_RenderPresent(renderer);


      }
    else
    {
      if(Tab1[0]>Tab2[6])
    {
 tmp = SDL_LoadBMP("fin3.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 dst.x=0;
 dst.y=0;
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
    if(Tab2[6]>Tab1[0])
    {
 tmp = SDL_LoadBMP("fin.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 dst.x=0;
 dst.y=0;
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);
    }
}
 break;

 case SDL_MOUSEBUTTONUP:
      souri.x = event.button.x;
      souri.y = event.button.y;

      if(souri.x>=365&&souri.x<=520&&souri.y>=494&&souri.y<=557)
        retour_menu=1;

      if(souri.x>=574&&souri.x<=760&&souri.y>=494&&souri.y<=557)
      {
          rejouer=1;

      }


break;
 }
}while(rejouer==0&&retour_menu==0);
 }


}while(rejouer==1&&retour_menu==0);

}

}

if(choix==3)
{
    tmp = SDL_LoadBMP("aide.bmp");

 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
 SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
 SDL_RenderCopy(renderer, texture, NULL, &dst);
 SDL_RenderPresent(renderer);


 do
 {

   SDL_WaitEvent(&event);
 switch(event.type)
{
case SDL_QUIT:
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();
break;

case SDL_MOUSEMOTION:
      souri.x = event.motion.x;
      souri.y = event.motion.y;


    if(souri.x>=59&&souri.x<=115&&souri.y>=34&&souri.y<=100)
      {

          tmp = SDL_LoadBMP("retour2.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

      }
      else
      {
          tmp = SDL_LoadBMP("aide.bmp");
          texture = SDL_CreateTextureFromSurface(renderer, tmp);
          SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plusbesoin */
          SDL_QueryTexture(texture,NULL,NULL, &dst.w, &dst.h);
          SDL_RenderCopy(renderer, texture, NULL, &dst);
          SDL_RenderPresent(renderer);

    }
 break;

 case SDL_MOUSEBUTTONUP:
      souri.x = event.button.x;
      souri.y = event.button.y;


      if(souri.x>=59&&souri.x<=115&&souri.y>=34&&souri.y<=100)
      {

        retour_menu=1;

      }
break;
 }
}while(retour_menu==0);

}



}while(retour_menu!=0);

system("cls");
afficher_plateau();
SDL_Delay(3000);
if(NULL != texture)
 SDL_DestroyTexture(texture);
 if(NULL != texture2)
 SDL_DestroyTexture(texture2);
 if(NULL != texture3)
 SDL_DestroyTexture(texture3);
 if(NULL != texture4)
 SDL_DestroyTexture(texture4);
 if(NULL != texture5)
 SDL_DestroyTexture(texture5);
 if(NULL != renderer)
 SDL_DestroyRenderer(renderer);
 if(NULL != window)
 SDL_DestroyWindow(window);

SDL_Quit();


    return 0;
}
