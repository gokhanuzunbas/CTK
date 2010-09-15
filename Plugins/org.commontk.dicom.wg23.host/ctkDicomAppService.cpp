/*=============================================================================

  Library: CTK

  Copyright (c) 2010 German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#include "ctkDicomAppService.h"

#include "ctkDicomServicePrivate.h"

#include "ctkDicomWG23TypesHelper.h"

ctkDicomAppService::ctkDicomAppService(int port)
  : d_ptr(new ctkDicomServicePrivate(port))
{

}
ctkDicomAppService::~ctkDicomAppService()
{
}


ctkDicomWG23::State ctkDicomAppService::getState()
{
  Q_D(ctkDicomService);

  QtSoapType result = d->askHost("getState", NULL);
  return ctkDicomSoapState::getState(result);
}

bool ctkDicomAppService::setState(ctkDicomWG23::State newState)
{
  Q_D(ctkDicomService);
  QtSoapType* input = new ctkDicomSoapState("state", newState);
  QtSoapType result = d->askHost("setState", input);
  return ctkDicomSoapBool::getBool(result);
}

bool ctkDicomAppService::bringToFront(const QRect& requestedScreenArea)
{
    Q_D(ctkDicomService);
    QtSoapType* input = new ctkDicomSoapRectangle("requestedScreenArea", requestedScreenArea);
    QtSoapType result = d->askHost("bringToFront", input);
    return ctkDicomSoapBool::getBool(result);
}