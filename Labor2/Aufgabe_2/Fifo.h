#pragma once
class Fifo
{
private:
	int getWPos();
	int getRPos();
	bool isEmpty();
	bool isFull();
public:
	Fifo(int maxSize = 20);
	~Fifo();
	int push(char c);
	char pop();

private:
	int maxSize;
	int number;
	char * ptr;
	int wPos;
	int rPos;

};

