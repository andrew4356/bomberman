#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "map.h"

using namespace sf;
using namespace std;


class Player {
private: float x, y;
public:
	float w, h, dx, dy, speed;
	int dir;
	bool onGround;
	String File;
	Image heroimage;
	Texture texture;
	Sprite herosprite;
	Player(float X, float Y, float W, float H) {
		dx = 0; dy = 0; speed = 0; dir = 0;
		w = W; h= H;
		heroimage.loadFromFile("images/hero2.png");
		texture.loadFromImage(heroimage);
		herosprite.setTexture(texture);
		x = X; y = Y;
		herosprite.setTextureRect(IntRect(0, 0, w, h));
	}


	void update(float time) 
	{
		switch (dir)
		{
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = speed; break;
			case 3: dx = 0; dy = -speed; break;
			case 4: dx = 0; dy = 0; break;
		}

		x += dx*time;
		checkCollisionWithMap(dx, 0); 
		y += dy*time;
		checkCollisionWithMap(0, dy); 


		speed = 0; 
		herosprite.setPosition(x, y); 
	}
	float getplayercoordinateX() {
		return x;
	}
	float getplayercoordinateY() {
		return y;
	}

	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = y / 34; i < (y + h) / 34; i++) 
			for (int j = x / 34; j<(x + w) / 34; j++)
			{
				if (TileMap[i][j] == '0') 
				{
					
					if (Dy>0) { y = i * 34 - h;  dy = 0; } 
					if (Dy<0) { y = i * 34 + 34;  dy = 0; } 
					if (Dx>0) { x = j * 34 - w; } 
					if (Dx<0) { x = j * 34 + 34; } 
				}
				if (TileMap[i][j] == 's') 
				{

					if (Dy>0) { y = i * 34 - h;  dy = 0; } 
					if (Dy<0) { y = i * 34 + 34;  dy = 0; }
					if (Dx>0) { x = j * 34 - w; } 
					if (Dx<0) { x = j * 34 + 34; } 
				}
			}

		
	}
};







int main()
{
	
	RenderWindow window(VideoMode(1050, 375), "BomberMan-Classic", Style::Close);

	

	Image map_image;
	map_image.loadFromFile("images/map4.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);


	Player p(34, 34, 26, 26);

	float CurrentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float coordinatePlayerX, coordinatePlayerY = 0;
		coordinatePlayerX = p.getplayercoordinateX();
		coordinatePlayerY = p.getplayercoordinateY();

		
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.herosprite.setTextureRect(IntRect(26, 0, 26, 26));
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 0; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.herosprite.setTextureRect(IntRect(/*96 * int(CurrentFrame), 192, 96, 96*/ 80 , 0, 26, 26));
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p.dir = 3; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.herosprite.setTextureRect(IntRect(52, 0, 26, 26));
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			p.dir = 2; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.herosprite.setTextureRect(IntRect(0, 0, 26, 26));
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			p.dir = 4; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.herosprite.setTextureRect(IntRect(0, 0, 26, 26));
		}

		//getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		p.update(time);

window.clear(Color::Blue);

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 34, 34));  
    			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(68, 0, 34, 34)); 
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(68, 0, 34, 34)); 

				s_map.setPosition(j * 34, i * 34);

				window.draw(s_map);
			}


		window.draw(p.herosprite);
		window.display();
	}

	return 0;
}