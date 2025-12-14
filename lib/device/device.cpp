#include "device.h"
#include "mqtt.h"




Device::Device() {}

Device device;

void Device::begin() {
	
	static const char * subscription_list[] = {
		"temperature",
		"humidity",
		"luminosity"
	};

	mqtt.set_subscriptions(subscription_list, 3);
}

void Device::check() {

}

