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
 * Written by: Roberto Di Lauro <roberto.dilauro@uniparthenope.it>,
 *             Department of Applied Science
 */

#include "OclHandler.h"

OCL_ROUTINE_HANDLER(GetPlatformIDs) {
    
    
    cl_uint num_entries = input_buffer->Get<cl_uint>();
    cl_platform_id *platforms=input_buffer->Assign<cl_platform_id>();
    cl_uint *num_platforms=input_buffer->Assign<cl_uint>();


    cl_int exit_code = clGetPlatformIDs(num_entries,platforms,num_platforms);

    Buffer *out = new Buffer();
    out->Add(num_platforms);
    out->Add(platforms);

    return new Result((cudaError_t)exit_code, out); 
}

OCL_ROUTINE_HANDLER(GetPlatformInfo) {

    cl_platform_id *platform=input_buffer->Assign<cl_platform_id>();
    cl_platform_info param_name=input_buffer->Get<cl_platform_info>();
    size_t param_value_size=input_buffer->Get<size_t>();
    char * param_value=new char[param_value_size];
    size_t param_value_size_ret=0;

    cl_int exit_code = clGetPlatformInfo(*platform,param_name,param_value_size,param_value,&param_value_size_ret);

    Buffer *out = new Buffer();
    out->Add(&param_value_size_ret);
    out->AddString(param_value);
    return new Result((cudaError_t)exit_code, out); 
}

