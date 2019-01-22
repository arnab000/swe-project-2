#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "collusion.h"

using namespace sf;
using namespace std;

struct enemy
{
    int x=0, y=0;
} ee[100];
struct enemybullet
{
    int x=0,y=0;
} eeb[100];
struct ass
{
    float x=0,y=0;
} ab[100];
string title(int life, int counte)
{
    string title1="  Shoot Them All             Life-Remaining :  ";
    string title2="                                                    SCORE : ";
    title1.append(to_string(life));
    title2.append(to_string(counte));
    title2.append(" ");
    title1.append(title2);
    return title1;
}

int randnum(struct enemy ee[],int t, char d)
{
    int v,q=1;
    while(1)
    {
        if(d=='x')
            v=rand()%2400+1400;
        else if(d=='y')
            v=rand()%650;
        for(q=1; q < t; q++)
        {
            if(abs(ee[q].x-v) <= 250 && d=='x'){
                break;
            }
            else if(abs(ee[q].y-v) <=70&& d=='y'){
                break;
            }
        }
        if(q==t)
            break;
    }
    return v;
}

int  main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1080,720),"  Shoot Them All");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,bossh,rin,tb,aid;
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
    bossh.loadFromFile("head_sheet.png");
    rin.loadFromFile("ring.png");
    tb.loadFromFile("textbox.png");
    aid.loadFromFile("aid.png");

    t1.setSmooth(true);
    t2.setSmooth(true);
    t3.setSmooth(true);
    t4.setSmooth(true);
    t11.setSmooth(true);
    t12.setSmooth(true);
    Sprite background(t2),bship(t1),bullet(t3),eh(t4),gm(t5),sp2(t6),sh(t7),menui(t8),eb(t9),cb(t10),boss(t11),bosshead(bossh),ring(rin),textbox(tb),aid1(aid);
    bool spacePressed=false,explosion=false,explosion1=false,menu=true,pause1=false,explosion2=false,explosion3=false,explosion4=false,bigboss=false,explosion5=false,explosion6=false,ins=false,fai=false;

    Clock clock1, clock2,gameoverclock,clock3,clock4,bossclock,bossbullet,bosslock,aidclock;
    SoundBuffer gunshot, explose;
    gunshot.loadFromFile("gunshot.wav");
    explose.loadFromFile("explosion.wav");
    Sound gun(gunshot), exp(explose);

    Font menuFont,mssgfont;
    menuFont.loadFromFile("gamefont.ttf");
    mssgfont.loadFromFile("DIEDIEDI.ttf");

    Text startText("Start Game", menuFont, 50);
    Text txt("Welcome, to your DEATH", mssgfont, 28);
    Text insText("Instruction", menuFont, 50);
    Text exitText("Exit Game", menuFont, 50);
    Text pauseText1("Resume",menuFont, 50);
    Text pauseText2("Main Menu",menuFont,50);
    Text vText("Press space to shoot", menuFont, 25);
    Text xText("Use up,down,left arrows to control your spaceship", menuFont, 25);
    Text yText("Make one hundred and fifty kills to reach Kratos", menuFont, 25);
    Text zText("Make sure to hit Kratos fifty times to end his life ", menuFont, 25);
    Text winText1("YOU WIN", menuFont, 50);
    Text winText2("WELL DONE", menuFont, 50);
    vText.setPosition(50,260);
    xText.setPosition(50,320);
    yText.setPosition(50,380);
    zText.setPosition(50,440);
    startText.setPosition(350,320);
    insText.setPosition(350,380);
    exitText.setPosition(350,440);
    pauseText1.setPosition(350,320);
    pauseText2.setPosition(350,380);
    winText1.setPosition(370,320);
    winText2.setPosition(350,380);

    startText.setFillColor(Color::White);
    exitText.setFillColor(Color::White);

    RectangleShape lifeframe,mainlife;
    lifeframe.setSize(sf::Vector2f(100, 5));
    lifeframe.setOutlineColor(sf::Color::Cyan);
    lifeframe.setOutlineThickness(1);
    lifeframe.setFillColor(Color::Transparent);

    int menuSelection=0,pauseSelection=0;
    int life=10,bosslife=50,mssg=1,z=1,ec1=1,ec2,n,gn=1,r,j=0,ex1,ex2,counte=0,hcounte=0,bul1,bul2,dada=0,he,hehe,XD,XD1,q=0,a=0,b=0,c=0,d=1,lock=0,ss1,ss2,ss3,ss4;
    float x=80,y=360,bx=1100,by=360;
    gm.setScale(1.08f,.9536f);
    aid1.setScale(.1f,.1f);
    background.setScale(1.0f,1.5f);
    sp2.setScale(1.0f,1.2f);
    bship.setOrigin(48,36);
    bullet.setOrigin(12.5,4);
    bullet.setScale(.5f,.5f);
    aid1.setPosition(-1111,-111);
    textbox.setScale(.4f,.15f);
    eb.setScale(.3f,.3f);
    cb.setScale(.3f,.3f);
    boss.setScale(0.5f,0.5f);
    bosshead.setOrigin(64,64);
    ring.setOrigin(128,128);
    bship.setScale(1.2f,1.2f);
    eh.setScale(0.15f,0.15f);
    gm.setScale(1.2f,1.0f);
    vector<Sprite>bullets;
    vector<Sprite>explosions;
    vector<Sprite>bb;
    vector<float>slope;
    vector<float>cc;
    vector<float>dir;
    vector<int>h;

    while(window.isOpen())
    {
        float time = clock1.getElapsedTime().asSeconds();
        float time4=clock2.getElapsedTime().asSeconds();
        float time6=clock4.getElapsedTime().asSeconds();
        float bosstime=bossclock.getElapsedTime().asSeconds();
        float bossbtime=bossbullet.getElapsedTime().asSeconds();
        float locktime=bosslock.getElapsedTime().asSeconds();
        float aidtime=aidclock.getElapsedTime().asSeconds();

        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyReleased)
                if(event.key.code == Keyboard::Space)
                    spacePressed=false;

        }
        if(pause1)
        {
            if(Keyboard::isKeyPressed(Keyboard::Up) && pauseSelection==1)
                pauseSelection--;
            if(Keyboard::isKeyPressed(Keyboard::Down) && pauseSelection==0)
                pauseSelection++;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && pauseSelection==0)
                pause1=false;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && pauseSelection==1){
                life=0;
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
        if(ins){
             window.draw(menui);
             window.draw(vText);
             window.draw(xText);
             window.draw(yText);
             window.draw(zText);
             window.display();
             if(Keyboard::isKeyPressed(Keyboard::Escape))
             {
                 ins=false;
                 menu=true;
             }
        }
        if(menu && !pause1){
            if(Keyboard::isKeyPressed(Keyboard::Down) && menuSelection==0){
                menuSelection=1;
                sleep(milliseconds(200));
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down)&& menuSelection==1){
                menuSelection=2;
                sleep(milliseconds(200));
            }
            else if(Keyboard::isKeyPressed(Keyboard::Up) && menuSelection==2){
                menuSelection=1;
                sleep(milliseconds(200));
            }
            else if(Keyboard::isKeyPressed(Keyboard::Up) && menuSelection==1){
                menuSelection=0;
                sleep(milliseconds(200));
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && menuSelection==0){
                menu=false;
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && menuSelection==2)
                window.close();
              if(Keyboard::isKeyPressed(Keyboard::Enter) && menuSelection==1){
              menu=false;
              ins=true;
              }

            if(menuSelection==0){
                startText.setFillColor(Color::White);
                exitText.setFillColor(Color::Black);
                insText.setFillColor(Color::Black);
            }
            else if(menuSelection==2){
                exitText.setFillColor(Color::White);
                startText.setFillColor(Color::Black);
                insText.setFillColor(Color::Black);
            }
            else if(menuSelection==1){
                exitText.setFillColor(Color::Black);
                startText.setFillColor(Color::Black);
                insText.setFillColor(Color::White);
            }

            window.clear();
            window.setTitle("  Shoot Them All");
            window.draw(menui);
            window.draw(startText);
            window.draw(insText);
            window.draw(exitText);
            window.display();
        }
        if(life==0){
            window.clear();
            bigboss=false;
            life=10,bosslife=50,z=1,ec1=1,ec2,n,r,j=0,ex1,ex2,bul1,bul2,dada=0,he,hehe,XD,XD1,q=0,a=0,b=0,c=0,d=1,lock=0,ss1,ss2,ss3,ss4,mssg=1;
            x=80,y=360,bx=1100,by=360,gn=1;
            h.clear();
            bb.clear();
            bullets.clear();
            explosions.clear();
            cc.clear();
            dir.clear();
            slope.clear();
            aid1.setPosition(-1111,-111);
            menuSelection=0,pauseSelection=0;
            window.setTitle(title(life,counte));
            spacePressed=false,explosion=false,explosion1=false,menu=true,pause1=false,explosion2=false,explosion3=false,explosion4=false,bigboss=false,explosion5=false,explosion6=false;
            if(counte > hcounte)
                hcounte=counte;
            counte=0;
            if(fai==false){
            window.draw(gm);

            window.display();
            sleep(milliseconds(300));
            }
             else if (fai==true)
                fai=false;
        }
        if(menu==false && pause1==false && life > 0 && !ins){
            if(Keyboard::isKeyPressed(Keyboard::Up) && y >=80 )
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
                bullet.setPosition(x,y);
                bullets.push_back(bullet);
                if(gn)
                   gun.play();
            }
            if(z <-799)
                z=-1;
            z--;
            if(j>=3)
                j=0;
            if(dada>=8)
                dada=0;
            if(q>=5)
                q=0;

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
            if(bigboss==false){
                for(; ec1 < 7; ec1++){
                    ee[ec1].x=randnum(ee,ec1,'x');
                    ee[ec1].y=randnum(ee,ec1,'y');
                    eeb[ec1].x=ee[ec1].x;
                    eeb[ec1].y=ee[ec1].y;
                    ab[ec1].x=ee[ec1].x+220;
                    ab[ec1].y=ee[ec1].y;
                }
                for(ec2=1; ec2 < 7 ; ec2++){
                    ee[ec2].x-=5;
                    ab[ec2].x-=5;
                    if(eeb[ec2].x>1000 || ee[ec2].x<-20)
                        eeb[ec2].x-=5;
                    else
                        eeb[ec2].x-=15;
                    if(ee[ec2].x<-400){
                        ee[ec2].x=randnum(ee,7,'x');
                        ee[ec2].y=randnum(ee,7,'y');
                        eeb[ec2].x=ee[ec2].x;
                        eeb[ec2].y=ee[ec2].y;
                    }
                    if(eeb[ec2].x<-90){
                        eeb[ec2].x=ee[ec2].x;
                        eeb[ec2].y=ee[ec2].y;
                    }
                    if(ab[ec2].x<-300){
                        ab[ec2].x=ee[ec2].x+220;
                        ab[ec2].y=ee[ec2].y;
                    }
                }
                window.draw(aid1);
                 if(Collision::PixelPerfectTest(aid1,bship)){
                        if(life<10)
                            life++;
                        aid1.setPosition(-1111,111);

                    }
                    if(aidtime>3)
                    {
                            aid1.setPosition(-1111,111);
                    }
                for(int k=1; k < 7; k++){
                    eh.setPosition(ee[k].x,ee[k].y);
                    eb.setPosition(eeb[k].x-10,eeb[k].y+30);
                    cb.setPosition(eeb[k].x-10,eeb[k].y+41);
                    window.draw(eh);
                    window.draw(eb);
                    window.draw(cb);
                    boss.setPosition(ab[k].x,ab[k].y+0);
                    window.draw(boss);

                    for(int i=0; i<bullets.size(); i++){
                        window.draw(bullets[i]);
                        bullets[i].move(Vector2f(2,0));
                        auto b = bullets[i].getPosition();
                        if(b.x > 1080 )
                            bullets.erase(bullets.begin()+i);
                        if(Collision::PixelPerfectTest(eh,bullets[i])){
                            counte++;
                            n=ee[k].x;
                            r=ee[k].y;
                            explosion=true;
                            exp.play();
                            bullets.erase(bullets.begin()+i);
                            ee[k].x=randnum(ee,7,'x');
                            ee[k].y=randnum(ee,7,'y');
                             if(counte%10==0){
                              aid1.setPosition(n,r);
                               aidclock.restart();
                             }


                        }

                        else if(Collision::PixelPerfectTest(boss,bullets[i]) ){
                            counte++;
                            he=ab[k].x;
                            hehe=ab[k].y;
                            explosion4=true;
                            exp.play();
                            bullets.erase(bullets.begin()+i);
                            ab[k].x=ee[k].x+220;
                            ab[k].y=ee[k].y;
                            if(counte%10==0){
                              aid1.setPosition(he,hehe);
                              aidclock.restart();
                            }


                        }
                    }
                    if(Collision::PixelPerfectTest(eb,bship)||Collision::PixelPerfectTest(cb,bship)){
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
                        ee[k].x=randnum(ee,7,'x');
                        ee[k].y=randnum(ee,7,'y');
                        x=80,y=360;
                    }
                    if(Collision::PixelPerfectTest(boss,bship) ){
                        life--;
                        XD=ab[k].x;
                        XD1=ab[k].y;
                        explosion3=true;
                        exp.play();
                        ab[k].x=ee[k].x+220;
                        ab[k].y=-1111;
                        x=80,y=360;
                    }
                }
            }
        else if(bigboss==true){
            if(mssg==1){
                    gn=0;
                    window.clear(Color::Black);
                    bosshead.setPosition(bx,360);
                    bosshead.setTextureRect(IntRect(0,q*128,128,128));
                    window.draw(bosshead);
                    x=80,y=360;
                    bship.setPosition(x,y);
                    window.draw(bship);
                    bx--;
                    if(bx == 800){
                       textbox.setPosition(720,230);
                       window.draw(textbox);
                       window.draw(mainlife);
                       window.draw(lifeframe);
                       sleep(milliseconds(200));
                       txt.setPosition(730,260);
                       window.draw(txt);
                       window.display();
                       mssg=0;
                       bx=952;
                       sleep(milliseconds(3000));
                       gn=1;
                       bullets.clear();
                    }
                }
            else if(mssg==0){
                for(int i=0; i< bullets.size(); i++){
                    window.draw(bullets[i]);
                    bullets[i].move(Vector2f(10,0));
                    auto b = bullets[i].getPosition();
                    if(b.x >1080 )
                        bullets.erase(bullets.begin()+i);
                    if(Collision::PixelPerfectTest(bosshead,bullets[i]) ){
                        counte++;
                        ss1=bx-50;
                        ss2=by-50;
                        explosion5=true;
                        exp.play();
                        bullets.erase(bullets.begin()+i);
                        bosslife--;
                        if(bosslife == 0){
                             window.draw(menui);
                             window.draw(winText1);
                             window.draw(winText2);
                             window.display();
                             if(counte > hcounte)
                                 hcounte=counte;
                             counte=0;
                             sleep(milliseconds(2000));
                             life=0;
                             menu=true;
                             fai=true;
                        }
                    }
                    if(Collision::PixelPerfectTest(ring,bullets[i]) ){
                        bullets.erase(bullets.begin()+i);
                    }
                }
                    if(d == 1 && c == 0){
                        by++;
                        if(by == 592)
                            c++;
                    }
                    else if(c == 1 && d == 1){
                        by--;
                        if(by == 360)
                            d++;
                    }
                    else if(d == 2 && b == 0){
                        by--;
                        if(by == 128)
                            b++;
                    }
                    else if(b == 1 && d == 2){
                        by++;
                        if(by == 360)
                            d++;
                    }
                    else if(d == 3 && a == 0){
                        bx--;
                        if(bx == 700)
                            a++;
                    }
                    else if(a == 1 && c == 1){
                        bx++;
                        by=(((592.0-360.0)/(952.0-700.0))*bx)+(360.0-(((592.0-360.0)/(952.0-700.0))*700.0));
                        if(bx == 952)
                            c++;
                    }
                    else if(c == 2 && a == 1){
                        bx--;
                        by=(((592.0-360.0)/(952.0-700.0))*bx)+(360.0-(((592.0-360.0)/(952.0-700.0))*700.0));
                        if(bx == 700)
                            a++;
                    }
                    else if(a == 2 && b == 1){
                        bx++;
                        by=(((128.0-360.0)/(952.0-700.0))*bx)+(360.0-(((128.0-360.0)/(952.0-700.0))*700.0));
                        if(bx == 952)
                            b++;
                    }
                    else if(b == 2 && a == 2){
                        bx--;
                        by=(((128.0-360.0)/(952.0-700.0))*bx)+(360.0-(((128.0-360.0)/(952.0-700.0))*700.0));
                        if(bx == 700)
                            a++;
                    }
                    else if(a == 3 && d == 3){
                        bx++;
                        if(bx == 952)
                            d=1,a=0,b=0,c=0;
                    }
                    bosshead.setPosition(bx,by);
                    if(lock == 0){
                        ring.setPosition(bx,by);
                        window.draw(ring);
                    }
                    else if(lock==1){
                        ring.setPosition(-1111,-1111);
                        window.draw(ring);
                    }
                    RectangleShape blifeframe,bmainlife;
                    blifeframe.setSize(sf::Vector2f(150, 8));
                    blifeframe.setOutlineColor(sf::Color::Cyan);
                    blifeframe.setOutlineThickness(1);
                    blifeframe.setPosition(bx-73, by-75);
                    blifeframe.setFillColor(Color::Transparent);
                    bmainlife.setPosition(bx-73, by-75);
                    bmainlife.setSize(sf::Vector2f(bosslife*3, 8));
                    if(bosslife <= 50 && bosslife >= 30)
                          bmainlife.setFillColor(Color::Green);
                    else if(bosslife >= 15 && bosslife < 30)
                          bmainlife.setFillColor(Color::Yellow);
                     else if(bosslife >= 0 && bosslife < 16)
                          bmainlife.setFillColor(Color::Red);
                     window.draw(bmainlife);
                     window.draw(blifeframe);
                    bosshead.setTextureRect(IntRect(0,q*128,128,128));
                    window.draw(bosshead);
                    for(int p=0; p< bb.size(); p++){
                        window.draw(bb[p]);
                        auto ggg = bb[p].getPosition();
                        if(abs(slope[p]) > 2.3){
                            if(dir[p] < 0)
                                ggg.x+=dir[p]+3.5;
                            else
                                ggg.x+=dir[p]-3.5;
                        }
                        else
                            ggg.x+=dir[p];

                        bb[p].setPosition(ggg.x,(slope[p]*ggg.x)+cc[p]);
                        if(ggg.x < -80){
                            bb.erase(bb.begin()+p);
                            slope.erase(slope.begin()+p);
                            cc.erase(cc.begin()+p);
                            dir.erase(dir.begin()+p);
                        }
                        if(Collision::PixelPerfectTest(bship,bb[p])){
                            life--;
                            ss3 =x;
                            ss4=y;
                            bb.erase(bb.begin()+p);
                            slope.erase(slope.begin()+p);
                            cc.erase(cc.begin()+p);
                            dir.erase(dir.begin()+p);
                            explosion6=true;
                            exp.play();
                            x=80,y=360;
                        }
                    }

                    if(bossbtime > .3){
                        eb.setPosition(bx,by);
                        bb.push_back(eb);
                        slope.push_back((by-y)/(bx-x));
                        cc.push_back(y-(((by-y)/(bx-x))*x));
                        if(bx-x < 0)
                            dir.push_back(5);
                        else
                            dir.push_back(-5);
                        bossbullet.restart();
                    }
               }

            }


            lifeframe.setPosition(x-35, y-65);
            mainlife.setPosition(x-35, y-65);
            mainlife.setSize(sf::Vector2f(life*10, 5));
            if(life <= 10 && life >= 8)
                 mainlife.setFillColor(Color::Green);
            else if(life >= 5 && life <= 7)
                 mainlife.setFillColor(Color::Yellow);
            else if(life >= 0 && life < 5)
                 mainlife.setFillColor(Color::Red);
            window.draw(mainlife);
            window.draw(lifeframe);
            bship.setTextureRect(IntRect(j*96,106*2,96,72));
            window.draw(bship);
            if(explosion6==true){
                sh.setPosition(ss3,ss4);
                explosions.push_back(sh);
                h.push_back(1);
                explosion6=false;
            }
            if(explosion5==true){
                sh.setPosition(ss1,ss2);
                explosions.push_back(sh);
                h.push_back(1);
                explosion5=false;
            }
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
           for(int u=0; u<explosions.size(); u++){
                explosions[u].setTextureRect(IntRect(h[u]*96,0,96,96));
                window.draw(explosions[u]);
                if(time >=0.085 && h[u]<13){
                    h[u]++;
                    clock1.restart();
                }
                if(h[u]<=13 && life==0){
                    h[u]=14;
                }
            }
            if(counte>=20){
                bigboss=true;
                ec1=1,z=1;
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
            if(bosstime > .25){
                q++;
                bossclock.restart();
            }
            if(locktime > 3){
                if(lock == 0)
                   lock=1;
                else
                   lock=0;
                bosslock.restart();
            }
            window.display();
        }
    }
    printf("Your Highest Score Is : %d",hcounte);
    window.close();
    return 0;
}
