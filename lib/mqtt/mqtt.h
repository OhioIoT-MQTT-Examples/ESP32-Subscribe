#pragma once

#include <WiFiClient.h>
#include <PubSubClient.h>

#define CLIENT_ID "test_device_2"		// needs to be unique across brokers
#define RETRY_INTERVAL 3000

class Mqtt {
	
	public:

		Mqtt();

		void enable_logging();
		void setup(const char *, int);
		void maintain();

		void publish(const char *, const char *);
		void publish(const char *, float);
		void publish(const char *, int);
		void publish(const char *);

		void set_subscriptions(const char **, int);
		
		bool is_connected = false;

	private:

		WiFiClient _wifi_client;
		PubSubClient _mqtt_client;

		void _log_state();

		void _publish(const char *, const char *);
		void _subscribe_to_all();

		unsigned long _retry_timer;
		bool _is_first = true;
		bool _echo = true;
		bool _initial_subscription = true; 

		const char ** _subscription_list = nullptr;
		int _sub_list_length = 0;

};

extern Mqtt mqtt;