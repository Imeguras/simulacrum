#include <cstdio>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include "simulacrum.hpp"

int main(int argc, char ** argv){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<Simulacrum>());
	
	rclcpp::shutdown();

	return 0;
}