/*****************************************************************************
 *   GATB : Genome Assembly Tool Box                                         *
 *   Copyright (c) 2013                                                      *
 *                                                                           *
 *   GATB is free software; you can redistribute it and/or modify it under   *
 *   the CECILL version 2 License, that is compatible with the GNU General   *
 *   Public License                                                          *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 *   CECILL version 2 License for more details.                              *
 *****************************************************************************/

/** \file Container.hpp
 *  \date 01/03/2013
 *  \author edrezen
 *  \brief Container interface
 *
 *  This file holds interfaces related to the Container interface, ie something we can ask for items.
 */

#ifndef _GATB_CORE_TOOLS_COLLECTIONS_CONTAINER_HPP_
#define _GATB_CORE_TOOLS_COLLECTIONS_CONTAINER_HPP_

/********************************************************************************/

#include <gatb/tools/designpattern/api/SmartPointer.hpp>

/********************************************************************************/
namespace gatb          {
namespace core          {
namespace tools         {
namespace collections   {
/********************************************************************************/

/** \brief Container interface
 *
 * The Container interface provides an operation that ask for a given item
 */
template <class Item> class Container : public dp::SmartPointer
{
public:

    /** Tells whether an item exists or not
     * \return true if the item exists, false otherwise */
    virtual bool contains (const Item& item) = 0;
};

/********************************************************************************/
} } } } /* end of namespaces. */
/********************************************************************************/

#endif /* _GATB_CORE_TOOLS_COLLECTIONS_CONTAINER_HPP_ */