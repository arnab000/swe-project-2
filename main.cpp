#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "collusion.h"

using namespace sf;
using namespace std;

struct enemy{
    int x=0, y=0;
} ee[100];
struct enemybullet{
    int x=0,y=0;
}eeb[100];
struct ass{
    float x=0,y=0;
}ab[100];
string title(int life, int counte){
    string title1="  Shoot Them All             Life-Remaining :  ";
    string title2="                                                    SCORE : ";
    title1.append(to_string(life));
    title2.append(to_string(counte));
    title2.append(" ");
    title1.append(title2);
    return title1;
}

int randnum(struct enemy ee[],int t, char d){
    int v,q=1;
    while(1){
        if(d=='x')
            v=rand()%1600+1400;
        else if(d=='y')
            v=rand()%600;
        for(q=1; q < t; q++){
            if(abs(ee[q].x-v) <= 300 && d=='x'){
                 break;
            }
            else if(abs(ee[q].y-v) <= 100&& d=='y'){
                break;
            }
        }
        if(q==t)
            break;
    }
    return v;
}

int  main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1080,720),"  Shoot Them All");
    window.setVerticalSyncEnabled(true);
    Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11;
    t1.loadFromFile("bgod.png");
    t2.loadFromFile("farback.gif");
    t3.loadFromFile("shot.png");
    t4.loadFromFile("ene.png");
    t5.loadFromFile("20376860.jpg");
    t6.loadFromFile("starfield.png");
    t7.loadFromFile("Explosion.png");
    t8.loadFromFile("Red Space.bmp");
    t9.loadFromFile("bullet1.png");
    t10.loadFromFile("bullet1.png");
    t11.loadFromFile("hehe1.png");

    t1.setSmooth(true);
    t2.setSmooth(true);
    t3.setSmooth(true);
    t4.setSmooth(true);
    t11.setSmooth(true);
    Sprite background(t2),bship(t1),bullet(t3),eh(t4),gm(t5),sp2(t6),sh(t7),menui(t8),eb(t9),cb(t10),boss(t11);
    bool isfire=false, spacePressed=false,explosion=false,explosion1=false,menu=true,pause1=false,explosion2=false,explosion3=false,explosion4=false;

    Clock clock1, clock2,gameoverclock,clock3,clock4;
    SoundBuffer gunshot, explose;
    gunshot.loadFromFile("gunshot.wav");
    explose.loadFromFile("explosion.wav");
    Sound gun(gunshot), exp(explose);

    vector<Sprite>bullets;
    vector<Sprite>explosions;

    vector<int>h;

    Font menuFont;
    menuFont.loadFromFile("gamefont.ttf");

    Text startText("Start Game", menuFont, 50);
    Text exitText("Exit Game", menuFont, 50);
    Text pauseText1("Resume",menuFont, 50);
    Text pauseText2("Main Menu",menuFont,50);
    startText.setPosition(350,320);
    exitText.setPosition(350,380);
    pauseText1.setPosition(350,320);
    pauseText2.setPosition(350,380);

    startText.setFillColor(Color::White);
    exitText.setFillColor(Color::White);

    int menuSelection=0,pauseSelection=0;
    int x=80,y=360,life=4,z=1,ec1=1,ec2,n,r,j=0,ex1,ex2,counte=0,hcounte=0,bul1,bul2 ,d,dada=1,he,hehe,XD,XD1;
    gm.setScale(1.08f,.9536f);
    background.setScale(1.0f,1.5f);
    sp2.setScale(1.0f,1.2f);
    bship.setOrigin(48,36);

    bullet.setOrigin(12.5,4);
    bullet.setScale(.7f,.7f);
    eb.setScale(.4f,.4f);
    cb.setScale(.4f,.4f);
    boss.setScale(0.7f,0.7f);

    bship.setScale(1.6f,1.6f);
    eh.setScale(0.2f,0.2f);

    gm.setScale(1.2f,1.0f);

    while(window.isOpen()){
        float time = clock1.getElapsedTime().asSeconds();
        float time4=clock2.getElapsedTime().asSeconds();
        float time6=clock4.getElapsedTime().asSeconds();

        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyReleased)
                if(event.key.code == Keyboard::Space)
                    spacePressed=false;
        }
        if(life==0){
            window.clear();
            d=0;

            window.draw(gm);
            window.display();
            sleep(milliseconds(300));

            x=80,y=360;

            window.setTitle(title(life,counte));
            bullets.clear();
            h.clear();
            explosions.clear();

            explosion=false;
            explosion1=false;
            explosion2=false;
            explosion3=false;
            explosion4=false;
            ec1=1;

            menu=true;
            pause1=false;
            life=4;
            if(counte > hcounte)
                hcounte=counte;
            counte=0;
            //sura=false;
        }

        if(pause1){
            if(Keyboard::isKeyPressed(Keyboard::Up) && pauseSelection==1)
                pauseSelection--;
            if(Keyboard::isKeyPressed(Keyboard::Down) && pauseSelection==0)
                pauseSelection++;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && pauseSelection==0)
                pause1=false;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && pauseSelection==1){





                menu=true;
                pause1=false;
                life=0;

            }

            if(pauseSelection<0)
                pauseSelection=0;
            if(pauseSelection>1)
                pauseSelection=1;

            if(pauseSelection==0){
                pauseText1.setFillColor(Color::White);
                pauseText2.setFillColor(Color::Black);
            }
            else{
                pauseText2.setFillColor(Color::White);
                pauseText1.setFillColor(Color::Black);
            }

            window.clear();
            window.draw(menui);
            window.draw(pauseText1);
            window.draw(pauseText2);
            window.display();
        }
        if(menu && !pause1){
            if(Keyboard::isKeyPressed(Keyboard::Up) && menuSelection==1)
                menuSelection--;
            if(Keyboard::isKeyPressed(Keyboard::Down) && menuSelection==0)
                menuSelection++;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && menuSelection==0){
                menu=false;
                //sura=false;

                }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && menuSelection==1)
                window.close();

            if(menuSelection<0)
                menuSelection=0;
            if(menuSelection>1)
                menuSelection=1;

            if(menuSelection==0){
                startText.setFillColor(Color::White);
                exitText.setFillColor(Color::Black);
            }
            else{
                exitText.setFillColor(Color::White);
                startText.setFillColor(Color::Black);
            }

            window.clear();
            window.setTitle("  Shoot Them All");
            window.draw(menui);
            window.draw(startText);
            window.draw(exitText);
            window.display();
        }
        if(menu==false && pause1==false && life > 0){
            if(Keyboard::isKeyPressed(Keyboard::Up) && y >=80)
                y=y-10;
            if(Keyboard::isKeyPressed(Keyboard::Left) && x>= 90)
                x=x-10;
            if(Keyboard::isKeyPressed(Keyboard::Down) && y<=660)
                y=y+10;
            if ( Keyboard::isKeyPressed(Keyboard::Right) && x<=960)
                x=x+10;
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                pause1=true;
            if(Keyboard::isKeyPressed(Keyboard::Space) && !spacePressed){
                spacePressed = true;
                isfire=true;
                gun.play();
            }
            if(z <-799)
                z=-1;
            z--;
            if(j>=3)
                j=0;
                if(dada>=8)
                    dada=0;

            window.clear();

            bship.setPosition(x,y);
            window.draw(background);
            sp2.setPosition(z,0);
            window.draw(sp2);
            sp2.setPosition(z+800,0);
            window.draw(sp2);
            sp2.setPosition(z+1600,0);
            window.draw(sp2);
            window.setTitle(title(life,counte));

            for(; ec1 < 5; ec1++){
                ee[ec1].x=randnum(ee,ec1,'x');
                ee[ec1].y=randnum(ee,ec1,'y');
                eeb[ec1].x=ee[ec1].x;
                eeb[ec1].y=ee[ec1].y;
                ab[ec1].x=ee[ec1].x+250;
                ab[ec1].y=ee[ec1].y;


            }
            for(ec2=1; ec2 <5; ec2++){
                ee[ec2].x-=5;
                ab[ec2].x-=5;
                if(eeb[ec2].x>1000 || ee[ec2].x<-20)
                    eeb[ec2].x-=5;
                else
                    eeb[ec2].x-=15;



                if(ee[ec2].x<-400){
                    ee[ec2].x=randnum(ee,5,'x');
                    ee[ec2].y=randnum(ee,5,'y');
                    eeb[ec2].x=ee[ec2].x;
                    eeb[ec2].y=ee[ec2].y;


                }
                if(eeb[ec2].x<-90)
                {
                    eeb[ec2].x=ee[ec2].x;
                    eeb[ec2].y=ee[ec2].y;
                }
                if(ab[ec2].x<-300)
                {
                    ab[ec2].x=ee[ec2].x+250;
                    ab[ec2].y=ee[ec2].y;
                }
            }
            for(int k=1; k <5; k++){



                eh.setPosition(ee[k].x,ee[k].y);
                eb.setPosition(eeb[k].x-10,eeb[k].y+40);
                cb.setPosition(eeb[k].x-10,eeb[k].y+60);



                window.draw(eh);
                window.draw(eb);
                window.draw(cb);




               boss.setPosition(ab[k].x,ab[k].y+0);
               window.draw(boss);









                if(isfire==true){
                    bullet.setPosition(x,y);
                    bullets.push_back(bullet);
                    isfire=false;
                }

                for(int i=0; i<bullets.size(); i++){
                    window.draw(bullets[i]);
                    bullets[i].move(Vector2f(2,0));
                    auto b = bullets[i].getPosition();
                    if(b.x >1080 )
                        bullets.erase(bullets.begin()+i);

                    if(Collision::PixelPerfectTest(eh,bullets[i])  ){
                        counte++;
                        n=ee[k].x;
                        r=ee[k].y;
                        explosion=true;
                        exp.play();
                        bullets.erase(bullets.begin()+i);
                        ee[k].x=randnum(ee,5,'x');
                        ee[k].y=randnum(ee,5,'y');
                    }

                     else if(Collision::PixelPerfectTest(boss,bullets[i]) ){
                        counte++;
                        he=ab[k].x;
                        hehe=ab[k].y+0;
                        explosion4=true;
                        exp.play();
                        bullets.erase(bullets.begin()+i);
                        ab[k].x=ee[k].x+250;
                        ab[k].y=ee[k].y;
                    }
                }
                 if(Collision::PixelPerfectTest(eb,bship)||Collision::PixelPerfectTest(cb,bship))
                 {
                     life--;
                    bul1=eeb[k].x;
                    bul2=eeb[k].y;
                    explosion2=true;
                    exp.play();
                    eeb[k].x=ee[k].x;
                    eeb[k].y=ee[k].y;
                    x=80,y=360;
                 }
                if(Collision::PixelPerfectTest(eh,bship) ){
                    life--;
                    ex1=ee[k].x;
                    ex2=ee[k].y;
                    explosion1=true;
                    exp.play();
                    ee[k].x=randnum(ee,5,'x');
                    ee[k].y=randnum(ee,5,'y');
                    x=80,y=360;
                }
               if(Collision::PixelPerfectTest(boss,bship) ){
                    life--;
                    XD=ab[k].x;
                    XD1=ab[k].y;
                    explosion3=true;
                    exp.play();
                    ab[k].x=ee[k].x+250;
                    ab[k].y=-1111;
                    x=80,y=360;
                }

            }

            bship.setPosition(x,y);
            bship.setTextureRect(IntRect(j*96,106*2,96,72));
            window.draw(bship);
             if(explosion3==true){
                sh.setPosition(XD,XD1);
                explosions.push_back(sh);
                h.push_back(1);
                explosion3=false;
            }
             if(explosion4==true){
                sh.setPosition(he,hehe);
                explosions.push_back(sh);
                h.push_back(1);
                explosion4=false;
            }
            if(explosion==true){
                sh.setPosition(n,r);
                explosions.push_back(sh);
                h.push_back(1);
                explosion=false;
            }
            if(explosion1==true){
                sh.setPosition(ex1,ex2);
                explosions.push_back(sh);
                h.push_back(1);
                explosion1=false;
            }
            if(explosion2==true){
                sh.setPosition(bul1,bul2);
                explosions.push_back(sh);
                h.push_back(1);
                explosion2=false;
            }
            for(d=0; d<explosions.size(); d++){
                explosions[d].setTextureRect(IntRect(h[d]*96,0,96,96));
                window.draw(explosions[d]);
                if(time >=0.085 && h[d]<13){
                    h[d]++;
                    clock1.restart();
                }
                if(h[d]<=13 && life==0){

                       h[d]=14;

                }
            }
            boss.setTextureRect(IntRect(1024/8*dada,1024/8*dada,1024/8,1024/8));

            if(time4>0.09){
                j++;
                clock2.restart();
            }
             if(time6>0.1){
                dada++;
                clock4.restart();
            }
            window.display();
        }
    }
    printf("Your Highest Score Is : %d",hcounte);
    window.close();
    return 0;
}

