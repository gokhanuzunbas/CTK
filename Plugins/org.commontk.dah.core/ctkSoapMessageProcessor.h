/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
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

#ifndef CTKSOAPMESSAGEPROCESSOR_H
#define CTKSOAPMESSAGEPROCESSOR_H

#include <qtsoap.h>

#include <org_commontk_dah_core_Export.h>

class org_commontk_dah_core_EXPORT ctkSoapMessageProcessor
{

public:

  virtual ~ctkSoapMessageProcessor() {}

	/**
	* Process a Soap Message and set the input reply.
	* @input message The message to process.
	* @input reply The reply to the input message.
	* @return True if the message could be processed.
	*/
	virtual bool process( 
		const QtSoapMessage& message,
    QtSoapMessage* reply) const
  {
    Q_UNUSED(message)
    Q_UNUSED(reply)
    // to implement
    return false;
  }
		
	bool operator==( const ctkSoapMessageProcessor& rhs )
	{
		if( this == &rhs )
		{
			return true;
		}
		return false;
	}

};

#endif // CTKSOAPMESSAGEPROCESSOR_H
