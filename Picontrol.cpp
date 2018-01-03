#include "Picontrol.h"
//#include <iostream>
#include <fstream>

Picontrol::Picontrol()
{
	std::ifstream in;
	in.open("cali.txt");

	for (int i{ 0 }; i < 90; ++i) {
		in >> calibX[i];
	}
	for (int i{ 0 }; i < 90; ++i) {
		in >> calibY[i];
	}
}

void Picontrol::start()
{
	run = true;
	//list.setBlocking(false);
	//soc.setBlocking(false);
	t = std::thread(&Picontrol::update, this);
}

void Picontrol::stop()
{
	run = false;

	
	//Disconnect controller and stop listening
	list.close();
	soc.disconnect();

	//Wait until thread is complete
	if(t.joinable())
		t.join();
	

	
}

void Picontrol::saveCalibration()
{
	std::ofstream out;

	out.open("cali.txt");

	for (int i{ 0 }; i < 90; ++i)
		out << gX[i] << " ";

	for (int i{ 0 }; i < 90; ++i)
		out << gY[i] << " ";

	out.close();
}

void Picontrol::startCalibration()
{
	for (int i{ 0 }; i < 90; ++i) {
		gX[i] = 0;
		gY[i] = 0;
		counterX[i] = 0;
		counterY[i] = 0;
	}
}

double Picontrol::caliX()
{
	double tmp{ 0 };

	for (int i{ 0 }; i < 90; ++i) {
		tmp += counterX[i];
	}

	return tmp/90;
}

double Picontrol::caliY()
{
	double tmp{ 0 };

	for (int i{ 0 }; i < 90; ++i) {
		tmp += counterY[i];
	}

	return tmp / 90;
}

void Picontrol::update()
{
	while (run) {
		
		//std::cout << "Waiting for connection" << std::endl;
		if (!connected) {



			if (list.listen(1001) != sf::Socket::Done) {

			}

			//std::cout << "Someone connecting" << std::endl;


			if (list.accept(soc) != sf::Socket::Done) {

			}
			connected = true;
		}
		else {
			this->rec_acc();

			this->rec_ori();

			//this->calibrate();

			this->fix_vectors();
		}
		
		
		//std::cout << accX << " : " << accY << " : " << accZ << std::endl;

		//std::cout << pitch << " : " << roll << " : " << yaw << std::endl;

		//soc.disconnect();
		//list.close();

	}

	
}

void Picontrol::rec_acc()
{
	std::size_t receivedSize;

	//accX
	char data[8];
	if (soc.receive(data, dataSize, receivedSize) != sf::Socket::Done) {

	}

	//accY
	char data1[8];
	if (soc.receive(data1, dataSize, receivedSize) != sf::Socket::Done) {

	}

	//accZ
	char data2[8];
	if (soc.receive(data2, dataSize, receivedSize) != sf::Socket::Done) {

	}





	//std::cout << "Received " << receivedSize << " bytes" << std::endl;

	//std::cout << data << std::endl;

	std::string num;


	for (int i{ 0 }; i < accLength; ++i) {
		num += data[i];
	}



	//To make sure packet corruptions are not sent through
	float tmpX = std::stof(num);
	if (abs(tmpX) <= 5)
		this->accX = tmpX;



	//std::cout << "Received " << receivedSize << " bytes" << std::endl;
	//std::cout << receivedSize << std::endl;
	num = "";


	for (int i{ 0 }; i < accLength; ++i) {
		num += data1[i];
	}

	//To make sure packet corruptions are not sent through
	float tmpY = std::stof(num);
	if (abs(tmpY) <= 5)
		this->accY = tmpY;

	num = "";


	for (int i{ 0 }; i < accLength; ++i) {
		num += data2[i];
	}

	//To make sure packet corruptions are not sent through
	float tmpZ = std::stof(num);
	if (abs(tmpZ) <= 5)
		this->accZ = tmpZ;


	
}

void Picontrol::rec_ori()
{
	std::size_t receivedSize;

	//pitch
	char data[8];
	if (soc.receive(data, dataSize, receivedSize) != sf::Socket::Done) {

	}

	//roll
	char data1[8];
	if (soc.receive(data1, dataSize, receivedSize) != sf::Socket::Done) {

	}

	//yaw
	char data2[8];
	if (soc.receive(data2, dataSize, receivedSize) != sf::Socket::Done) {

	}


	std::string num;



	for (int i{ 0 }; i < oriLength; ++i) {
		num += data[i];
	}



	//To make sure packet corruptions are not sent through
	float tmpX = std::stof(num);
	if(abs(tmpX) <= 360)
		this->pitch = tmpX;


	num = "";


	for (int i{ 0 }; i < oriLength; ++i) {
		num += data1[i];
	}

	//To make sure packet corruptions are not sent through
	float tmpY = std::stof(num);

	if (abs(tmpY) <= 360)
		this->roll = tmpY;

	num = "";


	for (int i{ 0 }; i < oriLength; ++i) {
		num += data2[i];
	}

	//To make sure packet corruptions are not sent through
	float tmpZ = std::stof(num);

	if (abs(tmpZ) <= 360)
		this->yaw = tmpZ;
}

void Picontrol::fix_vectors()
{
	/*
		Pitch: 360 -> 270, x: 0 -> 1
		Pitch: 0 -> 90, x: 0 -> -1
	
	*/

	/*

	if (0 < pitch && pitch < 90)
		accX -= -1 * (pitch / 90);
	else if (270 < pitch && pitch < 360)
		accX -= 1 + (pitch - 360) / 90;

	*/

	if(pitch >= 0 && pitch < 90)
		fixedX = accX - calibX[(int)pitch];

	if (roll >= 0 && roll < 90)
		fixedY = accY - calibY[(int)roll];

}

void Picontrol::calcRotation()
{
	
}

void Picontrol::calibrate()
{
	if (pitch > 0 && pitch < 90) {
		gX[(int)pitch] = accX;
		counterX[(int)pitch] = 1;
	}

	if (roll > 0 && roll < 90) {
		gY[(int)roll] = accY;
		counterY[(int)roll] = 1;
	}
}
