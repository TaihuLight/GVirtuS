/*
 * gVirtuS -- A GPGPU transparent virtualization component.
 *
 * Copyright (C) 2009-2010  The University of Napoli Parthenope at Naples.
 *
 * This file is part of gVirtuS.
 *
 * gVirtuS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gVirtuS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gVirtuS; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Written by: Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>,
 *             Department of Applied Science
 */

#include "CudaRt.h"

using namespace std;

extern "C" __host__ cudaError_t CUDARTAPI cudaConfigureCall(dim3 gridDim, dim3 blockDim,
        size_t sharedMem, cudaStream_t stream) {
    cerr << "Requesting cudaConfigureCall" << endl; 

    
    CudaRtFrontend::Prepare();
#if 0
    CudaRtFrontend::AddVariableForArguments(gridDim);
    CudaRtFrontend::AddVariableForArguments(blockDim);
    CudaRtFrontend::AddVariableForArguments(sharedMem);
    CudaRtFrontend::AddVariableForArguments(stream);
    CudaRtFrontend::Execute("cudaConfigureCall");
    return CudaRtFrontend::GetExitCode();
#endif
    Buffer *launch = CudaRtFrontend::GetLaunchBuffer();
    launch->Reset();
    // CNCL
    launch->Add<int>(0x434e34c);
    launch->Add(gridDim);
    launch->Add(blockDim);
    launch->Add(sharedMem);
#if CUDART_VERSION >= 3010
    launch->Add((pointer_t) stream);
#else
    launch->Add(stream);
#endif
    return cudaSuccess;
}

#ifndef CUDA_VERSION
#error CUDA_VERSION not defined
#endif
#if CUDA_VERSION >= 2030
extern "C" __host__ cudaError_t CUDARTAPI cudaFuncGetAttributes(struct cudaFuncAttributes *attr,
        const void *func) {
    cerr << "Requesting cudaFuncGetAttributes" << endl;
    CudaRtFrontend::Prepare();
    CudaRtFrontend::AddHostPointerForArguments(attr);
    CudaRtFrontend::AddVariableForArguments((pointer_t)func);
    //CudaRtFrontend::AddStringForArguments(CudaUtil::MarshalHostPointer((char*)func));
    CudaRtFrontend::Execute("cudaFuncGetAttributes");
    if(CudaRtFrontend::Success())
        memmove(attr, CudaRtFrontend::GetOutputHostPointer<cudaFuncAttributes>(),
                sizeof(cudaFuncAttributes));
    return CudaRtFrontend::GetExitCode();
}
#endif

extern "C" __host__ cudaError_t CUDARTAPI cudaFuncSetCacheConfig(const void *func,
        cudaFuncCache cacheConfig) {
    cerr << "Requesting cudaFuncSetCacheConfig" << endl;
    CudaRtFrontend::Prepare();
    //CudaRtFrontend::AddStringForArguments(CudaUtil::MarshalHostPointer((char*)func));
    CudaRtFrontend::AddVariableForArguments((pointer_t)func);
    CudaRtFrontend::AddVariableForArguments(cacheConfig);
    CudaRtFrontend::Execute("cudaFuncSetCacheConfig");
    
    return CudaRtFrontend::GetExitCode();
}

extern "C" __host__ cudaError_t CUDARTAPI cudaLaunch(const void *entry) {
#if 0
    CudaRtFrontend::AddStringForArguments(CudaUtil::MarshalHostPointer(entry));
    CudaRtFrontend::Execute("cudaLaunch");
    return CudaRtFrontend::GetExitCode();
#endif
    cerr << "Requesting cudaLaunch" << endl;
    Buffer *launch = CudaRtFrontend::GetLaunchBuffer();
    // LAUN
    launch->Add<int>(0x4c41554e);
    //launch->AddString(CudaUtil::MarshalHostPointer((char*)entry));
    launch->Add<pointer_t>((pointer_t)entry);
    cerr << "entry: " << CudaUtil::MarshalHostPointer((char*)entry) << endl;
    CudaRtFrontend::Execute("cudaLaunch", launch);
    return CudaRtFrontend::GetExitCode();
}

extern "C" __host__ cudaError_t CUDARTAPI cudaSetDoubleForDevice(double *d) {
    cerr << "Requesting cudaSetDoubleForDevice" << endl;
    CudaRtFrontend::Prepare();
    CudaRtFrontend::AddHostPointerForArguments(d);
    CudaRtFrontend::Execute("cudaSetDoubleForDevice");
    if(CudaRtFrontend::Success())
        *d = *(CudaRtFrontend::GetOutputHostPointer<double >());
    return CudaRtFrontend::GetExitCode();
}

extern "C" __host__ cudaError_t CUDARTAPI cudaSetDoubleForHost(double *d) {
    cerr << "Requesting cudaSetDoubleForHost" << endl;
    CudaRtFrontend::Prepare();
    CudaRtFrontend::AddHostPointerForArguments(d);
    CudaRtFrontend::Execute("cudaSetDoubleForHost");
    if(CudaRtFrontend::Success())
        *d = *(CudaRtFrontend::GetOutputHostPointer<double >());
    return CudaRtFrontend::GetExitCode();
}

extern "C" __host__ cudaError_t CUDARTAPI cudaSetupArgument(const void *arg, size_t size,
        size_t offset) {
    cerr << "Requesting cudaSetupArgument" << endl;
#if 0
    CudaRtFrontend::AddHostPointerForArguments(static_cast<const char *> (arg), size);
    CudaRtFrontend::AddVariableForArguments(size);
    CudaRtFrontend::AddVariableForArguments(offset);
    CudaRtFrontend::Execute("cudaSetupArgument");
    return CudaRtFrontend::GetExitCode();
#endif
    Buffer *launch = CudaRtFrontend::GetLaunchBuffer();
    // STAG
    launch->Add<int>(0x53544147);
    launch->Add<char>(static_cast<char *>(const_cast<void *>(arg)), size);
    launch->Add(size);
    launch->Add(offset);
    return cudaSuccess;
}
