#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

float offsetX = 0, offsetY = 0;

const int H = 17;
const int W = 863;

sf::String TileMap[H] =
{
    "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr",
"r                                                                                                                                                                                                                                                       b                                                                                                                                                                           b                                                                                                                                                                                               b                                                                                                                                                                                                                                                         r",
"r                 w                                                                                     w                                                            bbbbbbbbbbb                                                                   bbbbbbbbbbb                                           w                               w                                                                                            b                                                     bbbb                                                                                                                                   b                             w                                              w                                                                                                                                                                             r",
"r                                        w                                                                                                                           b         b                                                                   b         b                                                           k                                                                                                              b                                                  b    b                         t0                                       kkkkkk                                                         b                                                                                                   rrrrrrrrr                                                                                                                                               r",
"r                                                                                   kk                                                                               b         b                                                                   bbbbbbbbbbb                                                                                                                                               b                            b                                               b      b                        00                                                                                                     b                  k            w                  t0                          w                     r                                                                                                                                                       r",
"r                                                                                  k  k                                                                              b         b                                                                                                                                                                                                                            b b                             b                                            b        b                       00                                                                                                    b                 k                                 00                                                r                                                                                                                                                       r",
"r         w                                                                        c                                     bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb         bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb                           kkk                            bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb b          b b                 bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb          bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb                          bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb                k                bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb                     r                                                                                                                                                        r",
"r                                                                       r          k                                    b                                                                                                                                                                    b                                                        b                                                       b         b   b                                                                                                                            b                         b                                                          k                                                                                       r                                                                                                                                                       r",
"r                                             kckck                    rr          k  k                                b                                                                                                                                                                      b                                                      b                                                        b          b b                                   kk      kk                                                                                b                         b                                                        k                                                                                         r                                                                                                                                                       r",
"r                                                                     rrr           kk                                                                                                                                                        kkkkkk                                                            kkk             kkk                                                                                                                                kk                                                                                    bbbbbbbb         bbbbbbbbbb                                                      k                                                                                           r           r   r       r  r         r    r  r       r                                                                                                  r",
"r                    kckck                                           rrrr                                                                              kkkkkkkkkkkkkkkkckkkkkkkkkkkkkkkkk                                           kkkkkk                                                                                                                                                                                                                       kk  kk                                                                                                                                                                 k                                                                                             r           r   r       r  r          r   r  r       r         r                                                                                        r",
"r                                      t0                           rrrrr                                           b                                                                                                     kkkkkk                                                                 b                                                b                                                                                                                kk                                                         t0                                                                                                      k                                     kkkckkkckkkckkkckkk                                       r           r   r       r  r           r rrr rrrrrrrrr         r                                    t0                              t0                  r",
"r                                      00              t0          rrrrrr                                t0        b                                                                                             kkkkkk                                                                           b                                              b                            t0                              b                                                kk      kk                                                     00                                                                                                    k                                                                                                                                                                                                     00                              00                  r",
"r                                      00              00         rrrrrrr                                00       b                                                                                                                                                                                b                                            b                             00                              b                                                                                                               00                                                                                                  k                                                                                                                                                                                                       00                              00                  r",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",};

class PLAYER
{
    public:

    float dx,dy;
    sf::FloatRect rect;
    bool onGround;
    sf::Sprite sprite;
    float currentFrame;

    PLAYER(sf::Texture &image)
    {
        sprite.setTexture(image);
        rect = sf::FloatRect(100, 180, 16, 16);

        dx = dy = 0.1;
        currentFrame = 0;
    }

    void update(float time)
    {
        rect.left += dx * time;
        Collision(0);

        if(!onGround)
            dy = dy + 0.0005 * time;

        rect.top += dy * time;
        onGround = false;
        Collision(1);

        currentFrame += time * 0.005;
        if(currentFrame > 3)
            currentFrame -= 3;

        if(dx > 0)
            sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
        if(dx < 0)
            sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));

        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

        dx = 0;
    }

    void Collision(int num)
    {
        for(int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
            for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
                        {
                if((TileMap[i][j] == 'P') // Ground floor
                    || (TileMap[i][j] == 'k') //Sky land
                        || (TileMap[i][j] == '0') //Plumbing holes
                            || (TileMap[i][j] == 'r') //The Maze
                               || (TileMap[i][j] == 'b') // Another floor for some unknown reason
                                    || (TileMap[i][j] == 't')) //Also plumbing... again
                {
                    if(dy > 0 && num == 1)
                    {
                        rect.top = i * 16 - rect.height;
                        dy = 0;
                        onGround = true;
                    }

                    if(dy < 0 && num == 1)
                    {
                        rect.top = i * 16 + 16;
                        dy = 0;
                    }

                    if(dx > 0 && num == 0)
                    {
                        rect.left =  j * 16 -  rect.width;
                    }

                    if(dx < 0 && num == 0)
                    {
                        rect.left =  j * 16 + 16;
                    }

                }
                 if(TileMap[i][j] == 'c')
                {
                    if(dy > 0 && num == 1)
                    {
                        rect.top = i * 16 - rect.height;
                        dy = 0;
                        onGround = true;
                    }

                    if(dy < 0 && num == 1)
                    {
                        rect.top = i * 16 + 16;
                        dy = 0;
                    }

                    if(dx > 0 && num == 0)
                    {
                        rect.left =  j * 16 -  rect.width;
                    }

                    if(dx < 0 && num == 0)
                    {
                        rect.left =  j * 16 + 16;
                    }
                    printf("win");
                }

                         }

    }

};

