#include "simulacrum.hpp"
#include <cmath>
#include <math.h>
#include <rclcpp/create_publisher.hpp>
#include <rclcpp/node.hpp>

Simulacrum::Simulacrum() : rclcpp::Node("simulacrum") {
	const int i_frequency = 10; 
	
	spotter = this->create_publisher<geometry_msgs::msg::Pose2D>("/waypoints/current", 10);
	

	auto interval = std::chrono::duration<double>(1.0 / i_frequency);
	this->m_timer = this->create_wall_timer(interval, [this]()-> void {
		if(this->m_accumulator>=2*M_PI){
			this->m_accumulator=0;

		}
		const double radius = 10; //in meters
		
		
		geometry_msgs::msg::Pose2D k;
		const double x0= radius*sqrt(2)*cos(this->m_accumulator);
		const double x1= pow(sin(this->m_accumulator),2)+1;

		x= x0/x1; 
		const double y0= radius*sqrt(2)*cos(this->m_accumulator)*sin(this->m_accumulator);
		const double y1= pow(cos(this->m_accumulator),2)+1;
		y= y0/y1;
	
		k.x=x;
		k.y=y;
		k.theta=0;
		
		this->spotter->publish(k);
		this->m_accumulator+=this->m_lacunarity;
	});

}
