#pragma once
#include <stdint.h>

#define WAIT_REPLICA_TO_COMMIT 0xFD
#define DO_NOT_WAIT_REPLICA_TO_COMMIT 0xAC

#define NUM_OF_TRIES 1000
extern uint64_t wake_up_workers_operations;
#define OMMIT_IO_IN_THE_INSERT_PATH 0

