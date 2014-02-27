/*
 * ZeroMQWrapper.cpp
 *
 *  Created on: 2014年2月27日
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "zmq.h"

#include "ZeroMQWrapper.h"



ZeroMQWrapper::ZeroMQWrapper() {
	// TODO Auto-generated constructor stub

}

ZeroMQWrapper::~ZeroMQWrapper() {
	// TODO Auto-generated destructor stub
}

int ZeroMQWrapper::init()
{
	int rc = 0;

	context = zmq_ctx_new();
	subscriber = zmq_socket(context, ZMQ_SUB);
	rc = zmq_connect(subscriber, "tcp://192.168.1.113:5556");
	if (rc != 0)
	{
		std::cout << " connect fail\n";
		return rc;
	}

	char * filter = "";
	rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, filter, strlen(filter));
	if (rc != 0)
	{
		std::cout << "zmq_setsockopt fail\n";
	}

	return rc;
}

int ZeroMQWrapper::sub()
{
	int rc = 0;

	char buf[512];
	int size = zmq_recv(subscriber, buf, strlen(buf)-1, 0);
	std::cout << "size = " << size << std::endl;
	buf[size] = '\0';

	return rc;
}

void ZeroMQWrapper::cleanup()
{
	zmq_close(subscriber);
	zmq_ctx_destroy(context);
}