class ENEMY
{
    public:
        float dx,dy;
        sf::FloatRect rect;
        sf::Sprite sprite;
        float currentFrame;
        bool life;

        void set(sf::Texture &image, int x, int y)
        {
            sprite.setTexture(image);
            rect = sf::FloatRect(x, y, 16, 16);

            dx = 0.05;
            currentFrame = 0;
            life = true;
        }

        void update(float time)
        {
            rect.left += dx * time;

            Collision();

            currentFrame += time * 0.005;
            if(currentFrame > 2)
                currentFrame -= 2;

            sprite.setTextureRect(sf::IntRect(18 * int(currentFrame), 0, 16, 16));

            if(!life)
                sprite.setTextureRect(sf::IntRect(58, 0, 16, 16));

            sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

        }

        void Collision()
        {
            for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
                for(int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
                    if((TileMap[i][j] == 'P') || (TileMap[i][j] == '0'))
                    {
                        if(dx > 0)
                        {
                            rect.left = j * 16 - rect.width;
                            dx *= -1;
                        }

                                                else if(dx < 0)
                        {
                            rect.left = j * 16 + 16;
                            dx *=- 1;
                        }
                    }
        }
};

int main()
{

    sf::RenderWindow window(sf::VideoMode(1280, 960), "Super Mario");

        sf::Texture tileSet;
        tileSet.loadFromFile("assets/spritesheets/Mario_Tileset.png");

        PLAYER player(tileSet);
        ENEMY  enemy, enemy2;

        enemy.set(tileSet, 48*16, 13*16);

        sf::Sprite tile(tileSet);

        sf::Clock clock;

    while(window.isOpen())
    {
		sf::Event event;
		while (window.pollEvent(event)){
            if (event.type == event.Closed){
                window.close();}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
		}

                float time = clock.getElapsedTime().asMicroseconds();
                clock.restart();

                time = time / 500;

                if(time > 20)
            time = 20;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.dx =- 0.1;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.dx = 0.1;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            if(player.onGround)
            {
                player.dy =- 0.27;
                player.onGround = false;
            }

                 player.update(time);
                 enemy.update(time);

                 if(player.rect.intersects(enemy.rect))
                 {
             if(enemy.life)
             {
                 if(player.dy > 0)
                 {
                     enemy.dx = 0;
                     player.dy =- 0.2;
                     enemy.life = false;
                 }
                 else player.sprite.setColor(sf::Color::Red);
                         }
                 }

                 if(player.rect.left > 200)
            offsetX = player.rect.left - 200;           //&#1089;&#1084;&#1077;&#1097;&#1077;&#1085;&#1080;&#1077;

                 window.clear(sf::Color(107, 140, 255));

                 for(int i = 0; i < H; i++)
                         for(int j = 0; j < W; j++)
                          {
                                if(TileMap[i][j] == 'P')
                    tile.setTextureRect(sf::IntRect(143 - 16 * 3, 112, 16, 16));

                                if(TileMap[i][j] == 'k')
                    tile.setTextureRect(sf::IntRect(143, 112, 16, 16));

                            if(TileMap[i][j] == 'c')
                    tile.setTextureRect(sf::IntRect(143 - 16, 112, 16, 16));

                                if(TileMap[i][j] == 't')
                    tile.setTextureRect(sf::IntRect(0, 47, 32, 95 - 47));

                                if(TileMap[i][j] == 'g')
                    tile.setTextureRect(sf::IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

                                if(TileMap[i][j] == 'G')
                    tile.setTextureRect(sf::IntRect(145, 222, 222 - 145, 255 - 222));

                            if(TileMap[i][j] == 'd')
                    tile.setTextureRect(sf::IntRect(0, 106, 74, 127 - 106));

                                if(TileMap[i][j] == 'w')
                    tile.setTextureRect(sf::IntRect(99, 224, 140 - 99, 255 - 224));

                                if(TileMap[i][j] == 'r')
                    tile.setTextureRect(sf::IntRect(143 - 32, 112, 16, 16));

                                if((TileMap[i][j] == ' ') || (TileMap[i][j] == '0'))
                    continue;

                            tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
                        window.draw(tile);
                     }

            window.draw(player.sprite);
            for (int i = 0; i < 30; i++){
                    enemy.set(tileSet, 220 * i + 100, 13 * 6);
                window.draw(enemy.sprite);
            }
            window.draw(enemy2.sprite);

                window.display();
    }

    return 0;
}