/*
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <bits/stdc++.h>
#include "Collusion.h"
using namespace sf;
using namespace std;

struct enemy{
	int x=0, y=0;
}ee[100];

int randnum(struct enemy ee[],int t, char d){
    int v,q=1;
    while(1){
            if(d=='x')
                v=rand()%1000;
            else if(d=='y')
                v=rand()%300-720;
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
int main()
{

   ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1080,720),"battleship shooting");

    window.setVerticalSyncEnabled(true);
    Texture t1,t2,t3,t4,t5,t6,t7;
    t2.loadFromFile("farback.gif");
    t1.loadFromFile("bgod.png");
    t3.loadFromFile("bullet.png");
    t4.loadFromFile("alien1.png");
    t5.loadFromFile("20376860.jpg");
    t6.loadFromFile("starfield.png");
    t7.loadFromFile("Explosion.png");

    t1.setSmooth(true);
    t2.setSmooth(true);
    t3.setSmooth(true);
    t4.setSmooth(true);
    Sprite background(t2);
    Sprite bship(t1);
    Sprite bullet(t3);
    Sprite eh(t4);
    Sprite gm(t5);
    Sprite sp2(t6);
    Sprite sh(t7);
    bool isfire=false, spacePressed=false,explosion=false;
     Clock clock1, clock2;

    Clock gameOverClock;
    vector<Sprite>bullets;
    vector<Sprite>sura;
    vector<int>h;


    int x=540,y=620,l=0,z=0,ec1=1,ec2,n,r,j=0;
    //bship.setPosition(x,y);
    background.setScale(1.0f,1.5f);
     sp2.setScale(1.5f,1.5f);
   bship.setOrigin(48,53);
   bullet.setOrigin(47.5,75.5);
  // gm.setOrigin(500,415);
    bullet.setScale(.4f,.4f);
   // bship.setOrigin()
   bship.setScale(1.6f,1.6f);
   eh.setScale(.35f,.35f);
  gm.setScale(1.2f,1.0f);
    while(window.isOpen())
    {
        Event e;
        float time = clock1.getElapsedTime().asSeconds();
         float time4=clock2.getElapsedTime().asSeconds();
        while(window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
            if (e.type == Event::KeyReleased){
                if(e.key.code == Keyboard::Space) spacePressed=false;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && y >=100)
{
   y=y-10;
}
if (Keyboard::isKeyPressed(Keyboard::Left) && x>= 70)
{
  x=x-10;
}
if (Keyboard::isKeyPressed(Keyboard::Down) && y<=620)
{
  y=y+10;
}
if (Keyboard::isKeyPressed(Keyboard::Right) && x<=1000)
{
   x=x+10;
}

if(Keyboard::isKeyPressed(Keyboard::Space) && !spacePressed)
        {
            spacePressed = true;
          isfire=true;
        }
        window.clear();





        bship.setPosition(x,y);

        window.draw(background);

       if(z <-700)
            z=0;
        z--;
        if(j>=3)
            j=0;



        sp2.setPosition(0,z);
        window.draw(sp2);
        sp2.setPosition(0,z+700);
        window.draw(sp2);

        bship.setPosition(x,y);
        bship.setTextureRect(IntRect(j*96,289.5,96,106));
        window.draw(bship);
          for(; ec1 < 8; ec1++){
            ee[ec1].x=randnum(ee,ec1,'x');
            ee[ec1].y=randnum(ee,ec1,'y');
        }

        for(ec2=1; ec2 <8; ec2++){
            ee[ec2].y+=3;
            if(ee[ec2].y>700){
               ee[ec2].x=randnum(ee,8,'x');
               ee[ec2].y=randnum(ee,8,'y');
            }
        }


      //  if(x < -800)
           // x=0;
       // x--;

        for(int k=1; k < 8;k++){
           eh.setPosition(ee[k].x,ee[k].y);
           //eh.setTextureRect(IntRect(0,j*30,40,30));
           window.draw(eh);

         if(isfire==true)
        {
            bullet.setPosition(x,y);

            bullets.push_back(bullet);

            isfire=false;


        }

    for(int i=0;i<bullets.size();i++)
       {
           //sleep(milliseconds(10));
           window.draw(bullets[i]);
            bullets[i].move(Vector2f(0,-2));
            auto b = bullets[i].getPosition();
            if(b.y < 0)
                bullets.erase(bullets.begin()+i);
            if(Collision::PixelPerfectTest(eh,bullets[i])){

                    n=ee[k].x;
                    r=ee[k].y;
                    explosion=true;
                    bullets.erase(bullets.begin()+i);





                 ee[k].x=randnum(ee,8,'x');
                ee[k].y=randnum(ee,8,'y');

               // bullets[i].setColor(sf::Color::Transparent);


            }


        }
         if(Collision::PixelPerfectTest(eh,bship))
              {
                  n=ee[k].x;
                  r=ee[k].y;
                  explosion=true;
                   ee[k].x=randnum(ee,8,'x');
                ee[k].y=randnum(ee,8,'y');

x=540,y=620;
                // l++;






              }

        }
        if(explosion==true)
       {
            sh.setPosition(n,r);
            sura.push_back(sh);
            h.push_back(1);
            explosion=false;

        }
        for(int d=0;d<sura.size();d++)
        {


        sura[d].setTextureRect(IntRect(h[d]*96,0,96,96));
        window.draw(sura[d]);

if(time >=0.09){
            h[d]++;
        clock1.restart();
        }



        }
        //window.draw(bship);


        if(l>0){
            //gameOverClock.restart();
            //while(gameOverClock.getElapsedTime().asMilliseconds()<1000);
            window.draw(gm);
        }
if(time4>0.09)
   {
      j++;
      clock2.restart();
   }

        window.display();
    }
    window.close();
    return 0;
}*/

