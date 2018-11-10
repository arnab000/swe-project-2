#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "Collision.cpp"

using namespace sf;
using namespace std;

struct enemy{
    int x=0, y=0;
} ee[100];


int randnum(struct enemy ee[],int t, char d){
    int v,q=1;
    while(1){
        if(d=='x')
            v=rand()%1200+1080;
        else if(d=='y')
            v=rand()%600;
        for(q=1; q < t; q++){
            if(abs(ee[q].x-v) <= 110.25 && d=='x'){
                break;
            }
            else if(abs(ee[q].y-v) <= 58.1 && d=='y'){
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
    RenderWindow window(VideoMode(1080,720),"Shoot Them All");

    window.setVerticalSyncEnabled(true);
    Texture t1,t2,t3,t4,t5,t6,t7,t8;
    t1.loadFromFile("bgod.png");
    t2.loadFromFile("farback.gif");
    t3.loadFromFile("shot.png");
    t4.loadFromFile("ene.png");
    t5.loadFromFile("203768600.jpg");
    t6.loadFromFile("starfield.png");
    t7.loadFromFile("Explosion.png");
    t8.loadFromFile("Red Space.bmp");

    t1.setSmooth(true);
    t2.setSmooth(true);
    t3.setSmooth(true);
    t4.setSmooth(true);
    Sprite background(t2),bship(t1),bullet(t3),eh(t4),gm(t5),sp2(t6),sh(t7),menui(t8);
    bool isfire=false, spacePressed=false,explosion=false,explosion1=false,menu=true,pause1=false;

    Clock clock1, clock2,gameoverclock,clock3;
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
    int x=80,y=360,life=4,z=1,ec1=1,ec2,n,r,j=0,ex1,ex2,counte=0;
    gm.setScale(1.08f,.9536f);
    background.setScale(1.0f,1.5f);
    sp2.setScale(1.0f,1.2f);
    bship.setOrigin(48,36);
    bullet.setOrigin(12.5,4);
    bullet.setScale(.7f,.7f);
    bship.setScale(1.6f,1.6f);
    eh.setScale(0.2f,0.2f);
    gm.setScale(1.2f,1.0f);

    while(window.isOpen()){
        float time = clock1.getElapsedTime().asSeconds();
        float time4=clock2.getElapsedTime().asSeconds();

        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyReleased)
                if(event.key.code == Keyboard::Space)
                    spacePressed=false;
        }
        if(!life){
            float gameover=gameoverclock.getElapsedTime().asSeconds();
            window.clear();
            string title1="Shoot Them All!!              Life-Remaining :  ";
            string title2="                                                    SCORE : ";
            title1.append(to_string(life));
            title2.append(to_string(counte));
            title2.append(" ");
            title1.append(title2);
            window.setTitle(title1);
            window.draw(gm);
            window.display();
            if(gameover >= 10){
                 gameoverclock.restart();
                 menu=true;
                 pause1=false;
                 life=4;
            }
        }

        if(pause1){
            if(Keyboard::isKeyPressed(Keyboard::Up) && pauseSelection==1)
                pauseSelection--;
            if(Keyboard::isKeyPressed(Keyboard::Down) && pauseSelection==0)
                pauseSelection++;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && pauseSelection==0)
                pause1=false;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && pauseSelection==1){
                sleep(milliseconds(100));
                menu=true;
                pause1=false;
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
            if(Keyboard::isKeyPressed(Keyboard::Enter) && menuSelection==0)
                menu=false;
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
            if (Keyboard::isKeyPressed(Keyboard::Right) && x<=960)
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

            window.clear();

            bship.setPosition(x,y);
            window.draw(background);
            sp2.setPosition(z,0);
            window.draw(sp2);
            sp2.setPosition(z+800,0);
            window.draw(sp2);
            sp2.setPosition(z+1600,0);
            window.draw(sp2);
            string title1="Shoot Them All!!              Life-Remaining :  ";
            string title2="                                                    SCORE : ";
            title1.append(to_string(life));
            title2.append(to_string(counte));
            title2.append(" ");
            title1.append(title2);
            window.setTitle(title1);

            for(; ec1 < 8; ec1++){
                ee[ec1].x=randnum(ee,ec1,'x');
                ee[ec1].y=randnum(ee,ec1,'y');
            }
            for(ec2=1; ec2 <8; ec2++){
                ee[ec2].x-=3;
                if(ee[ec2].x<-29){
                    ee[ec2].x=randnum(ee,8,'x');
                    ee[ec2].y=randnum(ee,8,'y');
                }
            }
            for(int k=1; k < 8; k++){
                eh.setPosition(ee[k].x,ee[k].y);
                window.draw(eh);
                if(isfire==true){
                    bullet.setPosition(x,y);
                    bullets.push_back(bullet);
                    isfire=false;
                }
                for(int i=0; i<bullets.size(); i++){
                    window.draw(bullets[i]);
                    bullets[i].move(Vector2f(2,-0));
                    auto b = bullets[i].getPosition();
                    if(b.x >1080)
                        bullets.erase(bullets.begin()+i);
                    if(Collision::PixelPerfectTest(eh,bullets[i])){
                        counte++;
                        n=ee[k].x;
                        r=ee[k].y;
                        explosion=true;
                        exp.play();
                        bullets.erase(bullets.begin()+i);
                        ee[k].x=randnum(ee,8,'x');
                        ee[k].y=randnum(ee,8,'y');
                    }
                }
                if(Collision::PixelPerfectTest(eh,bship)){
                    life--;
                    counte=0;
                    ex1=ee[k].x;
                    ex2=ee[k].y;
                    explosion1=true;
                    exp.play();
                    ee[k].x=randnum(ee,8,'x');
                    ee[k].y=randnum(ee,8,'y');
                    x=80,y=360;
                }

            }
            bship.setPosition(x,y);
            bship.setTextureRect(IntRect(j*96,106*2,96,72));
            window.draw(bship);
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
            for(int d=0; d<explosions.size(); d++){
                explosions[d].setTextureRect(IntRect(h[d]*96,0,96,96));
                window.draw(explosions[d]);
                if(time >=0.085 && h[d]<13){
                    h[d]++;
                    clock1.restart();
                }
            }

            if(time4>0.09){
                j++;
                clock2.restart();
            }
            window.display();
        }
    }
    window.close();
  //  printf("Your Score Is : ",counte);
    return 0;
}
