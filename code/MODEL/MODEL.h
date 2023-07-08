#ifndef _MODEL_H_
#define _MODEL_H_

#include "../COMMON/COMMON.h"

class Map;
class Player;
class Box;

class Model
{
private:
	Map game_map;
	Player p;
	std::set<Box> all_box;
	Player p_init;
	syd::set<Box> all_box_init;

public:
	Model() noexcept;
	Model(const Model&) = delete;
	Model& operator = (const Model&) = delete;
	~Model() noexcept;
	Map get_game_map();
	Player get_player();
	std::set<Box> get_all_box();
	//初始化模型
	void set_model(int box_number, int wall[MAXN][MAXN], position destination[], position box[], position player);
	//回到初始状态
	void reset_model();
	//移动操作
	void move_operator(char c);
	//判断是否成功
	bool judge_if_win();
};

#endif


			