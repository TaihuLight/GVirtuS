#include <cuda_runtime_api.h>
#include "CudaRtHandler.h"

#ifndef CUDART_VERSION
#error CUDART_VERSION not defined
#endif
#if CUDART_VERSION >= 2030
CUDA_ROUTINE_HANDLER(DriverGetVersion) {
    int *driverVersion = input_buffer->Assign<int>();

    cudaError_t exit_code = cudaDriverGetVersion(driverVersion);

    Buffer *out = new Buffer();
    out->Add(driverVersion);

    return new Result(exit_code, out);
}

CUDA_ROUTINE_HANDLER(RuntimeGetVersion) {
    int *runtimeVersion = input_buffer->Assign<int>();

    cudaError_t exit_code = cudaRuntimeGetVersion(runtimeVersion);

    Buffer *out = new Buffer();
    out->Add(runtimeVersion);

    return new Result(exit_code, out);
}
#endif
