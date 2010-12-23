/******************************************************************************
 *
 * Project:  integrating laszip into liblas - http://liblas.org -
 * Purpose:
 * Author:   Martin Isenburg
 *           isenburg at cs.unc.edu
 *
 ******************************************************************************
 * Copyright (c) 2010, Martin Isenburg
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Licence as published
 * by the Free Software Foundation.
 *
 * See the COPYING file for more information.
 *
 ****************************************************************************/

/*
===============================================================================

  FILE:  LASunzipper.hpp
  
  CONTENTS:
  
    Reads (optionally compressed) LIDAR points to LAS formats 1.0 - 1.3

  PROGRAMMERS:
  
    martin isenburg@cs.unc.edu
  
  COPYRIGHT:
  
    copyright (C) 2010  martin isenburg@cs.unc.edu
    
    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    12 December 2010 -- created from LASwriter/LASreader after Howard got pushy (-;
  
===============================================================================
*/
#ifndef LAS_UNZIPPER_H
#define LAS_UNZIPPER_H

#include <stdio.h>

#include "laszip.hpp"

#ifdef LZ_WIN32_VC6
#include <fstream.h>
#else
#include <istream>
#include <fstream>
using namespace std;
#endif

class ByteStreamIn;
class LASreadPoint;

class LASunzipper
{
public:
  unsigned int open(FILE* file, unsigned int num_items, const LASitem items[], unsigned int compression=0);
  unsigned int open(istream& stream, unsigned int num_items, const LASitem items[], unsigned int compression=0);
  bool read(unsigned char * const * point);
  unsigned int close();

  LASunzipper();
  ~LASunzipper();

private:
  int count;
  ByteStreamIn* stream;
  LASreadPoint* reader;
};

#endif