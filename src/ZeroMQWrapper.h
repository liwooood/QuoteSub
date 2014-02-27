/*
 * ZeroMQWrapper.h
 *
 *  Created on: 2014年2月27日
 *      Author: root
 */

#ifndef ZEROMQWRAPPER_H_
#define ZEROMQWRAPPER_H_

class ZeroMQWrapper {
public:
	ZeroMQWrapper();
	virtual ~ZeroMQWrapper();

public:
	int init();
	void cleanup();
	int sub();

private:
	void * context;
	void * subscriber;

};

#endif /* ZEROMQWRAPPER_H_ */
