//============================================================================
// Name        : QuoteSub.cpp
// Author      : chenhf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ZeroMQWrapper.h"


int main() {

	ZeroMQWrapper mq;

	mq.init();

	while(true)
	{
		mq.sub();
	}

	mq.cleanup();

	return 0;
}
