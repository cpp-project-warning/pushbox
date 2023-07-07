#ifndef _MODEL_H_
#define _MODEL_H_

#include "../COMMON/COMMON.h"

class Map;
class Player;
class Box;

class Model
{
private:
	Map map;
	Player p;
	set<Box> all_box;
	Player p_init;
	set<Box> all_box_init;

public:
	Model(int box_number, int wall[MAXN][MAXN], position destination[], position box[], position player) :
		map(box_number, wall, destination), p(player), p_init(player);
	Model(const Model&) = delete;
	Model& operator = (const Model&) = delete;
	~Model() noexcept;
	//回到初始状态
	void reset();
	//移动操作
	void move(char c);
	//判断是否成功
	bool judge();
};

#endif