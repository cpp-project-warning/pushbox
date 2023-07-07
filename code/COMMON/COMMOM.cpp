#include "COMMON.h"

Map::Map() noexcept
{

}

Map::Map(int bn, int w[MAXN][MAXN], position des[]) noexcept
{
	box_number = bn;
	for(int i = 0; i < MAXN; i++)
	{
		for(int j = 0; j < MAXN; j++)
		{
			if(w[i][j] == 1)
			{
				wall[i][j] = 1;
			}
			else
			{
				wall[i][j] = 0;
			}
		}
	}
	for(auto a : des)
	{
		destination.insert(a);
	}
}

Map::~Map() noexcept
{

}

set<position> Map::get_destination()
{
	return destination;
}

bool if_wall(int x, int y)
{
	if(wall[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Player::Player(position p) : player.x(p.x), player.y(p.y)
{

}

position Player::get_position() const noexcept
{
	return player;
}

void Player::set_position(position p)
{
	player = p;
}

void Player::move(char c)
{
	cout << c << endl;
}

Box::Box(position b) : box.x(b.x), box.y(b.y)
{

}

position Box::get_position() const noexcept
{
	return box;
}

void Box::set_position(position p)
{
	box = p;
}

bool Box::check_around(char c, Map map) throw(int)
{
	bool ans;
	if(c == 'a')
	{
		ans = map.if_wall(box.x-1, box.y);
	}
	else if(c == 'w')
	{
		ans = map.if_wall(box.x, box.y+1);
	}
	else if(c == 's')
	{
		ans = map.if_wall(box.x, box.y-1);
	}
	else if(c == 'd')
	{
		ans = map.if_wall(box.x+1, box.y);
	}
	else
	{
		throw(1);
	}
	return ans;
}

void Box::move(char c, Map map)
{
	cout << c << endl;
}