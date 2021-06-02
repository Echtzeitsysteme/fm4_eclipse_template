#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "init.h"
#include "blink.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char *argv[]) {
	initBoard();
	BlinkMain();
	return 0;
}

#pragma GCC diagnostic pop
