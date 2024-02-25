
/* 

* rosserial Subscriber Example

* Blinks an LED on callback

*/
 
#include <ros.h>

#include <std_msgs/Int16.h>
 
ros::NodeHandle  nh;
std_msgs::Int16 sensorData; 

void control_LED( const std_msgs::Int16& cmd_msg)

{
  int value = cmd_msg.data;
  digitalWrite(13, cmd_msg.data);   // blink the led
}

ros::Subscriber<std_msgs::Int16> sub("Topic_LED_13", &control_LED );
ros::Publisher pub ("Topic_Sensor", &sensorData);

void setup()

{ 

  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);

}
 
void loop()

{  
  sensorData.data = digitalRead(8);
  pub.publish(&sensorData);
  nh.spinOnce();
  delay(500);

}
