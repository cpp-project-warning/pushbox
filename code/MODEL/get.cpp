#include "../COMMON/push_box_base.h"

int get_box_number()
{
	string datapath = "./Game" + map_count + "/box_number.txt";
	ifstream file;
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
	string datapath = "./Game" + map_count + "/wall.txt";
	ifstream file;
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
	string datapath = "./Game" + map_count + "/destination.txt";
	ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
		position *destination = 0;
		destination = new int[MAXN];
		for (int i = 0; i < box_number; i++)
		{
			int xx;
			int yy;
			position p;
			file >> xx >> yy;
			p.x = xx;
			p.y = yy;
			position[i] = p;
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
	string datapath = "./Game" + map_count + "/box.txt";
	ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
		position *box = 0;
		box = new int[MAXN];
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
	string datapath = "./Game" + map_count + "/player.txt";
	ifstream file;
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