//
//    FILE: malc_exceptions.h
//  AUTHOR: Talha Çelik
// VERSION: 1.0.0
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://talhacelik.com.tr
//

#ifndef malc_exceptions_h
#define malc_exceptions_h


class  malc_exceptions 
{
public:
	const char* model_exception(){
		return "Error : ModelException \nOnly use DHT 11 model.\nCheck the set_dht_pin(int dht_pin, int dht_model) function";
	}

private:
	
	
	};

	
#endif
