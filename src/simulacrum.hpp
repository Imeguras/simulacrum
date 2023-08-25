#include <cstdio>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/logger.hpp>
//include pose2d
#include <geometry_msgs/msg/pose2_d.hpp>

#ifndef SIMULACRUM_NODE__
#define SIMULACRUM_NODE__

class Simulacrum : public rclcpp::Node{
	public: 
		
		Simulacrum(); 
		virtual ~Simulacrum() = default; 
	private:
		double m_lacunarity=0.125;
		double m_accumulator=0;
		double x=0;
		double y=0; 
		rclcpp::TimerBase::SharedPtr m_timer;
		rclcpp::Publisher<geometry_msgs::msg::Pose2D>::SharedPtr spotter; 

}; 
#endif