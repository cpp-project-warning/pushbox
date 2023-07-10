#include "../COMMON/push_box_base.h"
#include "../COMMON/COMMON.h"

int get_box_number()
{
	std::string datapath = "./Game" + std::to_string(current_map_count) + "/box_number.txt";
	std::ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
		int t;
		file >> t;
		return t;
	}
	else
	{
		return -1;
	}
}

int** get_wall()
{
	std::string datapath = "./Game" + std::to_string(current_map_count) + "/wall.txt";
	std::ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
		int **wall = 0;
		wall = new int *[MAXN];
		for (int i = 0; i < MAXN; i++)
		{
			*(wall + i) = new int[MAXN];
		}
		for (int i = 0; i < MAXN; i++)
		{
			for (int j = 0; j < MAXN; j++)
			{
				int t;
				file >> t;
				wall[i][j] = t;
			}
		}
		return wall;
	}
	else
	{
		return NULL;
	}
}

position* get_destination(int box_number)
{
	std::string datapath = "./Game" + std::to_string(current_map_count) + "/destination.txt";
	std::ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
		position *destination = 0;
		destination = new position[MAXN];
		for (int i = 0; i < box_number; i++)
		{
			int xx;
			int yy;
			position p;
			file >> xx >> yy;
			p.x = xx;
			p.y = yy;
			destination[i] = p;
		}
		return destination;
	}
	else
	{
		return NULL;
	}
}

position* get_box(int box_number)
{
	std::string datapath = "./Game" + std::to_string(current_map_count) + "/box.txt";
	std::ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
		position *box = 0;
		box = new position[MAXN];
		for (int i = 0; i < box_number; i++)
		{
			int xx;
			int yy;
			position p;
			file >> xx >> yy;
			p.x = xx;
			p.y = yy;
			box[i] = p;
		}
		return box;
	}
	else
	{
		return NULL;
	}
}

position get_player()
{
	std::string datapath = "./Game" + std::to_string(current_map_count) + "/player.txt";
	std::ifstream file;
	file.open(datapath);
	position p;
	p.x = -1;
	p.y = -1;
	if(file.is_open())
	{
		int xx;
		int yy;		
		file >> xx >> yy;
		p.x = xx;
		p.y = yy;
	}
	return p;
}