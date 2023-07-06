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
	int wall[MAXN][MAXN];
	set<position> destination;
	Player p;
	Box all_box[];

public:
	Map() noexcept;
	Map(const Map&) = delete;
	Map& operator = (const Map&) = delete;
	Map(position wall[], position all_box[], position destination[], position player) noexcept;
	~Map() noexcept;
	void move() throw(int);
	void judge() throw(int);
};

class Player
{
private:
	shared_ptr<position> p;

public:
	shared_ptr<position> get_position() const noexcept;
	Player(position pp) : p.x(pp.x), p.y(pp.y);
}

class Box
{
private:
	shared_ptr<position> box;

public:
	shared_ptr<position> get_position() const noexcept;
	Box(position b) : box.x(b.x), box.y(b.y);
}
#endif