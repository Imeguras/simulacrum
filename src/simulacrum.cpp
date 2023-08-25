#include "simulacrum.hpp"
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
		x= radius*sin(x+this->m_accumulator);
		y= radius*sin(y+this->m_accumulator)*cos(y+this->m_accumulator);
		k.x=x;
		k.y=y;
		k.theta=0;
		
		this->spotter->publish(k);
		this->m_accumulator+=this->m_lacunarity;
	});

}
