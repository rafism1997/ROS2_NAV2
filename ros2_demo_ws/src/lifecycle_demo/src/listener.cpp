#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "lifecycle_msgs/msg/transition_event.hpp"

class Listener : public rclcpp::Node
{
    public:

    private:

    std::shared_ptr<rclcpp::Subscription</* msg_type */>::SharedPtr /* sub_name */;

};

int main(int argc , char ** argv){

    return 0;
}