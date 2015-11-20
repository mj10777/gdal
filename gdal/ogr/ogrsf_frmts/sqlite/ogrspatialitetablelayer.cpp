/******************************************************************************
 * $Id$
 *
 * Project:  OpenGIS Simple Features Reference Implementation
 * Purpose:  Implements OGRSpatialiteTableLayer class, access to an existing table.
 * Author:   Frank Warmerdam, warmerdam@pobox.com
 *
 ******************************************************************************
 * Copyright (c) 2004, Frank Warmerdam
 * Copyright (c) 2009-2013, Even Rouault <even dot rouault at mines-paris dot org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "cpl_conv.h"
#include "cpl_string.h"
#include "ogr_sqlite.h"
#include "ogr_p.h"
#include "cpl_time.h"
#include <string>

#define UNSUPPORTED_OP_READ_ONLY "%s : unsupported operation on a read-only datasource."

CPL_CVSID("$Id$");

/************************************************************************/
/*                        OGRSpatialiteTableLayer()                         */
/************************************************************************/

OGRSpatialiteTableLayer::OGRSpatialiteTableLayer( OGRSQLiteDataSource *poDSIn )
{ // start tasks (non-db) are done in OGRSpatialiteLayer(), which runs first
 poDS = poDSIn;
     /* SpatiaLite v.2.4.0 (or any subsequent) is required
       to support 2.5D: if an obsolete version of the library
       is found we'll unconditionally activate 2D casting mode.
    */
    if ( poDS->IsSpatialiteDB() )
     bSpatialite2D = poDS->GetSpatialiteVersionNumber() < 24;
}

/************************************************************************/
/*                        ~OGRSpatialiteTableLayer()                        */
/************************************************************************/

OGRSpatialiteTableLayer::~OGRSpatialiteTableLayer()
{ // cleanup done in ~OGRSpatialiteLayer()
}

/************************************************************************/
/*                             Initialize()  [done in OGRSpatialiteLayer]              */
/************************************************************************/
CPLErr OGRSpatialiteTableLayer::Initialize( const char *pszTableName, 
                                        OGRSpatialiteLayerType eSpatialiteLayerType,
                                        int bDeferredCreation )
{
 // CPLDebug( "OGR", "-I-> OGRSpatialiteTableLayer::Initialize(%s): layer_type=[%d] database_type=[%d]", pszTableName, eSpatialiteLayerType,poDS->GetDatabaseType());
 return OGRSpatialiteLayer::Initialize(pszTableName,eSpatialiteLayerType,bDeferredCreation);
}
