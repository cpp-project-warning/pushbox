#include "push_box_base.h"

#ifndef _MAP_H_
#define _MAP_H_

#define MAXN 20

struct position
{
	int x;
	int y;
};

class Map
{
private:
	int box_number;
	//1表示有墙，0表示没有
	int wall[MAXN][MAXN];
	set<position> destination;

public:
	Map() noexcept;
	Map(const Map&) = delete;
	Map& operator = (const Map&) = delete;
	Map(int bn, int w[MAXN][MAXN], position des[]) noexcept;
	~Map() noexcept;
	set<position> get_destination();
	bool if_wall(int x, int y);
};

class Player
{
private:
	position player;

public:
	Player(position p) : player.x(p.x), player.y(p.y);
	position get_position() const noexcept;
	void set_position(position p);
	//传入移动方向，判断能否进行移动（对应方向有墙不行，或有箱子且箱子后面还有东西不想）
				void move(char c);
};

class Box
{
private:
	position box;

public:
	Box(position b) : box.x(b.x), box.y(b.y);
	position get_position() const noexcept;
	void set_position(position p);
	//对应方向有墙返回1，没有返回0
	bool check_around(char c) throw(int);
	//'n'不移动，其他情况朝对应方向移动
				void move(char c, Map map);
};

#endif