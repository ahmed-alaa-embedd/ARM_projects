/***************************/
/*Author : ahmed alaa	*/
/*date : 30/9/2020 		*/
/*version : v01			*/
/***************************/

#ifndef Esp_CONFIG_H
#define Esp_CONFIG_H

/*define recieving timout for each command that if it exceeded it means no more data*/
/*It varies depending on the router and server and also Clock freq, you'll need to try it*/
#define ECHO_TIMEOUT		100
#define MODE_TIMEOUT		150
#define ROUTER_TIMEOUT		1100000
#define SERVER_TIMEOUT		300000
#define PREREQUEST_TIMEOUT	200
#define REQUEST_TIMEOUT		900000


#endif
