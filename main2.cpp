
/*#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "Collision.h"

struct {
	int x=0, y=225;
}s[1];

struct enemy{
	int x=0, y=0;
}ee[100];

int randnum(struct enemy ee[],int t, char d){
    int v,q=1;
    while(1){
            if(d=='x')
                v=rand()%300+724;
            else if(d=='y')
                v=rand()%509;
            for(q=1; q < t; q++){
                if(abs(ee[q].x-v) <= 40 && d=='x'){
                    break;
                }
                else if(abs(ee[q].y-v) <= 30 && d=='y'){
                    break;
                }
            }
            if(q==t)
                break;
        }
     return v;
    }

using namespace sf;

int main(){

    RenderWindow window(VideoMode(724, 550), "YoOOooOOoo BroOooO");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(40);
    window.setVerticalSyncEnabled(true);
    Texture bg,bg1,z,e;
    bg.loadFromFile("images/farback.gif");

    bg1.loadFromFile("images/starfield.png");
    z.loadFromFile("images/sh64x29.png");
    e.loadFromFile("images/eSpritesheet_40x30.png");

    Sprite sp1(bg),sp2(bg1),sh(z),eh(e);
    int x=1,i=0,j=0,k,ec1=1,ec2;
    Clock clock1,clock2;

    while (window.isOpen()){
        float time = clock1.getElapsedTime().asSeconds();
        float time1 = clock2.getElapsedTime().asSeconds();
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) && s[0].x >= 4)
			s[0].x-=4;
		if (Keyboard::isKeyPressed(Keyboard::Right) && s[0].x <= 656)
			s[0].x+=4;
		if (Keyboard::isKeyPressed(Keyboard::Up) && s[0].y >= 4)
			s[0].y-=4;
		if (Keyboard::isKeyPressed(Keyboard::Down) && s[0].y <= 520)
			s[0].y+=4;


        for(; ec1 < 6; ec1++){
            ee[ec1].x=randnum(ee,ec1,'x');
            ee[ec1].y=randnum(ee,ec1,'y');
        }

        for(ec2=1; ec2 <6; ec2++){
            ee[ec2].x-=3;
            if(ee[ec2].x<-29){
               ee[ec2].x=randnum(ee,6,'x');
               ee[ec2].y=randnum(ee,6,'y');
            }
        }


        if(x < -800)
            x=0;
        x--;
        if(i > 3)
           i=0;
        if(j > 5)
           j=0;

        window.clear();

        window.draw(sp1);
        sp2.setPosition(x,0);
        window.draw(sp2);
        sp2.setPosition(800+x,0);
        window.draw(sp2);

        sh.setPosition(s[0].x,s[0].y);
        sh.setTextureRect(IntRect(0,i*29,64,29));
        window.draw(sh);

        for(k=1; k < 6;k++){
           eh.setPosition(ee[k].x,ee[k].y);
           eh.setTextureRect(IntRect(0,j*30,40,30));
           window.draw(eh);
          // if( ((ee[k].x - s[0].x ) >= -16 && (ee[k].x - s[0].x ) <= 62) && ((ee[k].y - s[0].y ) >= -24 && (ee[k].y - s[0].y ) <= 24)){
         //     ee[k].x=rand()%150+724;
         //    ee[k].y=rand()%543-5;
         //     }
          //  if(eh.getGlobalBounds().intersects(sh.getGlobalBounds())){
      //          ee[k].x=rand()%150+724;
       //         ee[k].y=rand()%543-5;
     //       }
            if(Collision::PixelPerfectTest(eh,sh)){
                ee[k].x=randnum(ee,6,'x');
                ee[k].y=randnum(ee,6,'y');
            }
        }

        if(time > 0.02){
            i++;
        clock1.restart();
        }
        if(time1 > 0.11){
            j++;
        clock2.restart();
        }
        window.display();
    }

    return 0;
}*/
