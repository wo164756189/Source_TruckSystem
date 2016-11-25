#pragma once

#include <QString>

enum state
{
	running=1,
	stopping
};

enum instruction
{

};

class Risk
{
	int RFID;
	int truckID;
	int errorType;
};

class SieTruck
{
public:
	SieTruck();
	~SieTruck();
private:
	int truckID;
	QString driverName;
	float speed;
	float position_x;    // position of truck
	float position_y;
	bool ladle;          // if ladle is loaded on the truck
	bool steel;          // there is steel(liquid) in the ladle
	enum state truckState;
	int depatureID;
	int destinationID;
	int routeID;
	Risk risk;
	enum instruction Ins;
};

