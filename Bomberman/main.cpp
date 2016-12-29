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
//	//Персонаж
//	Image heroimage; //создаем объект Image (изображение)
//	heroimage.loadFromFile("images/hero2.png");//загружаем в него файл
//
//	Texture herotexture;//создаем объект Texture (текстура)
//	herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)
//
//	Sprite herosprite;
//	herosprite.setTexture(herotexture);
//	herosprite.setTextureRect(IntRect(0, 0, 26, 26));//получили нужный нам прямоугольник с котом
//	herosprite.setPosition(15, 15);
//
//
//	///////////////////
//
//	sf::Time t1 = sf::microseconds(10000);
//	sf::Time t2 = sf::milliseconds(10);
//	sf::Time t3 = sf::seconds(0.01f);
//
//	Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не загруженности/мощности процессора).
//	float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
//	clock.restart(); //перезагружает время
//	time = time / 30; //скорость игры
//	float step = 0.5 * time;
//
//	float heroteleporttimer = 0; //создаем для примера телепортации героя через 3 секунды
//	heroteleporttimer += time;//прибавляем к нашей переменной time
//
//							  //if (heroteleporttimer > 3000) { herosprite.setPosition(0, 120); heroteleporttimer = 0; } //если таймертелепорта больше 3000 (это примерно 3 секунды), то телепортируем героя и обнуляем таймер телепортации
//
//
//
//							  //std::cout << time << "\n";//смотрим как живет время (перезагружается, как видим)
//
//	Image map_image;//объект изображения для карты
//	map_image.loadFromFile("images/map.png");//загружаем файл для карты
//	Texture map;//текстура карты
//	map.loadFromFile("images/map.png");//заряжаем текстуру картинкой
//	Sprite s_map;//создаём спрайт для карты
//	s_map.setTexture(map);//заливаем текстуру спрайтом
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
//		} //координата Y, на которой герой изображен идущим влево равна 96
//		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
//		{
//			herosprite.move(step, 0); herosprite.setTextureRect(IntRect(80, 0, 26, 26));
//		} //координата Y, на которой герой изображен идущем вправо равна 96+96=192
//		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
//		{
//			herosprite.move(0, -step); herosprite.setTextureRect(IntRect(52, 0, 26, 26));
//		} //координата Y на которой герой изображен идущим вверх равна 288
//		if ((Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
//		{
//			herosprite.move(0, step); herosprite.setTextureRect(IntRect(0, 0, 26, 26));
//		} //координата 0, это верхняя часть изображения с героем, от нее и отталкиваемся ровными квадратиками по 96. 
//
//		window.clear(Color::Blue);
//
//
//		for (int i = 0; i < HEIGHT_MAP; i++)
//			for (int j = 0; j < WIDTH_MAP; j++)
//			{
//				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 16, 16)); //если встретили символ пробел, то рисуем 1й квадратик
//				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 16, 16));//если встретили символ s, то рисуем 2й квадратик
//				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(32, 0, 16, 16));//если встретили символ 0, то рисуем 3й квадратик
//
//
//				s_map.setPosition(j * 16, i * 16);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
//
//				window.draw(s_map);//рисуем квадратики на экран
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
////		interactionWithMap();//вызываем функцию, отвечающую за взаимодействие с картой
////	}
////
////
////	void interactionWithMap()//ф-ция взаимодействия с картой
////	{
////
////		for (int i = y / 16; i < (y + h) / 16; i++)//проходимся по тайликам, контактирующим с игроком,, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
////			for (int j = x / 16; j<(x + w) / 16; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
////			{
////				if (TileMap[i][j] == '0')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
////				{
////					if (dy>0)//если мы шли вниз,
////					{
////						y = i * 16 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
////					}
////					if (dy<0)
////					{
////						y = i * 16 + 16;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
////					}
////					if (dx>0)
////					{
////						x = j * 16 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
////					}
////					if (dx < 0)
////					{
////						x = j * 16 + 16;//аналогично идем влево
////					}
////				}
////
////				if (TileMap[i][j] == 's') { //если символ равен 's' (камень)
////					x = 300; y = 300;//какое то действие... например телепортация героя
////					TileMap[i][j] = ' ';//убираем камень, типа взяли бонус. можем и не убирать, кстати.
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
////		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
////		time = time / 30; //скорость игры
////		float step = 0.5 * time;
////
////		//if ((Keyboard::isKeyPressed(Keyboard::Left)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
////		//{ herosprite.move(-step, 0); herosprite.setTextureRect(IntRect(26, 0, 26, 26)); } //координата Y, на которой герой изображен идущим влево равна 96
////		//if ((Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Up)))
////		//{ herosprite.move(step, 0); herosprite.setTextureRect(IntRect(80, 0, 26, 26)); } //координата Y, на которой герой изображен идущем вправо равна 96+96=192
////		//if ((Keyboard::isKeyPressed(Keyboard::Up)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
////		//{ herosprite.move(0, -step); herosprite.setTextureRect(IntRect(52, 0, 26, 26)); } //координата Y на которой герой изображен идущим вверх равна 288
////		//if ((Keyboard::isKeyPressed(Keyboard::Down)) && (!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left))) 
////		//{ herosprite.move(0, step); herosprite.setTextureRect(IntRect(0, 0, 26, 26)); } //координата 0, это верхняя часть изображения с героем, от нее и отталкиваемся ровными квадратиками по 96. 
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
////		/////////////////////////////Рисуем карту/////////////////////
////		for (int i = 0; i < HEIGHT_MAP; i++)
////			for (int j = 0; j < WIDTH_MAP; j++)
////			{
////				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 16, 16)); //если встретили символ пробел, то рисуем 1й квадратик
////    			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 16, 16));//если встретили символ s, то рисуем 2й квадратик
////				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(32, 0, 16, 16));//если встретили символ 0, то рисуем 3й квадратик
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
////using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
////int main()
////{
////	RenderWindow window(sf::VideoMode(640, 480), "Lesson 3. kychka-pc.ru"); //увеличили для удобства размер окна
////
////	Image heroimage; //создаем объект Image (изображение)
////	heroimage.loadFromFile("images/hero.png");//загружаем в него файл
////
////	Texture herotexture;//создаем объект Texture (текстура)
////	herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)
////
////	Sprite herosprite;//создаем объект Sprite(спрайт)
////	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
////	herosprite.setPosition(50, 25);//задаем начальные координаты появления спрайта
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
////		window.draw(herosprite);//выводим спрайт на экран
////		window.display();
////	}
////
////	return 0;
////}