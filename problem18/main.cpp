#include <cstdio>

/*
const unsigned int length = 4;
unsigned int data[][length] = 
{
	{3, 4, 6, 3},
	{7, 4, 9, 0},
	{2, 5, 0, 0},
	{8, 0, 0, 0}
};
*/

const unsigned int length = 15;
unsigned int data[][length] =
{
	{75, 64, 82, 10, 65, 34, 67, 92, 33, 29, 14, 57, 48, 31, 23},
	{95, 47, 87, 47,  3, 63, 70, 70, 94, 51, 17, 29, 40,  4,  0},
	{17, 35, 82, 75,  7, 16, 80, 16, 97, 68, 27, 87, 60,  0,  0},
	{18,  4, 23, 73,  6, 40, 37, 52, 39, 50, 69, 53,  0,  0,  0},
	{20,  1, 77, 28, 83, 32, 91, 78, 58, 16, 38,  0,  0,  0,  0},
	{19,  2,  4, 56, 47, 43, 17, 43, 73, 93,  0,  0,  0,  0,  0},
	{88, 65, 26, 33, 25, 73, 91, 30, 73,  0,  0,  0,  0,  0,  0},
	{99, 41, 72, 65, 77, 14, 67, 98,  0,  0,  0,  0,  0,  0,  0},
	{41, 48, 44, 28, 17, 53, 70,  0,  0,  0,  0,  0,  0,  0,  0},
	{41, 71, 33, 38, 89,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{53, 11, 52, 68, 23,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{70, 71,  4, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{91, 66, 98,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{63, 62,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{ 4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
};

unsigned int max_score = 0;

void MaxPath(unsigned int x, unsigned int y, unsigned int score)
{
	unsigned int new_score = score + data[x][y];
	if (x == length - 1 ||
		y == length - 1 ||
		(data[x + 1] == 0 && data[y + 1] == 0))
	{
		max_score = max_score > new_score ? max_score : new_score;
		return;
	}
	
	MaxPath(x + 1, y, new_score);
	MaxPath(x, y + 1, new_score);
}

int main(int argc, char* argv[])
{
	MaxPath(0, 0, 0);
	printf("%u\n", max_score);
}
