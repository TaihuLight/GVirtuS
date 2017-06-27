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

#include <iostream>
#include <cstdio>
#include <string>

#include "CurandHandler.h"

using namespace std;
using namespace log4cplus;

CURAND_ROUTINE_HANDLER(Generate){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("Generate"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    unsigned int * outputPtr = in->Assign<unsigned int>();
    size_t num = in->Get<size_t>();
    
    curandStatus_t cs = curandGenerate(generator,outputPtr,num);
    
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GenerateLongLong){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateLongLong"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    unsigned long long int * outputPtr = in->Assign<unsigned long long int>();
    size_t num = in->Get<size_t>();
    
    curandStatus_t cs = curandGenerateLongLong(generator,outputPtr,num);
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GenerateUniform){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateUniform"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    float * outputPtr = in->Assign<float>();
    size_t num = in->Get<size_t>();
    
    curandStatus_t cs = curandGenerateUniform(generator,outputPtr,num);
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GenerateNormal){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateNormal"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    float * outputPtr = in->Assign<float>();
    size_t n = in->Get<size_t>();
    float mean = in->Get<float>();
    float stddev = in->Get<float>();
    
    curandStatus_t cs = curandGenerateNormal(generator,outputPtr,n,mean,stddev);
    return new Result(cs);
}


CURAND_ROUTINE_HANDLER(GenerateLogNormal){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateLogNormal"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    float * outputPtr = in->Assign<float>();
    size_t n = in->Get<size_t>();
    float mean = in->Get<float>();
    float stddev = in->Get<float>();
    
    curandStatus_t cs = curandGenerateLogNormal(generator,outputPtr,n,mean,stddev);
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GeneratePoisson){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GeneratePoisson"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    unsigned int * outputPtr = in->Assign<unsigned int>();
    size_t n = in->Get<size_t>();
    double lambda = in->Get<double>();
    
    curandStatus_t cs = curandGeneratePoisson(generator,outputPtr,n,lambda);
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GenerateUniformDouble){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateUniformDouble"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    double * outputPtr = in->Assign<double>();
    size_t num = in->Get<size_t>();
    
    curandStatus_t cs = curandGenerateUniformDouble(generator,outputPtr,num);
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GenerateNormalDouble){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateNormalDouble"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    double * outputPtr = in->Assign<double>();
    size_t n = in->Get<size_t>();
    double mean = in->Get<double>();
    double stddev = in->Get<double>();
    
    
    curandStatus_t cs = curandGenerateNormalDouble(generator,outputPtr,n,mean,stddev);
    return new Result(cs);
}

CURAND_ROUTINE_HANDLER(GenerateLogNormalDouble){
    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("GenerateLogNormalDouble"));
    
    curandGenerator_t generator = (curandGenerator_t)in->Get<long long int>();
    double * outputPtr = in->Assign<double>();
    size_t n = in->Get<size_t>();
    double mean = in->Get<double>();
    double stddev = in->Get<double>();
    
    
    curandStatus_t cs = curandGenerateLogNormalDouble(generator,outputPtr,n,mean,stddev);
    return new Result(cs);
}