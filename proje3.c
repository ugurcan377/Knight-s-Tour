//      proje3.c
//      
//      Copyright 2011 Uğurcan <ugurcan@pavilion>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      

   #include <allegro.h>
   #include <stdio.h>
   int goster();
   int sonraki(int x1,int x2,int stahta[][8]);
   int cursor_x=2000;
   int cursor_y=2000;
   FILE *dosya;
   BITMAP *buffer = NULL;
	BITMAP *at;
	void fare();
   void main()
   {
     int tahta[8][8]; 
     int i,j,k,l,x,y,ek,ex,ey,say;
		basla:
     allegro_init();
     install_keyboard();
     install_mouse();
     install_timer();
    set_color_depth(32);
    set_window_title("At Turu");
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 480, 480, 0, 0);
    buffer = create_bitmap(480, 480);
	at = load_bitmap( "at2.bmp", NULL);
    if(!buffer){
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Tampon hatası");
      allegro_exit();
      exit(-1);
    }
    show_mouse(screen);
    clear(buffer);
    goster();
	blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
   // acquire_screen();
   dosya=fopen("rapor.txt","w");     
    while(cursor_x==2000 && cursor_y ==2000){
    fare();
}
    for(i=0;i<=7;i++){
      for(j=0;j<=7;j++){
        tahta[i][j]=0; }}
    x=cursor_x/60;
    y=cursor_y/60;
    say=0;
	textprintf_ex(buffer,font,(x*60)+20,(y*60)+20,makecol(0,0,0),makecol(250, 250, 250),"%d %d",x+1,y+1);
		draw_sprite(screen,buffer,0,0);
		rest(2000);
     	draw_sprite(buffer,at,(x*60),(y*60));
	blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
     while(!key[KEY_SPACE]){}
    for(k=1;k<=63;k++){
      ek=0;
      ex=0;
      ey=0;
      tahta[x][y]=k;
        if((x-2)>=0 && (x-2)<=7 && (y-1)>=0 && (y-1)<=7) {
          if(tahta[x-2][y-1]==0) {
            say=sonraki(x-2,y-1,tahta);
              fprintf(dosya,"say1= %d ",say);
              if (say>ek) {
                ek=say;
                ex=x-2;
                ey=y-1;
          }
          }
      }
      say=0;
        if((x-1)>=0 && (x-1)<=7 && (y-2)>=0 && (y-2)<=7) {
          if(tahta[x-1][y-2]==0) {
            say=sonraki(x-1,y-2,tahta);
              fprintf(dosya,"say2= %d ",say);
              if (say>ek) {
                ek=say;
                ex=x-1;
                ey=y-2;
          }
          }
      }
      say=0;
        if((x+1)>=0 && (x+1)<=7 && (y-2)>=0 && (y-2)<=7) {
          if(tahta[x+1][y-2]==0) {
            say=sonraki(x+1,y+1,tahta);
              fprintf(dosya,"say3= %d ",say);
              if (say>ek) {
                ek=say;
                ex=x+1;
                ey=y-2;
          }
          }
      }
        say=0;
        if((x+2)>=0 && (x+2)<=7 && (y-1)>=0 && (y-1)<=7) {
          if(tahta[x+2][y-1]==0) {
            say=sonraki(x+2,y-1,tahta);
            fprintf(dosya,"say4= %d ",say);
            if (say>ek) {
              ek=say;
              ex=x+2;
              ey=y-1;
          }
          }
      }
      say=0;
        if((x+2)>=0 && (x+2)<=7 && (y+1)>=0 && (y+1)<=7) {
          if(tahta[x+2][y+1]==0) {
            say=sonraki(x+2,y+1,tahta);
              fprintf(dosya,"say5= %d ",say);
              if (say>ek) {
                ek=say;
                ex=x+2;
                ey=y+1;
          }
          }
      }
      say=0;
        if((x+1)>=0 && (x+1)<=7 && (y+2)>=0 && (y+2)<=7) {
          if(tahta[x+1][y+2]==0) {
            say=sonraki(x+1,y+2,tahta);
              fprintf(dosya,"say6= %d ",say);
              if (say>ek) {
                ek=say;
                ex=x+1;
                ey=y+2;
          }
          }
      }
      say=0;
        if((x-1)>=0 && (x-1)<=7 && (y+2)>=0 && (y+2)<=7) {
          if(tahta[x-1][y+2]==0) {
            say=sonraki(x-1,y+2,tahta);
             fprintf(dosya,"say7= %d ",say);
              if (say>ek) {
                ek=say;
                ex=x-1;
                ey=y+2;
          }
          }
      }
      say=0;
        if((x-2)>=0 && (x-2)<=7 && (y+1)>=0 && (y+1)<=7) {
          if(tahta[x-2][y+1]==0) {
            say=sonraki(x-2,y+1,tahta);
            fprintf(dosya,"say8= %d ",say);  
              if (say>ek) {
                ek=say;
                ex=x-2;
               ey=y+1;
         }
         }
     }
     say=0;
 
     fprintf(dosya,"\n"); 
   if (k==1) rectfill(buffer,(x*60)+2,(y*60)+2,(x*60)+58,(y*60)+58,makecol(250,30,30));
   else rectfill(buffer,(x*60)+2,(y*60)+2,(x*60)+58,(y*60)+58,makecol(30,30,30));
	fprintf(dosya,"x=%d y=%d ek=%d ex=%d ey=%d k=%d \n",x+1,y+1,ek,ex+1,ey+1,k);
	x=ex;
	y=ey;   
	draw_sprite(buffer,at,(x*60),(y*60));
	blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
   rest(150);
   while(!key[KEY_SPACE]){}
   } 
  // release_screen();
   fclose(dosya);
   while(!key[KEY_ESC]){
	  if(key[KEY_ENTER]) goto basla;
	   }
 } END_OF_MAIN();
 int goster()
 {
   int i,j,x,y,beyaz,gri,k1,k2;
   char a='d';
   beyaz=250;
   gri=175;
   y=0;
   for (i=1;i<=8;i++){
     x=0;
     if (i%2==0){
         k1=0;
         k2=1;
         }
       else {
         k1=1;
         k2=0;
         }  
     for(j=1;j<=8;j++){      
       if(j%2==k1) {rectfill(buffer,x,y,x+60,y+60,makecol(gri,gri,gri));
       }
       if (j%2==k2) {rectfill(buffer,x,y,x+60,y+60,makecol(beyaz,beyaz,beyaz));
       }
       x+=60;      }
     y+=60;
     }

   } 
 int sonraki(int x1,int y1,int stahta[][8]) {
   int say;
   say=0;
   if((x1-2)>=0 && (x1-2)<=7 && (y1-1)>=0 && (y1-1)<=7 && stahta[x1-2][y1-1]==0) say++;
   if((x1-1)>=0 && (x1-1)<=7 && (y1-2)>=0 && (y1-2)<=7 && stahta[x1-1][y1-2]==0) say++;
   if((x1+1)>=0 && (x1+1)<=7 && (y1-2)>=0 && (y1-2)<=7 && stahta[x1+1][y1-2]==0) say++;
   if((x1+2)>=0 && (x1+2)<=7 && (y1-1)>=0 && (y1-1)<=7 && stahta[x1+2][y1-1]==0) say++;
   if((x1+2)>=0 && (x1+2)<=7 && (y1+1)>=0 && (y1+1)<=7 && stahta[x1+2][y1+1]==0) say++;
   if((x1+1)>=0 && (x1+1)<=7 && (y1+2)>=0 && (y1+2)<=7 && stahta[x1+1][y1+2]==0) say++;
   if((x1-1)>=0 && (x1-1)<=7 && (y1+2)>=0 && (y1+2)<=7&& stahta[x1-1][y1+2]==0) say++;
   return say;
   }
void fare(){
if(mouse_b & 1){
cursor_x = mouse_x;
cursor_y = mouse_y;}
}
