//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <sstream>
//#include "map.h"
//
//using namespace sf;
//using namespace std;
//	
//
//
//int main()
//{
//
//
//	//��������
//	Image heroimage; //������� ������ Image (�����������)
//	heroimage.loadFromFile("images/hero2.png");//��������� � ���� ����
//
//	Texture herotexture;//������� ������ Texture (��������)
//	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)
//
//	Sprite herosprite;
//	herosprite.setTexture(herotexture);
//	herosprite.setTextureRect(IntRect(0, 0, 26, 26));//�������� ������ ��� ������������� � �����
//	herosprite.setPosition(15, 15);
//
//
//	///////////////////
//
//	sf::Time t1 = sf::microseconds(10000);
//	sf::Time t2 = sf::milliseconds(10);
//	sf::Time t3 = sf::seconds(0.01f);
//
//	Clock clock; //������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).
//	float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
//	clock.restart(); //������������� �����
//	time = time / 30; //�������� ����
//	float step = 0.5 * time;
//
//	float heroteleporttimer = 0; //������� ��� ������� ������������ ����� ����� 3 �������
//	heroteleporttimer += time;//���������� � ����� ���������� time
//
//							  //if (heroteleporttimer > 3000) { herosprite.setPosition(0, 120); heroteleporttimer = 0; } //���� ��������������� ������ 3000 (��� �������� 3 �������), �� ������������� ����� � �������� ������ ������������
//
//
//
//							  //std::cout << time << "\n";//������� ��� ����� ����� (���������������, ��� �����)
//
//	Image map_image;//������ ����������� ��� �����
//	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
//	Texture map;//�������� �����
//	map.loadFromFile("images/map.png");//�������� �������� ���������
//	Sprite s_map;//������ ������ ��� �����
//	s_map.setTexture(map);//�������� �������� ��������
//
//	RenderWindow window(VideoMode(1000, 650), "BomberMan-Classic", Style::Close);
//
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				window.close();
//				return 0;
//			}
//		}
//
//		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
//		{
//			herosprite.move(-step, 0); herosprite.setTextureRect(IntRect(26, 0, 26, 26));
//		} //���������� Y, �� ������� ����� ��������� ������ ����� ����� 96
//		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
//		{
//			herosprite.move(step, 0); herosprite.setTextureRect(IntRect(80, 0, 26, 26));
//		} //���������� Y, �� ������� ����� ��������� ������ ������ ����� 96+96=192
//		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
//		{
//			herosprite.move(0, -step); herosprite.setTextureRect(IntRect(52, 0, 26, 26));
//		} //���������� Y �� ������� ����� ��������� ������ ����� ����� 288
//		if ((Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
//		{
//			herosprite.move(0, step); herosprite.setTextureRect(IntRect(0, 0, 26, 26));
//		} //���������� 0, ��� ������� ����� ����������� � ������, �� ��� � ������������� ������� ������������ �� 96. 
//
//		window.clear(Color::Blue);
//
//
//		for (int i = 0; i < HEIGHT_MAP; i++)
//			for (int j = 0; j < WIDTH_MAP; j++)
//			{
//				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 16, 16)); //���� ��������� ������ ������, �� ������ 1� ���������
//				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 16, 16));//���� ��������� ������ s, �� ������ 2� ���������
//				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(32, 0, 16, 16));//���� ��������� ������ 0, �� ������ 3� ���������
//
//
//				s_map.setPosition(j * 16, i * 16);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
//
//				window.draw(s_map);//������ ���������� �� �����
//			}
//
//		window.draw(herosprite);
//		window.display();
//	}
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////
////class Player {
////private: float x, y;
////public:
////	float w, h, dx, dy, speed;
////	int dir;
////	String File;
////	Image image;
////	Texture texture;
////	Sprite sprite;
////	Player(String F, float X, float Y, float W, float H) {
////		dx = 0; dy = 0; speed = 0; dir = 0;
////		File = F;
////		w = W; h = H;
////		image.loadFromFile("images/" + File);
////		image.createMaskFromColor(Color(41, 33, 59));
////		texture.loadFromImage(image);
////		sprite.setTexture(texture);
////		x = X; y = Y;
////		sprite.setTextureRect(IntRect(0, 0, w, h));
////	}
////	void update(float time)
////	{
////		switch (dir)
////		{
////		case 0: dx = speed; dy = 0; break;
////		case 1: dx = -speed; dy = 0; break;
////		case 2: dx = 0; dy = speed; break;
////		case 3: dx = 0; dy = -speed; break;
////		}
////
////		x += dx*time;
////		y += dy*time;
////
////		speed = 0;
////		sprite.setPosition(x, y);
////		interactionWithMap();//�������� �������, ���������� �� �������������� � ������
////	}
////
////
////	void interactionWithMap()//�-��� �������������� � ������
////	{
////
////		for (int i = y / 16; i < (y + h) / 16; i++)//���������� �� ��������, �������������� � �������,, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
////			for (int j = x / 16; j<(x + w) / 16; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
////			{
////				if (TileMap[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
////				{
////					if (dy>0)//���� �� ��� ����,
////					{
////						y = i * 16 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
////					}
////					if (dy<0)
////					{
////						y = i * 16 + 16;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
////					}
////					if (dx>0)
////					{
////						x = j * 16 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
////					}
////					if (dx < 0)
////					{
////						x = j * 16 + 16;//���������� ���� �����
////					}
////				}
////
////				if (TileMap[i][j] == 's') { //���� ������ ����� 's' (������)
////					x = 300; y = 300;//����� �� ��������... �������� ������������ �����
////					TileMap[i][j] = ' ';//������� ������, ���� ����� �����. ����� � �� �������, ������.
////				}
////			}
////	}
////
////
////	float getplayercoordinateX() {
////		return x;
////	}
////	float getplayercoordinateY() {
////		return y;
////	}
////
////};
////
////
////
////
////
////
////
////int main()
////{
////	
////	RenderWindow window(sf::VideoMode(640, 480), "Lesson 11. kychka-pc.ru");
////
////
////	
////
////	Image map_image;
////	map_image.loadFromFile("images/map.png");
////	Texture map;
////	map.loadFromImage(map_image);
////	Sprite s_map;
////	s_map.setTexture(map);
////
////
////	Player p("hero2.png", 0, 0, 26, 26);
////
////	float CurrentFrame = 0;
////	Clock clock;
////
////	while (window.isOpen())
////	{
////
////		float time = clock.getElapsedTime().asMicroseconds();
////		clock.restart();
////		time = time / 800;
////
////
////		sf::Event event;
////		while (window.pollEvent(event))
////		{
////			if (event.type == sf::Event::Closed)
////				window.close();
////		}
////
////		float coordinatePlayerX, coordinatePlayerY = 0;
////		coordinatePlayerX = p.getplayercoordinateX();
////		coordinatePlayerY = p.getplayercoordinateY();
////
////		///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
////		time = time / 30; //�������� ����
////		float step = 0.5 * time;
////
////		//if ((Keyboard::isKeyPressed(Keyboard::Left)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
////		//{ herosprite.move(-step, 0); herosprite.setTextureRect(IntRect(26, 0, 26, 26)); } //���������� Y, �� ������� ����� ��������� ������ ����� ����� 96
////		//if ((Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
////		//{ herosprite.move(step, 0); herosprite.setTextureRect(IntRect(80, 0, 26, 26)); } //���������� Y, �� ������� ����� ��������� ������ ������ ����� 96+96=192
////		//if ((Keyboard::isKeyPressed(Keyboard::Up)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
////		//{ herosprite.move(0, -step); herosprite.setTextureRect(IntRect(52, 0, 26, 26)); } //���������� Y �� ������� ����� ��������� ������ ����� ����� 288
////		//if ((Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left))) 
////		//{ herosprite.move(0, step); herosprite.setTextureRect(IntRect(0, 0, 26, 26)); } //���������� 0, ��� ������� ����� ����������� � ������, �� ��� � ������������� ������� ������������ �� 96. 
////		//	//
////		
////		//
////		if (Keyboard::isKeyPressed(Keyboard::Left)) {
////			p.dir = 1; p.speed = 0.1;
////			CurrentFrame += 0.005*time;
////			if (CurrentFrame > 3) CurrentFrame -= 3;
////			p.sprite.setTextureRect(IntRect(26, 0, 26, 26));
////		}
////
////		if (Keyboard::isKeyPressed(Keyboard::Right)) {
////			p.dir = 0; p.speed = 0.1;
////			CurrentFrame += 0.005*time;
////			if (CurrentFrame > 3) CurrentFrame -= 3;
////			p.sprite.setTextureRect(IntRect(/*96 * int(CurrentFrame), 192, 96, 96*/ 80, 0, 26, 26));
////		}
////
////		if (Keyboard::isKeyPressed(Keyboard::Up)) {
////			p.dir = 3; p.speed = 0.1;
////			CurrentFrame += 0.005*time;
////			if (CurrentFrame > 3) CurrentFrame -= 3;
////			p.sprite.setTextureRect(IntRect(52, 0, 26, 26));
////		}
////
////		if (Keyboard::isKeyPressed(Keyboard::Down)) {
////			p.dir = 2; p.speed = 0.1;
////			CurrentFrame += 0.005*time;
////			if (CurrentFrame > 3) CurrentFrame -= 3;
////			p.sprite.setTextureRect(IntRect(0, 0, 26, 26));
////		}
////		
////		p.update(time);
////
////
////
////		window.clear();
////
////		/////////////////////////////������ �����/////////////////////
////		for (int i = 0; i < HEIGHT_MAP; i++)
////			for (int j = 0; j < WIDTH_MAP; j++)
////			{
////				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 16, 16)); //���� ��������� ������ ������, �� ������ 1� ���������
////    			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 16, 16));//���� ��������� ������ s, �� ������ 2� ���������
////				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(32, 0, 16, 16));//���� ��������� ������ 0, �� ������ 3� ���������
////
////				s_map.setPosition(j * 16, i * 16);
////
////				window.draw(s_map);
////			}
////
////
////		window.draw(p.sprite);
////		window.display();
////	}
////
////	return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////
////#include <SFML/Graphics.hpp>
////
////using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
////int main()
////{
////	RenderWindow window(sf::VideoMode(640, 480), "Lesson 3. kychka-pc.ru"); //��������� ��� �������� ������ ����
////
////	Image heroimage; //������� ������ Image (�����������)
////	heroimage.loadFromFile("images/hero.png");//��������� � ���� ����
////
////	Texture herotexture;//������� ������ Texture (��������)
////	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)
////
////	Sprite herosprite;//������� ������ Sprite(������)
////	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
////	herosprite.setPosition(50, 25);//������ ��������� ���������� ��������� �������
////
////	while (window.isOpen())
////	{
////		sf::Event event;
////		while (window.pollEvent(event))
////		{
////			if (event.type == sf::Event::Closed)
////				window.close();
////		}
////
////		window.clear();
////		window.draw(herosprite);//������� ������ �� �����
////		window.display();
////	}
////
////	return 0;
////}