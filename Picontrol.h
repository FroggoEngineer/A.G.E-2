#include <SFML/Network.hpp>
#include <thread>

#ifndef PICONTROL_H
#define PICONTROL_H




class Picontrol {

public:

	Picontrol();
	~Picontrol() = default;

	void start(); //Connects to the controller and starts the update on seperate thread to receive data
	void stop();  //Stops the thread and disconnects from the controller

	float getX() { return accX; };
	float getY() { return accY; };
	float getZ() { return accZ; };

	float getFixedX() { return fixedX; };
	float getFixedY() { return fixedY; };

	float getPitch() { return pitch; };
	float getRoll() { return roll; };
	float getYaw() { return yaw; };

	void setX(float a) { accX = a; };
	void setY(float a) { accY = a; };

	void saveCalibration();
	void startCalibration();
	double caliX();
	double caliY();

private:
	void update();

	std::thread t; //Thread to handle input
	bool connected{ false };
	bool run{ false };
	sf::TcpListener list;
	sf::TcpSocket soc;
	int dataSize{ 8 };
	int accLength{ 4 };
	int oriLength{ 8 };

	float accX{ 0 };
	float accY{ 0 };
	float accZ{ 0 };

	float pitch{ 0 };
	float roll{ 0 };
	float yaw{ 0 };

	void rec_acc();
	void rec_ori();

	void fix_vectors();

	void calcRotation();

	float gX[90];
	float gY[90];
	//float gZ[90];

	double counterX[90];
	double counterY[90];

	//Arrays used for calibration on accelerometer data to remove gravity
	double calibX[90];
	double calibY[90];

	//x,y acceleration without gravity
	float fixedX{ 0 };
	float fixedY{ 0 };

	void calibrate();

};

#endif