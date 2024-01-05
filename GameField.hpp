#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

const int width = 119;
const int height = 29;

class GameField {
private:
	char field[height][width];
public:
	void print();
	void Init();
};

#endif // GAMEFIELD_HPP