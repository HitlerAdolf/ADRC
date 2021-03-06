#ifndef TWIP_H
#define TWIP_H

#include "Gyroscope.h"
#include "Accelerometer.h"
#include "Motor.h"
#include "Encoders.h"
#include "Kalman.h"

// TWIP: Two Wheeled Inverted Pendulum

class TWIP {
	Gyroscope m_gyroscope;
	Kalman m_kalman_filter;
  Accelerometer m_accelerometer;
	Motor m_motors;
	Encoders m_encoders;
  int m_motor_ports[2];
  int m_encoder_offset[2];

public:
  
  TWIP(const unsigned int gyro_port, 
  	   const unsigned int accel_port,
       const unsigned int motor_left, 
       const unsigned int motor_right,
       float dt);

  virtual ~TWIP() {};

  Eigen::Vector2f output(float u);
};

#endif