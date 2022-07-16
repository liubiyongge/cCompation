#pragma once
#include <assert.h>
#include <inttypes.h>
#include <semaphore.h>

/*mvard added defines for return when function succeded or failed*/
typedef enum kreon_op_status {
	KREON_SUCCESS = 1,
	KREON_FAILURE,
	KREON_KEY_NOT_FOUND,
	KREON_VALUE_TOO_LARGE
} kreon_op_status;

//TODO move properties to a configuration file
#define RDMA_IP_FILTER "192.168.4."

#define NUM_OF_CONNECTIONS_PER_SERVER 1

#define TU_HEADER_SIZE (sizeof(struct msg_header))
#define TU_TAIL_SIZE (sizeof(uint8_t))
