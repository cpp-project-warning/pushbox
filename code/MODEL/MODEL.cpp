#include "MODEL.h"

Model::Model(int box_number, int wall[MAXN][MAXN], position destination[], position box[], position player) :
	map(box_number, wall, destination), p(player), p_init(player)
{
	for(auto a : box)
	{
		Box temp(a);
		all_box.insert(temp);
	}
	all_box_init = all_box;
}

Model::~Model() noexcept
{

}

void Model::reset()
{
	p.set_position(p_init.get_position());
	all_box = all_box_init;
}

void Model::move(char c)
{
	p.move(c);
}

bool Model::judge()
{
	set<position> boxes_position;
	for(auto a : all_box)
	{
		boxes_position.insert(a.get_position());
	}
	if(map.get_destination() == boxes_position)
	{
		return true;
	}
	else
	{
		return false;
	}
}
